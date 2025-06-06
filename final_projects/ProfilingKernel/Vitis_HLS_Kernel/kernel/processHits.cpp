#include "processHits.h"
#include <iostream>  // For debug prints
#include <bitset>    // For binary output

// Function to get the LAST bit from a 64-bit strip line
static bool get_LAST_bit(ap_uint<64> stripLine) {
    return stripLine[63] || stripLine[31];  // Check both first bits of upper and lower 32 bits
}

static ap_uint<8> getFlag(ap_uint<64> stripLine) 
{
    ap_uint<8> flag = stripLine.range(63, 56);
    return flag;
}

static void flushBuffers(hls::stream<ap_uint<64>>& outputStream, 
                   ap_uint<64>*& out, 
                   hls::stream<ap_uint<64>>& outEDMStream, 
                   ap_uint<64>*& outEDM) 
{
    flushBuffersEDM: while(!outEDMStream.empty()) {
        ap_uint<64> result = outEDMStream.read();
        *outEDM++ = result;
    }

    flushBuffersCluster: while (!outputStream.empty()) {
        ap_uint<64> result = outputStream.read();
        *out++ = result;
    }
}

static void flushBuffers(hls::stream<strip_cluster_local>& outputClusters, 
                   ap_uint<64>*& out, 
                   ap_uint<64>*& outEDM, ap_uint<64>& moduleHeader) 
{
    // output the stream and pack into 64 stream
    bool isFirst32Filled = false;
    bool outputWord = false;
    ap_uint<64> outWord = 0;


    flushBuffers: while(!outputClusters.empty()) {
        strip_cluster_local outClusterInfo = outputClusters.read();


        // Extract and encode the output fields
        strip_cluster outCluster;
        outCluster.row          = outClusterInfo.row;
        outCluster.nstrips      = outClusterInfo.nstrips;
        outCluster.strip_index  = outClusterInfo.strip_index;
        outCluster.last         = outClusterInfo.last;

        ap_uint<32> encodedCluster;   
        encode_strip_cluster(encodedCluster, outCluster);
        #ifdef SW_EMU
                std::cout << "[OUTPUT CLUSTER] Encoded Data = " << std::hex << encodedCluster;
                std::cout << " FIELDS ";
                std::cout << "LAST = " << std::dec << outCluster.last 
                        << ", ROW = " << std::dec << outCluster.row 
                        << ", NSTRIPS = " << std::dec <<  outCluster.nstrips 
                        << ", STRIP_INDEX = " << std::dec << outCluster.strip_index << std::endl;
        #endif

        // Fill the upper half first
        if(!isFirst32Filled)
        {
            outWord.range(63, 32) = encodedCluster;
            isFirst32Filled = true;
        }
        else
        {
            // move the cluster down, and add the other output, and then clean it
            outWord.range(31, 0) = outWord.range(63, 32);
            outWord.range(63, 32) = encodedCluster;
            // output the cluster
            // outputStream << outWord;

            // clean the state
            isFirst32Filled = false;
            outputWord = true;
        }

        if(outCluster.last) outputWord = true;

        if(outputWord)
        {
            *out++ = outWord;
            outWord = 0; 
            outputWord = false;
        }

        //  Fill out information for EDM output . Wrap this into a function, that takes strip_cluster outCluster as a input
        edm_stripcluster emdStrip;
        emdStrip.flag = EDM_STRIPCLUSTER_FLAG;
        // emdStrip.id_hash = hashCounter; // Global counter that is reset at each event
        // hashCounter = hashCounter + ap_uint<EDM_STRIPCLUSTER_W1_ID_HASH_bits>(1); 

        auto m_mdr = decode_m_hdr(moduleHeader);
        emdStrip.id_hash = m_mdr.modhash; 

        // Need to add info about the hits, but for now good enough
        emdStrip.identifier = 0;
        emdStrip.identifier.range(63, 32) = moduleHeader.range(55, 24);
        emdStrip.identifier.range(30, 17) = outCluster.strip_index;

        // Have to build these as well
        emdStrip.rdo_list_w1 = 0;
        emdStrip.rdo_list_w1.range(63, 32) = moduleHeader.range(55, 24);
        emdStrip.rdo_list_w1.range(30, 17) = outCluster.strip_index;

        emdStrip.rdo_list_w2 = 0;
        emdStrip.rdo_list_w3 = 0;
        emdStrip.rdo_list_w4 = 0;

        // These should be the row strips
        emdStrip.localposition_x = 0;
        emdStrip.localposition_y = 0;
        emdStrip.localcovariance_xx = 0;// calculable from strip width

        // To be filled by L2G
        emdStrip.globalposition_x = 0;
        emdStrip.globalposition_y = 0;
        emdStrip.globalposition_z = 0;

        emdStrip.channels_in_phi = outCluster.nstrips; // this is strip width;

        // EDM_STRIPCLUSTER_W9
        emdStrip.lastword = outClusterInfo.isLastofEvent;
        emdStrip.index = 0; // need to remove this;


        #ifdef SW_EMU
                std::cout << "[OUTPUT CLUSTER] Encoded for EDM Data = " << outClusterInfo.isLastofEvent << std::endl;
        #endif

        // Send it all to the outstream
        encode_edm_stripcluster(outEDM, emdStrip);


    }

   
}

static void outputClusterFromRow( ModuleRowData& rowData, ap_uint<1> row, ap_uint<64>* &out, ap_uint<64>* &outEDM, bool isLastClusterOfEvent, ap_uint<EDM_STRIPCLUSTER_W1_ID_HASH_bits>& hashCounter, ap_uint<64>& moduleHeader, flush_cnt_t& edmFlushCnt)
{

    // hls::stream<ap_uint<64>> outputStream("outputStream");
    // hls::stream<ap_uint<64>> outEDMStream("outEDMStream");
    // #pragma HLS STREAM variable=outputStream depth=128
    // #pragma HLS STREAM variable=outEDMStream depth=1024

    hls::stream<strip_cluster_local> outputClusters("outputClusters");
    #pragma HLS STREAM variable=outputClusters depth=500


    #ifdef SW_EMU
    std::cout << "[outputClusterFromRow] first Cluster = " << std::dec << rowData.firstStrip << std::endl;
    std::cout << "[outputClusterFromRow] last Cluster = " << std::dec << rowData.lastStrip << std::endl;
    #endif

    int i = rowData.firstStrip;

    ap_uint<MAX_STRIPS_PER_MODULE> cRow = rowData.row;

    cRow = cRow >> (rowData.firstStrip);

    outputClusterFromRowLoop: for(; i <= rowData.lastStrip; i++)
    {
        if(cRow[0] == 0)
        {
            // increment and then continue
            cRow = cRow >> 1;
            continue;
        }

        // // Safeguard to avoid filled streams 
        // ++edmFlushCnt;
        // if (edmFlushCnt >= FLUSH_THRESHOLD){
        //     flushBuffers(outputStream, out, outEDMStream, outEDM);
        //     edmFlushCnt = 0; 
        // }
        
        // Extract and encode the output fields
        strip_cluster_local outCluster;
        outCluster.row          = row;
        outCluster.nstrips      = 1;
        outCluster.strip_index  = i;
        // increment i and increment nstrips till we see a break
        i++;
        outputClusterFromRowInsideLoop: for(; i <= rowData.lastStrip; i++)
        {
            cRow = cRow >> 1;
            if(cRow[0] == 0) break;
            outCluster.nstrips++;
        }
        outCluster.last = ( i >= rowData.lastStrip);
        outCluster.isLastofEvent = (isLastClusterOfEvent && outCluster.last);
        outputClusters << outCluster;


        // // Extract and encode the output fields
        // strip_cluster outCluster;
        // outCluster.row          = row;
        // outCluster.nstrips      = 1;
        // outCluster.strip_index  = i;
        
        // // increment i and increment nstrips till we see a break
        // i++;
        // outputClusterFromRowInsideLoop: for(; i <= rowData.lastStrip; i++)
        // {
        //     if(cRow[0] == 0) break;
        //     cRow >> 1;
        //     outCluster.nstrips++;
        // }

        // outCluster.last = ( i >= rowData.lastStrip);


        // ap_uint<32> encodedCluster;   
        // encode_strip_cluster(encodedCluster, outCluster);
        // #ifdef SW_EMU
        //         std::cout << "[OUTPUT CLUSTER] Encoded Data = " << std::hex << encodedCluster;
        //         std::cout << " FIELDS ";
        //         std::cout << "LAST = " << std::dec << outCluster.last 
        //                 << ", ROW = " << std::dec << outCluster.row 
        //                 << ", NSTRIPS = " << std::dec <<  outCluster.nstrips 
        //                 << ", STRIP_INDEX = " << std::dec << outCluster.strip_index << std::endl;
        // #endif

        // // Fill the upper half first
        // if(!isFirst32Filled)
        // {
        //     outWord.range(63, 32) = encodedCluster;
        //     isFirst32Filled = true;
        // }
        // else
        // {
        //     // move the cluster down, and add the other output, and then clean it
        //     outWord.range(31, 0) = outWord.range(63, 32);
        //     outWord.range(63, 32) = encodedCluster;
        //     // output the cluster
        //     outputStream << outWord;

        //     // clean the state
        //     isFirst32Filled = false;
        //     outWord = 0; 
        // }

        // //  Fill out information for EDM output . Wrap this into a function, that takes strip_cluster outCluster as a input
        // edm_stripcluster emdStrip;
        // emdStrip.flag = EDM_STRIPCLUSTER_FLAG;
        // // emdStrip.id_hash = hashCounter; // Global counter that is reset at each event
        // // hashCounter = hashCounter + ap_uint<EDM_STRIPCLUSTER_W1_ID_HASH_bits>(1); 

        // auto m_mdr = decode_m_hdr(moduleHeader);
        // emdStrip.id_hash = m_mdr.modhash; 

        // // Need to add info about the hits, but for now good enough
        // emdStrip.identifier = 0;
        // emdStrip.identifier.range(63, 32) = moduleHeader.range(55, 24);
        // emdStrip.identifier.range(30, 17) = outCluster.strip_index;

        // // Have to build these as well
        // emdStrip.rdo_list_w1 = 0;
        // emdStrip.rdo_list_w1.range(63, 32) = moduleHeader.range(55, 24);
        // emdStrip.rdo_list_w1.range(30, 17) = outCluster.strip_index;

        // emdStrip.rdo_list_w2 = 0;
        // emdStrip.rdo_list_w3 = 0;
        // emdStrip.rdo_list_w4 = 0;

        // // These should be the row strips
        // emdStrip.localposition_x = 0;
        // emdStrip.localposition_y = 0;
        // emdStrip.localcovariance_xx = 0;// calculable from strip width

        // // To be filled by L2G
        // emdStrip.globalposition_x = 0;
        // emdStrip.globalposition_y = 0;
        // emdStrip.globalposition_z = 0;

        // emdStrip.channels_in_phi = outCluster.nstrips; // this is strip width;

        // // EDM_STRIPCLUSTER_W9
        // emdStrip.lastword = (isLastClusterOfEvent && outCluster.last); // have to calculate this for last hit in the event;
        // emdStrip.index = 0; // need to remove this;


        // #ifdef SW_EMU
        //         std::cout << "[OUTPUT CLUSTER] Encoded for EDM Data = " << isLastClusterOfEvent << std::endl;
        // #endif

        // // Send it all to the outstream
        // encode_edm_stripcluster(outEDMStream, emdStrip);
        cRow = cRow >> 1;

        }

    // // output the final cluster 
    // if(outWord) outputStream << outWord;

    // flushBuffers(outputStream, out, outEDMStream, outEDM);
    flushBuffers(outputClusters, out, outEDM, moduleHeader);
}

static void preprocessSingleStripData(ap_uint<32>& clusterInfo, ModuleRowData& rowZeroData, ModuleRowData& rowOneData)
{
    // if its empty, do nothing
    if(clusterInfo == 0) return;

    strip_ef_rdo strip_RDO = decode_strip_ef_rdo(clusterInfo);

    // unroll the position
    ap_uint<4> chipID = strip_RDO.chipid;
    ap_uint<8> stripID = strip_RDO.strip_num;
    ap_uint<12> unrolledStripID = 0;
    ap_uint<2> row = 0;
    if(stripID >= 128) 
    {
        unrolledStripID = (stripID - 128) + chipID*128;
        row = 1;
    }
    else
    { 
        unrolledStripID = (stripID) + chipID*128;
        row = 0;
    }

    // Now loop over and fill the big array for each strips that have been hit

    #ifdef SW_EMU
        std::cout << "[PROCESSING CLUSTER] Input Cluster = " 
                << ", unrolledStripID = " << std::dec << unrolledStripID
                << ", last = " << std::hex << strip_RDO.last 
                << ", chipid = " << std::dec << strip_RDO.chipid 
                << ", nstrips = " << std::dec << strip_RDO.strip_num 
                << ", cluster_map = " << std::bitset<3>(strip_RDO.cluster_map) << std::endl;
    #endif

    ap_uint<4> hitMask = 0;
    hitMask[0] = 1;
    hitMask[1] = strip_RDO.cluster_map[2];
    hitMask[2] = strip_RDO.cluster_map[1];
    hitMask[3] = strip_RDO.cluster_map[0];

    ModuleRowData& target = row ? rowOneData : rowZeroData;

    target.row.range(unrolledStripID + 4, unrolledStripID) = hitMask;
    target.rowHasHits = true;

    if(unrolledStripID < target.firstStrip ) target.firstStrip = unrolledStripID;

    ap_uint<12> lastHit = unrolledStripID;
    if(strip_RDO.cluster_map[2]) lastHit = unrolledStripID + 1;
    if(strip_RDO.cluster_map[1]) lastHit = unrolledStripID + 2;
    if(strip_RDO.cluster_map[0]) lastHit = unrolledStripID + 3;
    if(lastHit > target.lastStrip ) target.lastStrip = lastHit;
}


// Helper to process module block
static void preprocessModuleBlock(ap_uint<64>& stripLine, ModuleRowData& rowZeroData, ModuleRowData& rowOneData)
{
    ap_uint<32> cluster1 = stripLine.range(63, 32);
    ap_uint<32> cluster2 = stripLine.range(31, 0);

    #ifdef SW_EMU
        std::cout << "[CLUSTER] Cluster 1 = " << std::hex << cluster1 << std::endl;
        std::cout << "[CLUSTER] Cluster 2 = " << std::hex << cluster2 << std::endl;
    #endif

    // Preprocess the cluster info
    preprocessSingleStripData(cluster1, rowZeroData, rowOneData);
    preprocessSingleStripData(cluster2, rowZeroData, rowOneData);
}

// Read data from global memory and process
void process_inputs(ap_uint<64>* in, ap_uint<64>* out, ap_uint<64>* outEDM, unsigned int vSize) 
{
    // Safeguard variable 
    flush_cnt_t edmFlushCnt = 0; 

    // For counting the output hash number
    ap_uint<EDM_STRIPCLUSTER_W1_ID_HASH_bits> hashCounter = 0;
    // Store it for building other info
    ap_uint<64> moduleHeader = 0;

    State state = State::DECIDEONFLAG;    

    // Create a struct holder to hold all the strips for the module
    ModuleRowData rowZeroData = ModuleRowData(); 
    ModuleRowData rowOneData = ModuleRowData(); 

    ap_uint<64> stripLine;
	ap_uint<64> peakForwardLine;

    peakForwardLine = *in++;

    mainReadloop: for (unsigned int i = 0; i < vSize; i++) 
    {
        bool isLastClusterOfEvent = false;
        // Read the line
        ap_uint<64> stripLine = peakForwardLine;
        peakForwardLine = *in++;

        auto flag = getFlag(peakForwardLine);
        if(flag == 0xcd) isLastClusterOfEvent = true;
        
        if(state == State::DECIDEONFLAG)
        {
            auto flag = getFlag(stripLine);
            if(flag == 0xAB) state = State::READ_EVENT_HEADER_W1;
            else if(flag == 0x55) state = State::READ_MODULE_HEADER;
            else if(flag == 0xcd) state = State::READ_EVENT_FOOTER_W1;
            else state = State::READ_MODULE_HEADER;
        }

        if (state == State::READ_EVENT_HEADER_W1) {
            #ifdef SW_EMU
                std::cout << "[INPUT] Reading and Writing Header" << std::endl;
            #endif
            *out++ = stripLine;
            *outEDM++ = stripLine;
            state = State::READ_EVENT_HEADER_W2;

            // Reset hash counter
            hashCounter = 0;
        }
        else if (state == State::READ_EVENT_HEADER_W2) {
            #ifdef SW_EMU
                std::cout << "[INPUT] Reading and Writing Header" << std::endl;
            #endif
            *out++ = stripLine;
            *outEDM++ = stripLine;
            state = State::READ_EVENT_HEADER_W3;
        }
        else if (state == State::READ_EVENT_HEADER_W3) {
            #ifdef SW_EMU
                std::cout << "[INPUT] Reading and Writing Header" << std::endl;
            #endif
            *out++ = stripLine;
            *outEDM++ = stripLine;
            state = State::DECIDEONFLAG;
        }
        else if (state == State::READ_MODULE_HEADER) {
            *out++ = stripLine;
            moduleHeader = stripLine;

            state = State::READ_MODULE_BLOCK;
            #ifdef SW_EMU
            std::cout << "-------------------------------------------------------------" << std::endl;
            std::cout << "[MODULE HEADER] Module Header = " << std::hex <<  in[i] << std::endl;
            #endif
        }
        else if (state == State::READ_MODULE_BLOCK) 
        {
            bool lastBit = get_LAST_bit(stripLine);

            preprocessModuleBlock(stripLine, rowZeroData, rowOneData);

            if(lastBit)
            {
                #ifdef SW_EMU
                    std::cout << "[LAST BIT] Module boundary detected. Hits in the module" << std::endl;
                    for(int i = 0; i < MAX_STRIPS_PER_MODULE; i++)
                    {
                        if(rowZeroData.row[i]) std::cout<<"Row 0 ["<<std::dec<<i<<"] = 1"<<std::endl;
                    }
                    for(int i = 0; i < MAX_STRIPS_PER_MODULE; i++)
                    {
                        if(rowOneData.row[i]) std::cout<<"Row 1 ["<<std::dec<<i<<"] = 1"<<std::endl;
                    }

                #endif

                if(rowZeroData.rowHasHits) outputClusterFromRow(rowZeroData, 0, out, outEDM, isLastClusterOfEvent, hashCounter, moduleHeader, edmFlushCnt);
                if(rowOneData.rowHasHits)  outputClusterFromRow(rowOneData, 1, out, outEDM, isLastClusterOfEvent, hashCounter, moduleHeader, edmFlushCnt);

                // Reset the data at each module
                rowZeroData = ModuleRowData(); 
                rowOneData = ModuleRowData(); 
                
                state = State::DECIDEONFLAG;
            }
        }
        else if (state == State::READ_EVENT_FOOTER_W1) {
            #ifdef SW_EMU
                std::cout << "[INPUT] Reading and Writing Footer" << std::endl;
            #endif
            *out++ = stripLine;
            *outEDM++ = stripLine;
            state = State::READ_EVENT_FOOTER_W2;
        }
        else if (state == State::READ_EVENT_FOOTER_W2) {
            #ifdef SW_EMU
                std::cout << "[INPUT] Reading and Writing Footer" << std::endl;
            #endif
            *out++ = stripLine;
            *outEDM++ = stripLine;
            state = State::READ_EVENT_FOOTER_W3;
        }
        else if (state == State::READ_EVENT_FOOTER_W3) {
            #ifdef SW_EMU
                std::cout << "[INPUT] Reading and Writing Footer" << std::endl;
            #endif
            *out++ = stripLine;
            *outEDM++ = stripLine;
            state = State::DECIDEONFLAG;
            // flushBuffers(outputStream, out, outEDMStream, outEDM);

        }
    }

    // **Final Flush at End of `read_input` to Ensure All Data is Output**
    // flushBuffers(outputStream, out, outEDMStream, outEDM);
}

extern "C" {
    void processHits(ap_uint<64>* in, ap_uint<64>* out, ap_uint<64>* outEDM, unsigned int vSize) {
        #pragma HLS INTERFACE m_axi port=in offset=slave bundle=gmem
        #pragma HLS INTERFACE m_axi port=out offset=slave bundle=gmem
        #pragma HLS INTERFACE m_axi port=outEDM offset=slave bundle=gmem
        #pragma HLS INTERFACE s_axilite port=in bundle=control
        #pragma HLS INTERFACE s_axilite port=out bundle=control
        #pragma HLS INTERFACE s_axilite port=outEDM bundle=control
        #pragma HLS INTERFACE s_axilite port=vSize bundle=control
        #pragma HLS INTERFACE s_axilite port=return bundle=control


        process_inputs(in, out, outEDM, vSize);
    }
}



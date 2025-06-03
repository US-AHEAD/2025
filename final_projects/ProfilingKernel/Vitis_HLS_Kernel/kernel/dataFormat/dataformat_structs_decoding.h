#ifndef _DATAFORMAT_STRUCTS_DECODING_H_
#define _DATAFORMAT_STRUCTS_DECODING_H_

#include <ap_int.h>

#include "dataformat_defines.h"
#include "dataformat_structs.h"

#define SELECTBITS(len, startbit) (len == 64 ? 0xFFFFFFFFFFFFFFFFULL : (((1ULL << len) - 1ULL) << startbit))

// helper function to read in word
void inline read_word(ap_uint<WORD_LENGTH> *buf, hls::stream<ap_uint<WORD_LENGTH>> &inStream, unsigned int *i)
{
#pragma HLS INLINE
	*buf = inStream.read();
	++*i;
}

evt_hdr inline decode_evt_hdr(hls::stream<ap_uint<WORD_LENGTH>> &inStream, unsigned int *i, ap_uint<WORD_LENGTH> &buf)
{
#pragma HLS INLINE
	evt_hdr temp;

	temp.flag = (buf & SELECTBITS(EVT_HDR_W1_FLAG_bits, EVT_HDR_W1_FLAG_lsb)) >> EVT_HDR_W1_FLAG_lsb;
	temp.l0id = (buf & SELECTBITS(EVT_HDR_W1_L0ID_bits, EVT_HDR_W1_L0ID_lsb)) >> EVT_HDR_W1_L0ID_lsb;
	temp.bcid = (buf & SELECTBITS(EVT_HDR_W1_BCID_bits, EVT_HDR_W1_BCID_lsb)) >> EVT_HDR_W1_BCID_lsb;

	read_word(&buf, inStream, i);
	temp.runnumber = (buf & SELECTBITS(EVT_HDR_W2_RUNNUMBER_bits, EVT_HDR_W2_RUNNUMBER_lsb)) >> EVT_HDR_W2_RUNNUMBER_lsb;
	temp.time = (buf & SELECTBITS(EVT_HDR_W2_TIME_bits, EVT_HDR_W2_TIME_lsb)) >> EVT_HDR_W2_TIME_lsb;

	read_word(&buf, inStream, i);
	temp.status = (buf & SELECTBITS(EVT_HDR_W3_STATUS_bits, EVT_HDR_W3_STATUS_lsb)) >> EVT_HDR_W3_STATUS_lsb;
	temp.crc = (buf & SELECTBITS(EVT_HDR_W3_CRC_bits, EVT_HDR_W3_CRC_lsb)) >> EVT_HDR_W3_CRC_lsb;

	return temp;
}

void inline encode_evt_hdr(hls::stream<ap_uint<WORD_LENGTH>> &outStream, const evt_hdr &temp)
{
#pragma HLS INLINE
	ap_uint<WORD_LENGTH> buf;

	ap_uint<EVT_HDR_W1_FLAG_bits> t101 = 0x0;
	t101 |= (ap_uint<EVT_HDR_W1_FLAG_bits>)(temp.flag);
	ap_uint<EVT_HDR_W1_FLAG_bits + EVT_HDR_W1_L0ID_bits> t102 = (t101, (ap_uint<EVT_HDR_W1_L0ID_bits>)(temp.l0id));
	ap_uint<EVT_HDR_W1_FLAG_bits + EVT_HDR_W1_L0ID_bits + EVT_HDR_W1_BCID_bits> t103 = (t102, (ap_uint<EVT_HDR_W1_BCID_bits>)(temp.bcid));
	buf = (t103, (ap_uint<EVT_HDR_W1_SPARE_bits>)(0x0));
	outStream << buf;
	ap_uint<EVT_HDR_W2_RUNNUMBER_bits> t201 = 0x0;
	t201 |= (ap_uint<EVT_HDR_W2_RUNNUMBER_bits>)(temp.runnumber);
	buf = (t201, (ap_uint<EVT_HDR_W2_TIME_bits>)(temp.time));
	outStream << buf;
	ap_uint<EVT_HDR_W3_STATUS_bits> t301 = 0x0;
	t301 |= (ap_uint<EVT_HDR_W3_STATUS_bits>)(temp.status);
	buf = (t301, (ap_uint<EVT_HDR_W3_CRC_bits>)(temp.crc));
	outStream << buf;
}

evt_ftr inline decode_evt_ftr(hls::stream<ap_uint<WORD_LENGTH>> &inStream, unsigned int *i, ap_uint<WORD_LENGTH> &buf)
{
#pragma HLS INLINE
	evt_ftr temp;

	temp.flag = (buf & SELECTBITS(EVT_FTR_W1_FLAG_bits, EVT_FTR_W1_FLAG_lsb)) >> EVT_FTR_W1_FLAG_lsb;
	temp.hdr_crc = (buf & SELECTBITS(EVT_FTR_W1_HDR_CRC_bits, EVT_FTR_W1_HDR_CRC_lsb)) >> EVT_FTR_W1_HDR_CRC_lsb;

	read_word(&buf, inStream, i);
	temp.error_flags = 0x0;
	temp.error_flags |= buf;

	read_word(&buf, inStream, i);
	temp.word_count = (buf & SELECTBITS(EVT_FTR_W3_WORD_COUNT_bits, EVT_FTR_W3_WORD_COUNT_lsb)) >> EVT_FTR_W3_WORD_COUNT_lsb;
	temp.crc = (buf & SELECTBITS(EVT_FTR_W3_CRC_bits, EVT_FTR_W3_CRC_lsb)) >> EVT_FTR_W3_CRC_lsb;

	return temp;
}

void inline encode_evt_ftr(hls::stream<ap_uint<WORD_LENGTH>> &outStream, const evt_ftr &temp)
{
#pragma HLS INLINE
	ap_uint<WORD_LENGTH> buf;

	ap_uint<EVT_FTR_W1_FLAG_bits> t101 = 0x0;
	t101 |= (ap_uint<EVT_FTR_W1_FLAG_bits>)(temp.flag);
	ap_uint<EVT_FTR_W1_FLAG_bits + EVT_FTR_W1_SPARE_bits> t102 = (t101, (ap_uint<EVT_FTR_W1_SPARE_bits>)(0x0));
	buf = (t102, (ap_uint<EVT_FTR_W1_HDR_CRC_bits>)(temp.hdr_crc));
	outStream << buf;
	buf = 0x0;
	buf |= (ap_uint<EVT_FTR_W2_ERROR_FLAGS_bits>)(temp.error_flags);
	outStream << buf;
	ap_uint<EVT_FTR_W3_WORD_COUNT_bits> t301 = 0x0;
	t301 |= (ap_uint<EVT_FTR_W3_WORD_COUNT_bits>)(temp.word_count);
	buf = (t301, (ap_uint<EVT_FTR_W3_CRC_bits>)(temp.crc));
	outStream << buf;
}

m_hdr inline decode_m_hdr(ap_uint<WORD_LENGTH> &buf)
{
#pragma HLS INLINE
	m_hdr temp;

	temp.flag = (buf & SELECTBITS(M_HDR_W1_FLAG_bits, M_HDR_W1_FLAG_lsb)) >> M_HDR_W1_FLAG_lsb;
	temp.modid = (buf & SELECTBITS(M_HDR_W1_MODID_bits, M_HDR_W1_MODID_lsb)) >> M_HDR_W1_MODID_lsb;
	temp.modhash = (buf & SELECTBITS(M_HDR_W1_MODHASH_bits, M_HDR_W1_MODHASH_lsb)) >> M_HDR_W1_MODHASH_lsb;

	return temp;
}

void inline encode_m_hdr(hls::stream<ap_uint<WORD_LENGTH>> &outStream, const m_hdr &temp)
{
#pragma HLS INLINE
	ap_uint<WORD_LENGTH> buf;

	ap_uint<M_HDR_W1_FLAG_bits> t101 = 0x0;
	t101 |= (ap_uint<M_HDR_W1_FLAG_bits>)(temp.flag);
	ap_uint<M_HDR_W1_FLAG_bits + M_HDR_W1_MODID_bits> t102 = (t101, (ap_uint<M_HDR_W1_MODID_bits>)(temp.modid));
	ap_uint<M_HDR_W1_FLAG_bits + M_HDR_W1_MODID_bits + M_HDR_W1_MODHASH_bits> t103 = (t102, (ap_uint<M_HDR_W1_MODHASH_bits>)(temp.modhash));
	buf = (t103, (ap_uint<M_HDR_W1_SPARE_bits>)(0x0));
	outStream << buf;
}


strip_cluster_64 inline decode_strip_cluster_64(ap_uint<WORD_LENGTH> &buf)
{
#pragma HLS INLINE
	strip_cluster_64 temp;

	temp.strip_cluster_1.last = (buf & SELECTBITS(STRIP_CLUSTER_LAST_bits, STRIP_CLUSTER_LAST_lsb)) >> (STRIP_CLUSTER_LAST_lsb + 32);
	temp.strip_cluster_1.row = (buf & SELECTBITS(STRIP_CLUSTER_ROW_bits, STRIP_CLUSTER_ROW_lsb)) >> (STRIP_CLUSTER_ROW_lsb + 32);
	temp.strip_cluster_1.nstrips = (buf & SELECTBITS(STRIP_CLUSTER_NSTRIPS_bits, STRIP_CLUSTER_NSTRIPS_lsb)) >> (STRIP_CLUSTER_NSTRIPS_lsb + 32);
	temp.strip_cluster_1.strip_index = (buf & SELECTBITS(STRIP_CLUSTER_STRIP_INDEX_bits, STRIP_CLUSTER_STRIP_INDEX_lsb)) >> (STRIP_CLUSTER_STRIP_INDEX_lsb + 32);
	temp.strip_cluster_2.last = (buf & SELECTBITS(STRIP_CLUSTER_LAST_bits, STRIP_CLUSTER_LAST_lsb)) >> STRIP_CLUSTER_LAST_lsb;
	temp.strip_cluster_2.row = (buf & SELECTBITS(STRIP_CLUSTER_ROW_bits, STRIP_CLUSTER_ROW_lsb)) >> STRIP_CLUSTER_ROW_lsb;
	temp.strip_cluster_2.nstrips = (buf & SELECTBITS(STRIP_CLUSTER_NSTRIPS_bits, STRIP_CLUSTER_NSTRIPS_lsb)) >> STRIP_CLUSTER_NSTRIPS_lsb;
	temp.strip_cluster_2.strip_index = (buf & SELECTBITS(STRIP_CLUSTER_STRIP_INDEX_bits, STRIP_CLUSTER_STRIP_INDEX_lsb)) >> STRIP_CLUSTER_STRIP_INDEX_lsb;

	return temp;
}

void inline encode_strip_cluster(hls::stream<ap_uint<WORD_LENGTH>> &outStream, const strip_cluster &temp)
{
#pragma HLS INLINE
	ap_uint<WORD_LENGTH> buf;

	ap_uint<STRIP_CLUSTER_LAST_bits> t1 = 0x0;
	t1 |= (ap_uint<STRIP_CLUSTER_LAST_bits>)(temp.last);
	ap_uint<STRIP_CLUSTER_LAST_bits + STRIP_CLUSTER_ROW_bits> t2 = (t1, (ap_uint<STRIP_CLUSTER_ROW_bits>)(temp.row));
	ap_uint<STRIP_CLUSTER_LAST_bits + STRIP_CLUSTER_ROW_bits + STRIP_CLUSTER_NSTRIPS_bits> t3 = (t2, (ap_uint<STRIP_CLUSTER_NSTRIPS_bits>)(temp.nstrips));
	ap_uint<STRIP_CLUSTER_LAST_bits + STRIP_CLUSTER_ROW_bits + STRIP_CLUSTER_NSTRIPS_bits + STRIP_CLUSTER_STRIP_INDEX_bits> t4 = (t3, (ap_uint<STRIP_CLUSTER_STRIP_INDEX_bits>)(temp.strip_index));
	buf = 0x0;
	buf |= (t4, (ap_uint<STRIP_CLUSTER_SPARE_bits>)(0x0)) << 32;

	t1 = 0x0;
	t1 |= (ap_uint<STRIP_CLUSTER_LAST_bits>)(temp.last);
	t2 = (t1, (ap_uint<STRIP_CLUSTER_ROW_bits>)(temp.row));
	t3 = (t2, (ap_uint<STRIP_CLUSTER_NSTRIPS_bits>)(temp.nstrips));
	t4 = (t3, (ap_uint<STRIP_CLUSTER_STRIP_INDEX_bits>)(temp.strip_index));
	buf |= (t4, (ap_uint<STRIP_CLUSTER_SPARE_bits>)(0x0));
	outStream << buf;
}
void inline encode_strip_cluster(ap_uint<32> &outBuf, const strip_cluster &temp)
{
#pragma HLS INLINE
	ap_uint<32> buf;

	ap_uint<STRIP_CLUSTER_LAST_bits> t1 = 0x0;
	t1 |= (ap_uint<STRIP_CLUSTER_LAST_bits>)(temp.last);
	ap_uint<STRIP_CLUSTER_LAST_bits + STRIP_CLUSTER_ROW_bits> t2 = (t1, (ap_uint<STRIP_CLUSTER_ROW_bits>)(temp.row));
	ap_uint<STRIP_CLUSTER_LAST_bits + STRIP_CLUSTER_ROW_bits + STRIP_CLUSTER_NSTRIPS_bits> t3 = (t2, (ap_uint<STRIP_CLUSTER_NSTRIPS_bits>)(temp.nstrips));
	ap_uint<STRIP_CLUSTER_LAST_bits + STRIP_CLUSTER_ROW_bits + STRIP_CLUSTER_NSTRIPS_bits + STRIP_CLUSTER_STRIP_INDEX_bits> t4 = (t3, (ap_uint<STRIP_CLUSTER_STRIP_INDEX_bits>)(temp.strip_index));
	buf = 0x0;
	buf |= (ap_uint<32>)(t4, (ap_uint<STRIP_CLUSTER_SPARE_bits>)(0x0));

	outBuf = buf;

}




edm_stripcluster inline decode_edm_stripcluster(hls::stream<ap_uint<WORD_LENGTH>> &inStream, unsigned int *i, ap_uint<WORD_LENGTH> &buf)
{
#pragma HLS INLINE
	edm_stripcluster temp;

	temp.flag = (buf & SELECTBITS(EDM_STRIPCLUSTER_W1_FLAG_bits, EDM_STRIPCLUSTER_W1_FLAG_lsb)) >> EDM_STRIPCLUSTER_W1_FLAG_lsb;
	temp.id_hash = (buf & SELECTBITS(EDM_STRIPCLUSTER_W1_ID_HASH_bits, EDM_STRIPCLUSTER_W1_ID_HASH_lsb)) >> EDM_STRIPCLUSTER_W1_ID_HASH_lsb;

	read_word(&buf, inStream, i);
	temp.rdo_list_w1 = 0x0;
	temp.rdo_list_w1 |= buf;

	read_word(&buf, inStream, i);
	temp.rdo_list_w2 = 0x0;
	temp.rdo_list_w2 |= buf;

	read_word(&buf, inStream, i);
	temp.rdo_list_w3 = 0x0;
	temp.rdo_list_w3 |= buf;

	read_word(&buf, inStream, i);
	temp.rdo_list_w4 = 0x0;
	temp.rdo_list_w4 |= buf;

	read_word(&buf, inStream, i);
	temp.localposition_x = ((ap_int<EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_bits>)((buf & SELECTBITS(EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_bits, EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_lsb)) >> EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_lsb)) / EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_mf;
	temp.localposition_y = ((ap_int<EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_bits>)((buf & SELECTBITS(EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_bits, EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_lsb)) >> EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_lsb)) / EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_mf;
	temp.localcovariance_xx = ((ap_uint<EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_bits>)((buf & SELECTBITS(EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_bits, EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_lsb)) >> EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_lsb)) / EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_mf;

	read_word(&buf, inStream, i);
	temp.globalposition_x = ((ap_int<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_bits>)((buf & SELECTBITS(EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_bits, EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_lsb)) >> EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_lsb)) / EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_mf;
	temp.globalposition_y = ((ap_int<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_bits>)((buf & SELECTBITS(EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_bits, EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_lsb)) >> EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_lsb)) / EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_mf;
	temp.channels_in_phi = (buf & SELECTBITS(EDM_STRIPCLUSTER_W7_CHANNELS_IN_PHI_bits, EDM_STRIPCLUSTER_W7_CHANNELS_IN_PHI_lsb)) >> EDM_STRIPCLUSTER_W7_CHANNELS_IN_PHI_lsb;

	read_word(&buf, inStream, i);
	temp.identifier = 0x0;
	temp.identifier |= buf;

	read_word(&buf, inStream, i);
	temp.globalposition_z = ((ap_int<EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_bits>)((buf & SELECTBITS(EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_bits, EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_lsb)) >> EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_lsb)) / EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_mf;
	temp.lastword = (buf & SELECTBITS(EDM_STRIPCLUSTER_W9_LASTWORD_bits, EDM_STRIPCLUSTER_W9_LASTWORD_lsb)) >> EDM_STRIPCLUSTER_W9_LASTWORD_lsb;
	temp.index = (buf & SELECTBITS(EDM_STRIPCLUSTER_W9_INDEX_bits, EDM_STRIPCLUSTER_W9_INDEX_lsb)) >> EDM_STRIPCLUSTER_W9_INDEX_lsb;

	return temp;
}

void inline encode_edm_stripcluster(hls::stream<ap_uint<WORD_LENGTH>> &outStream, const edm_stripcluster &temp)
{
#pragma HLS INLINE
	ap_uint<WORD_LENGTH> buf;

	ap_uint<EDM_STRIPCLUSTER_W1_FLAG_bits> t101 = 0x0;
	t101 |= (ap_uint<EDM_STRIPCLUSTER_W1_FLAG_bits>)(temp.flag);
	ap_uint<EDM_STRIPCLUSTER_W1_FLAG_bits + EDM_STRIPCLUSTER_W1_ID_HASH_bits> t102 = (t101, (ap_uint<EDM_STRIPCLUSTER_W1_ID_HASH_bits>)(temp.id_hash));
	buf = (t102, (ap_uint<EDM_STRIPCLUSTER_W1_SPARE_bits>)(0x0));
	outStream << buf;
	buf = 0x0;
	buf |= (ap_uint<EDM_STRIPCLUSTER_W2_RDO_LIST_W1_bits>)(temp.rdo_list_w1);
	outStream << buf;
	buf = 0x0;
	buf |= (ap_uint<EDM_STRIPCLUSTER_W3_RDO_LIST_W2_bits>)(temp.rdo_list_w2);
	outStream << buf;
	buf = 0x0;
	buf |= (ap_uint<EDM_STRIPCLUSTER_W4_RDO_LIST_W3_bits>)(temp.rdo_list_w3);
	outStream << buf;
	buf = 0x0;
	buf |= (ap_uint<EDM_STRIPCLUSTER_W5_RDO_LIST_W4_bits>)(temp.rdo_list_w4);
	outStream << buf;
	ap_uint<EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_bits> t601 = 0x0;
	t601 |= (ap_int<EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_bits>)(temp.localposition_x * (ap_ufixed<EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_apfix + 1,EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_apfix + 1>)EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_mf);
	ap_uint<EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_bits + EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_bits> t602 = (t601, (ap_int<EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_bits>)(temp.localposition_y * (ap_ufixed<EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_apfix + 1,EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_apfix + 1>)EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_mf));
	ap_uint<EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_bits + EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_bits + EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_bits> t603 = (t602, (ap_uint<EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_bits>)(temp.localcovariance_xx * (ap_ufixed<EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_apfix + 1,EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_apfix + 1>)EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_mf));
	buf = (t603, (ap_uint<EDM_STRIPCLUSTER_W6_SPARE_bits>)(0x0));
	outStream << buf;
	ap_uint<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_bits> t701 = 0x0;
	t701 |= (ap_int<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_bits>)(temp.globalposition_x * (ap_ufixed<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_apfix + 1,EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_apfix + 1>)EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_mf);
	ap_uint<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_bits + EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_bits> t702 = (t701, (ap_int<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_bits>)(temp.globalposition_y * (ap_ufixed<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_apfix + 1,EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_apfix + 1>)EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_mf));
	ap_uint<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_bits + EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_bits + EDM_STRIPCLUSTER_W7_CHANNELS_IN_PHI_bits> t703 = (t702, (ap_uint<EDM_STRIPCLUSTER_W7_CHANNELS_IN_PHI_bits>)(temp.channels_in_phi));
	buf = (t703, (ap_uint<EDM_STRIPCLUSTER_W7_SPARE_bits>)(0x0));
	outStream << buf;
	buf = 0x0;
	buf |= (ap_uint<EDM_STRIPCLUSTER_W8_IDENTIFIER_bits>)(temp.identifier);
	outStream << buf;
	ap_uint<EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_bits> t901 = 0x0;
	t901 |= (ap_int<EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_bits>)(temp.globalposition_z * (ap_ufixed<EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_apfix + 1,EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_apfix + 1>)EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_mf);
	ap_uint<EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_bits + EDM_STRIPCLUSTER_W9_LASTWORD_bits> t902 = (t901, (ap_uint<EDM_STRIPCLUSTER_W9_LASTWORD_bits>)(temp.lastword));
	ap_uint<EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_bits + EDM_STRIPCLUSTER_W9_LASTWORD_bits + EDM_STRIPCLUSTER_W9_INDEX_bits> t903 = (t902, (ap_uint<EDM_STRIPCLUSTER_W9_INDEX_bits>)(temp.index));
	buf = (t903, (ap_uint<EDM_STRIPCLUSTER_W9_SPARE_bits>)(0x0));
	outStream << buf;
}



void inline encode_edm_stripcluster(ap_uint<64>*& outEDM, const edm_stripcluster &temp)
{
#pragma HLS INLINE
	ap_uint<WORD_LENGTH> buf;

	ap_uint<EDM_STRIPCLUSTER_W1_FLAG_bits> t101 = 0x0;
	t101 |= (ap_uint<EDM_STRIPCLUSTER_W1_FLAG_bits>)(temp.flag);
	ap_uint<EDM_STRIPCLUSTER_W1_FLAG_bits + EDM_STRIPCLUSTER_W1_ID_HASH_bits> t102 = (t101, (ap_uint<EDM_STRIPCLUSTER_W1_ID_HASH_bits>)(temp.id_hash));
	buf = (t102, (ap_uint<EDM_STRIPCLUSTER_W1_SPARE_bits>)(0x0));
	*outEDM++ =  buf;
	buf = 0x0;
	buf |= (ap_uint<EDM_STRIPCLUSTER_W2_RDO_LIST_W1_bits>)(temp.rdo_list_w1);
	*outEDM++ =  buf;
	buf = 0x0;
	buf |= (ap_uint<EDM_STRIPCLUSTER_W3_RDO_LIST_W2_bits>)(temp.rdo_list_w2);
	*outEDM++ =  buf;
	buf = 0x0;
	buf |= (ap_uint<EDM_STRIPCLUSTER_W4_RDO_LIST_W3_bits>)(temp.rdo_list_w3);
	*outEDM++ =  buf;
	buf = 0x0;
	buf |= (ap_uint<EDM_STRIPCLUSTER_W5_RDO_LIST_W4_bits>)(temp.rdo_list_w4);
	*outEDM++ =  buf;
	ap_uint<EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_bits> t601 = 0x0;
	t601 |= (ap_int<EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_bits>)(temp.localposition_x * (ap_ufixed<EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_apfix + 1,EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_apfix + 1>)EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_mf);
	ap_uint<EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_bits + EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_bits> t602 = (t601, (ap_int<EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_bits>)(temp.localposition_y * (ap_ufixed<EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_apfix + 1,EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_apfix + 1>)EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_mf));
	ap_uint<EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_bits + EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_bits + EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_bits> t603 = (t602, (ap_uint<EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_bits>)(temp.localcovariance_xx * (ap_ufixed<EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_apfix + 1,EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_apfix + 1>)EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_mf));
	buf = (t603, (ap_uint<EDM_STRIPCLUSTER_W6_SPARE_bits>)(0x0));
	*outEDM++ =  buf;
	ap_uint<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_bits> t701 = 0x0;
	t701 |= (ap_int<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_bits>)(temp.globalposition_x * (ap_ufixed<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_apfix + 1,EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_apfix + 1>)EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_mf);
	ap_uint<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_bits + EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_bits> t702 = (t701, (ap_int<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_bits>)(temp.globalposition_y * (ap_ufixed<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_apfix + 1,EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_apfix + 1>)EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_mf));
	ap_uint<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_bits + EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_bits + EDM_STRIPCLUSTER_W7_CHANNELS_IN_PHI_bits> t703 = (t702, (ap_uint<EDM_STRIPCLUSTER_W7_CHANNELS_IN_PHI_bits>)(temp.channels_in_phi));
	buf = (t703, (ap_uint<EDM_STRIPCLUSTER_W7_SPARE_bits>)(0x0));
	*outEDM++ =  buf;
	buf = 0x0;
	buf |= (ap_uint<EDM_STRIPCLUSTER_W8_IDENTIFIER_bits>)(temp.identifier);
	*outEDM++ =  buf;
	ap_uint<EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_bits> t901 = 0x0;
	t901 |= (ap_int<EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_bits>)(temp.globalposition_z * (ap_ufixed<EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_apfix + 1,EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_apfix + 1>)EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_mf);
	ap_uint<EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_bits + EDM_STRIPCLUSTER_W9_LASTWORD_bits> t902 = (t901, (ap_uint<EDM_STRIPCLUSTER_W9_LASTWORD_bits>)(temp.lastword));
	ap_uint<EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_bits + EDM_STRIPCLUSTER_W9_LASTWORD_bits + EDM_STRIPCLUSTER_W9_INDEX_bits> t903 = (t902, (ap_uint<EDM_STRIPCLUSTER_W9_INDEX_bits>)(temp.index));
	buf = (t903, (ap_uint<EDM_STRIPCLUSTER_W9_SPARE_bits>)(0x0));
	*outEDM++ = buf;
}


strip_ef_rdo_64 inline decode_strip_ef_rdo_64(ap_uint<WORD_LENGTH> &buf)
{
#pragma HLS INLINE
	strip_ef_rdo_64 temp;

	temp.strip_ef_rdo_1.last = (buf & SELECTBITS(STRIP_EF_RDO_LAST_bits, STRIP_EF_RDO_LAST_lsb)) >> (STRIP_EF_RDO_LAST_lsb + 32);
	temp.strip_ef_rdo_1.chipid = (buf & SELECTBITS(STRIP_EF_RDO_CHIPID_bits, STRIP_EF_RDO_CHIPID_lsb)) >> (STRIP_EF_RDO_CHIPID_lsb + 32);
	temp.strip_ef_rdo_1.strip_num = (buf & SELECTBITS(STRIP_EF_RDO_STRIP_NUM_bits, STRIP_EF_RDO_STRIP_NUM_lsb)) >> (STRIP_EF_RDO_STRIP_NUM_lsb + 32);
	temp.strip_ef_rdo_1.cluster_map = (buf & SELECTBITS(STRIP_EF_RDO_CLUSTER_MAP_bits, STRIP_EF_RDO_CLUSTER_MAP_lsb)) >> (STRIP_EF_RDO_CLUSTER_MAP_lsb + 32);
	temp.strip_ef_rdo_2.last = (buf & SELECTBITS(STRIP_EF_RDO_LAST_bits, STRIP_EF_RDO_LAST_lsb)) >> STRIP_EF_RDO_LAST_lsb;
	temp.strip_ef_rdo_2.chipid = (buf & SELECTBITS(STRIP_EF_RDO_CHIPID_bits, STRIP_EF_RDO_CHIPID_lsb)) >> STRIP_EF_RDO_CHIPID_lsb;
	temp.strip_ef_rdo_2.strip_num = (buf & SELECTBITS(STRIP_EF_RDO_STRIP_NUM_bits, STRIP_EF_RDO_STRIP_NUM_lsb)) >> STRIP_EF_RDO_STRIP_NUM_lsb;
	temp.strip_ef_rdo_2.cluster_map = (buf & SELECTBITS(STRIP_EF_RDO_CLUSTER_MAP_bits, STRIP_EF_RDO_CLUSTER_MAP_lsb)) >> STRIP_EF_RDO_CLUSTER_MAP_lsb;

	return temp;
}

strip_ef_rdo inline decode_strip_ef_rdo(ap_uint<32> &buf)
{
#pragma HLS INLINE
	strip_ef_rdo temp;

	temp.last = (buf & SELECTBITS(STRIP_EF_RDO_LAST_bits, STRIP_EF_RDO_LAST_lsb)) >> STRIP_EF_RDO_LAST_lsb;
	temp.chipid = (buf & SELECTBITS(STRIP_EF_RDO_CHIPID_bits, STRIP_EF_RDO_CHIPID_lsb)) >> STRIP_EF_RDO_CHIPID_lsb;
	temp.strip_num = (buf & SELECTBITS(STRIP_EF_RDO_STRIP_NUM_bits, STRIP_EF_RDO_STRIP_NUM_lsb)) >> STRIP_EF_RDO_STRIP_NUM_lsb;
	temp.cluster_map = (buf & SELECTBITS(STRIP_EF_RDO_CLUSTER_MAP_bits, STRIP_EF_RDO_CLUSTER_MAP_lsb)) >> STRIP_EF_RDO_CLUSTER_MAP_lsb;

	return temp;
}


void inline encode_strip_ef_rdo(hls::stream<ap_uint<WORD_LENGTH>> &outStream, const strip_ef_rdo &temp)
{
#pragma HLS INLINE
	ap_uint<WORD_LENGTH> buf;

	ap_uint<STRIP_EF_RDO_LAST_bits> t1 = 0x0;
	t1 |= (ap_uint<STRIP_EF_RDO_LAST_bits>)(temp.last);
	ap_uint<STRIP_EF_RDO_LAST_bits + STRIP_EF_RDO_CHIPID_bits> t2 = (t1, (ap_uint<STRIP_EF_RDO_CHIPID_bits>)(temp.chipid));
	ap_uint<STRIP_EF_RDO_LAST_bits + STRIP_EF_RDO_CHIPID_bits + STRIP_EF_RDO_STRIP_NUM_bits> t3 = (t2, (ap_uint<STRIP_EF_RDO_STRIP_NUM_bits>)(temp.strip_num));
	ap_uint<STRIP_EF_RDO_LAST_bits + STRIP_EF_RDO_CHIPID_bits + STRIP_EF_RDO_STRIP_NUM_bits + STRIP_EF_RDO_CLUSTER_MAP_bits> t4 = (t3, (ap_uint<STRIP_EF_RDO_CLUSTER_MAP_bits>)(temp.cluster_map));
	buf = 0x0;
	buf |= (t4, (ap_uint<STRIP_EF_RDO_SPARE_bits>)(0x0)) << 32;

	t1 = 0x0;
	t1 |= (ap_uint<STRIP_EF_RDO_LAST_bits>)(temp.last);
	t2 = (t1, (ap_uint<STRIP_EF_RDO_CHIPID_bits>)(temp.chipid));
	t3 = (t2, (ap_uint<STRIP_EF_RDO_STRIP_NUM_bits>)(temp.strip_num));
	t4 = (t3, (ap_uint<STRIP_EF_RDO_CLUSTER_MAP_bits>)(temp.cluster_map));
	buf |= (t4, (ap_uint<STRIP_EF_RDO_SPARE_bits>)(0x0));
	outStream << buf;
}


#endif // _DATAFORMAT_STRUCTS_DECODING_H_
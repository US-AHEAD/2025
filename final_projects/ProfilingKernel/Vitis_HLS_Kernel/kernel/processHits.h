#ifndef PROCESS_HITS_H
#define PROCESS_HITS_H

#define HEADER_SIZE 3    // Header lines (3x 64-bit)
#define FOOTER_SIZE 3    // Footer lines (3x 64-bit)

constexpr unsigned int FLUSH_THRESHOLD = 32; 
 
constexpr int MAX_CHIP_PER_MODULE = 15;
constexpr int MAX_STRIPS_PER_CHIP = 128;
constexpr int MAX_STRIPS_PER_MODULE = MAX_STRIPS_PER_CHIP * MAX_CHIP_PER_MODULE;

#define AP_INT_MAX_W MAX_STRIPS_PER_MODULE

#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include "dataformat_structs_decoding.h"
#include "dataformat_defines.h"

using flush_cnt_t = ap_uint<6>;

typedef struct strip_cluster_local {
	ap_uint<1> isLastofEvent;
	ap_uint<STRIP_CLUSTER_LAST_bits> last;
	ap_uint<STRIP_CLUSTER_ROW_bits> row;
	ap_uint<STRIP_CLUSTER_NSTRIPS_bits> nstrips;
	ap_uint<STRIP_CLUSTER_STRIP_INDEX_bits> strip_index;
} strip_cluster_local;


// Function declarations
extern "C" {
    void processHits(ap_uint<64>* in, ap_uint<64>* out, ap_uint<64>* outEDM, unsigned int vSize);
}


// Function for reading input data from global memory
static void process_inputs(ap_uint<64>* in, ap_uint<64>* out, ap_uint<64>* outEDM, unsigned int vSize);


// For reading
namespace {
    enum State {
        DECIDEONFLAG,
        READ_EVENT_HEADER_W1,
        READ_EVENT_HEADER_W2,
        READ_EVENT_HEADER_W3,
        READ_MODULE_HEADER,
        READ_MODULE_BLOCK,
        READ_EVENT_FOOTER_W1,
        READ_EVENT_FOOTER_W2,
        READ_EVENT_FOOTER_W3,

    };
}

// Buffer structure to hold data from module, with rows of HCC
struct ModuleRowData
{
    // One bit per strip (1920 bits total) rather than a RAM array
    ap_uint<MAX_STRIPS_PER_MODULE> row;

    bool rowHasHits;
    ap_uint<STRIP_CLUSTER_STRIP_INDEX_bits> firstStrip;
    ap_uint<STRIP_CLUSTER_STRIP_INDEX_bits> lastStrip;

    // Default-construct to a clean state
    ModuleRowData()
        : row(0),
          rowHasHits(false),
          firstStrip(MAX_STRIPS_PER_MODULE),
          lastStrip(0) {}
};

#endif // PROCESS_HITS_H

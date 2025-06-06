#ifndef _DATAFORMAT_STRUCTS_H_
#define _DATAFORMAT_STRUCTS_H_

#include <ap_int.h>
#include <ap_fixed.h>

#include "dataformat_defines.h"


typedef struct evt_hdr {
	// EVT_HDR_W1
	ap_uint<EVT_HDR_W1_FLAG_bits> flag;
	ap_uint<EVT_HDR_W1_L0ID_bits> l0id;
	ap_uint<EVT_HDR_W1_BCID_bits> bcid;

	// EVT_HDR_W2
	ap_uint<EVT_HDR_W2_RUNNUMBER_bits> runnumber;
	ap_uint<EVT_HDR_W2_TIME_bits> time;

	// EVT_HDR_W3
	ap_uint<EVT_HDR_W3_STATUS_bits> status;
	ap_uint<EVT_HDR_W3_CRC_bits> crc;
} evt_hdr;

typedef struct evt_ftr {
	// EVT_FTR_W1
	ap_uint<EVT_FTR_W1_FLAG_bits> flag;
	ap_uint<EVT_FTR_W1_HDR_CRC_bits> hdr_crc;

	// EVT_FTR_W2
	ap_uint<EVT_FTR_W2_ERROR_FLAGS_bits> error_flags;

	// EVT_FTR_W3
	ap_uint<EVT_FTR_W3_WORD_COUNT_bits> word_count;
	ap_uint<EVT_FTR_W3_CRC_bits> crc;
} evt_ftr;

typedef struct m_hdr {
	// M_HDR_W1
	ap_uint<M_HDR_W1_FLAG_bits> flag;
	ap_uint<M_HDR_W1_MODID_bits> modid;
	ap_uint<M_HDR_W1_MODHASH_bits> modhash;
} m_hdr;


typedef struct strip_cluster {
	ap_uint<STRIP_CLUSTER_LAST_bits> last;
	ap_uint<STRIP_CLUSTER_ROW_bits> row;
	ap_uint<STRIP_CLUSTER_NSTRIPS_bits> nstrips;
	ap_uint<STRIP_CLUSTER_STRIP_INDEX_bits> strip_index;
} strip_cluster;

typedef struct strip_cluster_64 {
	strip_cluster strip_cluster_1;
	strip_cluster strip_cluster_2;
} strip_cluster_64;

typedef struct edm_stripcluster {
	// EDM_STRIPCLUSTER_W1
	ap_uint<EDM_STRIPCLUSTER_W1_FLAG_bits> flag;
	ap_uint<EDM_STRIPCLUSTER_W1_ID_HASH_bits> id_hash;

	// EDM_STRIPCLUSTER_W2
	ap_uint<EDM_STRIPCLUSTER_W2_RDO_LIST_W1_bits> rdo_list_w1;

	// EDM_STRIPCLUSTER_W3
	ap_uint<EDM_STRIPCLUSTER_W3_RDO_LIST_W2_bits> rdo_list_w2;

	// EDM_STRIPCLUSTER_W4
	ap_uint<EDM_STRIPCLUSTER_W4_RDO_LIST_W3_bits> rdo_list_w3;

	// EDM_STRIPCLUSTER_W5
	ap_uint<EDM_STRIPCLUSTER_W5_RDO_LIST_W4_bits> rdo_list_w4;

	// EDM_STRIPCLUSTER_W6
	ap_fixed<EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_bits, EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_decb> localposition_x;
	ap_fixed<EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_bits, EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_decb> localposition_y;
	ap_ufixed<EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_bits, EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_decb> localcovariance_xx;

	// EDM_STRIPCLUSTER_W7
	ap_fixed<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_bits, EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_decb> globalposition_x;
	ap_fixed<EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_bits, EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_decb> globalposition_y;
	ap_uint<EDM_STRIPCLUSTER_W7_CHANNELS_IN_PHI_bits> channels_in_phi;

	// EDM_STRIPCLUSTER_W8
	ap_uint<EDM_STRIPCLUSTER_W8_IDENTIFIER_bits> identifier;

	// EDM_STRIPCLUSTER_W9
	ap_fixed<EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_bits, EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_decb> globalposition_z;
	ap_uint<EDM_STRIPCLUSTER_W9_LASTWORD_bits> lastword;
	ap_uint<EDM_STRIPCLUSTER_W9_INDEX_bits> index;
} edm_stripcluster;


typedef struct strip_ef_rdo {
	ap_uint<STRIP_EF_RDO_LAST_bits> last;
	ap_uint<STRIP_EF_RDO_CHIPID_bits> chipid;
	ap_uint<STRIP_EF_RDO_STRIP_NUM_bits> strip_num;
	ap_uint<STRIP_EF_RDO_CLUSTER_MAP_bits> cluster_map;
} strip_ef_rdo;

typedef struct strip_ef_rdo_64 {
	strip_ef_rdo strip_ef_rdo_1;
	strip_ef_rdo strip_ef_rdo_2;
} strip_ef_rdo_64;


#endif // _DATAFORMAT_STRUCTS_H_
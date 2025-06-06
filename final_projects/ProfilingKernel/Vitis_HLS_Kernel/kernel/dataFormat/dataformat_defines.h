#ifndef _DATAFORMAT_DEFINES_H_
#define _DATAFORMAT_DEFINES_H_

#define WORD_LENGTH 64

#define EVT_HDR_LWORDS                 3

// EVT_HDR defined flags
#define EVT_HDR_FLAG                   0xab

// EVT_HDR_W1 word description
#define EVT_HDR_W1_bits                64
#define EVT_HDR_W1_FLAG_bits           8
#define EVT_HDR_W1_FLAG_msb            63
#define EVT_HDR_W1_FLAG_lsb            56
#define EVT_HDR_W1_FLAG_mf             1.
#define EVT_HDR_W1_FLAG_s2c            0
#define EVT_HDR_W1_FLAG_decb           8
#define EVT_HDR_W1_FLAG_apfix          0

#define EVT_HDR_W1_L0ID_bits           40
#define EVT_HDR_W1_L0ID_msb            55
#define EVT_HDR_W1_L0ID_lsb            16
#define EVT_HDR_W1_L0ID_mf             1.
#define EVT_HDR_W1_L0ID_s2c            0
#define EVT_HDR_W1_L0ID_decb           40
#define EVT_HDR_W1_L0ID_apfix          0

#define EVT_HDR_W1_BCID_bits           12
#define EVT_HDR_W1_BCID_msb            15
#define EVT_HDR_W1_BCID_lsb            4
#define EVT_HDR_W1_BCID_mf             1.
#define EVT_HDR_W1_BCID_s2c            0
#define EVT_HDR_W1_BCID_decb           12
#define EVT_HDR_W1_BCID_apfix          0

#define EVT_HDR_W1_SPARE_bits          4
#define EVT_HDR_W1_SPARE_msb           3
#define EVT_HDR_W1_SPARE_lsb           0
#define EVT_HDR_W1_SPARE_mf            1.
#define EVT_HDR_W1_SPARE_s2c           0
#define EVT_HDR_W1_SPARE_decb          4
#define EVT_HDR_W1_SPARE_apfix         0

// EVT_HDR_W2 word description
#define EVT_HDR_W2_bits                64
#define EVT_HDR_W2_RUNNUMBER_bits      32
#define EVT_HDR_W2_RUNNUMBER_msb       63
#define EVT_HDR_W2_RUNNUMBER_lsb       32
#define EVT_HDR_W2_RUNNUMBER_mf        1.
#define EVT_HDR_W2_RUNNUMBER_s2c       0
#define EVT_HDR_W2_RUNNUMBER_decb      32
#define EVT_HDR_W2_RUNNUMBER_apfix     0

#define EVT_HDR_W2_TIME_bits           32
#define EVT_HDR_W2_TIME_msb            31
#define EVT_HDR_W2_TIME_lsb            0
#define EVT_HDR_W2_TIME_mf             1.
#define EVT_HDR_W2_TIME_s2c            0
#define EVT_HDR_W2_TIME_decb           32
#define EVT_HDR_W2_TIME_apfix          0

// EVT_HDR_W3 word description
#define EVT_HDR_W3_bits                64
#define EVT_HDR_W3_STATUS_bits         32
#define EVT_HDR_W3_STATUS_msb          63
#define EVT_HDR_W3_STATUS_lsb          32
#define EVT_HDR_W3_STATUS_mf           1.
#define EVT_HDR_W3_STATUS_s2c          0
#define EVT_HDR_W3_STATUS_decb         32
#define EVT_HDR_W3_STATUS_apfix        0

#define EVT_HDR_W3_CRC_bits            32
#define EVT_HDR_W3_CRC_msb             31
#define EVT_HDR_W3_CRC_lsb             0
#define EVT_HDR_W3_CRC_mf              1.
#define EVT_HDR_W3_CRC_s2c             0
#define EVT_HDR_W3_CRC_decb            32
#define EVT_HDR_W3_CRC_apfix           0

#define EVT_FTR_LWORDS                 3

// EVT_FTR defined flags
#define EVT_FTR_FLAG                   0xcd

// EVT_FTR_W1 word description
#define EVT_FTR_W1_bits                64
#define EVT_FTR_W1_FLAG_bits           8
#define EVT_FTR_W1_FLAG_msb            63
#define EVT_FTR_W1_FLAG_lsb            56
#define EVT_FTR_W1_FLAG_mf             1.
#define EVT_FTR_W1_FLAG_s2c            0
#define EVT_FTR_W1_FLAG_decb           8
#define EVT_FTR_W1_FLAG_apfix          0

#define EVT_FTR_W1_SPARE_bits          24
#define EVT_FTR_W1_SPARE_msb           55
#define EVT_FTR_W1_SPARE_lsb           32
#define EVT_FTR_W1_SPARE_mf            1.
#define EVT_FTR_W1_SPARE_s2c           0
#define EVT_FTR_W1_SPARE_decb          24
#define EVT_FTR_W1_SPARE_apfix         0

#define EVT_FTR_W1_HDR_CRC_bits        32
#define EVT_FTR_W1_HDR_CRC_msb         31
#define EVT_FTR_W1_HDR_CRC_lsb         0
#define EVT_FTR_W1_HDR_CRC_mf          1.
#define EVT_FTR_W1_HDR_CRC_s2c         0
#define EVT_FTR_W1_HDR_CRC_decb        32
#define EVT_FTR_W1_HDR_CRC_apfix       0

// EVT_FTR_W2 word description
#define EVT_FTR_W2_bits                64
#define EVT_FTR_W2_ERROR_FLAGS_bits    64
#define EVT_FTR_W2_ERROR_FLAGS_msb     63
#define EVT_FTR_W2_ERROR_FLAGS_lsb     0
#define EVT_FTR_W2_ERROR_FLAGS_mf      1.
#define EVT_FTR_W2_ERROR_FLAGS_s2c     0
#define EVT_FTR_W2_ERROR_FLAGS_decb    64
#define EVT_FTR_W2_ERROR_FLAGS_apfix   0

// EVT_FTR_W3 word description
#define EVT_FTR_W3_bits                64
#define EVT_FTR_W3_WORD_COUNT_bits     32
#define EVT_FTR_W3_WORD_COUNT_msb      63
#define EVT_FTR_W3_WORD_COUNT_lsb      32
#define EVT_FTR_W3_WORD_COUNT_mf       1.
#define EVT_FTR_W3_WORD_COUNT_s2c      0
#define EVT_FTR_W3_WORD_COUNT_decb     32
#define EVT_FTR_W3_WORD_COUNT_apfix    0

#define EVT_FTR_W3_CRC_bits            32
#define EVT_FTR_W3_CRC_msb             31
#define EVT_FTR_W3_CRC_lsb             0
#define EVT_FTR_W3_CRC_mf              1.
#define EVT_FTR_W3_CRC_s2c             0
#define EVT_FTR_W3_CRC_decb            32
#define EVT_FTR_W3_CRC_apfix           0

#define M_HDR_LWORDS                   1

// M_HDR defined flags
#define M_HDR_FLAG                     0x55

// M_HDR_W1 word description
#define M_HDR_W1_bits                  64
#define M_HDR_W1_FLAG_bits             8
#define M_HDR_W1_FLAG_msb              63
#define M_HDR_W1_FLAG_lsb              56
#define M_HDR_W1_FLAG_mf               1.
#define M_HDR_W1_FLAG_s2c              0
#define M_HDR_W1_FLAG_decb             8
#define M_HDR_W1_FLAG_apfix            0

#define M_HDR_W1_MODID_bits            32
#define M_HDR_W1_MODID_msb             55
#define M_HDR_W1_MODID_lsb             24
#define M_HDR_W1_MODID_mf              1.
#define M_HDR_W1_MODID_s2c             0
#define M_HDR_W1_MODID_decb            32
#define M_HDR_W1_MODID_apfix           0

#define M_HDR_W1_MODHASH_bits          16
#define M_HDR_W1_MODHASH_msb           23
#define M_HDR_W1_MODHASH_lsb           8
#define M_HDR_W1_MODHASH_mf            1.
#define M_HDR_W1_MODHASH_s2c           0
#define M_HDR_W1_MODHASH_decb          16
#define M_HDR_W1_MODHASH_apfix         0

#define M_HDR_W1_SPARE_bits            8
#define M_HDR_W1_SPARE_msb             7
#define M_HDR_W1_SPARE_lsb             0
#define M_HDR_W1_SPARE_mf              1.
#define M_HDR_W1_SPARE_s2c             0
#define M_HDR_W1_SPARE_decb            8
#define M_HDR_W1_SPARE_apfix           0

// STRIP_CLUSTER word description
#define STRIP_CLUSTER_bits             32
#define STRIP_CLUSTER_LAST_bits        1
#define STRIP_CLUSTER_LAST_msb         31
#define STRIP_CLUSTER_LAST_lsb         31
#define STRIP_CLUSTER_LAST_mf          1.
#define STRIP_CLUSTER_LAST_s2c         0
#define STRIP_CLUSTER_LAST_decb        1
#define STRIP_CLUSTER_LAST_apfix       0

#define STRIP_CLUSTER_ROW_bits         1
#define STRIP_CLUSTER_ROW_msb          30
#define STRIP_CLUSTER_ROW_lsb          30
#define STRIP_CLUSTER_ROW_mf           1.
#define STRIP_CLUSTER_ROW_s2c          0
#define STRIP_CLUSTER_ROW_decb         1
#define STRIP_CLUSTER_ROW_apfix        0

#define STRIP_CLUSTER_NSTRIPS_bits     8
#define STRIP_CLUSTER_NSTRIPS_msb      29
#define STRIP_CLUSTER_NSTRIPS_lsb      22
#define STRIP_CLUSTER_NSTRIPS_mf       1.
#define STRIP_CLUSTER_NSTRIPS_s2c      0
#define STRIP_CLUSTER_NSTRIPS_decb     8
#define STRIP_CLUSTER_NSTRIPS_apfix    0

#define STRIP_CLUSTER_STRIP_INDEX_bits 12
#define STRIP_CLUSTER_STRIP_INDEX_msb  21
#define STRIP_CLUSTER_STRIP_INDEX_lsb  10
#define STRIP_CLUSTER_STRIP_INDEX_mf   1.
#define STRIP_CLUSTER_STRIP_INDEX_s2c  0
#define STRIP_CLUSTER_STRIP_INDEX_decb 12
#define STRIP_CLUSTER_STRIP_INDEX_apfix 0

#define STRIP_CLUSTER_SPARE_bits       10
#define STRIP_CLUSTER_SPARE_msb        9
#define STRIP_CLUSTER_SPARE_lsb        0
#define STRIP_CLUSTER_SPARE_mf         1.
#define STRIP_CLUSTER_SPARE_s2c        0
#define STRIP_CLUSTER_SPARE_decb       10
#define STRIP_CLUSTER_SPARE_apfix      0

#define EDM_STRIPCLUSTER_LWORDS        9

// EDM_STRIPCLUSTER defined flags
#define EDM_STRIPCLUSTER_FLAG          0x66

// EDM_STRIPCLUSTER_W1 word description
#define EDM_STRIPCLUSTER_W1_bits       64
#define EDM_STRIPCLUSTER_W1_FLAG_bits  8
#define EDM_STRIPCLUSTER_W1_FLAG_msb   63
#define EDM_STRIPCLUSTER_W1_FLAG_lsb   56
#define EDM_STRIPCLUSTER_W1_FLAG_mf    1.
#define EDM_STRIPCLUSTER_W1_FLAG_s2c   0
#define EDM_STRIPCLUSTER_W1_FLAG_decb  8
#define EDM_STRIPCLUSTER_W1_FLAG_apfix 0

#define EDM_STRIPCLUSTER_W1_ID_HASH_bits 32
#define EDM_STRIPCLUSTER_W1_ID_HASH_msb 55
#define EDM_STRIPCLUSTER_W1_ID_HASH_lsb 24
#define EDM_STRIPCLUSTER_W1_ID_HASH_mf 1.
#define EDM_STRIPCLUSTER_W1_ID_HASH_s2c 0
#define EDM_STRIPCLUSTER_W1_ID_HASH_decb 32
#define EDM_STRIPCLUSTER_W1_ID_HASH_apfix 0

#define EDM_STRIPCLUSTER_W1_SPARE_bits 24
#define EDM_STRIPCLUSTER_W1_SPARE_msb  23
#define EDM_STRIPCLUSTER_W1_SPARE_lsb  0
#define EDM_STRIPCLUSTER_W1_SPARE_mf   1.
#define EDM_STRIPCLUSTER_W1_SPARE_s2c  0
#define EDM_STRIPCLUSTER_W1_SPARE_decb 24
#define EDM_STRIPCLUSTER_W1_SPARE_apfix 0

// EDM_STRIPCLUSTER_W2 word description
#define EDM_STRIPCLUSTER_W2_bits       64
#define EDM_STRIPCLUSTER_W2_RDO_LIST_W1_bits 64
#define EDM_STRIPCLUSTER_W2_RDO_LIST_W1_msb 63
#define EDM_STRIPCLUSTER_W2_RDO_LIST_W1_lsb 0
#define EDM_STRIPCLUSTER_W2_RDO_LIST_W1_mf 1.
#define EDM_STRIPCLUSTER_W2_RDO_LIST_W1_s2c 0
#define EDM_STRIPCLUSTER_W2_RDO_LIST_W1_decb 64
#define EDM_STRIPCLUSTER_W2_RDO_LIST_W1_apfix 0

// EDM_STRIPCLUSTER_W3 word description
#define EDM_STRIPCLUSTER_W3_bits       64
#define EDM_STRIPCLUSTER_W3_RDO_LIST_W2_bits 64
#define EDM_STRIPCLUSTER_W3_RDO_LIST_W2_msb 63
#define EDM_STRIPCLUSTER_W3_RDO_LIST_W2_lsb 0
#define EDM_STRIPCLUSTER_W3_RDO_LIST_W2_mf 1.
#define EDM_STRIPCLUSTER_W3_RDO_LIST_W2_s2c 0
#define EDM_STRIPCLUSTER_W3_RDO_LIST_W2_decb 64
#define EDM_STRIPCLUSTER_W3_RDO_LIST_W2_apfix 0

// EDM_STRIPCLUSTER_W4 word description
#define EDM_STRIPCLUSTER_W4_bits       64
#define EDM_STRIPCLUSTER_W4_RDO_LIST_W3_bits 64
#define EDM_STRIPCLUSTER_W4_RDO_LIST_W3_msb 63
#define EDM_STRIPCLUSTER_W4_RDO_LIST_W3_lsb 0
#define EDM_STRIPCLUSTER_W4_RDO_LIST_W3_mf 1.
#define EDM_STRIPCLUSTER_W4_RDO_LIST_W3_s2c 0
#define EDM_STRIPCLUSTER_W4_RDO_LIST_W3_decb 64
#define EDM_STRIPCLUSTER_W4_RDO_LIST_W3_apfix 0

// EDM_STRIPCLUSTER_W5 word description
#define EDM_STRIPCLUSTER_W5_bits       64
#define EDM_STRIPCLUSTER_W5_RDO_LIST_W4_bits 64
#define EDM_STRIPCLUSTER_W5_RDO_LIST_W4_msb 63
#define EDM_STRIPCLUSTER_W5_RDO_LIST_W4_lsb 0
#define EDM_STRIPCLUSTER_W5_RDO_LIST_W4_mf 1.
#define EDM_STRIPCLUSTER_W5_RDO_LIST_W4_s2c 0
#define EDM_STRIPCLUSTER_W5_RDO_LIST_W4_decb 64
#define EDM_STRIPCLUSTER_W5_RDO_LIST_W4_apfix 0

// EDM_STRIPCLUSTER_W6 word description
#define EDM_STRIPCLUSTER_W6_bits       64
#define EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_bits 21
#define EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_msb 63
#define EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_lsb 43
#define EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_mf 8192.
#define EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_s2c 1
#define EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_decb 8
#define EDM_STRIPCLUSTER_W6_LOCALPOSITION_X_apfix 13

#define EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_bits 21
#define EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_msb 42
#define EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_lsb 22
#define EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_mf 8192.
#define EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_s2c 1
#define EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_decb 8
#define EDM_STRIPCLUSTER_W6_LOCALPOSITION_Y_apfix 13

#define EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_bits 20
#define EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_msb 21
#define EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_lsb 2
#define EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_mf 524288.
#define EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_s2c 0
#define EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_decb 1
#define EDM_STRIPCLUSTER_W6_LOCALCOVARIANCE_XX_apfix 19

#define EDM_STRIPCLUSTER_W6_SPARE_bits 2
#define EDM_STRIPCLUSTER_W6_SPARE_msb  1
#define EDM_STRIPCLUSTER_W6_SPARE_lsb  0
#define EDM_STRIPCLUSTER_W6_SPARE_mf   1.
#define EDM_STRIPCLUSTER_W6_SPARE_s2c  0
#define EDM_STRIPCLUSTER_W6_SPARE_decb 2
#define EDM_STRIPCLUSTER_W6_SPARE_apfix 0

// EDM_STRIPCLUSTER_W7 word description
#define EDM_STRIPCLUSTER_W7_bits       64
#define EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_bits 27
#define EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_msb 63
#define EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_lsb 37
#define EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_mf 65536.
#define EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_s2c 1
#define EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_decb 11
#define EDM_STRIPCLUSTER_W7_GLOBALPOSITION_X_apfix 16

#define EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_bits 27
#define EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_msb 36
#define EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_lsb 10
#define EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_mf 65536.
#define EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_s2c 1
#define EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_decb 11
#define EDM_STRIPCLUSTER_W7_GLOBALPOSITION_Y_apfix 16

#define EDM_STRIPCLUSTER_W7_CHANNELS_IN_PHI_bits 6
#define EDM_STRIPCLUSTER_W7_CHANNELS_IN_PHI_msb 9
#define EDM_STRIPCLUSTER_W7_CHANNELS_IN_PHI_lsb 4
#define EDM_STRIPCLUSTER_W7_CHANNELS_IN_PHI_mf 1.
#define EDM_STRIPCLUSTER_W7_CHANNELS_IN_PHI_s2c 0
#define EDM_STRIPCLUSTER_W7_CHANNELS_IN_PHI_decb 6
#define EDM_STRIPCLUSTER_W7_CHANNELS_IN_PHI_apfix 0

#define EDM_STRIPCLUSTER_W7_SPARE_bits 4
#define EDM_STRIPCLUSTER_W7_SPARE_msb  3
#define EDM_STRIPCLUSTER_W7_SPARE_lsb  0
#define EDM_STRIPCLUSTER_W7_SPARE_mf   1.
#define EDM_STRIPCLUSTER_W7_SPARE_s2c  0
#define EDM_STRIPCLUSTER_W7_SPARE_decb 4
#define EDM_STRIPCLUSTER_W7_SPARE_apfix 0

// EDM_STRIPCLUSTER_W8 word description
#define EDM_STRIPCLUSTER_W8_bits       64
#define EDM_STRIPCLUSTER_W8_IDENTIFIER_bits 64
#define EDM_STRIPCLUSTER_W8_IDENTIFIER_msb 63
#define EDM_STRIPCLUSTER_W8_IDENTIFIER_lsb 0
#define EDM_STRIPCLUSTER_W8_IDENTIFIER_mf 1.
#define EDM_STRIPCLUSTER_W8_IDENTIFIER_s2c 0
#define EDM_STRIPCLUSTER_W8_IDENTIFIER_decb 64
#define EDM_STRIPCLUSTER_W8_IDENTIFIER_apfix 0

// EDM_STRIPCLUSTER_W9 word description
#define EDM_STRIPCLUSTER_W9_bits       64
#define EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_bits 29
#define EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_msb 63
#define EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_lsb 35
#define EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_mf 65536.
#define EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_s2c 1
#define EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_decb 13
#define EDM_STRIPCLUSTER_W9_GLOBALPOSITION_Z_apfix 16

#define EDM_STRIPCLUSTER_W9_LASTWORD_bits 1
#define EDM_STRIPCLUSTER_W9_LASTWORD_msb 34
#define EDM_STRIPCLUSTER_W9_LASTWORD_lsb 34
#define EDM_STRIPCLUSTER_W9_LASTWORD_mf 1.
#define EDM_STRIPCLUSTER_W9_LASTWORD_s2c 0
#define EDM_STRIPCLUSTER_W9_LASTWORD_decb 1
#define EDM_STRIPCLUSTER_W9_LASTWORD_apfix 0

#define EDM_STRIPCLUSTER_W9_INDEX_bits 32
#define EDM_STRIPCLUSTER_W9_INDEX_msb  33
#define EDM_STRIPCLUSTER_W9_INDEX_lsb  2
#define EDM_STRIPCLUSTER_W9_INDEX_mf   1.
#define EDM_STRIPCLUSTER_W9_INDEX_s2c  0
#define EDM_STRIPCLUSTER_W9_INDEX_decb 32
#define EDM_STRIPCLUSTER_W9_INDEX_apfix 0

#define EDM_STRIPCLUSTER_W9_SPARE_bits 2
#define EDM_STRIPCLUSTER_W9_SPARE_msb  1
#define EDM_STRIPCLUSTER_W9_SPARE_lsb  0
#define EDM_STRIPCLUSTER_W9_SPARE_mf   1.
#define EDM_STRIPCLUSTER_W9_SPARE_s2c  0
#define EDM_STRIPCLUSTER_W9_SPARE_decb 2
#define EDM_STRIPCLUSTER_W9_SPARE_apfix 0


// STRIP_EF_RDO word description
#define STRIP_EF_RDO_bits              32
#define STRIP_EF_RDO_LAST_bits         1
#define STRIP_EF_RDO_LAST_msb          31
#define STRIP_EF_RDO_LAST_lsb          31
#define STRIP_EF_RDO_LAST_mf           1.
#define STRIP_EF_RDO_LAST_s2c          0
#define STRIP_EF_RDO_LAST_decb         1
#define STRIP_EF_RDO_LAST_apfix        0

#define STRIP_EF_RDO_CHIPID_bits       4
#define STRIP_EF_RDO_CHIPID_msb        30
#define STRIP_EF_RDO_CHIPID_lsb        27
#define STRIP_EF_RDO_CHIPID_mf         1.
#define STRIP_EF_RDO_CHIPID_s2c        0
#define STRIP_EF_RDO_CHIPID_decb       4
#define STRIP_EF_RDO_CHIPID_apfix      0

#define STRIP_EF_RDO_STRIP_NUM_bits    8
#define STRIP_EF_RDO_STRIP_NUM_msb     26
#define STRIP_EF_RDO_STRIP_NUM_lsb     19
#define STRIP_EF_RDO_STRIP_NUM_mf      1.
#define STRIP_EF_RDO_STRIP_NUM_s2c     0
#define STRIP_EF_RDO_STRIP_NUM_decb    8
#define STRIP_EF_RDO_STRIP_NUM_apfix   0

#define STRIP_EF_RDO_CLUSTER_MAP_bits  3
#define STRIP_EF_RDO_CLUSTER_MAP_msb   18
#define STRIP_EF_RDO_CLUSTER_MAP_lsb   16
#define STRIP_EF_RDO_CLUSTER_MAP_mf    1.
#define STRIP_EF_RDO_CLUSTER_MAP_s2c   0
#define STRIP_EF_RDO_CLUSTER_MAP_decb  3
#define STRIP_EF_RDO_CLUSTER_MAP_apfix 0

#define STRIP_EF_RDO_SPARE_bits        16
#define STRIP_EF_RDO_SPARE_msb         15
#define STRIP_EF_RDO_SPARE_lsb         0
#define STRIP_EF_RDO_SPARE_mf          1.
#define STRIP_EF_RDO_SPARE_s2c         0
#define STRIP_EF_RDO_SPARE_decb        16
#define STRIP_EF_RDO_SPARE_apfix       0



#endif // _DATAFORMAT_DEFINES_H_
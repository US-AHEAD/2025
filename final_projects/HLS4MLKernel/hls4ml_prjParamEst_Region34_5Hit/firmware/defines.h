#ifndef DEFINES_H_
#define DEFINES_H_

#include "ap_fixed.h"
#include "ap_int.h"
#include "nnet_utils/nnet_types.h"
#include <cstddef>
#include <cstdio>

// hls-fpga-machine-learning insert numbers
#define PARAMEST_NN_N_INPUT_1_1 5
#define PARAMEST_NN_N_INPUT_2_1 3
#define PARAMEST_NN_N_SIZE_0_2 15
#define PARAMEST_NN_N_LAYER_3 32
#define PARAMEST_NN_N_LAYER_3 32
#define PARAMEST_NN_N_LAYER_3 32
#define PARAMEST_NN_N_LAYER_3 32
#define PARAMEST_NN_N_LAYER_6 64
#define PARAMEST_NN_N_LAYER_6 64
#define PARAMEST_NN_N_LAYER_6 64
#define PARAMEST_NN_N_LAYER_6 64
#define PARAMEST_NN_N_LAYER_9 32
#define PARAMEST_NN_N_LAYER_9 32
#define PARAMEST_NN_N_LAYER_9 32
#define PARAMEST_NN_N_LAYER_9 32
#define PARAMEST_NN_N_LAYER_12 5
#define PARAMEST_NN_N_LAYER_12 5
#define PARAMEST_NN_N_LAYER_12 5
#define PARAMEST_NN_N_LAYER_12 5

// hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<16,6> PARAMEST_NN_input_t;
typedef ap_fixed<16,6,AP_RND_CONV,AP_SAT> PARAMEST_NN_layer3_accum_t;
typedef ap_fixed<16,6,AP_RND_CONV,AP_SAT> PARAMEST_NN_layer3_t;
typedef ap_fixed<16,1> PARAMEST_NN_weight3_t;
typedef ap_fixed<16,1> PARAMEST_NN_bias3_t;
typedef ap_uint<1> PARAMEST_NN_layer3_index;
typedef ap_fixed<16,6> PARAMEST_NN_layer15_t;
typedef struct exponent_scale15_t {ap_uint<1> sign;ap_int<2> weight; } PARAMEST_NN_exponent_scale15_t;
typedef ap_fixed<16,1> PARAMEST_NN_bias15_t;
typedef ap_fixed<16,6,AP_RND_CONV,AP_SAT> PARAMEST_NN_layer4_t;
typedef ap_fixed<18,8> PARAMEST_NN_q_dense_linear_table_t;
typedef ap_ufixed<16,0,AP_RND_CONV,AP_SAT> PARAMEST_NN_layer5_t;
typedef ap_fixed<18,8> PARAMEST_NN_q_activation_table_t;
typedef ap_fixed<16,6,AP_RND_CONV,AP_SAT> PARAMEST_NN_layer6_accum_t;
typedef ap_fixed<16,6,AP_RND_CONV,AP_SAT> PARAMEST_NN_layer6_t;
typedef ap_fixed<16,1> PARAMEST_NN_weight6_t;
typedef ap_fixed<16,1> PARAMEST_NN_bias6_t;
typedef ap_uint<1> PARAMEST_NN_layer6_index;
typedef ap_fixed<16,6> PARAMEST_NN_layer16_t;
typedef struct exponent_scale16_t {ap_uint<1> sign;ap_int<2> weight; } PARAMEST_NN_exponent_scale16_t;
typedef ap_fixed<16,1> PARAMEST_NN_bias16_t;
typedef ap_fixed<16,6,AP_RND_CONV,AP_SAT> PARAMEST_NN_layer7_t;
typedef ap_fixed<18,8> PARAMEST_NN_q_dense_1_linear_table_t;
typedef ap_ufixed<16,0,AP_RND_CONV,AP_SAT> PARAMEST_NN_layer8_t;
typedef ap_fixed<18,8> PARAMEST_NN_q_activation_1_table_t;
typedef ap_fixed<16,6,AP_RND_CONV,AP_SAT> PARAMEST_NN_layer9_accum_t;
typedef ap_fixed<16,6,AP_RND_CONV,AP_SAT> PARAMEST_NN_layer9_t;
typedef ap_fixed<16,1> PARAMEST_NN_weight9_t;
typedef ap_fixed<16,1> PARAMEST_NN_bias9_t;
typedef ap_uint<1> PARAMEST_NN_layer9_index;
typedef ap_fixed<16,6> PARAMEST_NN_layer17_t;
typedef struct exponent_scale17_t {ap_uint<1> sign;ap_int<3> weight; } PARAMEST_NN_exponent_scale17_t;
typedef ap_fixed<16,1> PARAMEST_NN_bias17_t;
typedef ap_fixed<16,6,AP_RND_CONV,AP_SAT> PARAMEST_NN_layer10_t;
typedef ap_fixed<18,8> PARAMEST_NN_q_dense_2_linear_table_t;
typedef ap_ufixed<16,0,AP_RND_CONV,AP_SAT> PARAMEST_NN_layer11_t;
typedef ap_fixed<18,8> PARAMEST_NN_q_activation_2_table_t;
typedef ap_fixed<16,6,AP_RND_CONV,AP_SAT> PARAMEST_NN_layer12_accum_t;
typedef ap_fixed<16,6,AP_RND_CONV,AP_SAT> PARAMEST_NN_layer12_t;
typedef ap_fixed<16,1> PARAMEST_NN_weight12_t;
typedef ap_fixed<16,1> PARAMEST_NN_bias12_t;
typedef ap_uint<1> PARAMEST_NN_layer12_index;
typedef ap_fixed<16,6> PARAMEST_NN_layer18_t;
typedef struct exponent_scale18_t {ap_uint<1> sign;ap_int<2> weight; } PARAMEST_NN_exponent_scale18_t;
typedef ap_fixed<16,1> PARAMEST_NN_bias18_t;
typedef ap_fixed<16,6,AP_RND_CONV,AP_SAT> PARAMEST_NN_layer13_t;
typedef ap_fixed<18,8> PARAMEST_NN_q_dense_3_linear_table_t;
typedef ap_fixed<8,1,AP_RND_CONV,AP_SAT> PARAMEST_NN_result_t;
typedef ap_ufixed<2,0> PARAMEST_NN_slope14_t;
typedef ap_ufixed<2,0> PARAMEST_NN_shift14_t;
typedef ap_fixed<18,8> PARAMEST_NN_q_activation_3_table_t;

#endif

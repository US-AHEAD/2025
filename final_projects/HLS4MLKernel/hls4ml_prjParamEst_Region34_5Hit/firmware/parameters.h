#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include "ap_fixed.h"
#include "ap_int.h"

#include "nnet_utils/nnet_code_gen.h"
#include "nnet_utils/nnet_helpers.h"
// hls-fpga-machine-learning insert includes
#include "nnet_utils/nnet_activation.h"
#include "nnet_utils/nnet_activation_stream.h"
#include "nnet_utils/nnet_batchnorm.h"
#include "nnet_utils/nnet_batchnorm_stream.h"
#include "nnet_utils/nnet_dense.h"
#include "nnet_utils/nnet_dense_compressed.h"
#include "nnet_utils/nnet_dense_stream.h"

// hls-fpga-machine-learning insert weights
#include "weights/PARAMEST_NN_w3.h"
#include "weights/PARAMEST_NN_b3.h"
#include "weights/PARAMEST_NN_s15.h"
#include "weights/PARAMEST_NN_b15.h"
#include "weights/PARAMEST_NN_w6.h"
#include "weights/PARAMEST_NN_b6.h"
#include "weights/PARAMEST_NN_s16.h"
#include "weights/PARAMEST_NN_b16.h"
#include "weights/PARAMEST_NN_w9.h"
#include "weights/PARAMEST_NN_b9.h"
#include "weights/PARAMEST_NN_s17.h"
#include "weights/PARAMEST_NN_b17.h"
#include "weights/PARAMEST_NN_w12.h"
#include "weights/PARAMEST_NN_b12.h"
#include "weights/PARAMEST_NN_s18.h"
#include "weights/PARAMEST_NN_b18.h"

// hls-fpga-machine-learning insert layer-config
// q_dense
struct PARAMEST_NN_config3 : nnet::dense_config {
    static const unsigned n_in = 15;
    static const unsigned n_out = 32;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned strategy = nnet::latency;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 288;
    static const unsigned n_nonzeros = 192;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef PARAMEST_NN_layer3_accum_t accum_t;
    typedef PARAMEST_NN_bias3_t bias_t;
    typedef PARAMEST_NN_weight3_t weight_t;
    typedef PARAMEST_NN_layer3_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// q_dense_alpha
struct PARAMEST_NN_config15 : nnet::batchnorm_config {
    static const unsigned n_in = PARAMEST_NN_N_LAYER_3;
    static const unsigned n_filt = -1;
    static const unsigned n_scale_bias = (n_filt == -1) ? n_in : n_filt;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in, reuse_factor);
    static const bool store_weights_in_bram = false;
    typedef PARAMEST_NN_bias15_t bias_t;
    typedef PARAMEST_NN_exponent_scale15_t scale_t;
    template<class x_T, class y_T>
    using product = nnet::product::weight_exponential<x_T, y_T>;
};

// q_dense_linear
struct PARAMEST_NN_linear_config4 : nnet::activ_config {
    static const unsigned n_in = 32;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    typedef PARAMEST_NN_q_dense_linear_table_t table_t;
};

// q_activation
struct PARAMEST_NN_relu_config5 : nnet::activ_config {
    static const unsigned n_in = 32;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    typedef PARAMEST_NN_q_activation_table_t table_t;
};

// q_dense_1
struct PARAMEST_NN_config6 : nnet::dense_config {
    static const unsigned n_in = 32;
    static const unsigned n_out = 64;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned strategy = nnet::latency;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 1229;
    static const unsigned n_nonzeros = 819;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef PARAMEST_NN_layer6_accum_t accum_t;
    typedef PARAMEST_NN_bias6_t bias_t;
    typedef PARAMEST_NN_weight6_t weight_t;
    typedef PARAMEST_NN_layer6_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// q_dense_1_alpha
struct PARAMEST_NN_config16 : nnet::batchnorm_config {
    static const unsigned n_in = PARAMEST_NN_N_LAYER_6;
    static const unsigned n_filt = -1;
    static const unsigned n_scale_bias = (n_filt == -1) ? n_in : n_filt;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in, reuse_factor);
    static const bool store_weights_in_bram = false;
    typedef PARAMEST_NN_bias16_t bias_t;
    typedef PARAMEST_NN_exponent_scale16_t scale_t;
    template<class x_T, class y_T>
    using product = nnet::product::weight_exponential<x_T, y_T>;
};

// q_dense_1_linear
struct PARAMEST_NN_linear_config7 : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    typedef PARAMEST_NN_q_dense_1_linear_table_t table_t;
};

// q_activation_1
struct PARAMEST_NN_relu_config8 : nnet::activ_config {
    static const unsigned n_in = 64;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    typedef PARAMEST_NN_q_activation_1_table_t table_t;
};

// q_dense_2
struct PARAMEST_NN_config9 : nnet::dense_config {
    static const unsigned n_in = 64;
    static const unsigned n_out = 32;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned strategy = nnet::latency;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 1229;
    static const unsigned n_nonzeros = 819;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef PARAMEST_NN_layer9_accum_t accum_t;
    typedef PARAMEST_NN_bias9_t bias_t;
    typedef PARAMEST_NN_weight9_t weight_t;
    typedef PARAMEST_NN_layer9_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// q_dense_2_alpha
struct PARAMEST_NN_config17 : nnet::batchnorm_config {
    static const unsigned n_in = PARAMEST_NN_N_LAYER_9;
    static const unsigned n_filt = -1;
    static const unsigned n_scale_bias = (n_filt == -1) ? n_in : n_filt;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in, reuse_factor);
    static const bool store_weights_in_bram = false;
    typedef PARAMEST_NN_bias17_t bias_t;
    typedef PARAMEST_NN_exponent_scale17_t scale_t;
    template<class x_T, class y_T>
    using product = nnet::product::weight_exponential<x_T, y_T>;
};

// q_dense_2_linear
struct PARAMEST_NN_linear_config10 : nnet::activ_config {
    static const unsigned n_in = 32;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    typedef PARAMEST_NN_q_dense_2_linear_table_t table_t;
};

// q_activation_2
struct PARAMEST_NN_relu_config11 : nnet::activ_config {
    static const unsigned n_in = 32;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    typedef PARAMEST_NN_q_activation_2_table_t table_t;
};

// q_dense_3
struct PARAMEST_NN_config12 : nnet::dense_config {
    static const unsigned n_in = 32;
    static const unsigned n_out = 5;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned strategy = nnet::latency;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 96;
    static const unsigned n_nonzeros = 64;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in * n_out, reuse_factor) - n_zeros / reuse_factor;
    static const bool store_weights_in_bram = false;
    typedef PARAMEST_NN_layer12_accum_t accum_t;
    typedef PARAMEST_NN_bias12_t bias_t;
    typedef PARAMEST_NN_weight12_t weight_t;
    typedef PARAMEST_NN_layer12_index index_t;
    template<class x_T, class y_T>
    using product = nnet::product::mult<x_T, y_T>;
};

// q_dense_3_alpha
struct PARAMEST_NN_config18 : nnet::batchnorm_config {
    static const unsigned n_in = PARAMEST_NN_N_LAYER_12;
    static const unsigned n_filt = -1;
    static const unsigned n_scale_bias = (n_filt == -1) ? n_in : n_filt;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    static const unsigned multiplier_limit = DIV_ROUNDUP(n_in, reuse_factor);
    static const bool store_weights_in_bram = false;
    typedef PARAMEST_NN_bias18_t bias_t;
    typedef PARAMEST_NN_exponent_scale18_t scale_t;
    template<class x_T, class y_T>
    using product = nnet::product::weight_exponential<x_T, y_T>;
};

// q_dense_3_linear
struct PARAMEST_NN_linear_config13 : nnet::activ_config {
    static const unsigned n_in = 5;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    typedef PARAMEST_NN_q_dense_3_linear_table_t table_t;
};

// q_activation_3
struct PARAMEST_NN_hard_tanh_config14 {
    static const unsigned n_in = 5;
    static const PARAMEST_NN_slope14_t slope;
    static const PARAMEST_NN_shift14_t shift;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
};
const PARAMEST_NN_slope14_t PARAMEST_NN_hard_tanh_config14::slope = 0.5;
const PARAMEST_NN_shift14_t PARAMEST_NN_hard_tanh_config14::shift = 0.5;


#endif

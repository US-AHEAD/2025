#include <iostream>

#include "ParamEst_NN.h"
#include "parameters.h"

void ParamEst_NN(
    PARAMEST_NN_input_t input_1[PARAMEST_NN_N_INPUT_1_1*PARAMEST_NN_N_INPUT_2_1],
    PARAMEST_NN_result_t PARAMEST_NN_layer14_out[PARAMEST_NN_N_LAYER_12]
) {

    // hls-fpga-machine-learning insert IO
    #pragma HLS ARRAY_RESHAPE variable=input_1 complete dim=0
    #pragma HLS ARRAY_PARTITION variable=PARAMEST_NN_layer14_out complete dim=0
    #pragma HLS INTERFACE ap_vld port=input_1,PARAMEST_NN_layer14_out 
    #pragma HLS PIPELINE 

#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        // hls-fpga-machine-learning insert load weights
        nnet::load_weights_from_txt<PARAMEST_NN_weight3_t, 480>(PARAMEST_NN_w3, "PARAMEST_NN_w3.txt");
        nnet::load_weights_from_txt<PARAMEST_NN_bias3_t, 32>(PARAMEST_NN_b3, "PARAMEST_NN_b3.txt");
        nnet::load_exponent_weights_from_txt<PARAMEST_NN_exponent_scale15_t, 32>(PARAMEST_NN_s15, "PARAMEST_NN_s15.txt");
        nnet::load_weights_from_txt<PARAMEST_NN_bias15_t, 32>(PARAMEST_NN_b15, "PARAMEST_NN_b15.txt");
        nnet::load_weights_from_txt<PARAMEST_NN_weight6_t, 2048>(PARAMEST_NN_w6, "PARAMEST_NN_w6.txt");
        nnet::load_weights_from_txt<PARAMEST_NN_bias6_t, 64>(PARAMEST_NN_b6, "PARAMEST_NN_b6.txt");
        nnet::load_exponent_weights_from_txt<PARAMEST_NN_exponent_scale16_t, 64>(PARAMEST_NN_s16, "PARAMEST_NN_s16.txt");
        nnet::load_weights_from_txt<PARAMEST_NN_bias16_t, 64>(PARAMEST_NN_b16, "PARAMEST_NN_b16.txt");
        nnet::load_weights_from_txt<PARAMEST_NN_weight9_t, 2048>(PARAMEST_NN_w9, "PARAMEST_NN_w9.txt");
        nnet::load_weights_from_txt<PARAMEST_NN_bias9_t, 32>(PARAMEST_NN_b9, "PARAMEST_NN_b9.txt");
        nnet::load_exponent_weights_from_txt<PARAMEST_NN_exponent_scale17_t, 32>(PARAMEST_NN_s17, "PARAMEST_NN_s17.txt");
        nnet::load_weights_from_txt<PARAMEST_NN_bias17_t, 32>(PARAMEST_NN_b17, "PARAMEST_NN_b17.txt");
        nnet::load_weights_from_txt<PARAMEST_NN_weight12_t, 160>(PARAMEST_NN_w12, "PARAMEST_NN_w12.txt");
        nnet::load_weights_from_txt<PARAMEST_NN_bias12_t, 5>(PARAMEST_NN_b12, "PARAMEST_NN_b12.txt");
        nnet::load_exponent_weights_from_txt<PARAMEST_NN_exponent_scale18_t, 5>(PARAMEST_NN_s18, "PARAMEST_NN_s18.txt");
        nnet::load_weights_from_txt<PARAMEST_NN_bias18_t, 5>(PARAMEST_NN_b18, "PARAMEST_NN_b18.txt");
        loaded_weights = true;
    }
#endif

    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    // hls-fpga-machine-learning insert layers

    auto& PARAMEST_NN_layer2_out = input_1;
    PARAMEST_NN_layer3_t PARAMEST_NN_layer3_out[PARAMEST_NN_N_LAYER_3];
    #pragma HLS ARRAY_PARTITION variable=PARAMEST_NN_layer3_out complete dim=0
    nnet::dense<PARAMEST_NN_input_t, PARAMEST_NN_layer3_t, PARAMEST_NN_config3>(PARAMEST_NN_layer2_out, PARAMEST_NN_layer3_out, PARAMEST_NN_w3, PARAMEST_NN_b3); // q_dense

    PARAMEST_NN_layer15_t PARAMEST_NN_layer15_out[PARAMEST_NN_N_LAYER_3];
    #pragma HLS ARRAY_PARTITION variable=PARAMEST_NN_layer15_out complete dim=0
    nnet::normalize<PARAMEST_NN_layer3_t, PARAMEST_NN_layer15_t, PARAMEST_NN_config15>(PARAMEST_NN_layer3_out, PARAMEST_NN_layer15_out, PARAMEST_NN_s15, PARAMEST_NN_b15); // q_dense_alpha

    PARAMEST_NN_layer4_t PARAMEST_NN_layer4_out[PARAMEST_NN_N_LAYER_3];
    #pragma HLS ARRAY_PARTITION variable=PARAMEST_NN_layer4_out complete dim=0
    nnet::linear<PARAMEST_NN_layer15_t, PARAMEST_NN_layer4_t, PARAMEST_NN_linear_config4>(PARAMEST_NN_layer15_out, PARAMEST_NN_layer4_out); // q_dense_linear

    PARAMEST_NN_layer5_t PARAMEST_NN_layer5_out[PARAMEST_NN_N_LAYER_3];
    #pragma HLS ARRAY_PARTITION variable=PARAMEST_NN_layer5_out complete dim=0
    nnet::relu<PARAMEST_NN_layer4_t, PARAMEST_NN_layer5_t, PARAMEST_NN_relu_config5>(PARAMEST_NN_layer4_out, PARAMEST_NN_layer5_out); // q_activation

    PARAMEST_NN_layer6_t PARAMEST_NN_layer6_out[PARAMEST_NN_N_LAYER_6];
    #pragma HLS ARRAY_PARTITION variable=PARAMEST_NN_layer6_out complete dim=0
    nnet::dense<PARAMEST_NN_layer5_t, PARAMEST_NN_layer6_t, PARAMEST_NN_config6>(PARAMEST_NN_layer5_out, PARAMEST_NN_layer6_out, PARAMEST_NN_w6, PARAMEST_NN_b6); // q_dense_1

    PARAMEST_NN_layer16_t PARAMEST_NN_layer16_out[PARAMEST_NN_N_LAYER_6];
    #pragma HLS ARRAY_PARTITION variable=PARAMEST_NN_layer16_out complete dim=0
    nnet::normalize<PARAMEST_NN_layer6_t, PARAMEST_NN_layer16_t, PARAMEST_NN_config16>(PARAMEST_NN_layer6_out, PARAMEST_NN_layer16_out, PARAMEST_NN_s16, PARAMEST_NN_b16); // q_dense_1_alpha

    PARAMEST_NN_layer7_t PARAMEST_NN_layer7_out[PARAMEST_NN_N_LAYER_6];
    #pragma HLS ARRAY_PARTITION variable=PARAMEST_NN_layer7_out complete dim=0
    nnet::linear<PARAMEST_NN_layer16_t, PARAMEST_NN_layer7_t, PARAMEST_NN_linear_config7>(PARAMEST_NN_layer16_out, PARAMEST_NN_layer7_out); // q_dense_1_linear

    PARAMEST_NN_layer8_t PARAMEST_NN_layer8_out[PARAMEST_NN_N_LAYER_6];
    #pragma HLS ARRAY_PARTITION variable=PARAMEST_NN_layer8_out complete dim=0
    nnet::relu<PARAMEST_NN_layer7_t, PARAMEST_NN_layer8_t, PARAMEST_NN_relu_config8>(PARAMEST_NN_layer7_out, PARAMEST_NN_layer8_out); // q_activation_1

    PARAMEST_NN_layer9_t PARAMEST_NN_layer9_out[PARAMEST_NN_N_LAYER_9];
    #pragma HLS ARRAY_PARTITION variable=PARAMEST_NN_layer9_out complete dim=0
    nnet::dense<PARAMEST_NN_layer8_t, PARAMEST_NN_layer9_t, PARAMEST_NN_config9>(PARAMEST_NN_layer8_out, PARAMEST_NN_layer9_out, PARAMEST_NN_w9, PARAMEST_NN_b9); // q_dense_2

    PARAMEST_NN_layer17_t PARAMEST_NN_layer17_out[PARAMEST_NN_N_LAYER_9];
    #pragma HLS ARRAY_PARTITION variable=PARAMEST_NN_layer17_out complete dim=0
    nnet::normalize<PARAMEST_NN_layer9_t, PARAMEST_NN_layer17_t, PARAMEST_NN_config17>(PARAMEST_NN_layer9_out, PARAMEST_NN_layer17_out, PARAMEST_NN_s17, PARAMEST_NN_b17); // q_dense_2_alpha

    PARAMEST_NN_layer10_t PARAMEST_NN_layer10_out[PARAMEST_NN_N_LAYER_9];
    #pragma HLS ARRAY_PARTITION variable=PARAMEST_NN_layer10_out complete dim=0
    nnet::linear<PARAMEST_NN_layer17_t, PARAMEST_NN_layer10_t, PARAMEST_NN_linear_config10>(PARAMEST_NN_layer17_out, PARAMEST_NN_layer10_out); // q_dense_2_linear

    PARAMEST_NN_layer11_t PARAMEST_NN_layer11_out[PARAMEST_NN_N_LAYER_9];
    #pragma HLS ARRAY_PARTITION variable=PARAMEST_NN_layer11_out complete dim=0
    nnet::relu<PARAMEST_NN_layer10_t, PARAMEST_NN_layer11_t, PARAMEST_NN_relu_config11>(PARAMEST_NN_layer10_out, PARAMEST_NN_layer11_out); // q_activation_2

    PARAMEST_NN_layer12_t PARAMEST_NN_layer12_out[PARAMEST_NN_N_LAYER_12];
    #pragma HLS ARRAY_PARTITION variable=PARAMEST_NN_layer12_out complete dim=0
    nnet::dense<PARAMEST_NN_layer11_t, PARAMEST_NN_layer12_t, PARAMEST_NN_config12>(PARAMEST_NN_layer11_out, PARAMEST_NN_layer12_out, PARAMEST_NN_w12, PARAMEST_NN_b12); // q_dense_3

    PARAMEST_NN_layer18_t PARAMEST_NN_layer18_out[PARAMEST_NN_N_LAYER_12];
    #pragma HLS ARRAY_PARTITION variable=PARAMEST_NN_layer18_out complete dim=0
    nnet::normalize<PARAMEST_NN_layer12_t, PARAMEST_NN_layer18_t, PARAMEST_NN_config18>(PARAMEST_NN_layer12_out, PARAMEST_NN_layer18_out, PARAMEST_NN_s18, PARAMEST_NN_b18); // q_dense_3_alpha

    PARAMEST_NN_layer13_t PARAMEST_NN_layer13_out[PARAMEST_NN_N_LAYER_12];
    #pragma HLS ARRAY_PARTITION variable=PARAMEST_NN_layer13_out complete dim=0
    nnet::linear<PARAMEST_NN_layer18_t, PARAMEST_NN_layer13_t, PARAMEST_NN_linear_config13>(PARAMEST_NN_layer18_out, PARAMEST_NN_layer13_out); // q_dense_3_linear

    nnet::hard_tanh<PARAMEST_NN_layer13_t, PARAMEST_NN_result_t, PARAMEST_NN_hard_tanh_config14>(PARAMEST_NN_layer13_out, PARAMEST_NN_layer14_out); // q_activation_3

}

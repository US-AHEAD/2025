#ifndef PARAMEST_NN_H_
#define PARAMEST_NN_H_

#include "ap_fixed.h"
#include "ap_int.h"
#include "hls_stream.h"

#include "defines.h"

// Prototype of top level function for C-synthesis
void ParamEst_NN(
    PARAMEST_NN_input_t input_1[PARAMEST_NN_N_INPUT_1_1*PARAMEST_NN_N_INPUT_2_1],
    PARAMEST_NN_result_t PARAMEST_NN_layer14_out[PARAMEST_NN_N_LAYER_12]
);

#endif

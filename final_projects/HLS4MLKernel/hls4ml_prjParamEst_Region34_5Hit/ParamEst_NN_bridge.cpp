#ifndef PARAMEST_NN_BRIDGE_H_
#define PARAMEST_NN_BRIDGE_H_

#include "firmware/ParamEst_NN.h"
#include "firmware/nnet_utils/nnet_helpers.h"
#include <algorithm>
#include <map>

// hls-fpga-machine-learning insert bram

namespace nnet {
bool trace_enabled = false;
std::map<std::string, void *> *trace_outputs = NULL;
size_t trace_type_size = sizeof(double);
} // namespace nnet

extern "C" {

struct trace_data {
    const char *name;
    void *data;
};

void allocate_trace_storage(size_t element_size) {
    nnet::trace_enabled = true;
    nnet::trace_outputs = new std::map<std::string, void *>;
    nnet::trace_type_size = element_size;
}

void free_trace_storage() {
    for (std::map<std::string, void *>::iterator i = nnet::trace_outputs->begin(); i != nnet::trace_outputs->end(); i++) {
        void *ptr = i->second;
        free(ptr);
    }
    nnet::trace_outputs->clear();
    delete nnet::trace_outputs;
    nnet::trace_outputs = NULL;
    nnet::trace_enabled = false;
}

void collect_trace_output(struct trace_data *c_trace_outputs) {
    int ii = 0;
    for (std::map<std::string, void *>::iterator i = nnet::trace_outputs->begin(); i != nnet::trace_outputs->end(); i++) {
        c_trace_outputs[ii].name = i->first.c_str();
        c_trace_outputs[ii].data = i->second;
        ii++;
    }
}

// Wrapper of top level function for Python bridge
void ParamEst_NN_float(
    float input_1[PARAMEST_NN_N_INPUT_1_1*PARAMEST_NN_N_INPUT_2_1],
    float PARAMEST_NN_layer14_out[PARAMEST_NN_N_LAYER_12]
) {

    PARAMEST_NN_input_t input_1_ap[PARAMEST_NN_N_INPUT_1_1*PARAMEST_NN_N_INPUT_2_1];
    nnet::convert_data<float, PARAMEST_NN_input_t, PARAMEST_NN_N_INPUT_1_1*PARAMEST_NN_N_INPUT_2_1>(input_1, input_1_ap);

    PARAMEST_NN_result_t PARAMEST_NN_layer14_out_ap[PARAMEST_NN_N_LAYER_12];

    ParamEst_NN(input_1_ap,PARAMEST_NN_layer14_out_ap);

    nnet::convert_data<PARAMEST_NN_result_t, float, PARAMEST_NN_N_LAYER_12>(PARAMEST_NN_layer14_out_ap, PARAMEST_NN_layer14_out);
}

void ParamEst_NN_double(
    double input_1[PARAMEST_NN_N_INPUT_1_1*PARAMEST_NN_N_INPUT_2_1],
    double PARAMEST_NN_layer14_out[PARAMEST_NN_N_LAYER_12]
) {
    PARAMEST_NN_input_t input_1_ap[PARAMEST_NN_N_INPUT_1_1*PARAMEST_NN_N_INPUT_2_1];
    nnet::convert_data<double, PARAMEST_NN_input_t, PARAMEST_NN_N_INPUT_1_1*PARAMEST_NN_N_INPUT_2_1>(input_1, input_1_ap);

    PARAMEST_NN_result_t PARAMEST_NN_layer14_out_ap[PARAMEST_NN_N_LAYER_12];

    ParamEst_NN(input_1_ap,PARAMEST_NN_layer14_out_ap);

    nnet::convert_data<PARAMEST_NN_result_t, double, PARAMEST_NN_N_LAYER_12>(PARAMEST_NN_layer14_out_ap, PARAMEST_NN_layer14_out);
}
}

#endif

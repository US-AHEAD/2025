set SynModuleInfo {
  {SRCNAME dense_latency<ap_fixed,ap_fixed<16,6,4,0,0>,PARAMEST_NN_config3> MODELNAME dense_latency_ap_fixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_config3_s RTLNAME ParamEst_NN_dense_latency_ap_fixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_config3_s
    SUBMODULES {
      {MODELNAME ParamEst_NN_mul_16s_15s_31_1_0 RTLNAME ParamEst_NN_mul_16s_15s_31_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16s_16ns_32_1_0 RTLNAME ParamEst_NN_mul_16s_16ns_32_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16s_15ns_31_1_0 RTLNAME ParamEst_NN_mul_16s_15ns_31_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16s_14ns_30_1_0 RTLNAME ParamEst_NN_mul_16s_14ns_30_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16s_16s_32_1_0 RTLNAME ParamEst_NN_mul_16s_16s_32_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16s_14s_30_1_0 RTLNAME ParamEst_NN_mul_16s_14s_30_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16s_13s_29_1_0 RTLNAME ParamEst_NN_mul_16s_13s_29_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16s_13ns_29_1_0 RTLNAME ParamEst_NN_mul_16s_13ns_29_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16s_10ns_26_1_0 RTLNAME ParamEst_NN_mul_16s_10ns_26_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME normalize<ap_fixed,ap_fixed<16,6,5,3,0>,PARAMEST_NN_config15> MODELNAME normalize_ap_fixed_ap_fixed_16_6_5_3_0_PARAMEST_NN_config15_s RTLNAME ParamEst_NN_normalize_ap_fixed_ap_fixed_16_6_5_3_0_PARAMEST_NN_config15_s}
  {SRCNAME linear<ap_fixed,ap_fixed<16,6,4,0,0>,PARAMEST_NN_linear_config4> MODELNAME linear_ap_fixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_linear_config4_s RTLNAME ParamEst_NN_linear_ap_fixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_linear_config4_s}
  {SRCNAME relu<ap_fixed,ap_ufixed<16,0,4,0,0>,PARAMEST_NN_relu_config5> MODELNAME relu_ap_fixed_ap_ufixed_16_0_4_0_0_PARAMEST_NN_relu_config5_s RTLNAME ParamEst_NN_relu_ap_fixed_ap_ufixed_16_0_4_0_0_PARAMEST_NN_relu_config5_s}
  {SRCNAME dense_latency<ap_ufixed,ap_fixed<16,6,4,0,0>,PARAMEST_NN_config6> MODELNAME dense_latency_ap_ufixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_config6_s RTLNAME ParamEst_NN_dense_latency_ap_ufixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_config6_s
    SUBMODULES {
      {MODELNAME ParamEst_NN_mul_16ns_16ns_31_1_0 RTLNAME ParamEst_NN_mul_16ns_16ns_31_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_15s_31_1_0 RTLNAME ParamEst_NN_mul_16ns_15s_31_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_16s_32_1_0 RTLNAME ParamEst_NN_mul_16ns_16s_32_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_14s_30_1_0 RTLNAME ParamEst_NN_mul_16ns_14s_30_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_15ns_30_1_0 RTLNAME ParamEst_NN_mul_16ns_15ns_30_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_13s_29_1_0 RTLNAME ParamEst_NN_mul_16ns_13s_29_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_14ns_29_1_0 RTLNAME ParamEst_NN_mul_16ns_14ns_29_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_10s_26_1_0 RTLNAME ParamEst_NN_mul_16ns_10s_26_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_13ns_28_1_0 RTLNAME ParamEst_NN_mul_16ns_13ns_28_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_12s_28_1_0 RTLNAME ParamEst_NN_mul_16ns_12s_28_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_10ns_25_1_0 RTLNAME ParamEst_NN_mul_16ns_10ns_25_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_12ns_27_1_0 RTLNAME ParamEst_NN_mul_16ns_12ns_27_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_8ns_23_1_0 RTLNAME ParamEst_NN_mul_16ns_8ns_23_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_11ns_26_1_0 RTLNAME ParamEst_NN_mul_16ns_11ns_26_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME normalize<ap_fixed,ap_fixed<16,6,5,3,0>,PARAMEST_NN_config16> MODELNAME normalize_ap_fixed_ap_fixed_16_6_5_3_0_PARAMEST_NN_config16_s RTLNAME ParamEst_NN_normalize_ap_fixed_ap_fixed_16_6_5_3_0_PARAMEST_NN_config16_s}
  {SRCNAME linear<ap_fixed,ap_fixed<16,6,4,0,0>,PARAMEST_NN_linear_config7> MODELNAME linear_ap_fixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_linear_config7_s RTLNAME ParamEst_NN_linear_ap_fixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_linear_config7_s}
  {SRCNAME relu<ap_fixed,ap_ufixed<16,0,4,0,0>,PARAMEST_NN_relu_config8> MODELNAME relu_ap_fixed_ap_ufixed_16_0_4_0_0_PARAMEST_NN_relu_config8_s RTLNAME ParamEst_NN_relu_ap_fixed_ap_ufixed_16_0_4_0_0_PARAMEST_NN_relu_config8_s}
  {SRCNAME dense_latency<ap_ufixed,ap_fixed<16,6,4,0,0>,PARAMEST_NN_config9> MODELNAME dense_latency_ap_ufixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_config9_s RTLNAME ParamEst_NN_dense_latency_ap_ufixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_config9_s
    SUBMODULES {
      {MODELNAME ParamEst_NN_mul_16ns_8s_24_1_0 RTLNAME ParamEst_NN_mul_16ns_8s_24_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_7ns_22_1_0 RTLNAME ParamEst_NN_mul_16ns_7ns_22_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_9ns_24_1_0 RTLNAME ParamEst_NN_mul_16ns_9ns_24_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_11s_27_1_0 RTLNAME ParamEst_NN_mul_16ns_11s_27_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME ParamEst_NN_mul_16ns_9s_25_1_0 RTLNAME ParamEst_NN_mul_16ns_9s_25_1_0 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME normalize<ap_fixed,ap_fixed<16,6,5,3,0>,PARAMEST_NN_config17> MODELNAME normalize_ap_fixed_ap_fixed_16_6_5_3_0_PARAMEST_NN_config17_s RTLNAME ParamEst_NN_normalize_ap_fixed_ap_fixed_16_6_5_3_0_PARAMEST_NN_config17_s}
  {SRCNAME linear<ap_fixed,ap_fixed<16,6,4,0,0>,PARAMEST_NN_linear_config10> MODELNAME linear_ap_fixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_linear_config10_s RTLNAME ParamEst_NN_linear_ap_fixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_linear_config10_s}
  {SRCNAME relu<ap_fixed,ap_ufixed<16,0,4,0,0>,PARAMEST_NN_relu_config11> MODELNAME relu_ap_fixed_ap_ufixed_16_0_4_0_0_PARAMEST_NN_relu_config11_s RTLNAME ParamEst_NN_relu_ap_fixed_ap_ufixed_16_0_4_0_0_PARAMEST_NN_relu_config11_s}
  {SRCNAME dense_latency<ap_ufixed,ap_fixed<16,6,4,0,0>,PARAMEST_NN_config12> MODELNAME dense_latency_ap_ufixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_config12_s RTLNAME ParamEst_NN_dense_latency_ap_ufixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_config12_s}
  {SRCNAME normalize<ap_fixed,ap_fixed<16,6,5,3,0>,PARAMEST_NN_config18> MODELNAME normalize_ap_fixed_ap_fixed_16_6_5_3_0_PARAMEST_NN_config18_s RTLNAME ParamEst_NN_normalize_ap_fixed_ap_fixed_16_6_5_3_0_PARAMEST_NN_config18_s}
  {SRCNAME linear<ap_fixed,ap_fixed<16,6,4,0,0>,PARAMEST_NN_linear_config13> MODELNAME linear_ap_fixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_linear_config13_s RTLNAME ParamEst_NN_linear_ap_fixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_linear_config13_s}
  {SRCNAME hard_tanh<ap_fixed,ap_fixed<8,1,4,0,0>,PARAMEST_NN_hard_tanh_config14> MODELNAME hard_tanh_ap_fixed_ap_fixed_8_1_4_0_0_PARAMEST_NN_hard_tanh_config14_s RTLNAME ParamEst_NN_hard_tanh_ap_fixed_ap_fixed_8_1_4_0_0_PARAMEST_NN_hard_tanh_config14_s}
  {SRCNAME ParamEst_NN MODELNAME ParamEst_NN RTLNAME ParamEst_NN IS_TOP 1}
}

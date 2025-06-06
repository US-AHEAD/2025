// ==============================================================
// Generated by Vitis HLS v2023.1
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// ==============================================================

`timescale 1 ns / 1 ps 

module ParamEst_NN_linear_ap_fixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_linear_config4_s (
        ap_ready,
        data_0_val,
        data_1_val,
        data_2_val,
        data_3_val,
        data_4_val,
        data_5_val,
        data_6_val,
        data_7_val,
        data_8_val,
        data_9_val,
        data_10_val,
        data_11_val,
        data_12_val,
        data_13_val,
        data_14_val,
        data_15_val,
        data_16_val,
        data_17_val,
        data_18_val,
        data_19_val,
        data_20_val,
        data_21_val,
        data_22_val,
        data_23_val,
        data_24_val,
        data_25_val,
        data_26_val,
        data_27_val,
        data_28_val,
        data_29_val,
        data_30_val,
        data_31_val,
        ap_return_0,
        ap_return_1,
        ap_return_2,
        ap_return_3,
        ap_return_4,
        ap_return_5,
        ap_return_6,
        ap_return_7,
        ap_return_8,
        ap_return_9,
        ap_return_10,
        ap_return_11,
        ap_return_12,
        ap_return_13,
        ap_return_14,
        ap_return_15,
        ap_return_16,
        ap_return_17,
        ap_return_18,
        ap_return_19,
        ap_return_20,
        ap_return_21,
        ap_return_22,
        ap_return_23,
        ap_return_24,
        ap_return_25,
        ap_return_26,
        ap_return_27,
        ap_return_28,
        ap_return_29,
        ap_return_30,
        ap_return_31
);


output   ap_ready;
input  [15:0] data_0_val;
input  [15:0] data_1_val;
input  [15:0] data_2_val;
input  [15:0] data_3_val;
input  [15:0] data_4_val;
input  [15:0] data_5_val;
input  [15:0] data_6_val;
input  [15:0] data_7_val;
input  [15:0] data_8_val;
input  [15:0] data_9_val;
input  [15:0] data_10_val;
input  [15:0] data_11_val;
input  [15:0] data_12_val;
input  [15:0] data_13_val;
input  [15:0] data_14_val;
input  [15:0] data_15_val;
input  [15:0] data_16_val;
input  [15:0] data_17_val;
input  [15:0] data_18_val;
input  [15:0] data_19_val;
input  [15:0] data_20_val;
input  [15:0] data_21_val;
input  [15:0] data_22_val;
input  [15:0] data_23_val;
input  [15:0] data_24_val;
input  [15:0] data_25_val;
input  [15:0] data_26_val;
input  [15:0] data_27_val;
input  [15:0] data_28_val;
input  [15:0] data_29_val;
input  [15:0] data_30_val;
input  [15:0] data_31_val;
output  [15:0] ap_return_0;
output  [15:0] ap_return_1;
output  [15:0] ap_return_2;
output  [15:0] ap_return_3;
output  [15:0] ap_return_4;
output  [15:0] ap_return_5;
output  [15:0] ap_return_6;
output  [15:0] ap_return_7;
output  [15:0] ap_return_8;
output  [15:0] ap_return_9;
output  [15:0] ap_return_10;
output  [15:0] ap_return_11;
output  [15:0] ap_return_12;
output  [15:0] ap_return_13;
output  [15:0] ap_return_14;
output  [15:0] ap_return_15;
output  [15:0] ap_return_16;
output  [15:0] ap_return_17;
output  [15:0] ap_return_18;
output  [15:0] ap_return_19;
output  [15:0] ap_return_20;
output  [15:0] ap_return_21;
output  [15:0] ap_return_22;
output  [15:0] ap_return_23;
output  [15:0] ap_return_24;
output  [15:0] ap_return_25;
output  [15:0] ap_return_26;
output  [15:0] ap_return_27;
output  [15:0] ap_return_28;
output  [15:0] ap_return_29;
output  [15:0] ap_return_30;
output  [15:0] ap_return_31;

assign ap_ready = 1'b1;

assign ap_return_0 = data_0_val;

assign ap_return_1 = data_1_val;

assign ap_return_10 = data_10_val;

assign ap_return_11 = data_11_val;

assign ap_return_12 = data_12_val;

assign ap_return_13 = data_13_val;

assign ap_return_14 = data_14_val;

assign ap_return_15 = data_15_val;

assign ap_return_16 = data_16_val;

assign ap_return_17 = data_17_val;

assign ap_return_18 = data_18_val;

assign ap_return_19 = data_19_val;

assign ap_return_2 = data_2_val;

assign ap_return_20 = data_20_val;

assign ap_return_21 = data_21_val;

assign ap_return_22 = data_22_val;

assign ap_return_23 = data_23_val;

assign ap_return_24 = data_24_val;

assign ap_return_25 = data_25_val;

assign ap_return_26 = data_26_val;

assign ap_return_27 = data_27_val;

assign ap_return_28 = data_28_val;

assign ap_return_29 = data_29_val;

assign ap_return_3 = data_3_val;

assign ap_return_30 = data_30_val;

assign ap_return_31 = data_31_val;

assign ap_return_4 = data_4_val;

assign ap_return_5 = data_5_val;

assign ap_return_6 = data_6_val;

assign ap_return_7 = data_7_val;

assign ap_return_8 = data_8_val;

assign ap_return_9 = data_9_val;

endmodule //ParamEst_NN_linear_ap_fixed_ap_fixed_16_6_4_0_0_PARAMEST_NN_linear_config4_s

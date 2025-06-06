// ==============================================================
// Generated by Vitis HLS v2023.1
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// ==============================================================

`timescale 1 ns / 1 ps 

module ParamEst_NN_relu_ap_fixed_ap_ufixed_16_0_4_0_0_PARAMEST_NN_relu_config11_s (
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
        ap_return_30
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

wire   [5:0] tmp_fu_286_p4;
wire   [0:0] icmp_ln46_fu_296_p2;
wire   [15:0] shl_ln46_fu_280_p2;
wire   [0:0] icmp_ln45_fu_274_p2;
wire   [15:0] select_ln46_fu_302_p3;
wire   [5:0] tmp_33_fu_330_p4;
wire   [0:0] icmp_ln46_95_fu_340_p2;
wire   [15:0] shl_ln46_95_fu_324_p2;
wire   [0:0] icmp_ln45_95_fu_318_p2;
wire   [15:0] select_ln46_95_fu_346_p3;
wire   [5:0] tmp_s_fu_374_p4;
wire   [0:0] icmp_ln46_96_fu_384_p2;
wire   [15:0] shl_ln46_96_fu_368_p2;
wire   [0:0] icmp_ln45_96_fu_362_p2;
wire   [15:0] select_ln46_96_fu_390_p3;
wire   [5:0] tmp_92_fu_418_p4;
wire   [0:0] icmp_ln46_97_fu_428_p2;
wire   [15:0] shl_ln46_97_fu_412_p2;
wire   [0:0] icmp_ln45_97_fu_406_p2;
wire   [15:0] select_ln46_97_fu_434_p3;
wire   [5:0] tmp_93_fu_462_p4;
wire   [0:0] icmp_ln46_98_fu_472_p2;
wire   [15:0] shl_ln46_98_fu_456_p2;
wire   [0:0] icmp_ln45_98_fu_450_p2;
wire   [15:0] select_ln46_98_fu_478_p3;
wire   [5:0] tmp_94_fu_506_p4;
wire   [0:0] icmp_ln46_99_fu_516_p2;
wire   [15:0] shl_ln46_99_fu_500_p2;
wire   [0:0] icmp_ln45_99_fu_494_p2;
wire   [15:0] select_ln46_99_fu_522_p3;
wire   [5:0] tmp_95_fu_550_p4;
wire   [0:0] icmp_ln46_100_fu_560_p2;
wire   [15:0] shl_ln46_100_fu_544_p2;
wire   [0:0] icmp_ln45_100_fu_538_p2;
wire   [15:0] select_ln46_100_fu_566_p3;
wire   [5:0] tmp_96_fu_594_p4;
wire   [0:0] icmp_ln46_101_fu_604_p2;
wire   [15:0] shl_ln46_101_fu_588_p2;
wire   [0:0] icmp_ln45_101_fu_582_p2;
wire   [15:0] select_ln46_101_fu_610_p3;
wire   [5:0] tmp_97_fu_638_p4;
wire   [0:0] icmp_ln46_102_fu_648_p2;
wire   [15:0] shl_ln46_102_fu_632_p2;
wire   [0:0] icmp_ln45_102_fu_626_p2;
wire   [15:0] select_ln46_102_fu_654_p3;
wire   [5:0] tmp_98_fu_682_p4;
wire   [0:0] icmp_ln46_103_fu_692_p2;
wire   [15:0] shl_ln46_103_fu_676_p2;
wire   [0:0] icmp_ln45_103_fu_670_p2;
wire   [15:0] select_ln46_103_fu_698_p3;
wire   [5:0] tmp_99_fu_726_p4;
wire   [0:0] icmp_ln46_104_fu_736_p2;
wire   [15:0] shl_ln46_104_fu_720_p2;
wire   [0:0] icmp_ln45_104_fu_714_p2;
wire   [15:0] select_ln46_104_fu_742_p3;
wire   [5:0] tmp_100_fu_770_p4;
wire   [0:0] icmp_ln46_105_fu_780_p2;
wire   [15:0] shl_ln46_105_fu_764_p2;
wire   [0:0] icmp_ln45_105_fu_758_p2;
wire   [15:0] select_ln46_105_fu_786_p3;
wire   [5:0] tmp_101_fu_814_p4;
wire   [0:0] icmp_ln46_106_fu_824_p2;
wire   [15:0] shl_ln46_106_fu_808_p2;
wire   [0:0] icmp_ln45_106_fu_802_p2;
wire   [15:0] select_ln46_106_fu_830_p3;
wire   [5:0] tmp_102_fu_858_p4;
wire   [0:0] icmp_ln46_107_fu_868_p2;
wire   [15:0] shl_ln46_107_fu_852_p2;
wire   [0:0] icmp_ln45_107_fu_846_p2;
wire   [15:0] select_ln46_107_fu_874_p3;
wire   [5:0] tmp_103_fu_902_p4;
wire   [0:0] icmp_ln46_108_fu_912_p2;
wire   [15:0] shl_ln46_108_fu_896_p2;
wire   [0:0] icmp_ln45_108_fu_890_p2;
wire   [15:0] select_ln46_108_fu_918_p3;
wire   [5:0] tmp_104_fu_946_p4;
wire   [0:0] icmp_ln46_109_fu_956_p2;
wire   [15:0] shl_ln46_109_fu_940_p2;
wire   [0:0] icmp_ln45_109_fu_934_p2;
wire   [15:0] select_ln46_109_fu_962_p3;
wire   [5:0] tmp_105_fu_990_p4;
wire   [0:0] icmp_ln46_110_fu_1000_p2;
wire   [15:0] shl_ln46_110_fu_984_p2;
wire   [0:0] icmp_ln45_110_fu_978_p2;
wire   [15:0] select_ln46_110_fu_1006_p3;
wire   [5:0] tmp_106_fu_1034_p4;
wire   [0:0] icmp_ln46_111_fu_1044_p2;
wire   [15:0] shl_ln46_111_fu_1028_p2;
wire   [0:0] icmp_ln45_111_fu_1022_p2;
wire   [15:0] select_ln46_111_fu_1050_p3;
wire   [5:0] tmp_107_fu_1078_p4;
wire   [0:0] icmp_ln46_112_fu_1088_p2;
wire   [15:0] shl_ln46_112_fu_1072_p2;
wire   [0:0] icmp_ln45_112_fu_1066_p2;
wire   [15:0] select_ln46_112_fu_1094_p3;
wire   [5:0] tmp_108_fu_1122_p4;
wire   [0:0] icmp_ln46_113_fu_1132_p2;
wire   [15:0] shl_ln46_113_fu_1116_p2;
wire   [0:0] icmp_ln45_113_fu_1110_p2;
wire   [15:0] select_ln46_113_fu_1138_p3;
wire   [5:0] tmp_109_fu_1166_p4;
wire   [0:0] icmp_ln46_114_fu_1176_p2;
wire   [15:0] shl_ln46_114_fu_1160_p2;
wire   [0:0] icmp_ln45_114_fu_1154_p2;
wire   [15:0] select_ln46_114_fu_1182_p3;
wire   [5:0] tmp_110_fu_1210_p4;
wire   [0:0] icmp_ln46_115_fu_1220_p2;
wire   [15:0] shl_ln46_115_fu_1204_p2;
wire   [0:0] icmp_ln45_115_fu_1198_p2;
wire   [15:0] select_ln46_115_fu_1226_p3;
wire   [5:0] tmp_111_fu_1254_p4;
wire   [0:0] icmp_ln46_116_fu_1264_p2;
wire   [15:0] shl_ln46_116_fu_1248_p2;
wire   [0:0] icmp_ln45_116_fu_1242_p2;
wire   [15:0] select_ln46_116_fu_1270_p3;
wire   [5:0] tmp_112_fu_1298_p4;
wire   [0:0] icmp_ln46_117_fu_1308_p2;
wire   [15:0] shl_ln46_117_fu_1292_p2;
wire   [0:0] icmp_ln45_117_fu_1286_p2;
wire   [15:0] select_ln46_117_fu_1314_p3;
wire   [5:0] tmp_113_fu_1342_p4;
wire   [0:0] icmp_ln46_118_fu_1352_p2;
wire   [15:0] shl_ln46_118_fu_1336_p2;
wire   [0:0] icmp_ln45_118_fu_1330_p2;
wire   [15:0] select_ln46_118_fu_1358_p3;
wire   [5:0] tmp_114_fu_1386_p4;
wire   [0:0] icmp_ln46_119_fu_1396_p2;
wire   [15:0] shl_ln46_119_fu_1380_p2;
wire   [0:0] icmp_ln45_119_fu_1374_p2;
wire   [15:0] select_ln46_119_fu_1402_p3;
wire   [5:0] tmp_115_fu_1430_p4;
wire   [0:0] icmp_ln46_120_fu_1440_p2;
wire   [15:0] shl_ln46_120_fu_1424_p2;
wire   [0:0] icmp_ln45_120_fu_1418_p2;
wire   [15:0] select_ln46_120_fu_1446_p3;
wire   [5:0] tmp_116_fu_1474_p4;
wire   [0:0] icmp_ln46_121_fu_1484_p2;
wire   [15:0] shl_ln46_121_fu_1468_p2;
wire   [0:0] icmp_ln45_121_fu_1462_p2;
wire   [15:0] select_ln46_121_fu_1490_p3;
wire   [5:0] tmp_117_fu_1518_p4;
wire   [0:0] icmp_ln46_122_fu_1528_p2;
wire   [15:0] shl_ln46_122_fu_1512_p2;
wire   [0:0] icmp_ln45_122_fu_1506_p2;
wire   [15:0] select_ln46_122_fu_1534_p3;
wire   [5:0] tmp_118_fu_1562_p4;
wire   [0:0] icmp_ln46_123_fu_1572_p2;
wire   [15:0] shl_ln46_123_fu_1556_p2;
wire   [0:0] icmp_ln45_123_fu_1550_p2;
wire   [15:0] select_ln46_123_fu_1578_p3;
wire   [5:0] tmp_119_fu_1606_p4;
wire   [0:0] icmp_ln46_124_fu_1616_p2;
wire   [15:0] shl_ln46_124_fu_1600_p2;
wire   [0:0] icmp_ln45_124_fu_1594_p2;
wire   [15:0] select_ln46_124_fu_1622_p3;
wire   [15:0] select_ln45_fu_310_p3;
wire   [15:0] select_ln45_95_fu_354_p3;
wire   [15:0] select_ln45_96_fu_398_p3;
wire   [15:0] select_ln45_97_fu_442_p3;
wire   [15:0] select_ln45_98_fu_486_p3;
wire   [15:0] select_ln45_99_fu_530_p3;
wire   [15:0] select_ln45_100_fu_574_p3;
wire   [15:0] select_ln45_101_fu_618_p3;
wire   [15:0] select_ln45_102_fu_662_p3;
wire   [15:0] select_ln45_103_fu_706_p3;
wire   [15:0] select_ln45_104_fu_750_p3;
wire   [15:0] select_ln45_105_fu_794_p3;
wire   [15:0] select_ln45_106_fu_838_p3;
wire   [15:0] select_ln45_107_fu_882_p3;
wire   [15:0] select_ln45_108_fu_926_p3;
wire   [15:0] select_ln45_109_fu_970_p3;
wire   [15:0] select_ln45_110_fu_1014_p3;
wire   [15:0] select_ln45_111_fu_1058_p3;
wire   [15:0] select_ln45_112_fu_1102_p3;
wire   [15:0] select_ln45_113_fu_1146_p3;
wire   [15:0] select_ln45_114_fu_1190_p3;
wire   [15:0] select_ln45_115_fu_1234_p3;
wire   [15:0] select_ln45_116_fu_1278_p3;
wire   [15:0] select_ln45_117_fu_1322_p3;
wire   [15:0] select_ln45_118_fu_1366_p3;
wire   [15:0] select_ln45_119_fu_1410_p3;
wire   [15:0] select_ln45_120_fu_1454_p3;
wire   [15:0] select_ln45_121_fu_1498_p3;
wire   [15:0] select_ln45_122_fu_1542_p3;
wire   [15:0] select_ln45_123_fu_1586_p3;
wire   [15:0] select_ln45_124_fu_1630_p3;
wire    ap_ce_reg;

assign ap_ready = 1'b1;

assign icmp_ln46_100_fu_560_p2 = ((tmp_95_fu_550_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_101_fu_604_p2 = ((tmp_96_fu_594_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_102_fu_648_p2 = ((tmp_97_fu_638_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_103_fu_692_p2 = ((tmp_98_fu_682_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_104_fu_736_p2 = ((tmp_99_fu_726_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_105_fu_780_p2 = ((tmp_100_fu_770_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_106_fu_824_p2 = ((tmp_101_fu_814_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_107_fu_868_p2 = ((tmp_102_fu_858_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_108_fu_912_p2 = ((tmp_103_fu_902_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_109_fu_956_p2 = ((tmp_104_fu_946_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_110_fu_1000_p2 = ((tmp_105_fu_990_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_111_fu_1044_p2 = ((tmp_106_fu_1034_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_112_fu_1088_p2 = ((tmp_107_fu_1078_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_113_fu_1132_p2 = ((tmp_108_fu_1122_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_114_fu_1176_p2 = ((tmp_109_fu_1166_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_115_fu_1220_p2 = ((tmp_110_fu_1210_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_116_fu_1264_p2 = ((tmp_111_fu_1254_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_117_fu_1308_p2 = ((tmp_112_fu_1298_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_118_fu_1352_p2 = ((tmp_113_fu_1342_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_119_fu_1396_p2 = ((tmp_114_fu_1386_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_120_fu_1440_p2 = ((tmp_115_fu_1430_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_121_fu_1484_p2 = ((tmp_116_fu_1474_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_122_fu_1528_p2 = ((tmp_117_fu_1518_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_123_fu_1572_p2 = ((tmp_118_fu_1562_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_124_fu_1616_p2 = ((tmp_119_fu_1606_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_95_fu_340_p2 = ((tmp_33_fu_330_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_96_fu_384_p2 = ((tmp_s_fu_374_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_97_fu_428_p2 = ((tmp_92_fu_418_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_98_fu_472_p2 = ((tmp_93_fu_462_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_99_fu_516_p2 = ((tmp_94_fu_506_p4 != 6'd0) ? 1'b1 : 1'b0);

assign icmp_ln46_fu_296_p2 = ((tmp_fu_286_p4 != 6'd0) ? 1'b1 : 1'b0);

assign select_ln45_100_fu_574_p3 = ((icmp_ln45_100_fu_538_p2[0:0] == 1'b1) ? select_ln46_100_fu_566_p3 : 16'd0);

assign select_ln45_101_fu_618_p3 = ((icmp_ln45_101_fu_582_p2[0:0] == 1'b1) ? select_ln46_101_fu_610_p3 : 16'd0);

assign select_ln45_102_fu_662_p3 = ((icmp_ln45_102_fu_626_p2[0:0] == 1'b1) ? select_ln46_102_fu_654_p3 : 16'd0);

assign select_ln45_103_fu_706_p3 = ((icmp_ln45_103_fu_670_p2[0:0] == 1'b1) ? select_ln46_103_fu_698_p3 : 16'd0);

assign select_ln45_104_fu_750_p3 = ((icmp_ln45_104_fu_714_p2[0:0] == 1'b1) ? select_ln46_104_fu_742_p3 : 16'd0);

assign select_ln45_105_fu_794_p3 = ((icmp_ln45_105_fu_758_p2[0:0] == 1'b1) ? select_ln46_105_fu_786_p3 : 16'd0);

assign select_ln45_106_fu_838_p3 = ((icmp_ln45_106_fu_802_p2[0:0] == 1'b1) ? select_ln46_106_fu_830_p3 : 16'd0);

assign select_ln45_107_fu_882_p3 = ((icmp_ln45_107_fu_846_p2[0:0] == 1'b1) ? select_ln46_107_fu_874_p3 : 16'd0);

assign select_ln45_108_fu_926_p3 = ((icmp_ln45_108_fu_890_p2[0:0] == 1'b1) ? select_ln46_108_fu_918_p3 : 16'd0);

assign select_ln45_109_fu_970_p3 = ((icmp_ln45_109_fu_934_p2[0:0] == 1'b1) ? select_ln46_109_fu_962_p3 : 16'd0);

assign select_ln45_110_fu_1014_p3 = ((icmp_ln45_110_fu_978_p2[0:0] == 1'b1) ? select_ln46_110_fu_1006_p3 : 16'd0);

assign select_ln45_111_fu_1058_p3 = ((icmp_ln45_111_fu_1022_p2[0:0] == 1'b1) ? select_ln46_111_fu_1050_p3 : 16'd0);

assign select_ln45_112_fu_1102_p3 = ((icmp_ln45_112_fu_1066_p2[0:0] == 1'b1) ? select_ln46_112_fu_1094_p3 : 16'd0);

assign select_ln45_113_fu_1146_p3 = ((icmp_ln45_113_fu_1110_p2[0:0] == 1'b1) ? select_ln46_113_fu_1138_p3 : 16'd0);

assign select_ln45_114_fu_1190_p3 = ((icmp_ln45_114_fu_1154_p2[0:0] == 1'b1) ? select_ln46_114_fu_1182_p3 : 16'd0);

assign select_ln45_115_fu_1234_p3 = ((icmp_ln45_115_fu_1198_p2[0:0] == 1'b1) ? select_ln46_115_fu_1226_p3 : 16'd0);

assign select_ln45_116_fu_1278_p3 = ((icmp_ln45_116_fu_1242_p2[0:0] == 1'b1) ? select_ln46_116_fu_1270_p3 : 16'd0);

assign select_ln45_117_fu_1322_p3 = ((icmp_ln45_117_fu_1286_p2[0:0] == 1'b1) ? select_ln46_117_fu_1314_p3 : 16'd0);

assign select_ln45_118_fu_1366_p3 = ((icmp_ln45_118_fu_1330_p2[0:0] == 1'b1) ? select_ln46_118_fu_1358_p3 : 16'd0);

assign select_ln45_119_fu_1410_p3 = ((icmp_ln45_119_fu_1374_p2[0:0] == 1'b1) ? select_ln46_119_fu_1402_p3 : 16'd0);

assign select_ln45_120_fu_1454_p3 = ((icmp_ln45_120_fu_1418_p2[0:0] == 1'b1) ? select_ln46_120_fu_1446_p3 : 16'd0);

assign select_ln45_121_fu_1498_p3 = ((icmp_ln45_121_fu_1462_p2[0:0] == 1'b1) ? select_ln46_121_fu_1490_p3 : 16'd0);

assign select_ln45_122_fu_1542_p3 = ((icmp_ln45_122_fu_1506_p2[0:0] == 1'b1) ? select_ln46_122_fu_1534_p3 : 16'd0);

assign select_ln45_123_fu_1586_p3 = ((icmp_ln45_123_fu_1550_p2[0:0] == 1'b1) ? select_ln46_123_fu_1578_p3 : 16'd0);

assign select_ln45_124_fu_1630_p3 = ((icmp_ln45_124_fu_1594_p2[0:0] == 1'b1) ? select_ln46_124_fu_1622_p3 : 16'd0);

assign select_ln45_95_fu_354_p3 = ((icmp_ln45_95_fu_318_p2[0:0] == 1'b1) ? select_ln46_95_fu_346_p3 : 16'd0);

assign select_ln45_96_fu_398_p3 = ((icmp_ln45_96_fu_362_p2[0:0] == 1'b1) ? select_ln46_96_fu_390_p3 : 16'd0);

assign select_ln45_97_fu_442_p3 = ((icmp_ln45_97_fu_406_p2[0:0] == 1'b1) ? select_ln46_97_fu_434_p3 : 16'd0);

assign select_ln45_98_fu_486_p3 = ((icmp_ln45_98_fu_450_p2[0:0] == 1'b1) ? select_ln46_98_fu_478_p3 : 16'd0);

assign select_ln45_99_fu_530_p3 = ((icmp_ln45_99_fu_494_p2[0:0] == 1'b1) ? select_ln46_99_fu_522_p3 : 16'd0);

assign select_ln45_fu_310_p3 = ((icmp_ln45_fu_274_p2[0:0] == 1'b1) ? select_ln46_fu_302_p3 : 16'd0);

assign select_ln46_100_fu_566_p3 = ((icmp_ln46_100_fu_560_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_100_fu_544_p2);

assign select_ln46_101_fu_610_p3 = ((icmp_ln46_101_fu_604_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_101_fu_588_p2);

assign select_ln46_102_fu_654_p3 = ((icmp_ln46_102_fu_648_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_102_fu_632_p2);

assign select_ln46_103_fu_698_p3 = ((icmp_ln46_103_fu_692_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_103_fu_676_p2);

assign select_ln46_104_fu_742_p3 = ((icmp_ln46_104_fu_736_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_104_fu_720_p2);

assign select_ln46_105_fu_786_p3 = ((icmp_ln46_105_fu_780_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_105_fu_764_p2);

assign select_ln46_106_fu_830_p3 = ((icmp_ln46_106_fu_824_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_106_fu_808_p2);

assign select_ln46_107_fu_874_p3 = ((icmp_ln46_107_fu_868_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_107_fu_852_p2);

assign select_ln46_108_fu_918_p3 = ((icmp_ln46_108_fu_912_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_108_fu_896_p2);

assign select_ln46_109_fu_962_p3 = ((icmp_ln46_109_fu_956_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_109_fu_940_p2);

assign select_ln46_110_fu_1006_p3 = ((icmp_ln46_110_fu_1000_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_110_fu_984_p2);

assign select_ln46_111_fu_1050_p3 = ((icmp_ln46_111_fu_1044_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_111_fu_1028_p2);

assign select_ln46_112_fu_1094_p3 = ((icmp_ln46_112_fu_1088_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_112_fu_1072_p2);

assign select_ln46_113_fu_1138_p3 = ((icmp_ln46_113_fu_1132_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_113_fu_1116_p2);

assign select_ln46_114_fu_1182_p3 = ((icmp_ln46_114_fu_1176_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_114_fu_1160_p2);

assign select_ln46_115_fu_1226_p3 = ((icmp_ln46_115_fu_1220_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_115_fu_1204_p2);

assign select_ln46_116_fu_1270_p3 = ((icmp_ln46_116_fu_1264_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_116_fu_1248_p2);

assign select_ln46_117_fu_1314_p3 = ((icmp_ln46_117_fu_1308_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_117_fu_1292_p2);

assign select_ln46_118_fu_1358_p3 = ((icmp_ln46_118_fu_1352_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_118_fu_1336_p2);

assign select_ln46_119_fu_1402_p3 = ((icmp_ln46_119_fu_1396_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_119_fu_1380_p2);

assign select_ln46_120_fu_1446_p3 = ((icmp_ln46_120_fu_1440_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_120_fu_1424_p2);

assign select_ln46_121_fu_1490_p3 = ((icmp_ln46_121_fu_1484_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_121_fu_1468_p2);

assign select_ln46_122_fu_1534_p3 = ((icmp_ln46_122_fu_1528_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_122_fu_1512_p2);

assign select_ln46_123_fu_1578_p3 = ((icmp_ln46_123_fu_1572_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_123_fu_1556_p2);

assign select_ln46_124_fu_1622_p3 = ((icmp_ln46_124_fu_1616_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_124_fu_1600_p2);

assign select_ln46_95_fu_346_p3 = ((icmp_ln46_95_fu_340_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_95_fu_324_p2);

assign select_ln46_96_fu_390_p3 = ((icmp_ln46_96_fu_384_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_96_fu_368_p2);

assign select_ln46_97_fu_434_p3 = ((icmp_ln46_97_fu_428_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_97_fu_412_p2);

assign select_ln46_98_fu_478_p3 = ((icmp_ln46_98_fu_472_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_98_fu_456_p2);

assign select_ln46_99_fu_522_p3 = ((icmp_ln46_99_fu_516_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_99_fu_500_p2);

assign select_ln46_fu_302_p3 = ((icmp_ln46_fu_296_p2[0:0] == 1'b1) ? 16'd65535 : shl_ln46_fu_280_p2);

assign shl_ln46_100_fu_544_p2 = data_6_val << 16'd6;

assign shl_ln46_101_fu_588_p2 = data_7_val << 16'd6;

assign shl_ln46_102_fu_632_p2 = data_8_val << 16'd6;

assign shl_ln46_103_fu_676_p2 = data_9_val << 16'd6;

assign shl_ln46_104_fu_720_p2 = data_10_val << 16'd6;

assign shl_ln46_105_fu_764_p2 = data_12_val << 16'd6;

assign shl_ln46_106_fu_808_p2 = data_13_val << 16'd6;

assign shl_ln46_107_fu_852_p2 = data_14_val << 16'd6;

assign shl_ln46_108_fu_896_p2 = data_15_val << 16'd6;

assign shl_ln46_109_fu_940_p2 = data_16_val << 16'd6;

assign shl_ln46_110_fu_984_p2 = data_17_val << 16'd6;

assign shl_ln46_111_fu_1028_p2 = data_18_val << 16'd6;

assign shl_ln46_112_fu_1072_p2 = data_19_val << 16'd6;

assign shl_ln46_113_fu_1116_p2 = data_20_val << 16'd6;

assign shl_ln46_114_fu_1160_p2 = data_21_val << 16'd6;

assign shl_ln46_115_fu_1204_p2 = data_22_val << 16'd6;

assign shl_ln46_116_fu_1248_p2 = data_23_val << 16'd6;

assign shl_ln46_117_fu_1292_p2 = data_24_val << 16'd6;

assign shl_ln46_118_fu_1336_p2 = data_25_val << 16'd6;

assign shl_ln46_119_fu_1380_p2 = data_26_val << 16'd6;

assign shl_ln46_120_fu_1424_p2 = data_27_val << 16'd6;

assign shl_ln46_121_fu_1468_p2 = data_28_val << 16'd6;

assign shl_ln46_122_fu_1512_p2 = data_29_val << 16'd6;

assign shl_ln46_123_fu_1556_p2 = data_30_val << 16'd6;

assign shl_ln46_124_fu_1600_p2 = data_31_val << 16'd6;

assign shl_ln46_95_fu_324_p2 = data_1_val << 16'd6;

assign shl_ln46_96_fu_368_p2 = data_2_val << 16'd6;

assign shl_ln46_97_fu_412_p2 = data_3_val << 16'd6;

assign shl_ln46_98_fu_456_p2 = data_4_val << 16'd6;

assign shl_ln46_99_fu_500_p2 = data_5_val << 16'd6;

assign shl_ln46_fu_280_p2 = data_0_val << 16'd6;

assign tmp_100_fu_770_p4 = {{data_12_val[15:10]}};

assign tmp_101_fu_814_p4 = {{data_13_val[15:10]}};

assign tmp_102_fu_858_p4 = {{data_14_val[15:10]}};

assign tmp_103_fu_902_p4 = {{data_15_val[15:10]}};

assign tmp_104_fu_946_p4 = {{data_16_val[15:10]}};

assign tmp_105_fu_990_p4 = {{data_17_val[15:10]}};

assign tmp_106_fu_1034_p4 = {{data_18_val[15:10]}};

assign tmp_107_fu_1078_p4 = {{data_19_val[15:10]}};

assign tmp_108_fu_1122_p4 = {{data_20_val[15:10]}};

assign tmp_109_fu_1166_p4 = {{data_21_val[15:10]}};

assign tmp_110_fu_1210_p4 = {{data_22_val[15:10]}};

assign tmp_111_fu_1254_p4 = {{data_23_val[15:10]}};

assign tmp_112_fu_1298_p4 = {{data_24_val[15:10]}};

assign tmp_113_fu_1342_p4 = {{data_25_val[15:10]}};

assign tmp_114_fu_1386_p4 = {{data_26_val[15:10]}};

assign tmp_115_fu_1430_p4 = {{data_27_val[15:10]}};

assign tmp_116_fu_1474_p4 = {{data_28_val[15:10]}};

assign tmp_117_fu_1518_p4 = {{data_29_val[15:10]}};

assign tmp_118_fu_1562_p4 = {{data_30_val[15:10]}};

assign tmp_119_fu_1606_p4 = {{data_31_val[15:10]}};

assign tmp_33_fu_330_p4 = {{data_1_val[15:10]}};

assign tmp_92_fu_418_p4 = {{data_3_val[15:10]}};

assign tmp_93_fu_462_p4 = {{data_4_val[15:10]}};

assign tmp_94_fu_506_p4 = {{data_5_val[15:10]}};

assign tmp_95_fu_550_p4 = {{data_6_val[15:10]}};

assign tmp_96_fu_594_p4 = {{data_7_val[15:10]}};

assign tmp_97_fu_638_p4 = {{data_8_val[15:10]}};

assign tmp_98_fu_682_p4 = {{data_9_val[15:10]}};

assign tmp_99_fu_726_p4 = {{data_10_val[15:10]}};

assign tmp_fu_286_p4 = {{data_0_val[15:10]}};

assign tmp_s_fu_374_p4 = {{data_2_val[15:10]}};

assign ap_return_0 = select_ln45_fu_310_p3;

assign ap_return_1 = select_ln45_95_fu_354_p3;

assign ap_return_10 = select_ln45_104_fu_750_p3;

assign ap_return_11 = select_ln45_105_fu_794_p3;

assign ap_return_12 = select_ln45_106_fu_838_p3;

assign ap_return_13 = select_ln45_107_fu_882_p3;

assign ap_return_14 = select_ln45_108_fu_926_p3;

assign ap_return_15 = select_ln45_109_fu_970_p3;

assign ap_return_16 = select_ln45_110_fu_1014_p3;

assign ap_return_17 = select_ln45_111_fu_1058_p3;

assign ap_return_18 = select_ln45_112_fu_1102_p3;

assign ap_return_19 = select_ln45_113_fu_1146_p3;

assign ap_return_2 = select_ln45_96_fu_398_p3;

assign ap_return_20 = select_ln45_114_fu_1190_p3;

assign ap_return_21 = select_ln45_115_fu_1234_p3;

assign ap_return_22 = select_ln45_116_fu_1278_p3;

assign ap_return_23 = select_ln45_117_fu_1322_p3;

assign ap_return_24 = select_ln45_118_fu_1366_p3;

assign ap_return_25 = select_ln45_119_fu_1410_p3;

assign ap_return_26 = select_ln45_120_fu_1454_p3;

assign ap_return_27 = select_ln45_121_fu_1498_p3;

assign ap_return_28 = select_ln45_122_fu_1542_p3;

assign ap_return_29 = select_ln45_123_fu_1586_p3;

assign ap_return_3 = select_ln45_97_fu_442_p3;

assign ap_return_30 = select_ln45_124_fu_1630_p3;

assign ap_return_4 = select_ln45_98_fu_486_p3;

assign ap_return_5 = select_ln45_99_fu_530_p3;

assign ap_return_6 = select_ln45_100_fu_574_p3;

assign ap_return_7 = select_ln45_101_fu_618_p3;

assign ap_return_8 = select_ln45_102_fu_662_p3;

assign ap_return_9 = select_ln45_103_fu_706_p3;

assign icmp_ln45_100_fu_538_p2 = (($signed(data_6_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_101_fu_582_p2 = (($signed(data_7_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_102_fu_626_p2 = (($signed(data_8_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_103_fu_670_p2 = (($signed(data_9_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_104_fu_714_p2 = (($signed(data_10_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_105_fu_758_p2 = (($signed(data_12_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_106_fu_802_p2 = (($signed(data_13_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_107_fu_846_p2 = (($signed(data_14_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_108_fu_890_p2 = (($signed(data_15_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_109_fu_934_p2 = (($signed(data_16_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_110_fu_978_p2 = (($signed(data_17_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_111_fu_1022_p2 = (($signed(data_18_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_112_fu_1066_p2 = (($signed(data_19_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_113_fu_1110_p2 = (($signed(data_20_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_114_fu_1154_p2 = (($signed(data_21_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_115_fu_1198_p2 = (($signed(data_22_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_116_fu_1242_p2 = (($signed(data_23_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_117_fu_1286_p2 = (($signed(data_24_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_118_fu_1330_p2 = (($signed(data_25_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_119_fu_1374_p2 = (($signed(data_26_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_120_fu_1418_p2 = (($signed(data_27_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_121_fu_1462_p2 = (($signed(data_28_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_122_fu_1506_p2 = (($signed(data_29_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_123_fu_1550_p2 = (($signed(data_30_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_124_fu_1594_p2 = (($signed(data_31_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_95_fu_318_p2 = (($signed(data_1_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_96_fu_362_p2 = (($signed(data_2_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_97_fu_406_p2 = (($signed(data_3_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_98_fu_450_p2 = (($signed(data_4_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_99_fu_494_p2 = (($signed(data_5_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

assign icmp_ln45_fu_274_p2 = (($signed(data_0_val) > $signed(16'd0)) ? 1'b1 : 1'b0);

endmodule //ParamEst_NN_relu_ap_fixed_ap_ufixed_16_0_4_0_0_PARAMEST_NN_relu_config11_s

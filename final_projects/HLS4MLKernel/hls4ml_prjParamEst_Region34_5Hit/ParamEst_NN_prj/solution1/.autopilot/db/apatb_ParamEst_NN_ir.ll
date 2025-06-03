; ModuleID = '/home/pusharma/EF_Tracking/TrackMLTraining_HLS/Jupyter_Notebooks/HLSModels/hls4ml_prjParamEst_Region34_5Hit/ParamEst_NN_prj/solution1/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

%"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>" = type { %"struct.ap_fixed_base<16, 1, true, AP_TRN, AP_WRAP, 0>" }
%"struct.ap_fixed_base<16, 1, true, AP_TRN, AP_WRAP, 0>" = type { %"struct.ssdm_int<16, true>" }
%"struct.ssdm_int<16, true>" = type { i16 }
%"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>" = type { %"struct.ap_fixed_base<8, 1, true, AP_RND_CONV, AP_SAT, 0>" }
%"struct.ap_fixed_base<8, 1, true, AP_RND_CONV, AP_SAT, 0>" = type { %"class.std::ios_base::Init" }
%"class.std::ios_base::Init" = type { i8 }

; Function Attrs: inaccessiblemem_or_argmemonly noinline
define void @apatb_ParamEst_NN_ir(%"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="15" %input_1, %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"* noalias nocapture nonnull "fpga.decayed.dim.hint"="5" "partition" %PARAMEST_NN_layer14_out) local_unnamed_addr #0 {
entry:
  %input_1_copy5 = alloca i240, align 512
  %PARAMEST_NN_layer14_out_copy_0 = alloca i8, align 512
  %PARAMEST_NN_layer14_out_copy_1 = alloca i8, align 512
  %PARAMEST_NN_layer14_out_copy_2 = alloca i8, align 512
  %PARAMEST_NN_layer14_out_copy_3 = alloca i8, align 512
  %PARAMEST_NN_layer14_out_copy_4 = alloca i8, align 512
  %0 = bitcast %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"* %input_1 to [15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]*
  %1 = bitcast %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"* %PARAMEST_NN_layer14_out to [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]*
  call void @copy_in([15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* nonnull %0, i240* nonnull align 512 %input_1_copy5, [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* nonnull %1, i8* nonnull align 512 %PARAMEST_NN_layer14_out_copy_0, i8* nonnull align 512 %PARAMEST_NN_layer14_out_copy_1, i8* nonnull align 512 %PARAMEST_NN_layer14_out_copy_2, i8* nonnull align 512 %PARAMEST_NN_layer14_out_copy_3, i8* nonnull align 512 %PARAMEST_NN_layer14_out_copy_4)
  call void @apatb_ParamEst_NN_hw(i240* %input_1_copy5, i8* %PARAMEST_NN_layer14_out_copy_0, i8* %PARAMEST_NN_layer14_out_copy_1, i8* %PARAMEST_NN_layer14_out_copy_2, i8* %PARAMEST_NN_layer14_out_copy_3, i8* %PARAMEST_NN_layer14_out_copy_4)
  call void @copy_back([15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* %0, i240* %input_1_copy5, [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* %1, i8* %PARAMEST_NN_layer14_out_copy_0, i8* %PARAMEST_NN_layer14_out_copy_1, i8* %PARAMEST_NN_layer14_out_copy_2, i8* %PARAMEST_NN_layer14_out_copy_3, i8* %PARAMEST_NN_layer14_out_copy_4)
  ret void
}

; Function Attrs: nounwind
declare void @llvm.assume(i1) #1

; Function Attrs: argmemonly noinline norecurse
define void @"arraycpy_hls.p0a5struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"(i8* nocapture "orig.arg.no"="0" "unpacked"="0.0.0" %dst_0, i8* nocapture "orig.arg.no"="0" "unpacked"="0.0.1" %dst_1, i8* nocapture "orig.arg.no"="0" "unpacked"="0.0.2" %dst_2, i8* nocapture "orig.arg.no"="0" "unpacked"="0.0.3" %dst_3, i8* nocapture "orig.arg.no"="0" "unpacked"="0.0.4" %dst_4, [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* readonly "orig.arg.no"="1" "unpacked"="1" %src, i64 "orig.arg.no"="2" "unpacked"="2" %num) #2 {
entry:
  %0 = icmp eq [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %dst.addr.0.0.06.exit, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %dst.addr.0.0.06.exit ]
  %1 = trunc i64 %for.loop.idx2 to i3
  %src.addr.0.0.05 = getelementptr [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"], [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* %src, i64 0, i64 %for.loop.idx2, i32 0, i32 0, i32 0
  %2 = load i8, i8* %src.addr.0.0.05, align 1
  switch i3 %1, label %dst.addr.0.0.06.case.4 [
    i3 0, label %dst.addr.0.0.06.case.0
    i3 1, label %dst.addr.0.0.06.case.1
    i3 2, label %dst.addr.0.0.06.case.2
    i3 3, label %dst.addr.0.0.06.case.3
  ]

dst.addr.0.0.06.case.0:                           ; preds = %for.loop
  store i8 %2, i8* %dst_0, align 1
  br label %dst.addr.0.0.06.exit

dst.addr.0.0.06.case.1:                           ; preds = %for.loop
  store i8 %2, i8* %dst_1, align 1
  br label %dst.addr.0.0.06.exit

dst.addr.0.0.06.case.2:                           ; preds = %for.loop
  store i8 %2, i8* %dst_2, align 1
  br label %dst.addr.0.0.06.exit

dst.addr.0.0.06.case.3:                           ; preds = %for.loop
  store i8 %2, i8* %dst_3, align 1
  br label %dst.addr.0.0.06.exit

dst.addr.0.0.06.case.4:                           ; preds = %for.loop
  %3 = icmp eq i3 %1, -4
  call void @llvm.assume(i1 %3)
  store i8 %2, i8* %dst_4, align 1
  br label %dst.addr.0.0.06.exit

dst.addr.0.0.06.exit:                             ; preds = %dst.addr.0.0.06.case.4, %dst.addr.0.0.06.case.3, %dst.addr.0.0.06.case.2, %dst.addr.0.0.06.case.1, %dst.addr.0.0.06.case.0
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %dst.addr.0.0.06.exit, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @"onebyonecpy_hls.p0a5struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"(i8* noalias nocapture align 512 "orig.arg.no"="0" "unpacked"="0.0.0" %dst_0, i8* noalias nocapture align 512 "orig.arg.no"="0" "unpacked"="0.0.1" %dst_1, i8* noalias nocapture align 512 "orig.arg.no"="0" "unpacked"="0.0.2" %dst_2, i8* noalias nocapture align 512 "orig.arg.no"="0" "unpacked"="0.0.3" %dst_3, i8* noalias nocapture align 512 "orig.arg.no"="0" "unpacked"="0.0.4" %dst_4, [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* noalias readonly "orig.arg.no"="1" "unpacked"="1" %src) #3 {
entry:
  %0 = icmp eq [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @"arraycpy_hls.p0a5struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"(i8* %dst_0, i8* %dst_1, i8* %dst_2, i8* %dst_3, i8* %dst_4, [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* nonnull %src, i64 5)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define void @"arraycpy_hls.p0a5struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>.91"([5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* "orig.arg.no"="0" "unpacked"="0" %dst, i8* nocapture readonly "orig.arg.no"="1" "unpacked"="1.0.0" %src_0, i8* nocapture readonly "orig.arg.no"="1" "unpacked"="1.0.1" %src_1, i8* nocapture readonly "orig.arg.no"="1" "unpacked"="1.0.2" %src_2, i8* nocapture readonly "orig.arg.no"="1" "unpacked"="1.0.3" %src_3, i8* nocapture readonly "orig.arg.no"="1" "unpacked"="1.0.4" %src_4, i64 "orig.arg.no"="2" "unpacked"="2" %num) #2 {
entry:
  %0 = icmp eq [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %src.addr.0.0.05.exit, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %src.addr.0.0.05.exit ]
  %1 = trunc i64 %for.loop.idx2 to i3
  %dst.addr.0.0.06 = getelementptr [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"], [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* %dst, i64 0, i64 %for.loop.idx2, i32 0, i32 0, i32 0
  switch i3 %1, label %src.addr.0.0.05.case.4 [
    i3 0, label %src.addr.0.0.05.case.0
    i3 1, label %src.addr.0.0.05.case.1
    i3 2, label %src.addr.0.0.05.case.2
    i3 3, label %src.addr.0.0.05.case.3
  ]

src.addr.0.0.05.case.0:                           ; preds = %for.loop
  %_0 = load i8, i8* %src_0, align 1
  br label %src.addr.0.0.05.exit

src.addr.0.0.05.case.1:                           ; preds = %for.loop
  %_1 = load i8, i8* %src_1, align 1
  br label %src.addr.0.0.05.exit

src.addr.0.0.05.case.2:                           ; preds = %for.loop
  %_2 = load i8, i8* %src_2, align 1
  br label %src.addr.0.0.05.exit

src.addr.0.0.05.case.3:                           ; preds = %for.loop
  %_3 = load i8, i8* %src_3, align 1
  br label %src.addr.0.0.05.exit

src.addr.0.0.05.case.4:                           ; preds = %for.loop
  %2 = icmp eq i3 %1, -4
  call void @llvm.assume(i1 %2)
  %_4 = load i8, i8* %src_4, align 1
  br label %src.addr.0.0.05.exit

src.addr.0.0.05.exit:                             ; preds = %src.addr.0.0.05.case.4, %src.addr.0.0.05.case.3, %src.addr.0.0.05.case.2, %src.addr.0.0.05.case.1, %src.addr.0.0.05.case.0
  %3 = phi i8 [ %_0, %src.addr.0.0.05.case.0 ], [ %_1, %src.addr.0.0.05.case.1 ], [ %_2, %src.addr.0.0.05.case.2 ], [ %_3, %src.addr.0.0.05.case.3 ], [ %_4, %src.addr.0.0.05.case.4 ]
  store i8 %3, i8* %dst.addr.0.0.06, align 1
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %src.addr.0.0.05.exit, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @"onebyonecpy_hls.p0a5struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>.88"([5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* noalias "orig.arg.no"="0" "unpacked"="0" %dst, i8* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.0" %src_0, i8* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.1" %src_1, i8* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.2" %src_2, i8* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.3" %src_3, i8* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.4" %src_4) #3 {
entry:
  %0 = icmp eq [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @"arraycpy_hls.p0a5struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>.91"([5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* nonnull %dst, i8* %src_0, i8* %src_1, i8* %src_2, i8* %src_3, i8* %src_4, i64 5)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define void @"arraycpy_hls.p0a15struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>.101"(i240* nocapture "orig.arg.no"="0" "unpacked"="0.0" %dst, i64 %dst_shift, [15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* readonly "orig.arg.no"="1" "unpacked"="1" %src, i64 "orig.arg.no"="2" "unpacked"="2" %num) #2 {
entry:
  %0 = icmp eq [15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %src.addr.0.0.05 = getelementptr [15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"], [15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* %src, i64 0, i64 %for.loop.idx2, i32 0, i32 0, i32 0
  %1 = mul i64 16, %for.loop.idx2
  %2 = add i64 %dst_shift, %1
  %3 = load i16, i16* %src.addr.0.0.05, align 2
  %4 = load i240, i240* %dst, align 32
  %5 = zext i64 %2 to i240
  %6 = shl i240 65535, %5
  %7 = zext i16 %3 to i240
  %8 = shl i240 %7, %5
  %thr.xor1 = xor i240 %6, -1
  %thr.and2 = and i240 %4, %thr.xor1
  %thr.or3 = or i240 %thr.and2, %8
  store i240 %thr.or3, i240* %dst, align 32
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @"onebyonecpy_hls.p0a15struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>.98"(i240* noalias nocapture align 512 "orig.arg.no"="0" "unpacked"="0.0" %dst, [15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* noalias readonly "orig.arg.no"="1" "unpacked"="1" %src) #3 {
entry:
  %0 = icmp eq [15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @"arraycpy_hls.p0a15struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>.101"(i240* %dst, i64 0, [15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* nonnull %src, i64 15)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @copy_in([15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* noalias readonly "orig.arg.no"="0" "unpacked"="0", i240* noalias nocapture align 512 "orig.arg.no"="1" "unpacked"="1.0", [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* noalias readonly "orig.arg.no"="2" "unpacked"="2", i8* noalias nocapture align 512 "orig.arg.no"="3" "unpacked"="3.0.0" %_0, i8* noalias nocapture align 512 "orig.arg.no"="3" "unpacked"="3.0.1" %_1, i8* noalias nocapture align 512 "orig.arg.no"="3" "unpacked"="3.0.2" %_2, i8* noalias nocapture align 512 "orig.arg.no"="3" "unpacked"="3.0.3" %_3, i8* noalias nocapture align 512 "orig.arg.no"="3" "unpacked"="3.0.4" %_4) #4 {
entry:
  call void @"onebyonecpy_hls.p0a15struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>.98"(i240* align 512 %1, [15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* %0)
  call void @"onebyonecpy_hls.p0a5struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"(i8* align 512 %_0, i8* align 512 %_1, i8* align 512 %_2, i8* align 512 %_3, i8* align 512 %_4, [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* %2)
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define void @"arraycpy_hls.p0a15struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"([15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* "orig.arg.no"="0" "unpacked"="0" %dst, i240* nocapture readonly "orig.arg.no"="1" "unpacked"="1.0" %src, i64 %src_shift, i64 "orig.arg.no"="2" "unpacked"="2" %num) #2 {
entry:
  %0 = icmp eq [15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %for.loop ]
  %1 = mul i64 16, %for.loop.idx2
  %2 = add i64 %src_shift, %1
  %dst.addr.0.0.06 = getelementptr [15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"], [15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* %dst, i64 0, i64 %for.loop.idx2, i32 0, i32 0, i32 0
  %3 = load i240, i240* %src, align 32
  %4 = zext i64 %2 to i240
  %5 = lshr i240 %3, %4
  %6 = trunc i240 %5 to i16
  store i16 %6, i16* %dst.addr.0.0.06, align 2
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %for.loop, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @"onebyonecpy_hls.p0a15struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"([15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* noalias "orig.arg.no"="0" "unpacked"="0" %dst, i240* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0" %src) #3 {
entry:
  %0 = icmp eq [15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @"arraycpy_hls.p0a15struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"([15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* nonnull %dst, i240* %src, i64 0, i64 15)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @copy_out([15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* noalias "orig.arg.no"="0" "unpacked"="0", i240* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0", [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* noalias "orig.arg.no"="2" "unpacked"="2", i8* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.0" %_0, i8* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.1" %_1, i8* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.2" %_2, i8* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.3" %_3, i8* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.4" %_4) #5 {
entry:
  call void @"onebyonecpy_hls.p0a15struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"([15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* %0, i240* align 512 %1)
  call void @"onebyonecpy_hls.p0a5struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>.88"([5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* %2, i8* align 512 %_0, i8* align 512 %_1, i8* align 512 %_2, i8* align 512 %_3, i8* align 512 %_4)
  ret void
}

declare void @apatb_ParamEst_NN_hw(i240*, i8*, i8*, i8*, i8*, i8*)

; Function Attrs: argmemonly noinline norecurse
define internal void @copy_back([15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* noalias "orig.arg.no"="0" "unpacked"="0", i240* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0", [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* noalias "orig.arg.no"="2" "unpacked"="2", i8* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.0" %_0, i8* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.1" %_1, i8* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.2" %_2, i8* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.3" %_3, i8* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.4" %_4) #5 {
entry:
  call void @"onebyonecpy_hls.p0a5struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>.88"([5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* %2, i8* align 512 %_0, i8* align 512 %_1, i8* align 512 %_2, i8* align 512 %_3, i8* align 512 %_4)
  ret void
}

define void @ParamEst_NN_hw_stub_wrapper(i240*, i8*, i8*, i8*, i8*, i8*) #6 {
entry:
  %6 = alloca [15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]
  %7 = alloca [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]
  call void @copy_out([15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* %6, i240* %0, [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* %7, i8* %1, i8* %2, i8* %3, i8* %4, i8* %5)
  %8 = bitcast [15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* %6 to %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"*
  %9 = bitcast [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* %7 to %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"*
  call void @ParamEst_NN_hw_stub(%"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"* %8, %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"* %9)
  call void @copy_in([15 x %"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"]* %6, i240* %0, [5 x %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"]* %7, i8* %1, i8* %2, i8* %3, i8* %4, i8* %5)
  ret void
}

declare void @ParamEst_NN_hw_stub(%"struct.ap_fixed<16, 1, AP_TRN, AP_WRAP, 0>"*, %"struct.ap_fixed<8, 1, AP_RND_CONV, AP_SAT, 0>"*)

attributes #0 = { inaccessiblemem_or_argmemonly noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { nounwind }
attributes #2 = { argmemonly noinline norecurse "fpga.wrapper.func"="arraycpy_hls" }
attributes #3 = { argmemonly noinline norecurse "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #4 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyin" }
attributes #5 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyout" }
attributes #6 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}
!datalayout.transforms.on.top = !{!5}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
!5 = !{!6, !8, !10}
!6 = !{!7}
!7 = !{!"1.0", [5 x i8]* null}
!8 = !{!9}
!9 = !{!"array_partition", !"type=Complete", !"dim=1"}
!10 = !{!11, !12, !13, !14, !15}
!11 = !{!"1.0.0", i8* null}
!12 = !{!"1.0.1", i8* null}
!13 = !{!"1.0.2", i8* null}
!14 = !{!"1.0.3", i8* null}
!15 = !{!"1.0.4", i8* null}

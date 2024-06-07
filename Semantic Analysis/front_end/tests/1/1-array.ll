; ModuleID = '1-array.c'
source_filename = "1-array.c"
target datalayout = "e-m:o-i64:64-i128:128-n32:64-S128"
target triple = "arm64-apple-macosx14.0.0"

@__const.main.a = private unnamed_addr constant [4 x [2 x i32]] [[2 x i32] [i32 1, i32 2], [2 x i32] [i32 3, i32 4], [2 x i32] zeroinitializer, [2 x i32] [i32 7, i32 0]], align 4
@__const.main.c = private unnamed_addr constant [4 x [2 x i32]] [[2 x i32] [i32 1, i32 2], [2 x i32] [i32 3, i32 4], [2 x i32] [i32 5, i32 6], [2 x i32] [i32 7, i32 8]], align 4
@__const.main.d = private unnamed_addr constant [4 x [2 x i32]] [[2 x i32] [i32 1, i32 2], [2 x i32] [i32 3, i32 0], [2 x i32] [i32 5, i32 0], [2 x i32] [i32 7, i32 8]], align 4

; Function Attrs: mustprogress noinline nounwind optnone ssp uwtable(sync)
define noundef i32 @_Z4funciii(i32 noundef %0, i32 noundef %1, i32 noundef %2) #0 {
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  store i32 %0, ptr %4, align 4
  store i32 %1, ptr %5, align 4
  store i32 %2, ptr %6, align 4
  %7 = load i32, ptr %6, align 4
  ret i32 %7
}

; Function Attrs: mustprogress noinline norecurse nounwind optnone ssp uwtable(sync)
define noundef i32 @main() #1 {
  %1 = alloca i32, align 4
  %2 = alloca [4 x [2 x i32]], align 4
  %3 = alloca i32, align 4
  %4 = alloca [4 x [2 x i32]], align 4
  %5 = alloca [4 x [2 x i32]], align 4
  %6 = alloca [4 x [2 x i32]], align 4
  %7 = alloca [4 x [2 x [1 x i32]]], align 4
  store i32 0, ptr %1, align 4
  call void @llvm.memcpy.p0.p0.i64(ptr align 4 %2, ptr align 4 @__const.main.a, i64 32, i1 false)
  store i32 3, ptr %3, align 4
  call void @llvm.memset.p0.i64(ptr align 4 %4, i8 0, i64 32, i1 false)
  call void @llvm.memcpy.p0.p0.i64(ptr align 4 %5, ptr align 4 @__const.main.c, i64 32, i1 false)
  call void @llvm.memcpy.p0.p0.i64(ptr align 4 %6, ptr align 4 @__const.main.d, i64 32, i1 false)
  %8 = getelementptr inbounds [4 x [2 x [1 x i32]]], ptr %7, i64 0, i64 0
  %9 = getelementptr inbounds [2 x [1 x i32]], ptr %8, i64 0, i64 0
  %10 = getelementptr inbounds [1 x i32], ptr %9, i64 0, i64 0
  %11 = getelementptr inbounds [4 x [2 x i32]], ptr %6, i64 0, i64 2
  %12 = getelementptr inbounds [2 x i32], ptr %11, i64 0, i64 1
  %13 = load i32, ptr %12, align 4
  store i32 %13, ptr %10, align 4
  %14 = getelementptr inbounds [1 x i32], ptr %9, i64 1
  %15 = getelementptr inbounds [1 x i32], ptr %14, i64 0, i64 0
  %16 = getelementptr inbounds [4 x [2 x i32]], ptr %5, i64 0, i64 2
  %17 = getelementptr inbounds [2 x i32], ptr %16, i64 0, i64 1
  %18 = load i32, ptr %17, align 4
  store i32 %18, ptr %15, align 4
  %19 = getelementptr inbounds [2 x [1 x i32]], ptr %8, i64 1
  %20 = getelementptr inbounds [2 x [1 x i32]], ptr %19, i64 0, i64 0
  %21 = getelementptr inbounds [1 x i32], ptr %20, i64 0, i64 0
  store i32 3, ptr %21, align 4
  %22 = getelementptr inbounds [1 x i32], ptr %20, i64 1
  %23 = getelementptr inbounds [1 x i32], ptr %22, i64 0, i64 0
  store i32 4, ptr %23, align 4
  %24 = getelementptr inbounds [2 x [1 x i32]], ptr %19, i64 1
  %25 = getelementptr inbounds [2 x [1 x i32]], ptr %24, i64 0, i64 0
  %26 = getelementptr inbounds [1 x i32], ptr %25, i64 0, i64 0
  store i32 5, ptr %26, align 4
  %27 = getelementptr inbounds [1 x i32], ptr %25, i64 1
  %28 = getelementptr inbounds [1 x i32], ptr %27, i64 0, i64 0
  store i32 6, ptr %28, align 4
  %29 = getelementptr inbounds [2 x [1 x i32]], ptr %24, i64 1
  %30 = getelementptr inbounds [2 x [1 x i32]], ptr %29, i64 0, i64 0
  %31 = getelementptr inbounds [1 x i32], ptr %30, i64 0, i64 0
  store i32 7, ptr %31, align 4
  %32 = getelementptr inbounds [1 x i32], ptr %30, i64 1
  %33 = getelementptr inbounds [1 x i32], ptr %32, i64 0, i64 0
  store i32 8, ptr %33, align 4
  ret i32 0
}

; Function Attrs: nocallback nofree nounwind willreturn memory(argmem: readwrite)
declare void @llvm.memcpy.p0.p0.i64(ptr noalias nocapture writeonly, ptr noalias nocapture readonly, i64, i1 immarg) #2

; Function Attrs: nocallback nofree nounwind willreturn memory(argmem: write)
declare void @llvm.memset.p0.i64(ptr nocapture writeonly, i8, i64, i1 immarg) #3

attributes #0 = { mustprogress noinline nounwind optnone ssp uwtable(sync) "frame-pointer"="non-leaf" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="apple-m1" "target-features"="+aes,+complxnum,+crc,+dotprod,+fp-armv8,+fp16fml,+fullfp16,+jsconv,+lse,+neon,+pauth,+ras,+rcpc,+rdm,+sha2,+sha3,+v8.1a,+v8.2a,+v8.3a,+v8.4a,+v8.5a,+v8a,+zcm,+zcz" }
attributes #1 = { mustprogress noinline norecurse nounwind optnone ssp uwtable(sync) "frame-pointer"="non-leaf" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="apple-m1" "target-features"="+aes,+complxnum,+crc,+dotprod,+fp-armv8,+fp16fml,+fullfp16,+jsconv,+lse,+neon,+pauth,+ras,+rcpc,+rdm,+sha2,+sha3,+v8.1a,+v8.2a,+v8.3a,+v8.4a,+v8.5a,+v8a,+zcm,+zcz" }
attributes #2 = { nocallback nofree nounwind willreturn memory(argmem: readwrite) }
attributes #3 = { nocallback nofree nounwind willreturn memory(argmem: write) }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"uwtable", i32 1}
!3 = !{i32 7, !"frame-pointer", i32 1}
!4 = !{!"Homebrew clang version 18.1.6"}

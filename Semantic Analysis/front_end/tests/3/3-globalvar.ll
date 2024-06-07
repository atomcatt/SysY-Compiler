; ModuleID = './3/3-globalvar.c'
source_filename = "./3/3-globalvar.c"
target datalayout = "e-m:o-i64:64-i128:128-n32:64-S128"
target triple = "arm64-apple-macosx14.0.0"

@a0 = global [3 x i32] zeroinitializer, align 4
@b0 = global [4 x i32] [i32 0, i32 1, i32 0, i32 0], align 4
@c0 = global [7 x i32] [i32 2, i32 8, i32 6, i32 3, i32 9, i32 1, i32 5], align 4
@d0 = global [11 x i32] zeroinitializer, align 4
@e0 = global [2 x i32] [i32 22, i32 33], align 4
@f0 = global [6 x i32] zeroinitializer, align 4
@g0 = global [9 x i32] [i32 85, i32 0, i32 1, i32 29, i32 0, i32 0, i32 0, i32 0, i32 0], align 4
@scj82c9s0j = global i32 9, align 4
@a = global [5 x [3 x i32]] zeroinitializer, align 4
@b = global [5 x [3 x i32]] zeroinitializer, align 4
@c = global [5 x [3 x i32]] [[3 x i32] [i32 1, i32 2, i32 3], [3 x i32] [i32 4, i32 5, i32 6], [3 x i32] [i32 7, i32 8, i32 9], [3 x i32] [i32 10, i32 11, i32 12], [3 x i32] [i32 13, i32 14, i32 15]], align 4
@d = global [5 x [3 x i32]] [[3 x i32] [i32 1, i32 2, i32 3], [3 x i32] [i32 4, i32 5, i32 6], [3 x i32] [i32 7, i32 8, i32 9], [3 x i32] [i32 10, i32 11, i32 12], [3 x i32] [i32 13, i32 14, i32 15]], align 4
@e = global [5 x [3 x i32]] [[3 x i32] [i32 1, i32 2, i32 3], [3 x i32] [i32 4, i32 5, i32 6], [3 x i32] [i32 7, i32 8, i32 9], [3 x i32] [i32 10, i32 11, i32 12], [3 x i32] [i32 13, i32 14, i32 15]], align 4
@f = global [5 x i32] zeroinitializer, align 4
@g = global [5 x [3 x i32]] [[3 x i32] [i32 1, i32 2, i32 3], [3 x i32] [i32 4, i32 0, i32 0], [3 x i32] [i32 7, i32 0, i32 0], [3 x i32] [i32 10, i32 11, i32 12], [3 x i32] zeroinitializer], align 4
@h = global [3 x i32] zeroinitializer, align 4
@i = global [2 x [3 x [4 x i32]]] [[3 x [4 x i32]] [[4 x i32] [i32 1, i32 2, i32 3, i32 4], [4 x i32] [i32 5, i32 0, i32 0, i32 0], [4 x i32] zeroinitializer], [3 x [4 x i32]] zeroinitializer], align 4
@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

; Function Attrs: mustprogress noinline norecurse optnone ssp uwtable(sync)
define noundef i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  %2 = load i32, ptr getelementptr inbounds ([7 x i32], ptr @c0, i64 0, i64 2), align 4
  %3 = load i32, ptr getelementptr inbounds ([9 x i32], ptr @g0, i64 0, i64 3), align 4
  %4 = add nsw i32 %2, %3
  %5 = load i32, ptr @scj82c9s0j, align 4
  %6 = add nsw i32 %4, %5
  %7 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %6)
  ret i32 5
}

declare i32 @printf(ptr noundef, ...) #1

attributes #0 = { mustprogress noinline norecurse optnone ssp uwtable(sync) "frame-pointer"="non-leaf" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="apple-m1" "target-features"="+aes,+complxnum,+crc,+dotprod,+fp-armv8,+fp16fml,+fullfp16,+jsconv,+lse,+neon,+pauth,+ras,+rcpc,+rdm,+sha2,+sha3,+v8.1a,+v8.2a,+v8.3a,+v8.4a,+v8.5a,+v8a,+zcm,+zcz" }
attributes #1 = { "frame-pointer"="non-leaf" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="apple-m1" "target-features"="+aes,+complxnum,+crc,+dotprod,+fp-armv8,+fp16fml,+fullfp16,+jsconv,+lse,+neon,+pauth,+ras,+rcpc,+rdm,+sha2,+sha3,+v8.1a,+v8.2a,+v8.3a,+v8.4a,+v8.5a,+v8a,+zcm,+zcz" }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"uwtable", i32 1}
!3 = !{i32 7, !"frame-pointer", i32 1}
!4 = !{!"Homebrew clang version 18.1.6"}

	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0
	.globl	__Z4funciii                     ## -- Begin function _Z4funciii
	.p2align	4, 0x90
__Z4funciii:                            ## @_Z4funciii
	.cfi_startproc
## %bb.0:
	movl	12(%esp), %eax
	movl	8(%esp), %eax
	movl	4(%esp), %eax
	movl	12(%esp), %eax
	retl
	.cfi_endproc
                                        ## -- End function
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register %ebp
	subl	$184, %esp
	movl	L___stack_chk_guard$non_lazy_ptr, %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	$0, -176(%ebp)
	movups	l___const.main.a+16, %xmm0
	movaps	%xmm0, -24(%ebp)
	movups	l___const.main.a, %xmm0
	movaps	%xmm0, -40(%ebp)
	movl	$3, -172(%ebp)
	xorps	%xmm0, %xmm0
	movaps	%xmm0, -56(%ebp)
	movaps	%xmm0, -72(%ebp)
	movups	l___const.main.c+16, %xmm0
	movaps	%xmm0, -88(%ebp)
	movups	l___const.main.c, %xmm0
	movaps	%xmm0, -104(%ebp)
	movups	l___const.main.d+16, %xmm0
	movaps	%xmm0, -120(%ebp)
	movups	l___const.main.d, %xmm0
	movaps	%xmm0, -136(%ebp)
	movl	-116(%ebp), %eax
	movl	%eax, -168(%ebp)
	movl	-84(%ebp), %eax
	movl	%eax, -164(%ebp)
	movl	$3, -160(%ebp)
	movl	$4, -156(%ebp)
	movl	$5, -152(%ebp)
	movl	$6, -148(%ebp)
	movl	$7, -144(%ebp)
	movl	$8, -140(%ebp)
	movl	L___stack_chk_guard$non_lazy_ptr, %eax
	movl	(%eax), %eax
	movl	-4(%ebp), %ecx
	subl	%ecx, %eax
	jne	LBB1_1
	jmp	LBB1_2
LBB1_1:
	calll	___stack_chk_fail
LBB1_2:
	xorl	%eax, %eax
	addl	$184, %esp
	popl	%ebp
	retl
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__const
	.p2align	2, 0x0                          ## @__const.main.a
l___const.main.a:
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.space	8
	.long	7                               ## 0x7
	.long	0                               ## 0x0

	.p2align	2, 0x0                          ## @__const.main.c
l___const.main.c:
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	4                               ## 0x4
	.long	5                               ## 0x5
	.long	6                               ## 0x6
	.long	7                               ## 0x7
	.long	8                               ## 0x8

	.p2align	2, 0x0                          ## @__const.main.d
l___const.main.d:
	.long	1                               ## 0x1
	.long	2                               ## 0x2
	.long	3                               ## 0x3
	.long	0                               ## 0x0
	.long	5                               ## 0x5
	.long	0                               ## 0x0
	.long	7                               ## 0x7
	.long	8                               ## 0x8

	.section	__IMPORT,__pointers,non_lazy_symbol_pointers
L___stack_chk_guard$non_lazy_ptr:
	.indirect_symbol	___stack_chk_guard
	.long	0

.subsections_via_symbols

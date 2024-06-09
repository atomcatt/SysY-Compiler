.section .rodata
.globl	tt
.align	4
.type	tt, @object
.size	tt, 4
tt:
	.long	4
.align	4
.type	a.1, @object
.size	a.1, 8
a.1:
	.long	1
	.long	2
	.long	3
	.long	4
	.long	0
	.long	0
	.long	7
	.long	0
.section .data
.section .bss
.section .text
.globl	main
.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$1, -4(%rbp)
	movl	$1, -28(%rbp)
	movl	$2, -24(%rbp)
	movl	$3, -20(%rbp)
	movl	$4, -16(%rbp)
	movl	$5, -12(%rbp)
	movl	$6, -8(%rbp)
	movl	$2, -32(%rbp)
	movl	$1, -36(%rbp)
	movl	$1, %r10d
	movl	%r10d, %r8d
	movl	$0, %r11d
	movl	-32(%rbp), %r10d
	imull	$2, %r10d
	addl	%r10d, %r11d
	movl	-36(%rbp), %r10d
	addl	%r10d, %r11d
	leaq	-28(%rbp), %rsi
	shll	$2, %r11d
	addq	%r11, %rsi
	movl	(%rsi), %r10d
	movl	%r10d, %r9d
	addl	%r9d, %r8d
	movl	%r8d, -44(%rbp)
	movl	%r10d, -44(%rbp)
	movl	$0, %r11d
	movl	-32(%rbp), %r10d
	imull	$2, %r10d
	addl	%r10d, %r11d
	movl	-36(%rbp), %r10d
	addl	%r10d, %r11d
	leaq	-28(%rbp), %rsi
	shll	$2, %r11d
	addq	%r11, %rsi
	movl	(%rsi), %r10d
	movl	%r10d, -48(%rbp)
	movl	$0, %r11d
	movl	$1, %r10d
	imull	$2, %r10d
	addl	%r10d, %r11d
	movl	$1, %r10d
	addl	%r10d, %r11d
	leaq	-28(%rbp), %rsi
	shll	$2, %r11d
	addq	%r11, %rsi
	movl	(%rsi), %r10d
	movl	%r10d, -84(%rbp)
	movl	$2, -80(%rbp)
	movl	$3, -76(%rbp)
	movl	$5, -72(%rbp)
	movl	$6, -68(%rbp)
	movl	$0, %r11d
	movl	$2, %r10d
	imull	$2, %r10d
	addl	%r10d, %r11d
	movl	$1, %r10d
	addl	%r10d, %r11d
	leaq	-28(%rbp), %rsi
	shll	$2, %r11d
	addq	%r11, %rsi
	movl	(%rsi), %r10d
	movl	%r10d, -64(%rbp)
	movl	$8, -60(%rbp)
	movl	$9, -56(%rbp)
	movl	$10, -52(%rbp)
	movl	$1, -104(%rbp)
	movl	$2, -100(%rbp)
	movl	$3, -96(%rbp)
	movl	$4, -92(%rbp)
	movl	$5, -88(%rbp)
	movl	$9, -108(%rbp)
	leaq	-104(%rbp), %rsi
	movq	%rsi, %r10
	movq	%r10, -116(%rbp)
	movl	-4(%rbp), %r10d
	movl	%r10d, -124(%rbp)
	call	foo
	movl	$9, %r10d
	movl	%r10d, %r8d
	movl	$4, %r10d
	movl	%r10d, %r9d
	addl	%r9d, %r8d
	movl	%r8d, -128(%rbp)
	leave
	ret

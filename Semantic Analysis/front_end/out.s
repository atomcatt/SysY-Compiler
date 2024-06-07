.section .rodata
.globl	b0
.align	4
.type	b0, @object
.size	b0, 4
b0:
	.long	0
	.long	1
	.long	0
	.long	0
.globl	c0
.align	4
.type	c0, @object
.size	c0, 7
c0:
	.long	2
	.long	8
	.long	6
	.long	3
	.long	9
	.long	1
	.long	5
.globl	e0
.align	4
.type	e0, @object
.size	e0, 2
e0:
	.long	22
	.long	33
.globl	g0
.align	4
.type	g0, @object
.size	g0, 9
g0:
	.long	85
	.long	0
	.long	1
	.long	29
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
.globl	scj82c9s0j
.align	4
.type	scj82c9s0j, @object
.size	scj82c9s0j, 4
scj82c9s0j:
	.long	9
.globl	c
.align	4
.type	c, @object
.size	c, 15
c:
	.long	1
	.long	2
	.long	3
	.long	4
	.long	5
	.long	6
	.long	7
	.long	8
	.long	9
	.long	10
	.long	11
	.long	12
	.long	13
	.long	14
	.long	15
.globl	d
.align	4
.type	d, @object
.size	d, 15
d:
	.long	1
	.long	2
	.long	3
	.long	4
	.long	5
	.long	6
	.long	7
	.long	8
	.long	9
	.long	10
	.long	11
	.long	12
	.long	13
	.long	14
	.long	15
.globl	e
.align	4
.type	e, @object
.size	e, 15
e:
	.long	1
	.long	2
	.long	3
	.long	4
	.long	5
	.long	6
	.long	7
	.long	8
	.long	9
	.long	10
	.long	11
	.long	12
	.long	13
	.long	14
	.long	15
.globl	g
.align	4
.type	g, @object
.size	g, 15
g:
	.long	1
	.long	2
	.long	3
	.long	4
	.long	0
	.long	0
	.long	7
	.long	0
	.long	0
	.long	10
	.long	11
	.long	12
	.long	0
	.long	0
	.long	0
.globl	j
.align	4
.type	j, @object
.size	j, 24
j:
	.long	1
	.long	2
	.long	3
	.long	4
	.long	5
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
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
.globl	tt
.align	4
.type	tt, @object
.size	tt, 4
tt:
	.long	5
.globl	i
.align	4
.type	i, @object
.size	i, 30
i:
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
.globl	k
.align	4
.type	k, @object
.size	k, 40
k:
	.long	1
	.long	1
	.long	1
	.long	1
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
.globl	l
.align	4
.type	l, @object
.size	l, 6
l:
	.long	1
	.long	2
	.long	3
	.long	0
	.long	0
	.long	0
.section .bss
.section .text
.globl	main
.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$1, -4(%rbp)
	movl	$1, -24(%rbp)
	movl	$2, -20(%rbp)
	movl	$3, -16(%rbp)
	movl	$4, -12(%rbp)
	movl	$5, -8(%rbp)
	movl	$6, -4(%rbp)
	movl	$9, -28(%rbp)
	movl	$9, %r10d
	movl	%r10d, %r8d
	movl	tt(%rip), %r10d
	movl	%r10d, %r9d
	addl	%r9d, %r8d
	movl	%r8d, %eax
	leave
	ret

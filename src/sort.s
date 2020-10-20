	.file	"sort.c"
	.text
	.p2align 4,,15
	.globl	sort
	.type	sort, @function
sort:
.LFB0:
	.cfi_startproc
	subl	$1, %esi
	xorl	%r8d, %r8d
	testl	%esi, %esi
	movslq	%esi, %r9
	jle	.L10
	.p2align 4,,10
	.p2align 3
.L2:
	movq	%r9, %rax
	.p2align 4,,10
	.p2align 3
.L5:
	movl	-4(%rdi,%rax,4), %edx
	movl	(%rdi,%rax,4), %ecx
	cmpl	%ecx, %edx
	jle	.L4
	movl	%ecx, -4(%rdi,%rax,4)
	movl	%edx, (%rdi,%rax,4)
.L4:
	subq	$1, %rax
	cmpl	%eax, %r8d
	jl	.L5
	addl	$1, %r8d
	cmpl	%esi, %r8d
	jl	.L2
	rep ret
.L10:
	rep ret
	.cfi_endproc
.LFE0:
	.size	sort, .-sort
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits

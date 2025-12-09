	.file	"optSort.c"
	.text
	.p2align 4
	.globl	bubbleSort
	.type	bubbleSort, @function
bubbleSort:
.LFB11:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	movq	%rdi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movslq	%esi, %rbx
	movl	$4, %esi
	movq	%rbx, %rdi
	call	calloc@PLT
	movq	%rax, %rdi
	testl	%ebx, %ebx
	jle	.L13
	movl	%ebx, %edx
	movq	%r12, %rsi
	movq	%rbx, %rbp
	salq	$2, %rdx
	call	memcpy@PLT
	leaq	4(%r12), %r8
	movq	%rax, %rdi
.L3:
	cmpl	$1, %ebp
	jle	.L21
	.p2align 4
	.p2align 3
.L8:
	leal	-2(%rbp), %edx
	movq	%r12, %rax
	leaq	(%r8,%rdx,4), %rsi
	.p2align 6
	.p2align 4
	.p2align 3
.L5:
	movq	(%rax), %xmm0
	pshufd	$0xe5, %xmm0, %xmm1
	movd	%xmm0, %ecx
	movd	%xmm1, %edx
	cmpl	%edx, %ecx
	jle	.L4
	pshufd	$225, %xmm0, %xmm0
	movq	%xmm0, (%rax)
.L4:
	addq	$4, %rax
	cmpq	%rsi, %rax
	jne	.L5
	subl	$1, %ebp
	cmpl	$1, %ebp
	jg	.L8
.L21:
	subl	$1, %ebp
	jne	.L3
	salq	$2, %rbx
	xorl	%eax, %eax
	xorl	%ebp, %ebp
	.p2align 5
	.p2align 4
	.p2align 3
.L11:
	movl	(%rdi,%rax), %esi
	cmpl	%esi, (%r12,%rax)
	je	.L10
	addl	$1, %ebp
.L10:
	addq	$4, %rax
	cmpq	%rbx, %rax
	jne	.L11
	call	free@PLT
	movl	%ebp, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L13:
	.cfi_restore_state
	call	free@PLT
	xorl	%ebp, %ebp
	popq	%rbx
	.cfi_def_cfa_offset 24
	movl	%ebp, %eax
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE11:
	.size	bubbleSort, .-bubbleSort
	.ident	"GCC: (GNU) 15.2.1 20250813"
	.section	.note.GNU-stack,"",@progbits

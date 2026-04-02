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
	movslq	%esi, %r12
	movl	$4, %esi
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movq	%rdi, %rbp
	movq	%r12, %rdi
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%r12, %rbx
	salq	$2, %r12
	call	calloc@PLT
	movq	%r12, %rdx
	movq	%rbp, %rsi
	movq	%rax, %rdi
	call	memcpy@PLT
	movq	%rax, %r8
	testl	%ebx, %ebx
	jle	.L12
	movl	%ebx, %edi
	leaq	4(%rbp), %r9
.L3:
	cmpl	$1, %edi
	jle	.L21
	.p2align 4
	.p2align 3
.L8:
	leal	-2(%rdi), %edx
	movq	%rbp, %rax
	leaq	(%r9,%rdx,4), %rsi
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
	subl	$1, %edi
	cmpl	$1, %edi
	jg	.L8
.L21:
	subl	$1, %edi
	jne	.L3
	xorl	%eax, %eax
	xorl	%ebx, %ebx
	.p2align 5
	.p2align 4
	.p2align 3
.L7:
	movl	(%r8,%rax), %edi
	cmpl	%edi, 0(%rbp,%rax)
	je	.L10
	addl	$1, %ebx
.L10:
	addq	$4, %rax
	cmpq	%rax, %r12
	jne	.L7
	movq	%r8, %rdi
	call	free@PLT
	movl	%ebx, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L12:
	.cfi_restore_state
	xorl	%ebx, %ebx
	movq	%r8, %rdi
	call	free@PLT
	movl	%ebx, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
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

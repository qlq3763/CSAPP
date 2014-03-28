	.file	"ex3.70.c"
	.text
	.globl	traverse
	.type	traverse, @function
traverse:
.LFB0:
	.cfi_startproc
	movq	%rbx, -16(%rsp)
	movq	%rbp, -8(%rsp)
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -16
	.cfi_offset 3, -24
	movq	%rdi, %rbx
	testq	%rdi, %rdi
	je	.L3
	movq	8(%rdi), %rdi
	call	traverse
	movq	%rax, %rbp
	movq	16(%rbx), %rdi
	call	traverse
	cmpq	%rax, %rbp
	cmovl	%rax, %rbp
	movq	(%rbx), %rdx
	cmpq	%rdx, %rbp
	movq	%rdx, %rax
	cmovge	%rbp, %rax
	jmp	.L2
.L3:
	movabsq	$-9223372036854775808, %rax
.L2:
	movq	8(%rsp), %rbx
	movq	16(%rsp), %rbp
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	traverse, .-traverse
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

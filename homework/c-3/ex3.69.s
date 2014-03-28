	.file	"ex3.69.c"
	.text
	.globl	trace
	.type	trace, @function
trace:
.LFB0:
	.cfi_startproc
	movl	$0, %eax
	testq	%rdi, %rdi
	je	.L2
.L5:
	movq	(%rdi), %rax
	movq	16(%rdi), %rdi
	testq	%rdi, %rdi
	jne	.L5
.L2:
	rep
	ret
	.cfi_endproc
.LFE0:
	.size	trace, .-trace
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

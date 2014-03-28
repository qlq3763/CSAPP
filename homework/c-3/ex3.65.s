	.file	"ex3.65.c"
	.text
	.globl	setVal
	.type	setVal, @function
setVal:
.LFB0:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	12(%eax), %edx
	addl	36(%eax), %edx
	movl	4(%esp), %eax
	movl	%edx, 92(%eax)
	ret
	.cfi_endproc
.LFE0:
	.size	setVal, .-setVal
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

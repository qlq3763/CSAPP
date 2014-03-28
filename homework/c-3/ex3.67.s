	.file	"ex3.67.c"
	.text
	.globl	proc
	.type	proc, @function
proc:
.LFB0:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	4(%edx), %eax
	movl	(%eax), %ecx
	movl	(%ecx), %ecx
	subl	(%edx), %ecx
	movl	%ecx, 4(%eax)
	ret
	.cfi_endproc
.LFE0:
	.size	proc, .-proc
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

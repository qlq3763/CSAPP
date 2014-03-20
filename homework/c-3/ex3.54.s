	.file	"ex3.54.c"
	.text
	.globl	decode2
	.type	decode2, @function
decode2:
.LFB0:
	.cfi_startproc
	movl	8(%esp), %edx
	subl	12(%esp), %edx
	movl	%edx, %eax
	sall	$31, %eax
	sarl	$31, %eax
	imull	4(%esp), %edx
	xorl	%edx, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	decode2, .-decode2
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

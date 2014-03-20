	.file	"ex3.57.c"
	.text
	.globl	cread
	.type	cread, @function
cread:
.LFB0:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	$0, %eax
	testl	%edx, %edx
	je	.L2
	movl	(%edx), %eax
.L2:
	rep
	ret
	.cfi_endproc
.LFE0:
	.size	cread, .-cread
	.globl	cread_alt
	.type	cread_alt, @function
cread_alt:
.LFB1:
	.cfi_startproc
	subl	$16, %esp
	.cfi_def_cfa_offset 20
	movl	20(%esp), %eax
	movl	$0, 12(%esp)
	leal	12(%esp), %edx
	testl	%eax, %eax
	cmove	%edx, %eax
	movl	(%eax), %eax
	addl	$16, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE1:
	.size	cread_alt, .-cread_alt
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

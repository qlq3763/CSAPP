	.file	"ex3.59.c"
	.text
	.globl	switch_prob
	.type	switch_prob, @function
switch_prob:
.LFB0:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	8(%esp), %edx
	subl	$50, %edx
	cmpl	$5, %edx
	ja	.L2
	jmp	*.L7(,%edx,4)
	.section	.rodata
	.align 4
	.align 4
.L7:
	.long	.L3
	.long	.L2
	.long	.L3
	.long	.L4
	.long	.L5
	.long	.L6
	.text
.L3:
	sall	$2, %eax
	ret
.L4:
	sarl	$2, %eax
	.p2align 4,,6
	ret
.L5:
	leal	(%eax,%eax,2), %eax
.L6:
	imull	%eax, %eax
.L2:
	addl	$10, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	switch_prob, .-switch_prob
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

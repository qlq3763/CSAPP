	.file	"ex3.63.c"
	.text
	.globl	sum_col
	.type	sum_col, @function
sum_col:
.LFB0:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %esi
	leal	(%esi,%esi), %ebx
	addl	%ebx, %esi
	leal	1(%ebx), %edx
	movl	$0, %eax
	testl	%edx, %edx
	jle	.L2
	sall	$2, %esi
	movl	20(%esp), %edx
	movl	16(%esp), %eax
	leal	(%eax,%edx,4), %ecx
	addl	$2, %ebx
	movl	$1, %edx
	movl	$0, %eax
.L3:
	addl	(%ecx), %eax
	addl	$1, %edx
	addl	%esi, %ecx
	cmpl	%ebx, %edx
	jne	.L3
.L2:
	popl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_restore 3
	popl	%esi
	.cfi_def_cfa_offset 4
	.cfi_restore 6
	ret
	.cfi_endproc
.LFE0:
	.size	sum_col, .-sum_col
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

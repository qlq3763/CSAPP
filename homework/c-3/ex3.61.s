	.file	"ex3.61.c"
	.text
	.globl	var_prod_ele
	.type	var_prod_ele, @function
var_prod_ele:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	20(%esp), %esi
	movl	$0, %eax
	testl	%esi, %esi
	jle	.L2
	leal	0(,%esi,4), %edi
	movl	%edi, %ebp
	imull	32(%esp), %ebp
	addl	24(%esp), %ebp
	movl	36(%esp), %edx
	movl	28(%esp), %eax
	leal	(%eax,%edx,4), %ecx
	movl	$0, %eax
	movl	$0, %edx
.L3:
	movl	0(%ebp,%edx,4), %ebx
	imull	(%ecx), %ebx
	addl	%ebx, %eax
	addl	$1, %edx
	addl	%edi, %ecx
	cmpl	%esi, %edx
	jne	.L3
.L2:
	popl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_restore 3
	popl	%esi
	.cfi_def_cfa_offset 12
	.cfi_restore 6
	popl	%edi
	.cfi_def_cfa_offset 8
	.cfi_restore 7
	popl	%ebp
	.cfi_def_cfa_offset 4
	.cfi_restore 5
	ret
	.cfi_endproc
.LFE0:
	.size	var_prod_ele, .-var_prod_ele
	.globl	var_prod_ele2
	.type	var_prod_ele2, @function
var_prod_ele2:
.LFB1:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %ebx
	sall	$2, %ebx
	movl	%ebx, %edi
	imull	28(%esp), %edi
	addl	20(%esp), %edi
	movl	$0, %eax
	testl	%ebx, %ebx
	jle	.L7
	movl	32(%esp), %edx
	movl	24(%esp), %eax
	leal	(%eax,%edx,4), %ecx
	movl	$0, %eax
	movl	$0, %edx
.L8:
	movl	(%edi,%edx), %esi
	imull	(%ecx), %esi
	addl	%esi, %eax
	addl	$4, %edx
	addl	%ebx, %ecx
	cmpl	%edx, %ebx
	jg	.L8
.L7:
	popl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_restore 3
	popl	%esi
	.cfi_def_cfa_offset 8
	.cfi_restore 6
	popl	%edi
	.cfi_def_cfa_offset 4
	.cfi_restore 7
	ret
	.cfi_endproc
.LFE1:
	.size	var_prod_ele2, .-var_prod_ele2
	.globl	var_prod_ele3
	.type	var_prod_ele3, @function
var_prod_ele3:
.LFB2:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %esi
	sall	$2, %esi
	movl	%esi, %edx
	imull	28(%esp), %edx
	addl	20(%esp), %edx
	movl	%esi, %edi
	addl	%edx, %esi
	movl	$0, %eax
	cmpl	%esi, %edx
	jae	.L12
	movl	32(%esp), %ecx
	movl	24(%esp), %eax
	leal	(%eax,%ecx,4), %ecx
	movl	$0, %eax
.L13:
	movl	(%edx), %ebx
	imull	(%ecx), %ebx
	addl	%ebx, %eax
	addl	$4, %edx
	addl	%edi, %ecx
	cmpl	%edx, %esi
	ja	.L13
.L12:
	popl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_restore 3
	popl	%esi
	.cfi_def_cfa_offset 8
	.cfi_restore 6
	popl	%edi
	.cfi_def_cfa_offset 4
	.cfi_restore 7
	ret
	.cfi_endproc
.LFE2:
	.size	var_prod_ele3, .-var_prod_ele3
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

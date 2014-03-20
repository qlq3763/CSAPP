	.file	"ex3.56.c"
	.text
	.globl	loop
	.type	loop, @function
loop:
.LFB0:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %ebx
	movl	16(%esp), %ecx
	movl	$1, %edx
	movl	$-1, %eax
.L2:
	movl	%edx, %esi
	andl	%ebx, %esi
	xorl	%esi, %eax
	sall	%cl, %edx
	testl	%edx, %edx
	jne	.L2
	popl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_restore 3
	popl	%esi
	.cfi_def_cfa_offset 4
	.cfi_restore 6
	ret
	.cfi_endproc
.LFE0:
	.size	loop, .-loop
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

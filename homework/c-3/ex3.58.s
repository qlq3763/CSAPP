	.file	"ex3.58.c"
	.text
	.globl	switch3
	.type	switch3, @function
switch3:
.LFB0:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %ebx
	movl	12(%esp), %ecx
	movl	16(%esp), %edx
	movl	$-1, %eax
	cmpl	$4, %edx
	ja	.L2
	jmp	*.L8(,%edx,4)
	.section	.rodata
	.align 4
	.align 4
.L8:
	.long	.L3
	.long	.L4
	.long	.L5
	.long	.L6
	.long	.L7
	.text
.L7:
	movl	$17, %eax
	jmp	.L2
.L3:
	movl	(%ebx), %eax
	movl	(%ecx), %edx
	movl	%edx, (%ebx)
	jmp	.L2
.L4:
	movl	(%ecx), %eax
	addl	(%ebx), %eax
	movl	%eax, (%ecx)
	jmp	.L2
.L5:
	movl	$15, (%ecx)
	movl	(%ebx), %eax
	jmp	.L2
.L6:
	movl	(%ebx), %eax
	movl	%eax, (%ecx)
	movl	$17, %eax
.L2:
	popl	%ebx
	.cfi_def_cfa_offset 4
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE0:
	.size	switch3, .-switch3
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

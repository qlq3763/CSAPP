	.file	"ex3.66.c"
	.text
	.globl	test
	.type	test, @function
test:
.LFB0:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %edx
	movl	12(%esp), %eax
	leal	(%edx,%edx,4), %edx
	leal	(%eax,%edx,4), %edx
	movl	4(%edx), %ecx
	movl	(%eax), %ebx
	addl	184(%eax), %ebx
	movl	%ebx, 8(%edx,%ecx,4)
	popl	%ebx
	.cfi_def_cfa_offset 4
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE0:
	.size	test, .-test
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

/* A function with prototype */
/* int decode2(int x, int y, int z); */
/* is compiled into IA32 assembly code. The body of the code is as follows: */
/* x at %ebp+8, y at %ebp+12, z at %ebp+16 */

/* movl 12(%ebp), %edx */
/* subl 16(%ebp), %edx */
/* movl %edx, %eax */
/* sall $31, %eax */
/* sarl $31, %eax */
/* imull 8(%ebp), %edx */
/* xorl %edx, %eax */

/* the generated assembly code  */
	/* movl	8(%esp), %edx */
	/* subl	12(%esp), %edx */
	/* movl	%edx, %eax */
	/* sall	$31, %eax */
	/* sarl	$31, %eax */
	/* imull	4(%esp), %edx */
	/* xorl	%edx, %eax */
/* Parameters x, y, and z are stored at memory locations with offsets 8, 12, and 16 */
/* relative to the address in register %ebp. The code stores the return value in register */
/* %eax. */
/* Write C code for decode2 that will have an effect equivalent to our assembly */
/* code. */


/* Notice that on a 64-bit machine, with the -m32 -O1 flags, the generated code does NOT use */
/* %ebp to keep stack frame. So the first argument is at 4(%esp), the second 8(%esp), and so on. */
int decode2(int x, int y, int z) {
    y -= z;
    int t = y << 31 >> 31;
    y *= x;
    return t ^ y;
}

/* int main() { */
/*     return decode2(1, 2, 3); */
/* } */

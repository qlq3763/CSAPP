/* Consider the following source code, where E1 and E2 are macro expressions de- */
/* clared with #define that compute the dimensions of array A in terms of parameter */
/* n. This code computes the sum of the elements of column j of the array. */

/* int sum_col(int n, int A[E1(n)][E2(n)], int j) { */
/*     int i; */
/*     int result = 0; */
/*     for (i = 0; i < E1(n); i++) */
/*         result += A[i][j]; */
/*     return result; */
/* } */
/* In compiling this program, gcc generates the following assembly code: */
/* n at %ebp+8, A at %ebp+12, j at %ebp+16 */
/* movl 8(%ebp), %eax */
/* leal (%eax,%eax), %edx */
/* leal (%edx,%eax), %ecx */
/* movl %edx, %ebx */
/* leal 1(%edx), %eax */
/* movl $0, %edx */
/* testl %eax, %eax */
/* jle .L3 */
/* leal 0(,%ecx,4), %esi */
/* movl 16(%ebp), %edx */
/* movl 12(%ebp), %ecx */
/* leal (%ecx,%edx,4), %eax */
/* movl $0, %edx */
/* movl $1, %ecx */
/* addl $2, %ebx */
/* .L4:  */
/* addl (%eax), %edx */
/* addl $1, %ecx */
/* addl %esi, %eax */
/* cmpl %ebx, %ecx */
/* jne .L4 */
/* .L3: */
/* movl %edx, %eax */

/* Use your reverse engineering skills to determine the definitions of E1 and E2. */

///////////////////////////////////////////////////////////////////////////////////////////
#define E1(n) (2 * n + 1)
#define E2(n) (3 * n)

int sum_col(int n, int A[E1(n)][E2(n)], int j) {
    int i;
    int result = 0;
    for (i = 0; i < E1(n); i++)
        result += A[i][j];
    return result;
}

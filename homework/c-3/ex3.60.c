/* Consider the following source code, where R, S, and T are constants declared with */
/* #define: */
/* int A[R][S][T]; */
/* int store_ele(int i, int j, int k, int *dest) */
/* { */
/* *dest = A[i][j][k]; */
/* return sizeof(A); */
/* } */

/* In compiling this program, gcc generates the following assembly code: */

/* movl 12(%ebp), %edx */
/* leal (%edx,%edx,4), %eax */
/* leal (%edx,%eax,2), %eax */
/* imull $99, 8(%ebp), %edx */
/* addl %edx, %eax */
/* addl 16(%ebp), %eax */
/* movl A(,%eax,4), %edx */
/* movl 20(%ebp), %eax */
/* movl %edx, (%eax) */
/* movl $1980, %eax */

/* A. Extend Equation 3.1 from two dimensions to three to provide a formula for */
/* the location of array element A[i][j][k]. */
/* B. Use your reverse engineering skills to determine the values of R, S, and T */
/* based on the assembly code. */

/* A. */
/* Equation 3.1:  */
/* T D[R][C]; */
/* &D[i][j] = xD + L(C.i + j); */

/* T D[R][C1][C2]; */
/* &D[i][j][k] = xD + L(C1*C2*i + C2*j + k); */

/* B. */
/* 4*(99*i + 11*j + k) */
/* So,  */
/* T = 11, S = 99/11 = 9, R = 1980/9/11/4 = 5 */

#define R 5
#define S 9
#define T 11

int A[R][S][T];
int store_ele(int i, int j, int k, int *dest)
{
    *dest = A[i][j][k];
    return sizeof(A);
}

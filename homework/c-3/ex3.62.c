/* The following code transposes the elements of an M × M array, where M is a */
/* constant defined by #define: */
/* void transpose(Marray_t A) { */
/*     int i, j; */
/*     for (i = 0; i < M; i++) */
/*         for (j = 0; j < i; j++) { */
/*             int t = A[i][j]; */
/*             A[i][j] = A[j][i]; */
/*             A[j][i] = t; */
/*         } */
/* } */
/* When compiled with optimization level -O2, gcc generates the following code for */
/* the inner loop of the function: */

/* .L3: */
/* movl (%ebx), %eax */
/* movl (%esi,%ecx,4), %edx */
/* movl %eax, (%esi,%ecx,4) */
/* addl $1, %ecx */
/* movl %edx, (%ebx) */
/* addl $52, %ebx */
/* cmpl %edi, %ecx */
/* jl .L3 */

/* A. What is the value of M? */
/* B. What registers hold program values i and j ? */
/* C. Write a C code version of transpose that makes use of the optimizations */
/* that occur in this loop. Use the parameter M in your code rather than numeric */
/* constants. */

/////////////////////////////////////////////////////////////////////////////////////
/* A. */
/* M = 52 / 4 = 13. */

/* B. */
/* %ecx: j */
/* %edi: i */

/* C. */
// just translate
void transpose(Marray_t A) {
    int i, j;
    int *pa, *pb;
    for (i = 0; i < M; i++) {
        pa = &M[i][0];
        pb = &M[0][i];
        
        for (j = 0; j < i; j++) {
            int t = *(pa + j);
            *(pa + j) = *pb;
            *pb = t;
            pb += M;
        }
}

/* In the following code, A and B are constants defined with #define: */
/* typedef struct { */
/*     short x[A][B]; /\* Unknown constants A and B *\/ */
/*     int y; */
/* } str1; */
/* typedef struct { */
/*     char array[B]; */
/*     int t; */
/*     short s[B]; */
/*     int u; */
/* } str2; */
/* void setVal(str1 *p, str2 *q) { */
/*     int v1 = q->t; */
/*     int v2 = q->u; */
/*     p->y = v1+v2; */
/* } */

/* gcc generates the following code for the body of setVal: */

/* movl 12(%ebp), %eax */
/* movl 36(%eax), %edx */
/* addl 12(%eax), %edx */
/* movl 8(%ebp), %eax */
/* movl %edx, 92(%eax) */

/* What are the values of A and B? (The solution is unique.) */

/////////////////////////////////////////////////////////////////////////////////////////////

/* t at offset 12, and u at offset 36, so s[B] occupies 20 bytes(including padding). */
/* From this we can know that B is 9 or 10. */

/* y at offset 92, so A * B is either 45 or 46. */

/* From the above facts, this is only one combination left:  */
/* A = 5,  */
/* B = 9. */

#define A 5
#define B 9

typedef struct {
    short x[A][B]; /* Unknown constants A and B */
    int y;
} str1;
typedef struct {
    char array[B];
    int t;
    short s[B];
    int u;
} str2;

void setVal(str1 *p, str2 *q) {
    int v1 = q->t;
    int v2 = q->u;
    p->y = v1+v2;
}

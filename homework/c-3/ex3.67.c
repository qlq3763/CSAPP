/* Consider the following union declaration: */

/* union ele { */
/*     struct { */
/*         int *p; */
/*         int y; */
/*     } e1; */
/*     struct { */
/*         int x; */
/*         union ele *next; */
/*     } e2; */
/* }; */

/* This declaration illustrates that structures can be embedded within unions. */
/* The following procedure (with some expressions omitted) operates on a */
/* linked list having these unions as list elements: */

/* void proc (union ele *up) */
/* { */
/* up-> */
/* = *(up-> */
/* } */

/* A. What would be the offsets (in bytes) of the following fields: */
/* e1.p: */
/* e1.y: */
/* e2.x: */
/* e2.next: */
/* B. How many total bytes would the structure require? */
/* C. The compiler generates the following assembly code for the body of proc: */
/* up at %ebp+8 */

/* movl 8(%ebp), %edx */
/* movl 4(%edx), %ecx */
/* movl (%ecx), %eax */
/* movl (%eax), %eax */
/* subl (%edx), %eax */
/* movl %eax, 4(%ecx) */

/* On the basis of this information, fill in the missing expressions in the code */
/* for proc. Hint: Some union references can have ambiguous interpretations. */
/* These ambiguities get resolved as you see where the references lead. There */
/* is only one answer that does not perform any casting and does not violate */
/* any type constraints. */

/////////////////////////////////////////////////////////////////////////////////////////////////////

/* suppose both int and pointer are 4 bytes long */

/* A. */
/* e1.p: 0 */
/* e1.y: 4 */
/* e2.x: 0 */
/* e2.next: 4 */

/* B. */
/* Total: 8 bytes */

/* C. */

/* movl 8(%ebp), %edx */ // get up
/* movl 4(%edx), %ecx */ // next = (up->e2).next
/* movl (%ecx), %eax */ // p = (next->e1).p
/* movl (%eax), %eax */ // x = *p
/* subl (%edx), %eax */ // x2 = x - (up->e2).x
/* movl %eax, 4(%ecx) */ // (next->e1).y = x2

union ele {
    struct {
        int *p;
        int y;
    } e1;
    struct {
        int x;
        union ele *next;
    } e2;
};

void proc (union ele *up) {
    union ele *next = (up->e2).next;
    (next->e1).y = *((next->e1).p) - (up->e2).x;
}

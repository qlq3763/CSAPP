/* For this exercise, we will examine the code generated by gcc for functions that have */
/* structures as arguments and return values, and from this see how these language */
/* features are typically implemented. */
/* The following C code has a function word_sum having structures as argument */
/* and return values, and a function prod that calls word_sum: */

/* typedef struct { */
/* int a; */
/* int *p; */
/* } str1; */
/* typedef struct { */
/* int sum; */
/* int diff; */
/* } str2; */
/* str2 word_sum(str1 s1) { */
/* str2 result; */
/* result.sum = s1.a + *s1.p; */
/* result.diff = s1.a - *s1.p; */
/* return result; */
/* } */
/* int prod(int x, int y) */
/* { */
/* str1 s1; */
/* str2 s2; */
/* s1.a = x; */
/* s1.p = &y; */
/* s2 = word_sum(s1); */
/* return s2.sum * s2.diff; */
/* } */

/* gcc generates the following code for these two functions: */

/* The instruction ret $4 is like a normal return instruction, but it increments */
/* the stack pointer by 8 (4 for the return address plus 4 additional), rather than 4. */
/* A. We can see in lines 5–7 of the code for word_sum that it appears as if three */
/* values are being retrieved from the stack, even though the function has only */
/* a single argument. Describe what these three values are. */
/* B. We can see in line 4 of the code for prod that 20 bytes are allocated in the */
/* stack frame. These get used as five fields of 4 bytes each. Describe how each */
/* of these fields gets used. */
/* C. How would you describe the general strategy for passing structures as argu- */
/* ments to a function? */
/* D. How would you describe the general strategy for handling a structure as a */
/* return value from a function? */

////////////////////////////////////////////////////////////////////////////////////////////////////

/* A. */
/* 8(%ebp): address of return value(eg. &s2). */
/* 12(%ebp): first 4 bytes of struct str1. */
/* 16(%ebp): second 4 bytes of struct str1. */

/* B. */
/* %esp: &s2 */
/* 4(%esp): x */
/* 8(%esp): &y */
/* 12(%esp): str2.sum */
/* 16(%esp): str2.diff */

/* C. */
/* Pass all elments separately. */

/* D. */
/* Copy the elements to an address. Copy to the result value(s2) through an address. */

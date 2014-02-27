/* Following the bit-level floating-point coding rules, implement the function with */
/* the following prototype: */
/* /\* Compute 2*f. If f is NaN, then return f. *\/ */
/* float_bits float_twice(float_bits f); */
/* For floating-point number f , this function computes 2.0 . f . If f is NaN, your */
/* function should simply return f . */
/* Test your function by evaluating it for all 232 values of argument f and com- */
/* paring the result to what would be obtained using your machine’s floating-point */
/* operations. */

#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

#include "float_def.h"
/* Compute 2*f. If f is NaN, then return f. */
/* Some cases: */
/* 1. normalized values: exp + 1 */

/* 2. denormalized values:  */
/* if frac is: 1xxxxxx..., then exp + 1(or just set exp to 1), frac << 1; */
/* otherwise(0xxxxx...), then frac << 1; */

/* 3. special values: */
/* just return */
float_bits float_twice(float_bits f) {
    /* Decompose bit representation into parts */
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    /* special values */
    if (exp == 0xFF) return f;

    /* denormalized values */
    if (exp == 0) {
        if (frac & 0x400000) exp += 1;
        frac = (frac << 1) & 0x7FFFFF;
    }
    else { /* normalized values */
        exp += 1;
        /* normalized to special */
        if (exp == 0xFF) frac = 0;
    }
    
    /* Reassemble bits */
    return (sign << 31) | (exp << 23) | frac;
}

///////////////////////////////////////////////////
// copy from ex2.89.c. Not a good practice. Just for exercise.
float u2f(unsigned u) {
    float f = *(float *)&u;
    return f;
}

// copy from ex2.83.c. Not a good practice. Just for exercise.
unsigned f2u(float x) {
    unsigned u = *(unsigned *)&x;
    return u;
}
//////////////////////////////////////////////////

static void test() {
    float f, f_twice;
    unsigned u, u_twice;
    
    for (unsigned x = UINT_MAX; x > 0; --x) {
        f = u2f(x);
        u = isnan(f) ? f2u(f) : f2u(2 * f);
        u_twice = float_twice(x);
        f_twice = u2f(u_twice);

        if (u != u_twice) {
            printf("x: %x, u: %x, u_twice: %x, f: %f, f_twice %f\n", x, u, u_twice, f, f_twice);
        }
        assert(u == u_twice);
    }

    // one last case
    assert(float_twice(0) == f2u(2 * 0.0));

    printf("All tests pass!\n");
}

int main() {
    test();

    return 0;
}

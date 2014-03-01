/* Following the bit-level floating-point coding rules, implement the function with */
/* the following prototype: */
/* /\* Compute 0.5*f. If f is NaN, then return f. *\/ */
/* float_bits float_half(float_bits f); */
/* For floating-point number f , this function computes 0.5 . f . If f is NaN, your */
/* function should simply return f . */
/* Test your function by evaluating it for all 232 values of argument f and com- */
/* paring the result to what would be obtained using your machine’s floating-point */
/* operations. */

#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

#include "float_def.h"

/* Compute 0.5*f. If f is NaN, then return f. */
float_bits float_half(float_bits f) {
    /* Decompose bit representation into parts */
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    /* special values */
    if (exp == 0xFF) return f;

    /* denormalized values */
    if (exp == 0) {
        unsigned temp = frac >> 1;
        if ((frac & 3) == 3)
            frac = temp + 1; // round to even
        else 
            frac = temp;
    }
    else { /* normalized values */
        exp -= 1;
        if (exp == 0) {
            unsigned temp = (frac >> 1) | 0x400000;
            if ((frac & 3) == 3) 
                frac = temp + 1; // round to even
            else
                frac = temp;
        }
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
    float f, f_half;
    unsigned u, u_half;
    
    for (unsigned x = UINT_MAX; x > 0; --x) {
        f = u2f(x);
        u = isnan(f) ? f2u(f) : f2u(0.5 * f);
        u_half = float_half(x);
        f_half = u2f(u_half);

        if (u != u_half) {
            printf("x: %x, u: %x, u_half: %x, f: %f, f_half %f\n", x, u, u_half, f, f_half);
        }
        assert(u == u_half);
    }

    // one last case
    assert(float_half(0) == f2u(0.5 * 0.0));

    printf("All tests pass!\n");
}

int main() {
    test();

    unsigned u, u2, u3, u4;
    u = 0x80ffffff;
    u2 = 0x80fffffe;
    u3 = 0x80fffffd;
    u4 = 0x80fffffc;
    
    printf("u: %x, u2: %x, u3: %x, u4: %x\n", f2u(u2f(u) * 0.5), f2u(u2f(u2) * 0.5), f2u(u2f(u3) * 0.5), f2u(u2f(u4) * 0.5));
    
    return 0;
}

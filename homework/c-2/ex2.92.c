/* Following the bit-level floating-point coding rules, implement the function with */
/* the following prototype: */
/* /\* Compute |f|. If f is NaN, then return f. *\/ */
/* float_bits float_absval(float_bits f); */
/* For floating-point number f , this function computes |f |. If f is NaN, your function */
/* should simply return f . */
/* Test your function by evaluating it for all 232 values of argument f and com- */
/* paring the result to what would be obtained using your machine’s floating-point */
/* operations. */

#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

#include "float_def.h"

/* Compute |f|. If f is NaN, then return f. */
float_bits float_absval(float_bits f) {
    /* Decompose bit representation into parts */
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;
	
    // NaN, just return
    if ((exp == 0xFF) && (frac != 0)) {
        return f;
    }

    sign = 0;
    /* Reassemble bits */
    return (sign << 31) | (exp << 23) | frac;

}

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

/* Use float point operation to compute the correct resutls: I have to choise */
/* one use "fabsf" function from <math.h>, two use -f when f is negative or -0. */
/* Just test both */

/* One special case: -0 */
static void test() {
    float f, f_abs;
    unsigned u, u2, u_abs;
    for (unsigned x = UINT_MAX; x > 0; --x) { // mistake, infinite loop
        f = u2f(x);
        u = isnan(f) ? f2u(f) : ((f < 0 || f == -0.0) ? f2u(-f) : f2u(f)); // careful here
        u2 = isnan(f) ? f2u(f) : f2u(fabsf(f));
        u_abs = float_absval(x);
        f_abs = u2f(u_abs);
		
        if (u != u_abs) {
            /* printf("raw: %x, uf: %x, -uf: %x, isnan: %d\n", *(unsigned *)&f, f2u(f), f2u(-f), isnan(f)); */
            printf("x: %x, u: %x, u_abs: %x, f: %f, f_abs: %f\n", x, u, u_abs, f, f_abs);
        }
        if (u2 != u_abs) {
            /* printf("raw: %x, uf: %x, -uf: %x, isnan: %d\n", *(unsigned *)&f, f2u(f), f2u(-f), isnan(f)); */
            printf("x: %x, u2: %x, u_abs: %x, f: %f, f_abs: %f\n", x, u2, u_abs, f, f_abs);
        }        
        assert(u == u_abs);
        assert(u2 == u_abs);
    };
    // one last test case: bit pattern zero(s)
    assert(float_absval(0) == f2u(0.0));
    assert(float_absval(0) == f2u(fabsf(0.0)));

    printf("all tests pass!\n");    
}

int main() {
    test();

    return 0;
}

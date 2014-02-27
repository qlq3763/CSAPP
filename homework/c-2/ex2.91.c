/* Following the bit-level floating-point coding rules, implement the function with */
/* the following prototype: */
/* /\* Compute -f. If f is NaN, then return f. *\/ */
/* float_bits float_negate(float_bits f); */
/* For floating-point number f , this function computes −f . If f is NaN, your func- */
/* tion should simply return f . */
/* Test your function by evaluating it for all 232 values of argument f and com- */
/* paring the result to what would be obtained using your machine’s floating-point */
/* operations. */

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>
#include "float_def.h"
///////////////////////////////////////////////////////
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(float));
}
///////////////////////////////////////////////////////////////
/* Compute -f. If f is NaN, then return f. */
float_bits float_negate(float_bits f) {
    /* Decompose bit representation into parts */
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;
	
    // NaN, just return
    if ((exp == 0xFF) && (frac != 0)) {
        return f;
    }

    sign = !sign;
    /* Reassemble bits */
    return (sign << 31) | (exp << 23) | frac;

}

// copy from ex2.89.c. Not a good practice. Just for exercise.
// See the button for why the code is changed
float u2f(unsigned u, float *pf) {
    float f = *(float *)&u;
    /* printf("inside u2f, u: %x, f: %x, f: %f\n", u, *(unsigned *)&f, f); */
    /* show_float(f); */
    *pf = f;
    return f;

    /* The return value and the value passed by pf should have the same bit pattern, */
    /* but it does NOT. See main for examples */
    /* union { */
    /* 	unsigned u; */
    /* 	float f; */
    /* } a; */
    /* a.u = u; */
    /* return a.f; */
}
// copy from ex2.83.c. Not a good practice. Just for exercise.
unsigned f2u(float x) {
    unsigned u = *(unsigned *)&x;
    return u;

    /* union { */
    /* 	unsigned u; */
    /* 	float f; */
    /* } a; */
    /* a.f = x; */
    /* return a.u; */
}

// assume 32-bit integer
static void test() {
    float f, f_neg;
    unsigned u, u2;
    for (unsigned x = UINT_MAX; x > 0/* x >= 0 */; --x) { // mistake, infinite loop
        u2f(x, &f);
        u = isnan(f) ? f2u(f) : f2u(-f); // careful here
        u2 = float_negate(x);
        u2f(u2, &f_neg);
		
        if (u2 != u) {
            printf("raw: %x, uf: %x, -uf: %x, isnan: %d\n", *(unsigned *)&f, f2u(f), f2u(-f), isnan(f));
            printf("x: %x, u: %x, u2: %x, f: %f, f_neg: %f\n", x, u, u2, f, f_neg);
        }
        assert(u2 == u);
    };
    // one last test case: bit pattern zero(s)
    assert(float_negate(0) == f2u(-0.0));

    printf("all tests pass!\n");
}

int main() {
    test();
	
    // show the strange behavior of returning from u2f
    unsigned u = 0xffbfffff;
    float f2;
    float f3344 = u2f(u, &f2);
    printf("u: %x, uf: %x, f: %f, uf2: %x\n", u, f2u(f3344), f3344, f2u(f2));
    show_float(f3344);
    show_float(f2);

    return 0;
}

/* In u2f: */
/* ffb => fff */
/* ffa => ffe */
/* ff9 => ffd */
/* ff8 => ffc */
/* 	Do NOT understand the reason. Inside u2f, the bit pattern is correct, when returned, the  */
/* 	bit pattern is not correct. Why? */

/* On one of my machines there is the strange behavior, on another there is NOT. Just keep all these comments */

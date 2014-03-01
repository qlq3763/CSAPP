/* Following the bit-level floating-point coding rules, implement the function with */
/* the following prototype: */
/* /\* Compute (float) i *\/ */
/* float_bits float_i2f(int i); */
/* For argument i, this function computes the bit-level representation of */
/* (float) i. */
/* Test your function by evaluating it for all 232 values of argument f and com- */
/* paring the result to what would be obtained using your machine’s floating-point */
/* operations. */

#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

#include "float_def.h"

/* Compute (float) i */
// assumpe 32-bit, two's-complement integer
float_bits float_i2f(int i) {
    unsigned sign = (i >> 31) & 1;
    
    unsigned bias = 127;
    unsigned exp = 0;
    unsigned frac = 0;

    // one special case
    if (!i) return 0;
    // comment this out, the following code can handle this "special" case
    /* if (i == 0x80000000) { */
    /*     exp = 31 + bias; */
    /*     frac = 0; */
    /*     return (sign << 31) | (exp << 23) | frac;     */
    /* } */

    frac = i;
    if (sign) frac = (~i) + 1;
    // now frac is absoluate value
    // from now on, operate on absolute value
    
    // get bit position of most significant 1
    // copied from internet, this version is (much) faster than the commented version
    unsigned pos_sig = 0;
    unsigned x = frac;
    if (x >= 0x10000) { pos_sig += 16; x >>= 16; }
    if (x >=   0x100) { pos_sig += 8;  x >>= 8; }
    if (x >=    0x10) { pos_sig += 4;  x >>= 4; }
    if (x >=     0x4) { pos_sig += 2;  x >>= 2; }
    if (x >=       2) pos_sig += 1; 
    
    /* for (int k = 0; k < 32; ++k) { */
    /*     if ((frac >> k) & 1)  */
    /*         pos_sig = k; */
    /* } */

    exp = pos_sig + bias;

    // move most significant one to 23th(start from 0)
    if (pos_sig <= 23) {
        frac <<= (23 - pos_sig);
        // Now cast away the implicit bit
        frac &= 0x7fffff;
    }
    else {
        unsigned n = pos_sig - 23;
        // get the bits that will be shifted out
        unsigned shift_out = frac & ((1 << n) - 1);
        frac >>= n;
        // Now cast away the implicit bit
        frac &= 0x7fffff;
        // round to closeset or round to even(when lies in right middle)
        if ((shift_out > (1 << (n - 1))) || ((frac & 1) && (shift_out >> (n - 1)))) 
            frac += 1;
        if (frac == 0x800000) { // round cause overflow, readjust it
            exp += 1;
            frac = 0;
        }
        //printf("--p1-- exp %d, frac: %x\n", exp, frac);
    }

    unsigned u = (sign << 31) | (exp << 23) | frac;
    //unsigned exp2 = (u >> 23) & 0xFF;
    //unsigned frac2 = u & 0x7FFFFF;
    //printf("--p2-- exp: %d, frac: %x\n", exp2, frac2);
    return u;
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
    float f, f_i2f;
    int i;
    unsigned u, u_i2f;
    for (unsigned x = UINT_MAX; x > 0; --x) {
        i = x;
        f = (float)i;
        u = f2u(f);
        u_i2f = float_i2f(i);
        f_i2f = u2f(u_i2f);

        if (u != u_i2f) {
            printf("\nx: %x, i: %x, i_d: %d, f: %f, u: %x, u_i2f: %x, f_i2f: %f\n", 
                   x, i, i, f, u, u_i2f, f_i2f);
        }

        assert(u == u_i2f);
    }
    // one last case
    assert(float_i2f(0) == f2u(0.0));

    printf("%s\n", "All test pass!");
}

int main() {
    test();

    int i = 0xfe000001;
    float_i2f(i);
    float f = i;
    unsigned u = f2u(f);
    unsigned exp = (u >> 23) & 0xFF;
    unsigned frac = u & 0x7FFFFF;
    printf("--p3-- exp: %d, frac: %x\n", exp, frac);

    return 0;
}

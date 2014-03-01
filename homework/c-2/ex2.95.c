/* Following the bit-level floating-point coding rules, implement the function with */
/* the following prototype: */
/* /\* */
/* * Compute (int) f. */
/* * If conversion causes overflow or f is NaN, return 0x80000000 */
/* *\/ */
/* int float_f2i(float_bits f); */
/* For floating-point number f , this function computes (int) f . Your function */
/* should round toward zero. If f cannot be represented as an integer (e.g., it is */
/* out of range, or it is NaN), then the function should return 0x80000000. */
/* Test your function by evaluating it for all 232 values of argument f and com- */
/* paring the result to what would be obtained using your machine’s floating-point */
/* operations. */

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

#include "float_def.h"

/* Compute (int) f.
* If conversion causes overflow or f is NaN, return 0x80000000
*/

/* Assume two's-complement encoding, and 32-bit integers */
int float_f2i(float_bits f) {
    /* Decompose bit representation into parts */
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int bias = 127;
    int limit = 31 + bias;
    // overflow
    // for positive: max = 2^31 - 1
    // for negative: min = -2^31

    // special case min = -2^31
    // merged to the overflow case, but should know there is a special case
    /* if (sign && exp == limit && frac == 0) { */
    /*     return 0x80000000; */
    /* } */

    if (exp >= limit) {  // unsigned comparation, careful
        return 0x80000000;
    }

    // zeros
    if (exp < bias) 
        return 0;

    // now bias <= exp < limit
    // compute absolute value
    frac |= 0x800000; // add the implicit bit back
    int effect_val = exp - bias;
    effect_val += 1; // for the implicit bit
    if (effect_val >= 24) { // no fraction part
        frac <<= (effect_val - 24);
    } 
    else {
        // suposse val = .11001110111 shift the binary dot(.) to right by 5 bit,
        // then val = 11001.110111. Now val has the integer part and the fraction part
        // to convert val to a integer, we need to separate those two parts and do the
        // correct rounding.
        // That is what the following lines do
        int int_mask = ((1 << effect_val) - 1) << (24 - effect_val);
        //int frac_mask = (1 << (24 - effect_val)) - 1;
        int int_part = frac & int_mask;
        //int frac_part = frac & frac_mask;
        // rounding toward zero means just discard the fraction part(?)
        // remember this is abolute value
        frac = int_part >> (24 - effect_val);
    }

    // now turn the abolute value into integer value
    if (sign) {
        frac = (~frac) + 1;
    }

    return (int)frac;
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
    float f;
    int i, i_f;
    
    for (unsigned x = UINT_MAX; x > 0; --x) {
        f = u2f(x);
        i = (int)f;
        i_f = float_f2i(x);

        if (i != i_f) {
            printf("\nx: %x, i: %x, i_d: %d, i_f: %x, i_f_d: %d, f: %f, limit: %d\n", 
                   x, i, i, i_f, i_f, f, 0x80000000);
        }
        assert(i == i_f);
    }
    // one last case
    assert(float_f2i(0) == (int)u2f(0));

    printf("All tests pass!\n");
}

int main() {
    test();

    printf("tmin: %d\n", INT_MIN);
    return 0;
}

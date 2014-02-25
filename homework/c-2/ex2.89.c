/* You have been assigned the task of writing a C function to compute a floating- */
/* point representation of 2x . You decide that the best way to do this is to directly */
/* construct the IEEE single-precision representation of the result. When x is too */
/* small, your routine will return 0.0. When x is too large, it will return +∞. Fill in the */
/* blank portions of the code that follows to compute the correct result. Assume the */
/* function u2f returns a floating-point value having an identical bit representation */
/* as its unsigned argument. */

#include <assert.h>

float u2f(unsigned u) {
	float f = *(float *)&u;
	return f;
}

/* float u2f(unsigned u) { */
/*   union { */
/*     unsigned u; */
/*     float f; */
/*   } a; */
/*   a.u = u; */
/*   return a.f; */
/* } */

float fpwr2(int x) {
	/* Result exponent and fraction */
	unsigned exp, frac;
	unsigned u;

	if (x <  -149) { // -23 + (-126) = -149
		/* Too small. Return 0.0 */
		exp = 0;
		frac = 0;
	} else if (x < -126) { // 1 - 127
		/* Denormalized result */
		exp = 0;
		frac = 1 << (149 + x);
	} else if (x < 	128){ // 254 - 127
		/* Normalized result. */
		exp = x + 127;
		frac = 0; // M = 1 + f = 1 + 0 = 1
	} else {
		/* Too big. Return +oo */
		exp = 255;
		frac = 0;
	}
	/* Pack exp and frac into 32 bits */
	u = exp << 23 | frac;
	/* Return as float */
	return u2f(u);
}

// almost copy from fpwrw-ans.c
static float fpwr2_v2(int x) {
	double rst = 1.0;
	double p2 = 2.0;
	int is_neg = x < 0;
	if (is_neg) x = -x;
	
	while(x > 0) {
		if (x & 1) rst *= p2;
		p2 *= p2;
		x >>= 1;
	}
	return (float)(is_neg ? 1.0 / rst : rst);
}

static void test() {
	for (int i = -200; i < 200; ++i) {
		float f1 = fpwr2(i);
		float f2 = fpwr2_v2(i);
		assert(f1 == f2);
	}
}

int main() {
	test();

	return 0;
}

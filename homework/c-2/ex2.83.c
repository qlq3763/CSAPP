/* Fill in the return value for the following procedure, which tests whether its first */
/* argument is less than or equal to its second. Assume the function f2u returns an */
/* unsigned 32-bit number having the same bit representation as its floating-point */
/* argument. You can assume that neither argument is NaN. The two flavors of zero, */
/* +0 and −0, are considered equal. */
/* int float_le(float x, float y) { */
/* unsigned ux = f2u(x); */
/* unsigned uy = f2u(y); */
/* /\* Get the sign bits *\/ */
/* unsigned sx = ux >> 31; */
/* unsigned sy = uy >> 31; */
/* /\* Give an expression using only ux, uy, sx, and sy *\/ */
/* ; */
/* return */
/* } */

#include <assert.h>
#include <stdio.h>

unsigned f2u(float x) {
	unsigned u = *(unsigned *)&x;

	return u;
}

int float_le(float x, float y) {
	unsigned ux = f2u(x);
	unsigned uy = f2u(y);
	/* Get the sign bits */
	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;
	/* Give an expression using only ux, uy, sx, and sy */
	// Four cases: both positive, both negative, both zero, x negative y positive
	return (!sx && !sy && ux <= uy) || (sx && sy && ux >= uy) ||
		((ux << 1) == 0 && (uy << 1) == 0) || (sx && !sy);
}

static void test() {
	int i = 1 << 31;
	float x1 = 0;
	float x2 = *(float *)&i;
	printf("\n %f \n", x2);

	float x3 = 3344;
	float x4 = 5566;
	
	float x5 = -7788;
	float x6 = -1122;

	// both zero
	assert(float_le(x1, x2) == 1);

	// both positive
	assert(float_le(x3, x4) == 1);
	assert(float_le(x3, x3) == 1);
	assert(float_le(x4, x3) == 0);

	// both negative
	assert(float_le(x5, x6) == 1);
	assert(float_le(x6, x6) == 1);
	assert(float_le(x6, x5) == 0);

	// zero and positive
	assert(float_le(x1, x3) == 1);
	assert(float_le(x2, x3) == 1);
	assert(float_le(x3, x1) == 0);
	assert(float_le(x3, x2) == 0);

	// zero and negative
	assert(float_le(x1, x6) == 0);
	assert(float_le(x2, x6) == 0);
	assert(float_le(x6, x1) == 1);
	assert(float_le(x6, x2) == 1);

	// positive and negative
	assert(float_le(x3, x6) == 0);
	assert(float_le(x6, x3) == 1);
}

int main() {
	test();

	return 0;
}

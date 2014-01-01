/* Write C expressions that evaluate to 1 when the following conditions are true, and */
/* to 0 when they are false. Assume x is of type int. */
/* A. Any bit of x equals 1. */
/* B. Any bit of x equals 0. */
/* C. Any bit in the least significant byte of x equals 1. */
/* D. Any bit in the most significant byte of x equals 0. */
/* Your code should follow the bit-level integer coding rules (page 120), with the */
/* additional restriction that you may not use equality (==) or inequality (!=) tests. */

#include <stdio.h>
#include <assert.h>

/* Get most significant byte from x */
static int get_msb(int x) {
	/* Shift by w-8 */
	int shift_val = (sizeof(int)-1)<<3;
	/* Arithmetic shift */
	int xright = x >> shift_val;
	/* Zero all but LSB */
	return xright & 0xFF;
}

int is_any_bit_one(int x) {
	return !!x;
}

int is_any_bit_zero(int x) {
	return is_any_bit_one(~x);
}

int is_any_bit_one_lsb(int x) {
	return is_any_bit_one(x & 0xff);
}

int is_any_bit_zero_msb(int x) {
	int msb = get_msb(x); // we may add zeros here
	int mask = ~0xff; // remove all other zeros than the ones one msb
	return is_any_bit_zero(msb | mask);
}

static void test() {
	assert(is_any_bit_one(1) == 1);
	assert(is_any_bit_one(0) == 0);

	assert(is_any_bit_zero(1) == 1);
	assert(is_any_bit_zero(-1) == 0);

	assert(is_any_bit_one_lsb(1) == 1);
	assert(is_any_bit_one_lsb(~0xff) == 0);

	int num = (sizeof(int) - 1) << 3;
	assert(is_any_bit_zero_msb(0xfe << num) == 1);
	assert(is_any_bit_zero_msb(0xff << num) == 0);
}

int main() {
	test();
	
	return 0;
}

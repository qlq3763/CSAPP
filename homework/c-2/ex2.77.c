/* Write code for a function with the following prototype: */
/* /\* Divide by power of two. Assume 0 <= k < w-1 *\/ */
/* int divide_power2(int x, int k); */
/* The function should compute x/2k with correct rounding, and it should follow the */
/* bit-level integer coding rules (page 120). */

#include <assert.h>

int divide_power2(int x, int k) {
	int w = sizeof(x) << 3;
	assert(0 <= k && k < w - 1);

	/* (x < 0 ? x + (1 << k) - 1 : x) >> k; */
	int mask = (1 << k) - 1;
	// fill all the bits with sign bit, then mask unnessary part
	int bias = (x >> (w - 1)) & mask;

	return (x + bias) >> k;
}

static void test() {
	assert(divide_power2(14, 2) == 14 / 4);
	assert(divide_power2(-14, 2) == -14 / 4);

	assert(divide_power2(14, 0) == 14 / 1);
	assert(divide_power2(-14, 0) == -14 / 1);

	assert(divide_power2(34567, 4) == 34567 / 16);
	assert(divide_power2(-34567, 4) == -34567 / 16);
}

int main() {
	test();

	return 0;
}

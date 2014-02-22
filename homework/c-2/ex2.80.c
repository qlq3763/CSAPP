/* Write C expressions to generate the bit patterns that follow, where a k represents */
/* k repetitions of symbol a. Assume a w-bit data type. Your code may contain */
/* references to parameters j and k, representing the values of j and k, but not a */
/* parameter representing w. */
/* A. 1w−k 0k */
/* B. 0w−k−j 1k 0j */

#include <assert.h>

int kzeros(int k) {
	int w = sizeof(int) << 3;

	assert(0 <= k && k < w);

	return ~((1 << k) - 1);
}

int kones_jzeros(int k, int j) {
	int w = sizeof(int) << 3;

	assert(0 <= k && k < w);
	assert(0 <= j && j < w);

	return ((1 << k) - 1) << j;
}

// assume 4-bytes int
static void test() {
	assert(kzeros(0) == ~0);
	assert(kzeros(4) == ~0xf);
	assert(kzeros(8) == ~0xff);
	assert(kzeros(12) == ~0xfff);
	assert(kzeros(16) == ~0xffff);
	assert(kzeros(20) == ~0xfffff);
	assert(kzeros(24) == ~0xffffff);
	assert(kzeros(28) == ~0xfffffff);

	assert(kones_jzeros(0, 0) == 0);

	assert(kones_jzeros(4, 0) == 0xf);
	assert(kones_jzeros(0, 4) == 0);
	assert(kones_jzeros(4, 4) == 0xf0);

	assert(kones_jzeros(12, 0) == 0xfff);
	assert(kones_jzeros(0, 12) == 0);
	assert(kones_jzeros(12, 12) == 0xfff000);
}

int main() {
	test();

	return 0;
}

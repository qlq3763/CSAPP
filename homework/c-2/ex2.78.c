/* Write code for a function mul3div4 that, for integer argument x, computes 3*x/4, */
/* but following the bit-level integer coding rules (page 120). Your code should */
/* replicate the fact that the computation 3*x can cause overflow. */

#include <assert.h>
#include <limits.h>

// from ex2.77.c
int divide_power2(int x, int k) {
	int w = sizeof(x) << 3;
	assert(0 <= k && k < w - 1);

	/* (x < 0 ? x + (1 << k) - 1 : x) >> k; */
	int mask = (1 << k) - 1;
	// fill all the bits with sign bit, then mask unnessary part
	int bias = (x >> (w - 1)) & mask;

	return (x + bias) >> k;
}

int mul3div4(int x) {
	x = x + (x << 1);
	return divide_power2(x, 2);
}

static void test() {
	int tmax = INT_MAX;
	int tmin = INT_MIN;

	assert(mul3div4(tmax) == tmax * 3 / 4);
	assert(mul3div4(tmin) == tmin * 3 / 4);

	assert(mul3div4(7788) == 7788 * 3 / 4);
	assert(mul3div4(-8899) == -8899 * 3 / 4);
}

int main() {
	test();

	return 0;
}

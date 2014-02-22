/* Write code for a function threefourths which, for integer argument x, computes */
/* the value of 3/4 x, rounded toward zero. It should not overflow. Your function should */
/* follow the bit-level integer coding rules (page 120). */

#include <assert.h>

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

// 3/4 = 1/2 + 1/4
// the above equation will make the work easier
// little sample
// x:          0 1 2 3 4 5 6 7 8 9
// 3/4*x:      0 0 1 2 3 3 4 5 6 6
// x/2 + x/4:  0 0 1 1 3 3 4 4 6 6

// x:          0 -1 -2 -3 -4 -5 -6 -7 -8 -9
// 3/4*x:      0  0 -1 -2 -3 -3 -4 -5 -6 -6
// x/2 + x/4:  0  0 -1 -1 -3 -3 -4 -4 -6 -6

int threefourths(int x) {
	int w = sizeof(x) << 3;
	int sx = x >> (w - 1); // all 0(s) or all 1(s)
	int mod4 = x & 3;

	int need_bias = (!sx && mod4 == 3) || (sx && mod4 == 1);
	int neg_bias = (need_bias & sx) << (w - 1) >> (w - 1); // 0(s) or 1(s)
	int pos_bias = need_bias; // 0 or 1
	int bias = neg_bias | pos_bias;

	return divide_power2(x, 1) + divide_power2(x, 2) + bias;
}

static void test() {
	assert(threefourths(0) == 0);
	assert(threefourths(1) == 0);
	assert(threefourths(2) == 1);
	assert(threefourths(3) == 2);
	assert(threefourths(4) == 3);
	assert(threefourths(5) == 3);
	assert(threefourths(6) == 4);
	assert(threefourths(7) == 5);
	assert(threefourths(8) == 6);
	assert(threefourths(9) == 6);

	assert(threefourths(-1) == 0);
	assert(threefourths(-2) == -1);
	assert(threefourths(-3) == -2);
	assert(threefourths(-4) == -3);
	assert(threefourths(-5) == -3);
	assert(threefourths(-6) == -4);
	assert(threefourths(-7) == -5);
	assert(threefourths(-8) == -6);
	assert(threefourths(-9) == -6);
}

int main() {
	test();

	return 0;
}

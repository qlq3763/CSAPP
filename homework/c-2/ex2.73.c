/* Write code for a function with the following prototype: */
/* /\* Addition that saturates to TMin or TMax *\/ */
/* int saturating_add(int x, int y); */
/* Instead of overflowing the way normal two’s-complement addition does, sat- */
/* urating addition returns TMax when there would be positive overflow, and TMin */
/* when there would be negative overflow. Saturating arithmetic is commonly used */
/* in programs that perform digital signal processing. */
/* Your function should follow the bit-level integer coding rules (page 120). */

#include <assert.h>
#include <limits.h>

int saturating_add(int x, int y) {
	int rst = x + y;
	int w = sizeof(x) << 3;
	int k = w - 1;

	int sx = x >> k;
	int sy = y >> k;
	int sr = rst >> k;

	/* three cases: */
	/* 1. positive + positive => negative, positive overflow, should return INT_MAX; */
	/* 2. negative + negative => positive, negative overflow, should return INT_MIN; */
	/* 3. no overflow, should return rst. */

	// tmax = 0 or INT_MAX
	int tmax = ((!sx && !sy && sr) << k >> k) & INT_MAX;

	// tmin = 0 or INT_MIN
	int tmin = ((sx && sy && !sr) << k >> k) & INT_MIN;

	// rst = 0 when there is overflow; stay the same otherwise.
	// when there is no overflow, tmax == tmin == 0; tmax != tmin otherwise
	rst = ((tmax == tmin) << k >> k) & rst;

	return (rst | tmax | tmin);
}

static void test() {
	int tmax = INT_MAX;
	int tmin = INT_MIN;
	int n1 = tmax - 14;
	int n2 = tmin + 14;

	assert(saturating_add(tmax, 1) == tmax);
	assert(saturating_add(tmin, -1) == tmin);
	
	assert(saturating_add(n1, 13) == n1 + 13);
	assert(saturating_add(n1, 14) == n1 + 14);
	assert(saturating_add(n1, 15) == tmax);
	assert(saturating_add(n1, 2233) == tmax);

	assert(saturating_add(n2, -13) == n2 - 13);
	assert(saturating_add(n2, -14) == n2 - 14);
	assert(saturating_add(n2, -15) == tmin);
	assert(saturating_add(n2, -2233) == tmin);

	assert(saturating_add(tmax, tmin) == tmax + tmin);
	assert(saturating_add(n1, n2) == n1 + n2);
	assert(saturating_add(3344, 5566) == 3344 + 5566);
}

int main() {
	test();

	return 0;
}

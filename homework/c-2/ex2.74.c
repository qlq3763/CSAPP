/* Write a function with the following prototype: */
/* /\* Determine whether arguments can be subtracted without overflow *\/ */
/* int tsub_ok(int x, int y); */
/* This function should return 1 if the computation x − y does not overflow. */

#include <assert.h>
#include <limits.h>

int tsub_ok(int x, int y) {
	// Need be careful with a special case: x = 0, and y = INT_MIN.
	// over flow case 1
	int ovf1 = x >= 0 && y <=0 && (x - y) < 0;
	// over flow case 2
	int ovf2 = x <= 0 && y >= 0 && (x - y) > 0;

	return !ovf1 && !ovf2;
}

// suppose two's complement implementation of integer
static void test() {
	int tmin = INT_MIN;
	int tmax = INT_MAX;

	assert(tsub_ok(0, tmin) == 0);
	assert(tsub_ok(-1, tmin) == 1);

	assert(tsub_ok(0, tmax) == 1);
	assert(tsub_ok(-1, tmax) == 1);
	assert(tsub_ok(-2, tmax) == 0);

	assert(tsub_ok(tmax, tmin) == 0);
	assert(tsub_ok(tmin, tmax) == 0);

	assert(tsub_ok(-2233, tmin) == 1);
	assert(tsub_ok(5566, tmax) == 1);
}

int main() {
	test();

	return 0;
}

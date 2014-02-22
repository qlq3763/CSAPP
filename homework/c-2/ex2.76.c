/* Suppose we are given the task of generating code to multiply integer variable x */
/* by various different constant factors K. To be efficient, we want to use only the */
/* operations +, -, and <<. For the following values of K, write C expressions to */
/* perform the multiplication using at most three operations per expression. */
/* A. K = 17 */
/* B. K = -7 */
/* C. K = 60 */
/* D. K = -112 */

#include <assert.h>
#include <limits.h>

int mul_17(int x) {	return (x << 4) + x; }

int mul_m7(int x) { return x - (x << 3); }

int mul_60(int x) { return (x << 6) - (x << 2); }

int mul_m112(int x) { return (x << 4) - (x << 7); }

static void test() {
	int n1 = INT_MAX;
	int n2 = INT_MIN;
	int n3 = 3344;
	int n4 = -7788;

	assert(mul_17(n1) == n1 * 17);
	assert(mul_17(n2) == n2 * 17);
	assert(mul_17(n3) == n3 * 17);
	assert(mul_17(n4) == n4 * 17);

	assert(mul_m7(n1) == n1 * -7);
	assert(mul_m7(n2) == n2 * -7);
	assert(mul_m7(n3) == n3 * -7);
	assert(mul_m7(n4) == n4 * -7);

	assert(mul_60(n1) == n1 * 60);
	assert(mul_60(n2) == n2 * 60);
	assert(mul_60(n3) == n3 * 60);
	assert(mul_60(n4) == n4 * 60);

	assert(mul_m112(n1) == n1 * -112);
	assert(mul_m112(n2) == n2 * -112);
	assert(mul_m112(n3) == n3 * -112);
	assert(mul_m112(n4) == n4 * -112);
}

int main() {
	test();

	return 0;
}

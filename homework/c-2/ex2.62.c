/* Write a function int_shifts_are_arithmetic() that yields 1 when run on a */
/* machine that uses arithmetic right shifts for int’s, and 0 otherwise. Your code */
/* should work on a machine with any word size. Test your code on several machines. */

#include <stdio.h>
#include <assert.h>

int int_shifts_are_arithmetic() {
	int x = ~0; // make a value that has sign bit set to 1
	x >>= 1;
	// the number of shift to move the new sign bit to the least significant bit
	int num_shift = (sizeof(x) << 3) - 1;
	return (x >> num_shift) & 1;
}

// this function should return 0
static int for_test() {
	unsigned int x = ~0; // make a value that has sign bit set to 1
	x >>= 1;
	// the number of shift to move the new sign bit to the least significant bit
	int num_shift = (sizeof(x) << 3) - 1;
	return (x >> num_shift) & 1;
}

static void test() {
	assert(int_shifts_are_arithmetic() == 1);
	assert(for_test() == 0);
}

int main() {
	test();

	return 0;
}

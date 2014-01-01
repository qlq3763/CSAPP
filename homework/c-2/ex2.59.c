/* Write a C expression that will yield a word consisting of the least significant */
/* byte of x, and the remaining bytes of y. For operands x = 0x89ABCDEF and y = */
/* 0x76543210, this would give 0x765432EF. */

#include <stdio.h>

#include "./lib/show-bytes.h"

// I will use type long as a "word".
long least_x_remaining_y(long x, long y) {
	long xmask = 0xff;
	long ymask = ~xmask;
	return (x & xmask) | (y & ymask);
}

static void show_long(long x) {
  show_bytes((byte_pointer)&x, sizeof(x));  
}

static void test() {
	long x = 0x11223344;
	long y = 0xaabbccdd;
	show_long(x);
	show_long(y);
	show_long(least_x_remaining_y(x, y));
}

int main() {
	test();

	return 0;
}

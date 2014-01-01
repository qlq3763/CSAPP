/* Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8 − 1 */
/* (most significant). Write code for the following C function, which will return an */
/* unsigned value in which byte i of argument x has been replaced by byte b: */
/* unsigned replace_byte (unsigned x, int i, unsigned char b); */
/* Here are some examples showing how the function should work: */
/* replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678 */
/* replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB */

#include <stdio.h>
#include <assert.h>

#include "./lib/show-bytes.h"

static void show_unsigned_int(unsigned x) {
	show_bytes((byte_pointer)&x, sizeof(x));
}

unsigned replace_byte(unsigned x, int i, unsigned char b) {
	int word_size = sizeof(x);
	assert(0 <= i && i < word_size);

	int shift_num = i << 3;
	unsigned mask = ~(0xff << shift_num);
	// need cast here, for we should NOT shift char more(or equal) than 8 bits.
	unsigned shifted_value = (unsigned)b << shift_num;

	return (x & mask) | shifted_value;
}

static void test() {
	unsigned x = 0x11223344;
	unsigned char b = 0xcc;
	
	show_unsigned_int(x);

	for (int i = 0; i < sizeof(x); ++i)
		show_unsigned_int(replace_byte(x, i, b));
}

int main() {
	test();

	return 0;
}

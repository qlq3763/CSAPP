/* Write code for a function with the following prototype: */
/* /\* */
/* * Do rotating left shift. Assume 0 <= n < w */
/* * Examples when x = 0x12345678 and w = 32: */
/* * n=4 -> 0x23456781, n=20 -> 0x67812345 */
/* *\/ */
/* unsigned rotate_left(unsigned x, int n); */
/* Your function should follow the bit-level integer coding rules (page 120). Be */
/* careful of the case n = 0. */

#include <assert.h>

unsigned rotate_left(unsigned x, int n) {
  int w = sizeof(x) * 8;
  assert(0 <= n && n < w);

  // get the most significant n bits that will be shifted away
  unsigned most_n = x >> (w - n - 1) >> 1;

  x <<= n;

  return x | most_n;
}

unsigned rotate_right(unsigned x, int n) {
	int w = sizeof(x) * 8;
	assert(0 <= n && n < w);

	// get the least siginificant n bits that will be shifted away
	unsigned most_n = x & ((1 << n) - 1);
	// shift most_n to the most significant bits
	most_n = most_n << (w - n - 1) << 1;

	x >>= n;

	return x | most_n;
}

// assume int is of 4 bytes
static void test() {
  unsigned x = 0x12345678;

  int n1 = 4;
  unsigned lx_rst1 = 0x23456781;
  unsigned rx_rst1 = 0x81234567;

  int n2 = 20;
  unsigned lx_rst2 = 0x67812345;
  unsigned rx_rst2 = 0x45678123;

  int n3 = 0;
  unsigned lx_rst3 = x;
  unsigned rx_rst3 = x;

  int n4 = 31;
  unsigned lx_rst4 = 0x091a2b3c;
  unsigned rx_rst4 = 0x2468acf0;

  assert(rotate_left(x, n1) == lx_rst1);
  assert(rotate_left(x, n2) == lx_rst2);
  assert(rotate_left(x, n3) == lx_rst3);
  assert(rotate_left(x, n4) == lx_rst4);

  assert(rotate_right(x, n1) == rx_rst1);
  assert(rotate_right(x, n2) == rx_rst2);
  assert(rotate_right(x, n3) == rx_rst3);
  assert(rotate_right(x, n4) == rx_rst4);

}

int main() {
  test();

  return 0;
}

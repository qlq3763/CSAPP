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

static void test() {
  unsigned x = 0x12345678;

  int n1 = 4;
  unsigned x_rst1 = 0x23456781;

  int n2 = 20;
  unsigned x_rst2 = 0x67812345;

  int n3 = 0;
  unsigned x_rst3 = x;

  int n4 = 31;
  unsigned x_rst4 = 0x091a2b3c;

  assert(rotate_left(x, n1) == x_rst1);
  assert(rotate_left(x, n2) == x_rst2);
  assert(rotate_left(x, n3) == x_rst3);
  assert(rotate_left(x, n4) == x_rst4);
}

int main() {
  test();

  return 0;
}

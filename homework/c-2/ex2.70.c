/* Write code for the function with the following prototype: */
/* /\* */
/* * Return 1 when x can be represented as an n-bit, 2’s complement */
/* * number; 0 otherwise */
/* * Assume 1 <= n <= w */
/* *\/ */
/* int fits_bits(int x, int n); */
/* Your function should follow the bit-level integer coding rules (page 120). */

#include <assert.h>

int fits_bits(int x, int n) {
  int w = sizeof(x) * 8;
  assert(1 <= n && n <= w);

  // truncate, then sign extension
  int xn = (x << (w - n)) >> (w - n);
  return xn == x;
}

static void test() {
  int n = 8;
  
  for (int i = -128; i < 128; ++i)
    assert(fits_bits(i, n) == 1);

  assert(fits_bits(-129, n) == 0);
  assert(fits_bits(128, n) == 0);

  assert(fits_bits(-3344, n) == 0);
  assert(fits_bits(5566, n) == 0);
}

int main() {
  test();

  return 0;
}

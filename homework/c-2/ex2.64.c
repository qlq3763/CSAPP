/* Write code to implement the following function: */
/* /\* Return 1 when any odd bit of x equals 1; 0 otherwise. */
/* Assume w=32. *\/ */
/* int any_odd_one(unsigned x); */
/* Your function should follow the bit-level integer coding rules (page 120), except */
/* that you may assume that data type int has w = 32 bits. */

#include <assert.h>
#include <stdio.h>

/* 0 1 2 3 4 5 6 7... */
/* 0 1 0 1 0 1 0 1 */

int any_odd_one(unsigned x) {
  int mask = 0xaaaaaaaa; // 0101 0101 ......
  return !!(x & mask);
}

static void test() {
  int x1 = 1;
  int x2 = 2;
  int x3 = 4;
  int x4 = 8;

  assert(any_odd_one(x1) == 0);
  assert(any_odd_one(x2) == 1);
  assert(any_odd_one(x3) == 0);
  assert(any_odd_one(x4) == 1);
}

int main() {
  printf("size of int: %d\n", sizeof(int));

  test();

  return 0;
}

/* Write code to implement the following function: */
/* /\* */
/* * Generate mask indicating leftmost 1 in x. Assume w=32. */
/* * For example 0xFF00 -> 0x8000, and 0x6600 --> 0x4000. */
/* * If x = 0, then return 0. */
/* *\/ */
/* int leftmost_one(unsigned x); */
/* Your function should follow the bit-level integer coding rules (page 120), except */
/* that you may assume that data type int has w = 32 bits. */
/* Your code should contain a total of at most 15 arithmetic, bit-wise, and logical */
/* operations. */
/* Hint: First transform x into a bit vector of the form [0 . . . 011 . . . 1]. */

#include <assert.h>
#include <stdio.h>

int leftmost_one(unsigned x) {
  // propagate the left most one
  x |= x >> 1; 
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  
  //printf("x: %d\n", x);
  return x - (x >> 1);
}

static void test() {
  int x0 = 0x0;
  int x1 = 0x1;
  int x2 = 0x21;
  int x3 = 0x321;
  int x4 = 0x4321;
  int x5 = 0x54321;
  int x6 = 0x654321;
  int x7 = 0x7654321;
  int x8 = 0x87654321;

  assert(leftmost_one(x0) == 0x0);
  assert(leftmost_one(x1) == 0x1);
  assert(leftmost_one(x2) == 0x20);
  assert(leftmost_one(x3) == 0x200);
  assert(leftmost_one(x4) == 0x4000);
  assert(leftmost_one(x5) == 0x40000);
  assert(leftmost_one(x6) == 0x400000);
  assert(leftmost_one(x7) == 0x4000000);
  assert(leftmost_one(x8) == 0x80000000);
}

int main() {
  test();

  return 0;
}

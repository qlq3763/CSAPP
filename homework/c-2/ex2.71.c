#include <assert.h>
#include <stdio.h>
/* A. */
/* This code just extracts the designated byte, but no extension. */

/* B. */
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum) {
  assert(0 <= bytenum && bytenum < sizeof(word));

  int w = sizeof(word) * 8;
  int n = bytenum * 8;

  int nth_byte = (word >> n) & 0xff;
  // in case n = 0
  nth_byte = (nth_byte << (w - 8)) >> (w - 8);
  //printf("%x\n", nth_byte);
  return nth_byte;
}

static void test() {
  int x = 0x1122fffe;
  
  assert(xbyte(x, 0) == -2);
  assert(xbyte(x, 1) == -1);
  assert(xbyte(x, 2) == 0x22);
  assert(xbyte(x, 3) == 0x11);
}

int main() {
  test();

  return 0;
}

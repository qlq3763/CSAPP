/* You just started working for a company that is implementing a set of procedures */
/* to operate on a data structure where 4 signed bytes are packed into a 32-bit */
/* unsigned. Bytes within the word are numbered from 0 (least significant) to 3 */
/* (most significant). You have been assigned the task of implementing a function */
/* for a machine using two’s-complement arithmetic and arithmetic right shifts with */
/* the following prototype: */
/* /\* Declaration of data type where 4 bytes are packed */
/* into an unsigned *\/ */
/* typedef unsigned packed_t; */
/* /\* Extract byte from word. Return as signed integer *\/ */
/* int xbyte(packed_t word, int bytenum); */
/* That is, the function will extract the designated byte and sign extend it to be a */
/* 32-bit int. */
/* Your predecessor (who was fired for incompetence) wrote the following code: */
/* /\* Failed attempt at xbyte *\/ */
/* int xbyte(packed_t word, int bytenum) */
/* { */
/* return (word >> (bytenum << 3)) & 0xFF; */
/* } */
/* A. What is wrong with this code? */
/* B. Give a correct implementation of the function that uses only left and right */
/* shifts, along with one subtraction. */

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

/* Write procedures show_short, show_long, and show_double that print the byte */

#include <stdio.h>

#include "./lib/show-bytes.h"

/* Wonder which way is better: sizeof(type-name) VS sizeof(variable-name) */
void show_short(short x) {
  show_bytes((byte_pointer)&x, sizeof(x));
}

void show_long(long x) {
  show_bytes((byte_pointer)&x, sizeof(x));  
}

void show_double(double x) {
  show_bytes((byte_pointer)&x, sizeof(x));
}


static void test() {
  short s = 0x34AB;
  long l = 0x1122AABB;
  double d = 1.0;
  
  show_short(s);
  show_long(l);
  show_double(d);
}

int main() {
  test();

  return 0;
}

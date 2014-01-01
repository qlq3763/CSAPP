/* Write a procedure is_little_endian that will return 1 when compiled and run */
/* on a little-endian machine, and will return 0 when compiled and run on a big- */
/* endian machine. This program should run on any machine, regardless of its word */
/* size. */

#include <stdio.h>
#include <stdbool.h>

// Assumption: 
// type int uses a multiple-byte(more than one) representation.
// type char uses a one-byte representation.
bool is_little_endian() {
	int i = 1;
	// get the value of the lowest-address byte.
	unsigned char uc = *(unsigned char*)&i;
	return  uc == 1;
}

int main() {
	printf("is little endian: %s\n", is_little_endian() ? "true" : "false");

	return 0;
}

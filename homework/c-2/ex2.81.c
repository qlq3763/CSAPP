/* We are running programs on a machine where values of type int are 32 bits. They */
/* are represented in two’s complement, and they are right shifted arithmetically. */
/* Values of type unsigned are also 32 bits. */
/* We generate arbitrary values x and y, and convert them to unsigned values as */
/* follows: */
/* /\* Create some arbitrary values *\/ */
/* int x = random(); */
/* int y = random(); */
/* /\* Convert to unsigned *\/ */
/* unsigned ux = (unsigned) x; */
/* unsigned uy = (unsigned) y; */
/* For each of the following C expressions, you are to indicate whether or */
/* not the expression always yields 1. If it always yields 1, describe the underlying */
/* mathematical principles. Otherwise, give an example of arguments that make it */
/* yield 0. */
/* A. (x<y) == (-x>-y) */
/* B. ((x+y)<<4) + y-x == 17*y+15*x */
/* C. ~x+~y+1 == ~(x+y) */
/* D. (ux-uy) == -(unsigned)(y-x) */
/* E. ((x >> 2) << 2) <= x */

/* A.  */
/* x = tmin, y = 0; */
/* -x = tmin, -y = 0. */

/* B. */
/* Correct. */
/* 	16(x+y) + y - x = 17y + 15x. */

/* C. */
/* 	Equation:	-x = ~x + 1; => ~x = -x - 1; */

/* ~(x+y) = -(x+y) - 1; */
/* ~x + ~y + 1 = -x - 1 + -y - 1 + 1 = (-x+y) - 1; */

/* So, correct. */

/* D. */
/* Correct. */
/* See the code in "main". */
/* The expressions on the two sides of "==" will produce the same bit-level results. And  */
/* they are both interpretated as unsingned integer, so the whole expression will be always */
/* true. */

/* One thing I am not sure: what is the meaning of apply "-" to an unsigned integer? From the code, */
/* I guess this has the same bit-level effect as applied to signed integer(that is: ~x + 1). */

/* E. */
/* Correct. */
/* 	let rst = (x >> 2) << 2; This may lose one or two of the least significant bits, now */
	/* consider two cases:	 */
	/* 1. x >= 0, rst <= x; */
	/* 2. x < 0 (x = -2), rst <= x. */

#include <assert.h>
#include <stdio.h>

int main() {
	int x = 4;
	int y = 14;
	
	int ux = (unsigned)x;
	int uy = (unsigned)y;

	assert((ux-uy) == -(unsigned)(y-x));
	assert((uy-ux) == -(unsigned)(x-y));

	printf("\n%x\n", -x);

	return 0;
}

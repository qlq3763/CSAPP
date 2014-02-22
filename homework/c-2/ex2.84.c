/* Given a floating-point format with a k-bit exponent and an n-bit fraction, write */
/* formulas for the exponent E, significand M, the fraction f , and the value V for */
/* the quantities that follow. In addition, describe the bit representation. */
/* A. The number 7.0 */
/* B. The largest odd integer that can be represented exactly */
/* C. The reciprocal of the smallest positive normalized value */

/* A. */
/* 7/4 = 1 + 3/4; */
/* E = 2 */
/* f = 3/4 */
/* M = 1 + f = 7/4 */
/* V = M.2^E = 7 */

/* bit representation: (sign bit)  */
/*                     (bit representation for (2 + 2^(k-1) - 1))  */
/*                     (bit representation for 3/4) */

/* B. */
/* All 1(s) for the n-bit fraction: f = (1 - 2^-n), M = 1 + f, E = n */
/* V = 2 ^ (n+1) - 1 */

/* C. */
/* Smallest positive normalized value: 
E = 1 - (2^(k-1) - 1) = -2^(k-1) + 2 */
/* f = 0, M = 1 + f = 1 */
/* V = M.2^E = 2^(-2^(k-1) + 2) */
/* Reciprocal: (2^2^(k-1)) / 4 */

#include <stdio.h>

int main() {
	// binary representation of 7.0
	// sign(0)       e(129)            f(3/4)
	// 0            1000 0001           .11000000000000000000000
	// 0x40e00000
	int j = 0x40e00000;
	float f = 7.0;
	float f1 = *(float *)&j;
	
	printf("\n j = %x, f = %x, f1 = %x \n", j, *(int *)&f, *(int *)&f1);
	printf("\n j = %f, f = %f, f1 = %f \n", *(float *)&j, f, f1);

	/////////////////////////////////////////////////////////////
	// largest integer that can be represented exactly by a float(32 bit)
	float f2 = 1 << 24;

	float f2m1 = f2 - 1;
	float f2m2 = f2 - 2;
	float f2m3 = f2 - 3;

	float f2p1 = f2 + 1;
	float f2p2 = f2 + 2;
	float f2p3 = f2 + 3;
	printf("\n f2-3 = %f, f2-2 = %f, f2-1 = %f, \n f2 = %f, \n f2+1 = %f, f2+2 = %f, f2+3 = %f \n", 
		   f2m3, f2m2, f2m1, 
		   f2, 
		   f2p1, f2p2, f2p3);

	return 0;
}

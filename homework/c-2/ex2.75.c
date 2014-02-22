/* Suppose we want to compute the complete 2w-bit representation of x . y, where */
/* both x and y are unsigned, on a machine for which data type unsigned is w bits. */
/* The low-order w bits of the product can be computed with the expression x*y, so */
/* we only require a procedure with prototype */
/* unsigned int unsigned_high_prod(unsigned x, unsigned y); */
/* that computes the high-order w bits of x . y for unsigned variables. */
/* We have access to a library function with prototype */
/* int signed_high_prod(int x, int y); */
/* that computes the high-order w bits of x . y for the case where x and y are in two’s- */
/* complement form. Write code calling this procedure to implement the function */
/* for unsigned arguments. Justify the correctness of your solution. */
/* Hint: Look at the relationship between the signed product x . y and the */
/* unsigned product x . y in the derivation of Equation 2.18. */


/* I now found that the version of my text book(Chinese English version) has some minor differences */
/* from the standard English version. */

/* My version asks me to compute signed from unsigned */

/* I will follow the standard version, for the underlying pricipals are the same and I've used the standard  */
/* verions for some precious exercises. */

/* x' * y' = (x + xw-1 * 2^w).(y + yw-1 * 2^w) */
/* 	= x.y + (xw-1*y + yw-1*x)2^w + xw-1*yw-1*2^w */

// from the above equation, we just need to coumpute xw-1*y + yw-1*x(the 2^w
// part will be moudulus away)
int signed_high_prod(int x, int y) { return 0; } // for compile

unsigned int unsigned_high_prod(unsigned x, unsigned y) {
	int shp = (unsigned)signed_high_prod(x, y);
	int k = (sizeof(x) << 3) - 1;

	unsigned sx = x >> k;
	unsigned sy = y >> k;

	return shp + sx * y + sy * x;
}

int main() { return 0; }

/* Fill in code for the following C functions. Function srl performs a logical right */
/* shift using an arithmetic right shift (given by value xsra), followed by other oper- */
/* ations not including right shifts or division. Function sra performs an arithmetic */
/* right shift using a logical right shift (given by value xsrl), followed by other */
/* operations not including right shifts or division. You may use the computation */
/* 8*sizeof(int) to determine w, the number of bits in data type int. The shift */
/* amount k can range from 0 to w − 1. */

#include <assert.h>

unsigned srl(unsigned x, int k) {
	int word_size = sizeof(x) << 3;
	assert(0 <= k && k < word_size);
	/* Perform shift arithmetically */
	unsigned xsra = (int) x >> k;

	// get (word_size - k) ones
	// 1 << 1, then << (word_size - k - 1). In case k == 0
    unsigned mask = ((1 << 1) << (word_size - k - 1)) - 1;
	// k zeros followed by ones
	//unsigned mask = ~wk_ones;
	
	return xsra & mask;
}

int sra(int x, int k) {
	int word_size = sizeof(x) << 3;
	assert(0 <= k && k < word_size);
	/* Perform shift logically */
	int xsrl = (unsigned) x >> k;

	// get k ones
	unsigned k_ones = (1 << k) - 1;
	// in case k == 0
	unsigned mask = (k_ones << 1) << (word_size - k - 1);

	return (x < 0) ? xsrl | mask : xsrl;
}

static void test() {
	unsigned ux = ~0;
	unsigned ux2 = 1;
	int ix = ~0;
	int ix2 = 1;

	assert(srl(ux, 0) == ux);
	assert(srl(ux, 9) == (ux >> 9));
	assert(srl(ux, 31) == (ux >> 31));
	
	assert(srl(ux2, 0) == ux2);
	assert(srl(ux2, 9) == (ux2 >> 9));
	assert(srl(ux2, 31) == (ux2 >> 31));

	assert(sra(ix, 0) == ix);
	assert(sra(ix, 9) == (ix >> 9));
	assert(sra(ix, 31) == (ix >> 31));		   

	assert(sra(ix2, 0) == ix2);
	assert(sra(ix2, 9) == (ix2 >> 9));
	assert(sra(ix2, 31) == (ix2 >> 31));		   
}


int main() {
	test();

	return 0;
}

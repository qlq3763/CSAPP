/* Consider numbers having a binary representation consisting of an infinite string */
/* of the form 0.y y y y y y . . ., where y is a k-bit sequence. For example, the binary */
/* representation of 1/3 is 0.01010101 . . . (y = 01), while the representation of 1/5 is */
/* . . . (y = 0011). */
/* 0.001100110011 */
/* A. Let Y = B2U k (y), that is, the number having binary representation y. Give */
/* a formula in terms of Y and k for the value represented by the infinite string. */
/* Hint: Consider the effect of shifting the binary point k positions to the right. */
/* B. What is the numeric value of the string for the following values of y? */
/* (a) 101 */
/* (b) 0110 */
/* (c) 010011 */

A.
geometric sequence:
v = Y/2^k / (1 - 1/2^k) = Y/(2^k - 1)

B.
(a) Y = 5, k = 3, so v = 5/7
(b) Y = 6, k = 4, so v = 6/15, notice the relation between this binary string and that of 1/5
(c) Y = 19, k = 6, so v = 19/63

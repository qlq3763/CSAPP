/* Using the same tree data structure we saw in Problem 3.69, and a function with */
/* the prototype */
/* long traverse(tree_ptr tp); */
/* gcc generates the following x86-64 code: */

/* traverse: */
/* tp in %rdi */
/* movq %rbx, -24(%rsp) */
/* movq %rbp, -16(%rsp) */
/* movq %r12, -8(%rsp) */
/* subq $24, %rsp */
/* movq %rdi, %rbp */
/* movabsq $-9223372036854775808, %rax */
/* testq %rdi, %rdi */
/* je .L9 */
/* movq (%rdi), %rbx */
/* movq 8(%rdi), %rdi */
/* call traverse */
/* movq %rax, %r12 */
/* movq 16(%rbp), %rdi */
/* call traverse */
/* cmpq %rax, %r12 */
/* cmovge %r12, %rax */
/* cmpq %rbx, %rax */
/* cmovl %rbx, %rax */
/* .L9: */
/* movq (%rsp), %rbx */
/* movq 8(%rsp), %rbp */
/* movq 16(%rsp), %r12 */
/* addq $24, %rsp */
/* ret */


#include <limits.h>

#define NULL 0

typedef struct ELE *tree_ptr;

struct ELE {
    long val;
    tree_ptr left;
    tree_ptr right;
};

/* 0x8000000000000000 */ 
/* $-9223372036854775808 */
/* the smallest value of 8-byte long */
long traverse(tree_ptr tp) {
    long result = LONG_MIN;
    long cur, left;

    if (tp != NULL) {
        cur = tp->val;
        left = traverse(tp->left);
        result = traverse(tp->right);
        result = (left >= result) ? left : result;
        result = (cur > result) ? cur : result;
    }

    return result;
}

// this function get the largest value of all nodes.

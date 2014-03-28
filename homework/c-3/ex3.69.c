/* The following declaration defines a class of structures for use in constructing */
/* binary trees: */

/* typedef struct ELE *tree_ptr; */

/* struct ELE { */
/* long val; */
/* tree_ptr left; */
/* tree_ptr right; */
/* }; */

/* For a function with the following prototype: */
/* long trace(tree_ptr tp); */
/* gcc generates the following x86-64 code: */

/* trace: */
/* tp in %rdi */

/* movl $0, %eax */
/* testq %rdi, %rdi */
/* je .L3 */
/* .L5: */
/* movq (%rdi), %rax */
/* movq 16(%rdi), %rdi */
/* testq %rdi, %rdi */
/* jne .L5 */
/* .L3: */
/* rep */
/* ret */

#define NULL 0

typedef struct ELE *tree_ptr;

struct ELE {
    long val;
    tree_ptr left;
    tree_ptr right;
};


long trace(tree_ptr tp) {
    long result = 0;
    
    while(tp != NULL) {
        result = tp->val;
        tp = tp->right;
    }

    return result;
}

// This function gets the most right node value.

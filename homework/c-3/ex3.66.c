/* You are charged with maintaining a large C program, and you come across the */
/* following code: */

/* typedef struct { */
/*     int left; */
/*     a_struct a[CNT]; */
/*     int right; */
/* } b_struct; */

/* void test(int i, b_struct *bp) */
/* { */
/*     int n = bp->left + bp->right; */
/*     a_struct *ap = &bp->a[i]; */
/*     ap->x[ap->idx] = n; */
/* } */


/* push %ebp */
/* mov %esp,%ebp */
/* mov 0x8(%ebp),%eax */
/* mov 0xc(%ebp),%ecx */
/* lea (%eax,%eax,4),%eax */
/* add 0x4(%ecx,%eax,4),%eax */
/* mov 0xb8(%ecx),%edx */
/* add (%ecx),%edx */
/* mov %edx,0x8(%ecx,%eax,4) */
/* pop %ebp */
/* ret */

/* The declarations of the compile-time constant CNT and the structure a_struct */
/* are in a file for which you do not have the necessary access privilege. Fortunately, */
/* you have a copy of the ‘.o’ version of code, which you are able to disassemble with */
/* the objdump program, yielding the disassembly shown in Figure 3.45. */
/* Using your reverse engineering skills, deduce the following. */
/* A. The value of CNT. */
/* B. A complete declaration of structure a_struct. Assume that the only fields */
/* in this structure are idx and x. */

/////////////////////////////////////////////////////////////////////

/* push %ebp */
/* mov %esp,%ebp */
/* mov 0x8(%ebp),%eax */           // get i
/* mov 0xc(%ebp),%ecx */           // get bp
/* lea (%eax,%eax,4),%eax */      // 5i
/* add 0x4(%ecx,%eax,4),%eax */   // 5i + a[i].idx
/* mov 0xb8(%ecx),%edx */         // get bp->right
/* add (%ecx),%edx */             // n = bp->left + bp->right
/* mov %edx,0x8(%ecx,%eax,4) */   // a[i].x[a[i].idx] = n. 8 is for b_struct.left and a_struct.idx
/* pop %ebp */
/* ret */

/* From the above we know that a_struct.idx is of type int(add , %eax). And that the total size of */
/* a_struct is 20 bytes(5i). */

/* b_struct.right is at offset 0xb8=184. */

/* A. */
/* CNT = (184 - 4) / 20 = 9. */

/* B. */

#define CNT 9

typedef struct {
    int idx;
    int x[4];
} a_struct;

typedef struct {
    int left;
    a_struct a[CNT];
    int right;
} b_struct;

void test(int i, b_struct *bp)
{
    int n = bp->left + bp->right;
    a_struct *ap = &bp->a[i];
    ap->x[ap->idx] = n;
}

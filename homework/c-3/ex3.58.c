/* The code that follows shows an example of branching on an enumerated type */
/* value in a switch statement. Recall that enumerated types in C are simply a way */
/* to introduce a set of names having associated integer values. By default, the values */
/* assigned to the names go from zero upward. In our code, the actions associated */
/* with the different case labels have been omitted. */

/* /\* Enumerated type creates set of constants numbered 0 and upward *\/ */
/* typedef enum {MODE_A, MODE_B, MODE_C, MODE_D, MODE_E} mode_t; */
/* int switch3(int *p1, int *p2, mode_t action) */
/* { */
/* int result = 0; */
/* switch(action) { */
/* case MODE_A: */
/* case MODE_B: */
/* case MODE_C: */
/* case MODE_D: */
/* case MODE_E: */
/* default: */
/* } */
/* return result; */
/* } */

/* The part of the generated assembly code implementing the different actions */
/* is shown in Figure 3.43. The annotations indicate the argument locations, the */
/* register values, and the case labels for the different jump destinations. Register */
/* %edx corresponds to program variable result and is initialized to −1. */
/* Fill in the missing parts of the C code. Watch out for cases that fall through. */

/* Arguments: p1 at %ebp+8, p2 at %ebp+12, action at %ebp+16 */
/* Registers: result in %edx (initialized to -1) */
/* The jump targets: */

/* .L17:  MODE_E */
/* movl $17, %edx */
/* jmp .L19  */

/* .L13: MODE_A */
/* movl 8(%ebp), %eax */
/* movl (%eax), %edx */
/* movl 12(%ebp), %ecx */
/* movl (%ecx), %eax */
/* movl 8(%ebp), %ecx */
/* movl %eax, (%ecx) */
/* jmp .L19 */

/* .L14: MODE_B */
/* movl 12(%ebp), %edx */
/* movl (%edx), %eax */
/* movl %eax, %edx */
/* movl 8(%ebp), %ecx */
/* addl (%ecx), %edx */
/* movl 12(%ebp), %eax */
/* movl %edx, (%eax) */
/* jmp .L19 */

/* .L15: MODE_C */
/* movl 12(%ebp), %edx */
/* movl $15, (%edx) */
/* movl 8(%ebp), %ecx */
/* movl (%ecx), %edx */
/* jmp .L19 */

/* .L16: MODE_D */
/* movl 8(%ebp), %edx */
/* movl (%edx), %eax */
/* movl 12(%ebp), %ecx */
/* movl %eax, (%ecx) */
/* movl $17, %edx */

/* .L19: default */
/* movl %edx, %eax Set return value */

typedef enum {MODE_A, MODE_B, MODE_C, MODE_D, MODE_E} mode_t;

int switch3(int *p1, int *p2, mode_t action)
{
    int result = 0;
    switch(action) {
    case MODE_A:
        result = *p1;
        *p1 = *p2;
        break;
    case MODE_B:
        result = *p2 + *p1;
        *p2 = result;
        break;
    case MODE_C:
        *p2 = 15;
        result = *p1;
        break;
    case MODE_D:
        *p2 = *p1;
        result = 17; // can fall through to MODE_E
        break; 
    case MODE_E:
        result = 17;
        break;
    default:
        result = -1;
        break;
    }
    return result;
}

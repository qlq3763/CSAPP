/* This problem will give you a chance to reverse engineer a switch statement from */
/* machine code. In the following procedure, the body of the switch statement has */
/* been removed: */

/* int switch_prob(int x, int n) */
/* { */
/*     int result = x; */
/*     switch(n) { */
/*     } */
/*     return result; */
/* } */

/* Figure 3.44 shows the disassembled machine code for the procedure. We can */
/* see in lines 4 and 5 that parameters x and n are loaded into registers %eax and */
/* %edx, respectively. */
/* The jump table resides in a different area of memory. We can see from the */
/* indirect jump on line 9 that the jump table begins at address 0x80485d0. Using */
/* the gdb debugger, we can examine the six 4-byte words of memory comprising */
/* the jump table with the command x/6w 0x80485d0. gdb prints the following: */
/* (gdb) x/6w 0x80485d0 */
/* 0x80485d0: 0x08048438 0x08048448 0x08048438 0x0804843d */
/* 0x80485e0: 0x08048442 0x08048445 */
/* Fill in the body of the switch statement with C code that will have the same */
/* behavior as the machine code. */

/* 08048420 <switch_prob>: */
/* 8048420: 55                        push %ebp */
/* 8048421: 89 e5                     mov %esp,%ebp */
/* 8048423: 8b 45 08                  mov 0x8(%ebp),%eax */
/* 8048426: 8b 55 0c                  mov 0xc(%ebp),%edx */
/* 8048429: 83 ea 32                  sub $0x32,%edx */
/* 804842c: 83 fa 05                  cmp $0x5,%edx */
/* 804842f: 77 17                     ja 8048448 <switch_prob+0x28> */
/* 8048431: ff 24 95 d0 85 04 08      jmp *0x80485d0(,%edx,4) */
/* 8048438: c1 e0 02                  shl $0x2,%eax */
/* 804843b: eb 0e                     jmp 804844b <switch_prob+0x2b> */
/* 804843d: c1 f8 02                  sar $0x2,%eax */
/* 8048440: eb 09                     jmp 804844b <switch_prob+0x2b> */
/* 8048442: 8d 04 40                  lea (%eax,%eax,2),%eax */
/* 8048445: 0f af c0                  imul %eax,%eax */
/* 8048448: 83 c0 0a                  add $0xa,%eax */
/* 804844b: 5d                        pop %ebp */
/* 804844c: c3                        ret */

int switch_prob(int x, int n)
{
    int result = x;
    switch(n) {
    case 50:
    case 52:
        result <<= 2;
        break;
    case 53:
        result >>= 2;
        break;
    case 54:
        result *= 3; // fall through
    case 55:
        result *= result; // still fall through
    default:
        result += 10;
        break;
    }
    return result;
}

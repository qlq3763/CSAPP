/* Write a function good_echo that reads a line from standard input and writes it to */
/* standard output. Your implementation should work for an input line of arbitrary */
/* length. You may use the library function fgets, but you must make sure your */
/* function works correctly even when the input line requires more space than you */
/* have allocated for your buffer. Your code should also check for error conditions */
/* and return when one is encountered. Refer to the definitions of the standard I/O */
/* functions for documentation [48, 58]. */

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 16 // for test
int echo() {
    char str[BUF_SIZE];

    while (fgets(str, BUF_SIZE, stdin) != NULL) {
        if (fputs(str, stdout) == EOF) {
            perror("error when output string");
            return errno;
        }
        if (str[strlen(str) - 1] == '\n')
            return 0;
    }

    if (ferror(stdin)) {
        perror("error when read input");
        return errno;
    }

    return 0;
}

int main() {
    return echo();
}

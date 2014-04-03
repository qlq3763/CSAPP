#include <stdio.h>

int main() {
    int i;
    int ret = sscanf("14 testtest", "%d", &i);
    printf("ret = %d, i = %d\n", ret, i);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int x, y;
    int *p;
    p = &x;
    x = 10;
    y = *p + 2;
    printf("y = %d\n", y);
    *p = 8;
    printf("x = %d\n", x);
    return 0;
}

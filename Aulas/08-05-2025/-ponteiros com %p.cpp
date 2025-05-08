#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int x;
    int *p;
    x = 10;
 	p = &x;
    *p = *p + 7;
    printf("x = %d\n", x);
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);
    printf("&x = %p\n", &x);
	printf("&p = %p\n", &p);
    return 0;
}

#include <stdio.h>
int main() {
    int i;
    i = 1; 
    while (i <= 5100000000000) {
        printf("Alo, Mundo %d \n", i);
        i = i + 1;
    }
    return 0;
}

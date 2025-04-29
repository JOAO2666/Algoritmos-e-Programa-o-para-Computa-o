#include <stdio.h>

int soma_um(int x){
    printf("3. x = %d\n", x);
    x = x + 1;
    printf("4. x = %d\n", x);
    return x;
}

int main() {
    int x, calculo;
    x = 3; 
    printf("1. x = %d\n", x);
    printf("2. x = %d\n", x);
    calculo = soma_um(x); 
    printf("5. x = %d\n", x);
    printf("6. calculo = %d\n", calculo);
    return 0;
}

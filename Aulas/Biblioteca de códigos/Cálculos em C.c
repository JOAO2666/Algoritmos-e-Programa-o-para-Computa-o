#include <stdio.h>

int main() {
    int A, B, soma, subtr, mult, divis;
    
    printf("Digite o primeiro valor:\n");
    scanf("%d", &A);
    
    printf("Digite o segundo valor:\n");
    scanf("%d", &B);
    
    soma = A + B;
    subtr = A - B;
    mult = A * B;
    
    printf("Resultados:\n");
    printf("Soma: %d.\n", soma);
    printf("Subtra.: %d.\n", subtr);
    printf("Multiplic.: %d.\n", mult);
    
    if (B != 0) {
        divis = A / B;
        printf("Divis.: %d.\n", divis);
    } else {
        printf("Divis.: Erro - divisao por zero.\n");
    }
    
    return 0;
}

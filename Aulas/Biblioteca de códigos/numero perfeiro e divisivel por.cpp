#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int n;
    int i;
    int verificar = 0; // Inicializando a variável
    
    printf("Entre com um inteiro n: ");
    scanf("%d", &n);
    
    if (n % 2 == 0) {
        printf("Os divisores próprios de %d são: ", n);
        
        for (i = 1; i < n; i++) {
            if (n % i == 0) { // Verifica se i é divisor de n
                printf("%d ", i); // Imprime o divisor
                verificar += i;   // Soma o divisor
            }
        }
        
        if (n == verificar) {
            printf("\n\n%d é um número perfeito!", n);
        }
        else {
            printf("\n\n%d não é um número perfeito!", n);
        }
    }
    else {
        printf("\nO número digitado não é par.");
        printf("\nO programa verificará apenas números pares.");
        
        while (n % 2 != 0) {
            printf("\nEntre com um inteiro par: ");
            scanf("%d", &n);
        }
        
        // Adicionando a verificação de número perfeito após o novo input
        verificar = 0; // Resetando a variável para o novo número
        printf("Os divisores próprios de %d são: ", n);
        
        for (i = 1; i < n; i++) {
            if (n % i == 0) {
                printf("%d ", i);
                verificar += i;
            }
        }
        
        if (n == verificar) {
            printf("\n\n%d é um número perfeito!", n);
        }
        else {
            printf("\n\n%d não é um número perfeito!", n);
        }
    }
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int n;
    int i;
    int verificar = 0; // Inicializando a vari�vel
    
    printf("Entre com um inteiro n: ");
    scanf("%d", &n);
    
    if (n % 2 == 0) {
        printf("Os divisores pr�prios de %d s�o: ", n);
        
        for (i = 1; i < n; i++) {
            if (n % i == 0) { // Verifica se i � divisor de n
                printf("%d ", i); // Imprime o divisor
                verificar += i;   // Soma o divisor
            }
        }
        
        if (n == verificar) {
            printf("\n\n%d � um n�mero perfeito!", n);
        }
        else {
            printf("\n\n%d n�o � um n�mero perfeito!", n);
        }
    }
    else {
        printf("\nO n�mero digitado n�o � par.");
        printf("\nO programa verificar� apenas n�meros pares.");
        
        while (n % 2 != 0) {
            printf("\nEntre com um inteiro par: ");
            scanf("%d", &n);
        }
        
        // Adicionando a verifica��o de n�mero perfeito ap�s o novo input
        verificar = 0; // Resetando a vari�vel para o novo n�mero
        printf("Os divisores pr�prios de %d s�o: ", n);
        
        for (i = 1; i < n; i++) {
            if (n % i == 0) {
                printf("%d ", i);
                verificar += i;
            }
        }
        
        if (n == verificar) {
            printf("\n\n%d � um n�mero perfeito!", n);
        }
        else {
            printf("\n\n%d n�o � um n�mero perfeito!", n);
        }
    }
    
    return 0;
}

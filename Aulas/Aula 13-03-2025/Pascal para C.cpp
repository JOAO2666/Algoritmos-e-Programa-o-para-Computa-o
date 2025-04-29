#include <stdio.h>
#include <math.h>

int main() {
    int n;
    int dezena1, dezena2;
    double raiz;
    
    printf("Digite um numero de 4 algarismos: ");
    scanf("%d", &n);
    

    raiz = sqrt(n);
    

    dezena1 = n / 100;    
    dezena2 = n % 100;   
    

    int soma = dezena1 + dezena2;
    

    printf("Raiz quadrada de %d = %.2f\n", n, raiz);
    printf("Soma das dezenas: %d + %d = %d\n", dezena1, dezena2, soma);
    
    if (raiz == soma) {
        printf("A raiz quadrada eh igual a soma das dezenas!\n");
    } else {
        printf("A raiz quadrada nao eh igual a soma das dezenas.\n");
    }
    
    return 0;
}

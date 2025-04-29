#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[10], i;

    printf("Digite os valores do vetor:\n");
    for (i = 0; i<10; i++) {
        printf("Digite o valor %d:",i+1);
        scanf("%d", &vetor[i]);
    }

    int soma = 0;
    for (i=0; i<10; i++) {
        soma+=vetor[i];
    }

    printf("A soma dos valores do vetor eh: %d", soma);
}

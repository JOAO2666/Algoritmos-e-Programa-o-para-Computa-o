#include <stdio.h>
#define NLINHAS 5 //Deve ser maior que 4
#define NCOLUNAS 5 //Deve ser maior que 2

int main()
{
    int matriz[NLINHAS][NCOLUNAS];
    int i, j;

    //Lê matriz
    for (i=0; i<NLINHAS; i++) {
        for (j=0; j<NCOLUNAS; j++) {
            printf("Digite o valor da posição [%d,%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    //Imprime a matriz lida:
    printf("A matriz lida foi:\n");
    for (i=0; i<NLINHAS; i++) {
        for (j=0; j<NCOLUNAS; j++) {
            printf("| %d ", matriz[i][j]);
        }
        printf("|\n");
    }

    //Imprime a diagonal principal
    printf("Diagonal principal: [");
    for (i=0; i<NLINHAS; i++) {
        for (j=0; j<NCOLUNAS; j++) {
            if (i==j)
                printf(" %d ", matriz[i][j]);
        }
    }
    printf("]\n");

    //Imprime a diagonal secundaria
    printf("Diagonal secundaria: [");
    for (i=0; i<NLINHAS; i++) {
        for (j=0; j<NCOLUNAS; j++) {
            if (i==NCOLUNAS-j-1)
                printf(" %d ", matriz[i][j]);
        }
    }
    printf("]\n");

    //Imprime a soma da linha 4:
    int soma = 0;
    for (j=0; j<NCOLUNAS; j++) {
         soma += matriz[4][j];
    }
    printf("Soma da linha 4: %d\n", soma);

    //Imprime a soma da coluna 2:
    soma = 0;
    for (i=0; i<NLINHAS; i++) {
         soma += matriz[i][2];
    }
    printf("Soma da coluna 2: %d\n", soma);

    //Imprime valores fora da diagonal principal
    printf("Valores fora da diagonal principal: [");
    for (i=0; i<NLINHAS; i++) {
        for (j=0; j<NCOLUNAS; j++) {
            if (i!=j)
                printf(" %d ", matriz[i][j]);
        }
    }
    printf("]\n");

    return 0;
}

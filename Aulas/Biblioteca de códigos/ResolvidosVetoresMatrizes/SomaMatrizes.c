#include <stdio.h>
#include <stdlib.h>
#define LINHAS 2
#define COLUNAS 2

int main()
{
    int matriz1[LINHAS][COLUNAS],
    matriz2[LINHAS][COLUNAS],
    matriz3[LINHAS][COLUNAS];
    int i, j;

    for (i=0;i<LINHAS;i++) {
        for (j=0;j<COLUNAS;j++) {
            printf("Digite o elementro (%d,%d) da 1a. matriz:", i+1, j+1);
            scanf("%d", &matriz1[i][j]);
        }
    }
    printf("\n");

    for (i=0;i<LINHAS;i++) {
        for (j=0;j<COLUNAS;j++) {
            printf("Digite o elementro (%d,%d) da 2a. matriz:", i+1, j+1);
            scanf("%d", &matriz2[i][j]);
        }
    }

    for (i=0;i<LINHAS;i++) {
        for (j=0;j<COLUNAS;j++) {
            matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    printf("\nResultado da soma:\n");
    for (i=0;i<LINHAS;i++) {
        printf("|");
        for (j=0;j<COLUNAS;j++) {
            printf(" %d |", matriz3[i][j]);
        }
        printf("\n");
    }

    return 0;
}

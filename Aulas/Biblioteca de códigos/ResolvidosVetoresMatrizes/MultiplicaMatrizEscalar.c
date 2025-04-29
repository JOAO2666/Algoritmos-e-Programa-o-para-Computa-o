#include <stdio.h>
#include <stdlib.h>
#define LINHAS 3
#define COLUNAS 3

void multiplica(int matriz[][COLUNAS], int l, int k) {
    int i;
    int j;

    for (i=0;i<l;i++) {
        for (j=0;j<COLUNAS;j++) {
            matriz[i][j] = matriz[i][j]*k;
        }
    }
}

int main()
{
    int matriz[LINHAS][COLUNAS];
    int i, j, k;

    for (i=0;i<LINHAS;i++) {
        for (j=0;j<COLUNAS;j++) {
            printf("Digite o elementro (%d,%d) da matriz:", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Digite k:\n");
    scanf("%d", &k);

    multiplica(matriz, LINHAS, k);

    printf("Resultado:\n");
    for (i=0;i<LINHAS;i++) {
        for (j=0;j<COLUNAS;j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>
#define NLINHAS 5
#define NCOLUNAS 5

int pesquisarEmMatriz(int m[][NCOLUNAS], int x) {
    int i, j, count=0;

    //Procura o valor na matriz:
    count = 0;
    for (i=0; i<NLINHAS; i++) {
        for (j=0; j<NCOLUNAS; j++) {
            if (x == m[i][j]) {
                printf("Valor %d encontrado na posicao [%d,%d].\n", x, i, j);
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int matriz[NLINHAS][NCOLUNAS];
    int i, j, valor, n;

    //Lê matriz
    for (i=0; i<NLINHAS; i++) {
        for (j=0; j<NCOLUNAS; j++) {
            printf("Digite o valor da posicao [%d,%d]: ", i, j);
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

    //Lê o valor que será pesquisado:
    printf("Digite o valor que gostaria de pesquisar na matriz: ");
    scanf("%d", &valor);

    //Imprime a quantidade de ocorrências encontradas:
    n = pesquisarEmMatriz(matriz, valor);
    if (n == 0)
        printf("O valor %d nao foi encontrado na matriz.\n", valor);
    else
        printf("Foram encontradas %d ocorrencia do valor %d na matriz.\n", n, valor);

    return 0;
}

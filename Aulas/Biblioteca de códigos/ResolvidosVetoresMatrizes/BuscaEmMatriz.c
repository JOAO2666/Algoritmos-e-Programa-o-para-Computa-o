#include <stdio.h>
#define NLINHAS 20
#define NCOLUNAS 20

int main()
{
    int matriz[NLINHAS][NCOLUNAS];
    int i, j, valor, count;

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

    //Lê o valor que será pesquisado:
    printf("Digite o valor que gostaria de pesquisar na matriz: ");
    scanf("%d", &valor);

    //Procura o valor na matriz:
    count = 0;
    for (i=0; i<NLINHAS; i++) {
        for (j=0; j<NCOLUNAS; j++) {
            if (valor == matriz[i][j]) {
                printf("Valor %d encontrado na posição [%d,%d].\n", valor, i, j);
                count++;
            }
        }
    }

    //Imprime a quantidade de ocorrências encontradas:
    if (count == 0)
        printf("O valor %d não foi encontrado na matriz.\n", valor);
    else
        printf("Foram encontradas %d ocorrência do valor %d na matriz.\n", count, valor);

    return 0;
}

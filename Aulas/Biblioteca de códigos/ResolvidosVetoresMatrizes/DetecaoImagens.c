#include <stdio.h>
#define IMAGEM_N 1000
#define SUBIMAGEM_N 3

int Detectar(int imagem[IMAGEM_N][IMAGEM_N], int subimagem[SUBIMAGEM_N][SUBIMAGEM_N]) {

    int i, j;
    int is, js;
    int encontrado;

    for (i=0; i<=IMAGEM_N-SUBIMAGEM_N; i++)
    for (j=0; j<=IMAGEM_N-SUBIMAGEM_N; j++) {
        encontrado = 1;

        for (is=0; is<SUBIMAGEM_N && encontrado; is++)
        for (js=0; js<SUBIMAGEM_N && encontrado; js++) {
            if (imagem[i+is][j+js]!=subimagem[is][js]) {
                encontrado = 0;
            }
        }
        if (encontrado) return 1;
    }

    return 0;
}

int main()
{
    int imagem[IMAGEM_N][IMAGEM_N];
    int subimagem[SUBIMAGEM_N][SUBIMAGEM_N] = {{1,1,1}, {1,1,1}, {2,2,2}};
    int i, j;

    for (i=0; i<IMAGEM_N; i++)
    for (j=0; j<IMAGEM_N; j++) {
        printf("Digite o valor da imagem na posicao [%d][%d]:", i, j);
        scanf("%d", &imagem[i][j]);
    }

    printf("Imagem lida: \n");
    for (i=0; i<IMAGEM_N; i++) {
        for (j=0; j<IMAGEM_N; j++) {
                printf("%d\t", imagem[i][j]);
        }
        printf("\n");
    }

    printf("Sub-imagem a ser detectada: \n");
    for (i=0; i<SUBIMAGEM_N; i++) {
        for (j=0; j<SUBIMAGEM_N; j++) {
                printf("%d\t", subimagem[i][j]);
        }
        printf("\n");
    }

    if (Detectar(imagem, subimagem)==1) {
        printf("Doenca detectada!");
    } else {
        printf("Doenca nao detectada!");
    }

    return 0;
}

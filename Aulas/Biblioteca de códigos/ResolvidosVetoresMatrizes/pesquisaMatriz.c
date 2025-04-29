#include <stdio.h>
#include <stdlib.h>
#define LINHAS 2
#define COLUNAS 2

int i, j;

float leitura(float matriz[LINHAS][COLUNAS]) {
    int i,j;
    float X;

    for(i=0; i<LINHAS; i++)
        for(j=0; j<COLUNAS; j++) {
            printf("Digite linha %d e coluna %d:",(i+1),(j+1));
            scanf("%f",&matriz[i][j]);
        }
    printf("\nDigite o valor a ser procurado:");
    scanf("%f",&X);

    return X;
}


//0-X está na matriz. 1-X nao está na matriz.
int procura(float matriz[LINHAS][COLUNAS],float X) {

    for(i=0; i<LINHAS; i++)
        for(j=0; j<COLUNAS; j++) {
            if(X==matriz[i][j])
                return 0;

        }
    return 1;

}

int main() {
    float matriz[LINHAS][COLUNAS];
    float X;
    int encontrou;

    X=leitura(matriz);
    encontrou=procura(matriz,X);

    if (encontrou) {
        printf("\nNumero pertence a matriz!!!");
        printf("\nLinha:%d Coluna:%d",(i+1),(j+1));
    } else {
        printf("\nNumero nao pertence a matriz :(");
    }
    return 0;
}

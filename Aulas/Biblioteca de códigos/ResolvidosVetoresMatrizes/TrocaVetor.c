#include <stdio.h>

void Troca(int vetor[]){
 int i, aux;
 for (i=0; i<8;i++) {
    aux = vetor[i];
    vetor[i] = vetor[i+8];
    vetor[i+8] = aux;
 }
}

int main(){
    int vetor[16];
    int i;

    for(i=0;i<16;i++){
        printf("Digite o %da. numero do vetor:",(i+1));
        scanf("%d",&vetor[i]);
    }

    Troca(vetor);

    for(i=0;i<16;i++){
        printf("%d ",vetor[i]);
    }
    return 0;
}

    int mat[3][4];
    int i,j;

    //Inicialza a matriz com 1's
    for (i=0; i<3; i++) {
        for (j=0; j<4; j++) {
            mat[i][j] = 1;
        }
    }


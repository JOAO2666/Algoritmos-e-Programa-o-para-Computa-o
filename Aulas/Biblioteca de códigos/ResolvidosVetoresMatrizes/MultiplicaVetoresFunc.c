#include <stdio.h>
#define TAMANHO 20

void multiplica(float v1[], float v2[], int n, float r[]) {
    int i;

    for (i=0; i<n; i++) {
        r[i] = v1[i]*v2[i];
    }
}

int main()
{
    float vetor1[TAMANHO], vetor2[TAMANHO], vetor3[TAMANHO];
    int i;

    //Inicializa cada vetor com valores crescentes (decrescentres)
    for (i=0; i<TAMANHO; i++) {
        vetor1[i] = i+1;
        vetor2[i] = TAMANHO-i;
    }

    multiplica(vetor1, vetor2, TAMANHO, vetor3);

    for (i=0; i<TAMANHO; i++) {
        printf("%.2f x %.2f = %.2f\n", vetor1[i], vetor2[i], vetor3[i]);
    }
    return 0;
}

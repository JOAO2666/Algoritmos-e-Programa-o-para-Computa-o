#include <stdio.h>
#define TAMANHO 20

int main()
{
    float vetor1[TAMANHO], vetor2[TAMANHO], vetor3[TAMANHO];
    int i;

    //Inicializa cada vetor com valores crescentes (decrescentres)
    for (i=0; i<TAMANHO; i++) {
            vetor1[i] = i+1;
            vetor2[i] = TAMANHO-i;
    }

    for (i=0; i<TAMANHO; i++) {
        vetor3[i] = vetor1[i]*vetor2[i];
    }

    for (i=0; i<TAMANHO; i++) {
        printf("%.2f x %.2f = %.2f\n", vetor1[i], vetor2[i], vetor3[i]);
    }
    return 0;
}

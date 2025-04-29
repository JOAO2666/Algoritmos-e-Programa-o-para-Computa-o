#include <stdio.h>

int main() {
    int v[200];
    int i, n, imp, par, soma;
    float media, mediana;

    // Leitura de n, se n for menor que 5 ou maior que 200
    do {
        printf("n=");
        scanf("%d", &n);
    } while (n < 5 || n > 200);

    // Leitura do vetor se i for menor que n, acrescenta mais um
    for (i = 0; i < n; i++) {
        printf("v[%d]=", i+1);
        scanf("%d", &v[i]);
    }

    // Inicializando os valores
    soma = 0;
    imp = 0;
    par = 0;

    // C�lculo da mediana, pega o resto dos valores
    if (n % 2 == 1) {
        mediana = v[n/2];  // Se quantidade �mpar, pega o do meio
    } else {
        mediana = (v[n/2 - 1] + v[n/2]) / 2.0;
    }

    // C�lculo da soma, pares e �mpares
    for (i = 0; i < n; i++) {
        soma += v[i];
        if (v[i] % 2 == 1) {
            imp++;  // Conta �mpar
        } else {
            par++;  // Conta par
        }
    }

    media = (float)soma / n;

    // Impress�o dos valores
    printf("Media=%.2f\n", media);
    printf("Mediana=%.2f\n", mediana);
    printf("Pares=%5d\n", par);
    printf("Impares=%5d\n", imp);

    return 0;
}

#include <stdio.h>

int main() {
    int LA, CA, LB, CB, l, c, s, sum = 0;
    int A[10][10], B[10][10], C[10][10];

    do {
        printf("Informe o numero de linhas e colunas da primeira matriz (ate 10):\n");
        scanf("%d%d", &LA, &CA);
    } while (CA>10 || LA>10);

    do {
        printf("Informe o numero de linhas e colunas da segunda matriz (ate 10):\n");
        scanf("%d%d", &LB, &CB);
    } while (LB>10 || CB>10);

    if (CA != LB)
        printf("Estas matrizes nao pode ser multiplicadas.\n");
    else {
        printf("Informe os elementos da primeira matriz:\n");

        for (l = 0; l < LA; l++)
            for (c = 0; c < CA; c++)
                scanf("%d", &A[l][c]);

        printf("Informe os elementos da segunda matriz:\n");

        for (l = 0; l < LB; l++)
            for (c = 0; c < CB; c++)
                scanf("%d", &B[l][c]);

        for (l = 0; l < LA; l++) {
            for (c = 0; c < CB; c++) {
                for (s = 0; s < LB; s++) {
                    sum = sum + A[l][s]*B[s][c];
                }

                C[l][c] = sum;
                sum = 0;
            }
        }

        printf("Produto das matrizes:-\n");

        for (l = 0; l < LA; l++) {
            for (c = 0; c < CB; c++)
                printf("%d\t", C[l][c]);

            printf("\n");
        }
    }

    return 0;
}

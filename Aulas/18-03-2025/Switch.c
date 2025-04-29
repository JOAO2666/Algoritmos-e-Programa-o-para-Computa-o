#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int d;

    printf("Insira um valor de 1 a 7:\n");
    scanf("%d", &d);

    switch (d) {
        case 1:
            printf("Domingo.\n");
            break;
        case 2:
            printf("Segunda-feira.\n");
            break;
        case 3:
            printf("Terca-feira.\n");
            break;
        case 4:
            printf("Quarta-feira.\n");
            break;
        case 5:
            printf("Quinta-feira.\n");
            break;
        case 6:
            printf("Sexta-feira.\n");
            break;
        case 7:
            printf("Sábado.\n");
            break;
        default:
            printf("Valor inválido.\n");
    }

    return 0;
}


#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 300
#define MIN_SIZE 2

void ler_matriz(float matriz[MAX_SIZE][MAX_SIZE], int m, int n) {
    int i, j;
    printf("Digite os elementos da matriz %dx%d:\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }
}

void imprimir_matriz(float matriz[MAX_SIZE][MAX_SIZE], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%8.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void diagonal_principal(float matriz[MAX_SIZE][MAX_SIZE], int m, int n) {
    int i;
    if (m != n) {
        printf("Erro: A matriz nao e quadrada (M != N)\n");
        return;
    }
    
    printf("Diagonal principal:\n");
    for (i = 0; i < m; i++) {
        printf("%8.2f ", matriz[i][i]);
    }
    printf("\n");
}

void matriz_transposta(float matriz[MAX_SIZE][MAX_SIZE], int m, int n) {
    int i, j;
    printf("Matriz transposta:\n");
    for (j = 0; j < n; j++) {
        for (i = 0; i < m; i++) {
            printf("%8.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplicar_escalar(float matriz[MAX_SIZE][MAX_SIZE], int m, int n, float escalar) {
    int i, j;
    printf("Matriz multiplicada por %.2f:\n", escalar);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%8.2f ", matriz[i][j] * escalar);
        }
        printf("\n");
    }
}

void somar_escalar(float matriz[MAX_SIZE][MAX_SIZE], int m, int n, float escalar) {
    int i, j;
    printf("Matriz somada com %.2f:\n", escalar);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%8.2f ", matriz[i][j] + escalar);
        }
        printf("\n");
    }
}

int main() {
    float matriz[MAX_SIZE][MAX_SIZE];
    int m, n, opcao;
    float escalar;
    int i, j;  // Variáveis para loops
    
    // Ler tamanho da matriz
    do {
        printf("Digite as dimensoes da matriz (M N, entre %d e %d): ", MIN_SIZE, MAX_SIZE);
        scanf("%d %d", &m, &n);
    } while (m < MIN_SIZE || m > MAX_SIZE || n < MIN_SIZE || n > MAX_SIZE);
    
    // Ler elementos da matriz
    ler_matriz(matriz, m, n);
    
    // Menu de operações
    do {
        printf("\nMenu de Operacoes:\n");
        printf("1) Imprimir diagonal principal\n");
        printf("2) Imprimir matriz transposta\n");
        printf("3) Multiplicar matriz por escalar\n");
        printf("4) Somar escalar a matriz\n");
        printf("5) Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        printf("\nMatriz original:\n");
        imprimir_matriz(matriz, m, n);
        printf("\n");
        
        switch(opcao) {
            case 1:
                diagonal_principal(matriz, m, n);
                break;
            case 2:
                matriz_transposta(matriz, m, n);
                break;
            case 3:
                printf("Digite o valor escalar para multiplicacao: ");
                scanf("%f", &escalar);
                multiplicar_escalar(matriz, m, n, escalar);
                break;
            case 4:
                printf("Digite o valor escalar para soma: ");
                scanf("%f", &escalar);
                somar_escalar(matriz, m, n, escalar);
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);
    
    return 0;
}#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 300
#define MIN_SIZE 2

void ler_matriz(float matriz[MAX_SIZE][MAX_SIZE], int m, int n) {
    int i, j;
    printf("Digite os elementos da matriz %dx%d:\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }
}

void imprimir_matriz(float matriz[MAX_SIZE][MAX_SIZE], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%8.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void diagonal_principal(float matriz[MAX_SIZE][MAX_SIZE], int m, int n) {
    int i;
    if (m != n) {
        printf("Erro: A matriz nao e quadrada (M != N)\n");
        return;
    }
    
    printf("Diagonal principal:\n");
    for (i = 0; i < m; i++) {
        printf("%8.2f ", matriz[i][i]);
    }
    printf("\n");
}

void matriz_transposta(float matriz[MAX_SIZE][MAX_SIZE], int m, int n) {
    int i, j;
    printf("Matriz transposta:\n");
    for (j = 0; j < n; j++) {
        for (i = 0; i < m; i++) {
            printf("%8.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplicar_escalar(float matriz[MAX_SIZE][MAX_SIZE], int m, int n, float escalar) {
    int i, j;
    printf("Matriz multiplicada por %.2f:\n", escalar);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%8.2f ", matriz[i][j] * escalar);
        }
        printf("\n");
    }
}

void somar_escalar(float matriz[MAX_SIZE][MAX_SIZE], int m, int n, float escalar) {
    int i, j;
    printf("Matriz somada com %.2f:\n", escalar);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%8.2f ", matriz[i][j] + escalar);
        }
        printf("\n");
    }
}

int main() {
    float matriz[MAX_SIZE][MAX_SIZE];
    int m, n, opcao;
    float escalar;
    int i, j;  // Variáveis para loops
    
    // Ler tamanho da matriz
    do {
        printf("Digite as dimensoes da matriz (M N, entre %d e %d): ", MIN_SIZE, MAX_SIZE);
        scanf("%d %d", &m, &n);
    } while (m < MIN_SIZE || m > MAX_SIZE || n < MIN_SIZE || n > MAX_SIZE);
    
    // Ler elementos da matriz
    ler_matriz(matriz, m, n);
    
    // Menu de operações
    do {
        printf("\nMenu de Operacoes:\n");
        printf("1) Imprimir diagonal principal\n");
        printf("2) Imprimir matriz transposta\n");
        printf("3) Multiplicar matriz por escalar\n");
        printf("4) Somar escalar a matriz\n");
        printf("5) Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        printf("\nMatriz original:\n");
        imprimir_matriz(matriz, m, n);
        printf("\n");
        
        switch(opcao) {
            case 1:
                diagonal_principal(matriz, m, n);
                break;
            case 2:
                matriz_transposta(matriz, m, n);
                break;
            case 3:
                printf("Digite o valor escalar para multiplicacao: ");
                scanf("%f", &escalar);
                multiplicar_escalar(matriz, m, n, escalar);
                break;
            case 4:
                printf("Digite o valor escalar para soma: ");
                scanf("%f", &escalar);
                somar_escalar(matriz, m, n, escalar);
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);
    
    return 0;
}

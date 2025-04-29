#include <stdio.h>

#define MAX 300
#define MIN 2

int main() {
    float matriz[MAX][MAX];
    int m, n, opcao;
    float escalar;
    
    // a) Leitura do tamanho da matriz
    do {
        printf("Digite o numero de linhas (entre %d e %d): ", MIN, MAX);
        scanf("%d", &m);
        
        if (m < MIN || m > MAX)
            printf("Valor invalido!\n");
            
    } while (m < MIN || m > MAX);
    
    do {
        printf("Digite o numero de colunas (entre %d e %d): ", MIN, MAX);
        scanf("%d", &n);
        
        if (n < MIN || n > MAX)
            printf("Valor invalido!\n");
            
    } while (n < MIN || n > MAX);
    
    // b) Leitura dos elementos da matriz
    printf("\nDigite os elementos da matriz %dx%d:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }
    
    // c) Menu de opcoes
    do {
        printf("\n=== MENU ===\n");
        printf("1 - Imprimir diagonal principal\n");
        printf("2 - Imprimir matriz transposta\n");
        printf("3 - Multiplicar matriz por escalar\n");
        printf("4 - Somar escalar aos elementos da matriz\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        // d) Realizar a operacao solicitada
        switch (opcao) {
            case 1: // Diagonal principal
                // Imprimir matriz original
                printf("\nMatriz original:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%.2f\t", matriz[i][j]);
                    }
                    printf("\n");
                }
                
                // Verificar se é matriz quadrada
                if (m != n) {
                    printf("\nERRO: A matriz nao e quadrada!\n");
                } else {
                    printf("\nDiagonal principal: ");
                    for (int i = 0; i < m; i++) {
                        printf("%.2f ", matriz[i][i]);
                    }
                    printf("\n");
                }
                break;
                
            case 2: // Matriz transposta
                // Imprimir matriz original
                printf("\nMatriz original:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%.2f\t", matriz[i][j]);
                    }
                    printf("\n");
                }
                
                // Imprimir transposta
                printf("\nMatriz transposta:\n");
                for (int j = 0; j < n; j++) {
                    for (int i = 0; i < m; i++) {
                        printf("%.2f\t", matriz[i][j]);
                    }
                    printf("\n");
                }
                break;
                
            case 3: // Multiplicação por escalar
                printf("\nDigite o valor do escalar para multiplicacao: ");
                scanf("%f", &escalar);
                
                // Imprimir matriz original
                printf("\nMatriz original:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%.2f\t", matriz[i][j]);
                    }
                    printf("\n");
                }
                
                // Imprimir resultado
                printf("\nResultado da multiplicacao por %.2f:\n", escalar);
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%.2f\t", matriz[i][j] * escalar);
                    }
                    printf("\n");
                }
                break;
                
            case 4: // Soma com escalar
                printf("\nDigite o valor do escalar para soma: ");
                scanf("%f", &escalar);
                
                // Imprimir matriz original
                printf("\nMatriz original:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%.2f\t", matriz[i][j]);
                    }
                    printf("\n");
                }
                
                // Imprimir resultado
                printf("\nResultado da soma com %.2f:\n", escalar);
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%.2f\t", matriz[i][j] + escalar);
                    }
                    printf("\n");
                }
                break;
                
            case 0:
                printf("\nEncerrando o programa...\n");
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
        
    } while (opcao != 0);
    
    return 0;
}

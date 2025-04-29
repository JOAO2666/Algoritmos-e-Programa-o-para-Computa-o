#include <stdio.h>

void imprimir(float mat[300][300], int m, int n) {
    int i, j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%.2f\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float mat[300][300];
    int m, n, opcao;
    float escalar;
    int i, j; /* Declaração das variáveis de controle dos loops fora deles */
    
    /* Leitura do tamanho da matriz */
    do {
        printf("Digite o numero de linhas: ");
        scanf("%d", &m);
    } while(m < 2 || m > 300);
    
    do {
        printf("Digite o numero de colunas: ");
        scanf("%d", &n);
    } while(n < 2 || n > 300);
    
    /* Leitura dos elementos da matriz */
    printf("\nDigite os elementos da matriz %dx%d:\n", m, n);
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%f", &mat[i][j]);
        }
    }
    
    /* Menu de operações */
    do {
        printf("\n=== MENU ===\n");
        printf("1 - Imprimir diagonal principal\n");
        printf("2 - Imprimir matriz transposta\n");
        printf("3 - Multiplicar matriz por escalar\n");
        printf("4 - Somar escalar aos elementos da matriz\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: /* Diagonal principal */
                printf("\nMatriz original:\n");
                imprimir(mat, m, n);
                
                if(m != n) {
                    printf("\nERRO: A matriz nao e quadrada!\n");
                } else {
                    printf("\nDiagonal principal: ");
                    for(i = 0; i < m; i++) {
                        printf("%.2f ", mat[i][i]);
                    }
                    printf("\n");
                }
                break;
                
            case 2: /* Matriz transposta */
                printf("\nMatriz original:\n");
                imprimir(mat, m, n);
                
                printf("\nMatriz transposta:\n");
                for(j = 0; j < n; j++) {
                    for(i = 0; i < m; i++) {
                        printf("%.2f\t", mat[i][j]);
                    }
                    printf("\n");
                }
                break;
                
            case 3: /* Multiplicação por escalar */
                printf("\nDigite o valor do escalar para multiplicacao: ");
                scanf("%f", &escalar);
                
                printf("\nMatriz original:\n");
                imprimir(mat, m, n);
                
                printf("\nResultado da multiplicacao por %.2f:\n", escalar);
                for(i = 0; i < m; i++) {
                    for(j = 0; j < n; j++) {
                        printf("%.2f\t", mat[i][j] * escalar);
                    }
                    printf("\n");
                }
                break;
                
            case 4: /* Soma com escalar */
                printf("\nDigite o valor do escalar para soma: ");
                scanf("%f", &escalar);
                
                printf("\nMatriz original:\n");
                imprimir(mat, m, n);
                
                printf("\nResultado da soma com %.2f:\n", escalar);
                for(i = 0; i < m; i++) {
                    for(j = 0; j < n; j++) {
                        printf("%.2f\t", mat[i][j] + escalar);
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
    } while(opcao != 0);
    
    return 0;
}

#include <stdio.h>

int main(void) {
    int n, m[10][10];
    int i, j;
    int soma_ref, soma_atual;
    int eh_magico = 1; // Começa assumindo que é um quadrado mágico

    // Leitura da dimensão e dos elementos da matriz
    printf("Digite a dimensao da matriz (n < 10): ");
    scanf("%d", &n);

    // --- CORREÇÃO 1: Validação da dimensão da matriz ---
    // Impede que o usuário insira um valor inválido que cause erro.
    if (n <= 0 || n >= 10) {
        printf("Erro: a dimensao deve ser um numero entre 1 e 9.\n");
        return 1; // Termina o programa indicando um erro
    }

    printf("Digite os elementos da matriz %dx%d:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("m[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    // 1. Calcula a soma da diagonal principal para usar como referência
    soma_ref = 0;
    for (i = 0; i < n; i++) {
        soma_ref += m[i][i];
    }
    printf("\nSoma da diagonal principal: %d\n", soma_ref);

    // 2. Calcula e compara a soma da diagonal secundária
    soma_atual = 0;
    for (i = 0; i < n; i++) {
        soma_atual += m[i][n - 1 - i];
    }
    printf("Soma da diagonal secundaria: %d\n", soma_atual);
    if (soma_atual != soma_ref) {
        eh_magico = 0;
    }

    // --- CORREÇÃO 2: Otimização da verificação ---
    // Se 'eh_magico' já for 0, não é necessário fazer as outras verificações.
    if (eh_magico) { 
        // 3. Calcula e compara a soma de cada linha
        printf("\nSomas das linhas:\n");
        for (i = 0; i < n; i++) {
            soma_atual = 0;
            for (j = 0; j < n; j++) {
                soma_atual += m[i][j];
            }
            printf("Linha %d: %d\n", i, soma_atual);
            if (soma_atual != soma_ref) {
                eh_magico = 0;
                break; // Se uma linha falhar, para a verificação de linhas
            }
        }
    }
    
    // --- CORREÇÃO 2 (continuação) ---
    if (eh_magico) {
        // 4. Calcula e compara a soma de cada coluna
        printf("\nSomas das colunas:\n");
        for (j = 0; j < n; j++) {
            soma_atual = 0;
            for (i = 0; i < n; i++) {
                soma_atual += m[i][j];
            }
            printf("Coluna %d: %d\n", j, soma_atual);
            if (soma_atual != soma_ref) {
                eh_magico = 0;
                break; // Se uma coluna falhar, para a verificação de colunas
            }
        }
    }

    // 5. Imprime o resultado final
    if (eh_magico) { // A verificação pode ser simplificada para 'if (eh_magico)'
        printf("\nA matriz eh um Quadrado Magico!\n");
    } else {
        printf("\nA matriz NAO eh um Quadrado Magico.\n");
    }

    return 0;
}

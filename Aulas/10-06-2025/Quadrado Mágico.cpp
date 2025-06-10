#include <stdio.h>

int main(void) {
    int n, m[10][10];
    int i, j;
    int soma_ref, soma_atual;
    int eh_magico = 1; // Come�a assumindo que � um quadrado m�gico

    // Leitura da dimens�o e dos elementos da matriz
    printf("Digite a dimensao da matriz (n < 10): ");
    scanf("%d", &n);

    // --- CORRE��O 1: Valida��o da dimens�o da matriz ---
    // Impede que o usu�rio insira um valor inv�lido que cause erro.
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

    // 1. Calcula a soma da diagonal principal para usar como refer�ncia
    soma_ref = 0;
    for (i = 0; i < n; i++) {
        soma_ref += m[i][i];
    }
    printf("\nSoma da diagonal principal: %d\n", soma_ref);

    // 2. Calcula e compara a soma da diagonal secund�ria
    soma_atual = 0;
    for (i = 0; i < n; i++) {
        soma_atual += m[i][n - 1 - i];
    }
    printf("Soma da diagonal secundaria: %d\n", soma_atual);
    if (soma_atual != soma_ref) {
        eh_magico = 0;
    }

    // --- CORRE��O 2: Otimiza��o da verifica��o ---
    // Se 'eh_magico' j� for 0, n�o � necess�rio fazer as outras verifica��es.
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
                break; // Se uma linha falhar, para a verifica��o de linhas
            }
        }
    }
    
    // --- CORRE��O 2 (continua��o) ---
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
                break; // Se uma coluna falhar, para a verifica��o de colunas
            }
        }
    }

    // 5. Imprime o resultado final
    if (eh_magico) { // A verifica��o pode ser simplificada para 'if (eh_magico)'
        printf("\nA matriz eh um Quadrado Magico!\n");
    } else {
        printf("\nA matriz NAO eh um Quadrado Magico.\n");
    }

    return 0;
}

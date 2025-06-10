#include <stdio.h>
#define MAX_N 50

/**
 * @brief Verifica se um 'elemento' existe dentro de um vetor 'v' de tamanho 'n'.
 * @return 1 se pertence, 0 caso contrário.
 */
int pertence(int v[], int n, int elemento) {
    for (int i = 0; i < n; i++) {
        if (v[i] == elemento) {
            return 1; // Encontrou o elemento
        }
    }
    return 0; // Não encontrou
}

/**
 * @brief Verifica se um vetor 'v' de tamanho 'n' contém todos os inteiros de 1 a n.
 * @return 1 se for uma permutação, 0 caso contrário.
 */
int verificaVetor(int v[], int n) {
    // Para cada número de 1 a n...
    for (int i = 1; i <= n; i++) {
        // ...verifica se ele pertence ao vetor.
        if (pertence(v, n, i) == 0) {
            return 0; // Se algum número faltar, já não é "latino"
        }
    }
    return 1; // Se todos os números de 1 a n foram encontrados, é "latino"
}

int main() {
    int n, i, j, A[MAX_N][MAX_N], v_coluna[MAX_N];
    int eh_quad_latino = 1; // Flag: assume que é um quadrado latino até provar o contrário.

    // a) Leitura e validação do valor de n 
    do {
        printf("Digite a ordem da matriz (n, entre 4 e 50): ");
        scanf("%d", &n);
        if (n < 4 || n > 50) {
            printf("Valor invalido. Tente novamente.\n");
        }
    } while (n < 4 || n > 50);

    // b) Leitura dos dados da matriz A 
    printf("Digite os valores da matriz %dx%d:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // d) Verificação das linhas 
    for (i = 0; i < n; i++) {
        if (!verificaVetor(A[i], n)) { // A[i] já é um ponteiro para a linha i
            eh_quad_latino = 0;
            break; // Se uma linha falha, não precisa checar o resto
        }
    }

    // Verificação das colunas (só se todas as linhas estiverem OK)
    if (eh_quad_latino) {
        for (j = 0; j < n; j++) {
            // Copia a coluna j para um vetor auxiliar 
            for (i = 0; i < n; i++) {
                v_coluna[i] = A[i][j];
            }
            if (!verificaVetor(v_coluna, n)) {
                eh_quad_latino = 0;
                break; // Se uma coluna falha, não precisa checar o resto
            }
        }
    }

    // Impressão do resultado final
    if (eh_quad_latino) {
        printf("\nA matriz e' um quadrado latino.\n");
    } else {
        printf("\nA matriz NAO e' um quadrado latino.\n");
    }

    return 0;
}

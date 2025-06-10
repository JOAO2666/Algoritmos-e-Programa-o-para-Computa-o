#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Aloca dinamicamente um vetor de n inteiros.
 * @param n O tamanho do vetor.
 * @return Um ponteiro para o in�cio do vetor alocado.
 */
int* AlocaMemoria(int n) {
    int* res = (int*) malloc(n * sizeof(int));
    if (res == NULL) {
        printf("Erro na alocacao de memoria!\n");
        exit(1); // Encerra o programa se a mem�ria n�o puder ser alocada
    }
    return res;
}

/**
 * @brief Imprime os n elementos de um vetor de inteiros.
 * @param p Ponteiro para o vetor.
 * @param n N�mero de elementos a imprimir.
 */
void Imprime(int *p, int n) {
    printf("\nElementos do vetor: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

/**
 * @brief Libera a mem�ria alocada para um vetor.
 * @param p Ponteiro para a �rea de mem�ria a ser liberada.
 */
void LiberaMemoria(int *p) {
    if (p != NULL) {
        free(p); // Libera a mem�ria 
    }
}

int main(void) {
    int n;
    int *p_vetor;

    printf("Digite o tamanho do vetor (n): ");
    scanf("%d", &n);

    // Chama a fun��o para alocar a mem�ria
    p_vetor = AlocaMemoria(n);

    // L� os n elementos do vetor
    printf("Digite os %d elementos do vetor:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Valor de [%d]: ", i);
        scanf("%d", &p_vetor[i]); // ou scanf("%d", p_vetor + i);
    }

    // Chama a fun��o para imprimir o vetor
    Imprime(p_vetor, n);

    // Chama a fun��o para liberar a mem�ria
    LiberaMemoria(p_vetor);
    
    printf("Memoria liberada.\n");

    return 0;
}

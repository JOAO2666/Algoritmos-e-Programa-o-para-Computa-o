#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Preenche um vetor com a quantidade de leitos de cada município.
 * @param leitos Vetor a ser preenchido.
 * @param tamanho Número de municípios.
 */
void preencher(int leitos[], int tamanho) { [cite: 138, 174]
    printf("\n--- Preenchimento de Leitos por Municipio ---\n");
    for (int i = 0; i < tamanho; i++) {
        // CORREÇÃO: Usar i + 1 para mostrar o número correto do município
        printf("Informe leitos do municipio %d: ", i + 1);
        scanf("%d", &leitos[i]);
    }
}

/**
 * @brief Calcula a média e o valor máximo de leitos em um vetor.
 * @param leitos Vetor com os dados.
 * @param tamanho Número de elementos no vetor.
 * @param media Ponteiro para armazenar a média calculada.
 * @param maximo Ponteiro para armazenar o valor máximo encontrado.
 */
void obter_estatisticas(int leitos[], int tamanho, float *media, float *maximo) { [cite: 139, 175]
    if (tamanho <= 0) return;

    *media = 0;
    *maximo = leitos[0]; // Inicia o máximo com o primeiro elemento

    for (int i = 0; i < tamanho; i++) {
        *media += leitos[i]; // Acumula a soma

        if (leitos[i] > *maximo) { // Verifica se encontrou um novo máximo
            *maximo = leitos[i];
        }
    }

    // CORREÇÃO: A divisão para calcular a média deve ser feita fora do laço
    *media = *media / tamanho;
}

int main() {
    int m;
    // CORREÇÃO: med e max devem ser float para corresponder à função
    float med, max;
    int *leitos_vetor;

    // i. Ler e validar a quantidade de municípios 
    do {
        printf("Digite a quantidade de municipios (entre 3 e 100): ");
        scanf("%d", &m);
    } while (m < 3 || m > 100);

    // ii. Criar vetor dinamicamente 
    // CORREÇÃO: Faltava o operador '*' na multiplicação
    leitos_vetor = (int*) malloc(m * sizeof(int));
    if (leitos_vetor == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    // iii. Preencher o vetor 
    preencher(leitos_vetor, m);

    // iv. Obter as estatísticas 
    obter_estatisticas(leitos_vetor, m, &med, &max);

    // v. Imprimir os resultados 
    printf("\n--- Estatisticas de Leitos ---\n");
    printf("Media de leitos por municipio: %.2f\n", med);
    printf("Maxima quantidade de leitos em um municipio: %.0f\n", max);

    // Liberar memória alocada
    free(leitos_vetor);

    return 0;
}

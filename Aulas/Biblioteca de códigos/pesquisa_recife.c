#include <stdio.h>
#include <stdlib.h>

#define NUM_HABITANTES 5 // Reduzido para teste
#define NUM_DADOS 3

// Procedimento para ler os dados dos entrevistados
void lerDados(float minf[NUM_DADOS][NUM_HABITANTES])
{
    int i;
    printf("Digite os dados dos %d entrevistados:\n", NUM_HABITANTES);
    for (i = 0; i < NUM_HABITANTES; i++)
    {
        printf("\nEntrevistado %d:\n", i + 1);
        printf("Salario: R$ ");
        scanf("%f", &minf[0][i]);
        printf("Idade: ");
        scanf("%f", &minf[1][i]);
        printf("Numero de filhos: ");
        scanf("%f", &minf[2][i]);
    }
}

// Função para calcular a média de uma linha específica
float calcMedia(float minf[NUM_DADOS][NUM_HABITANTES], int linha)
{
    float soma = 0;
    int i;
    for (i = 0; i < NUM_HABITANTES; i++)
    {
        soma += minf[linha][i];
    }
    return soma / NUM_HABITANTES;
}

// Procedimento para calcular o menor e maior valor de uma linha
void calcMinMax(float minf[NUM_DADOS][NUM_HABITANTES], int linha, float *menor, float *maior)
{
    int i;
    *menor = minf[linha][0];
    *maior = minf[linha][0];

    for (i = 1; i < NUM_HABITANTES; i++)
    {
        if (minf[linha][i] < *menor)
        {
            *menor = minf[linha][i];
        }
        if (minf[linha][i] > *maior)
        {
            *maior = minf[linha][i];
        }
    }
}

int main()
{
    float minf[NUM_DADOS][NUM_HABITANTES];
    float menor, maior;

    // Verificar se a memória foi alocada corretamente
    if (minf == NULL)
    {
        printf("Erro: Nao foi possivel alocar memoria suficiente.\n");
        return 1;
    }

    // Ler os dados
    lerDados(minf);

    // Calcular e exibir médias
    printf("\nResultados da Pesquisa:\n");
    printf("Media salarial: R$ %.2f\n", calcMedia(minf, 0));
    printf("Idade media: %.2f anos\n", calcMedia(minf, 1));
    printf("Media de filhos: %.2f\n", calcMedia(minf, 2));

    // Calcular e exibir menor e maior número de filhos
    calcMinMax(minf, 2, &menor, &maior);
    printf("Menor numero de filhos: %.2f\n", menor);
    printf("Maior numero de filhos: %.2f\n", maior);

    // Pausa para visualizar os resultados
    printf("\nPressione ENTER para sair...");
    getchar();
    getchar();

    return 0;
}
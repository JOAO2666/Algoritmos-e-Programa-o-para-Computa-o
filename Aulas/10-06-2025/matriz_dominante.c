#include <stdio.h>
#include <math.h> // Para a função abs()

#define N 3

// Protótipos das funções
int dominante(int matriz[N][N]);
void escalona(int matriz[N][N]);
void imprime(int matriz[N][N]);

/**
 * a) Verifica se a matriz é estritamente diagonal dominante por coluna.
 * Retorna 1 se for dominante, 0 caso contrário.
 */
int dominante(int matriz[N][N])
{
    int i, j, soma;
    // Itera por cada coluna
    for (i = 0; i < N; i++)
    {
        soma = 0;
        // Soma os valores absolutos dos elementos fora da diagonal principal na coluna i
        for (j = 0; j < N; j++)
        {
            if (i != j)
            {
                soma = soma + abs(matriz[j][i]); // Soma os elementos da coluna i
            }
        }
        // Se o elemento da diagonal for menor ou igual à soma, não é dominante
        if (abs(matriz[i][i]) <= soma)
        {
            return 0; // Não satisfaz a condição
        }
    }
    return 1; // Satisfaz a condição para todas as colunas
}

/**
 * b) Troca as linhas da matriz para tentar torná-la diagonal dominante (pivotação parcial).
 */
void escalona(int matriz[N][N])
{
    int i, j, k;
    int maior, linha_maior, aux;

    // Para cada coluna i...
    for (i = 0; i < N; i++)
    {
        maior = abs(matriz[i][i]);
        linha_maior = i;

        // ...encontra a linha 'j' com o maior elemento em módulo na coluna 'i' (a partir da diagonal)
        for (j = i + 1; j < N; j++)
        {
            if (abs(matriz[j][i]) > maior)
            {
                maior = abs(matriz[j][i]);
                linha_maior = j;
            }
        }

        // Se a linha com o maior elemento não for a linha da diagonal (linha i), troca as linhas.
        if (linha_maior != i)
        {
            printf("\nTrocando linha %d com linha %d...\n", i + 1, linha_maior + 1);
            for (k = 0; k < N; k++)
            {
                aux = matriz[i][k];
                matriz[i][k] = matriz[linha_maior][k];
                matriz[linha_maior][k] = aux;
            }
        }
    }
}

/**
 * c) Imprime uma matriz 3x3 na tela.
 */
void imprime(int matriz[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

/**
 * d) Função principal que gerencia o fluxo do programa.
 */
int main()
{
    int matriz[N][N];
    int i, j;

    // Pede ao usuário para preencher a matriz
    printf("Digite os valores para a matriz %dx%d:\n", N, N);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("Digite o termo a[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz Original:\n");
    imprime(matriz);

    // Verifica se a matriz é dominante
    if (dominante(matriz))
    {
        printf("\nA matriz ja e diagonal estritamente dominante.\n");
    }
    else
    {
        printf("\nA matriz nao e diagonal estritamente dominante. Tentando escalonar...\n");
        // Se não for, escalona
        escalona(matriz);
        // Imprime a matriz resultante
        printf("\nMatriz Apos Escalonamento:\n");
        imprime(matriz);
    }

    return 0;
}
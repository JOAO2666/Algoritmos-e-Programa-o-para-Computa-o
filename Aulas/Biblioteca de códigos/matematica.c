/**
 * @file matematica.c
 * @brief Implementação das funções matemáticas
 */

#include "matematica.h"
#include <stdlib.h>
#include <math.h>

// Funções aritméticas básicas
double soma(double a, double b)
{
    return a + b;
}

double subtracao(double a, double b)
{
    return a - b;
}

double multiplicacao(double a, double b)
{
    return a * b;
}

double divisao(double a, double b)
{
    if (b == 0)
    {
        printf("Erro: Divisão por zero!\n");
        return 0;
    }
    return a / b;
}

// Funções trigonométricas
double seno(double angulo)
{
    return sin(angulo * M_PI / 180.0);
}

double cosseno(double angulo)
{
    return cos(angulo * M_PI / 180.0);
}

double tangente(double angulo)
{
    return tan(angulo * M_PI / 180.0);
}

// Cálculo de áreas e volumes
double area_retangulo(double base, double altura)
{
    return base * altura;
}

double area_triangulo(double base, double altura)
{
    return (base * altura) / 2.0;
}

double area_circulo(double raio)
{
    return M_PI * raio * raio;
}

double volume_cubo(double lado)
{
    return lado * lado * lado;
}

double volume_esfera(double raio)
{
    return (4.0 / 3.0) * M_PI * raio * raio * raio;
}

// Funções para matrizes e vetores
void soma_matrizes(double **matriz1, double **matriz2, double **resultado, int linhas, int colunas)
{
    int i, j;

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void multiplica_matrizes(double **matriz1, double **matriz2, double **resultado, int linhas1, int colunas1, int colunas2)
{
    int i, j, k;

    for (i = 0; i < linhas1; i++)
    {
        for (j = 0; j < colunas2; j++)
        {
            resultado[i][j] = 0;
            for (k = 0; k < colunas1; k++)
            {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

void transpor_matriz(double **matriz, double **resultado, int linhas, int colunas)
{
    int i, j;

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            resultado[j][i] = matriz[i][j];
        }
    }
}

double produto_escalar(double *vetor1, double *vetor2, int tamanho)
{
    double resultado = 0;
    for (int i = 0; i < tamanho; i++)
    {
        resultado += vetor1[i] * vetor2[i];
    }
    return resultado;
}

// Funções estatísticas
double media(double *dados, int tamanho)
{
    double soma = 0;
    int i;

    for (i = 0; i < tamanho; i++)
    {
        soma += dados[i];
    }
    return soma / tamanho;
}

double mediana(double *dados, int tamanho)
{
    int i, j;
    double temp;

    // Ordenar os dados
    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = i + 1; j < tamanho; j++)
        {
            if (dados[j] < dados[i])
            {
                temp = dados[i];
                dados[i] = dados[j];
                dados[j] = temp;
            }
        }
    }

    if (tamanho % 2 == 0)
    {
        return (dados[tamanho / 2 - 1] + dados[tamanho / 2]) / 2;
    }
    else
    {
        return dados[tamanho / 2];
    }
}

double moda(double *dados, int tamanho)
{
    int i, j;
    int max_contagem = 0;
    int contagem;
    double moda = dados[0];

    for (i = 0; i < tamanho; i++)
    {
        contagem = 0;
        for (j = 0; j < tamanho; j++)
        {
            if (dados[j] == dados[i])
            {
                contagem++;
            }
        }
        if (contagem > max_contagem)
        {
            max_contagem = contagem;
            moda = dados[i];
        }
    }
    return moda;
}

double desvio_padrao(double *dados, int tamanho)
{
    double med = media(dados, tamanho);
    double soma = 0;
    int i;

    for (i = 0; i < tamanho; i++)
    {
        soma += pow(dados[i] - med, 2);
    }
    return sqrt(soma / tamanho);
}

// Funções para equações
int equacao_primeiro_grau(double a, double b, double *x)
{
    if (a == 0)
    {
        return 0; // Sem solução ou infinitas soluções
    }
    *x = -b / a;
    return 1;
}

int equacao_segundo_grau(double a, double b, double c, double *x1, double *x2)
{
    double delta;

    if (a == 0)
    {
        return equacao_primeiro_grau(b, c, x1);
    }

    delta = b * b - 4 * a * c;

    if (delta < 0)
    {
        return 0; // Sem solução real
    }

    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);
    return 1;
}
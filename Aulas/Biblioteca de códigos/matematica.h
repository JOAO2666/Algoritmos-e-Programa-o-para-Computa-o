/**
 * @file matematica.h
 * @brief Cabeçalho para funções matemáticas
 */

#ifndef MATEMATICA_H
#define MATEMATICA_H

#include <math.h>
#include <stdbool.h>

// Funções aritméticas básicas
double soma(double a, double b);
double subtracao(double a, double b);
double multiplicacao(double a, double b);
double divisao(double a, double b);

// Funções trigonométricas
double seno(double angulo);
double cosseno(double angulo);
double tangente(double angulo);

// Cálculo de áreas e volumes
double area_retangulo(double base, double altura);
double area_triangulo(double base, double altura);
double area_circulo(double raio);
double volume_cubo(double lado);
double volume_esfera(double raio);

// Resolução de equações
bool resolve_equacao_primeiro_grau(double a, double b, double *x);
bool resolve_equacao_segundo_grau(double a, double b, double c, double *x1, double *x2);

// Funções para matrizes e vetores
void soma_matrizes(double **matriz1, double **matriz2, double **resultado, int linhas, int colunas);
void multiplica_matrizes(double **matriz1, double **matriz2, double **resultado, int linhas1, int colunas1, int colunas2);
double produto_escalar(double *vetor1, double *vetor2, int tamanho);

// Estatística básica
double media(double *valores, int tamanho);
double mediana(double *valores, int tamanho);
double moda(double *valores, int tamanho);
double desvio_padrao(double *valores, int tamanho);

#endif // MATEMATICA_H
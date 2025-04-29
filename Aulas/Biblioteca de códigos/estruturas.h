/**
 * @file estruturas.h
 * @brief Cabeçalho para estruturas de dados
 */

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição de tipos genéricos
typedef void *Dado;
typedef void (*ImprimirDado)(Dado);
typedef int (*CompararDado)(Dado, Dado);

// Estrutura para nó de lista encadeada
typedef struct No
{
    Dado dado;
    struct No *proximo;
} No;

// Estrutura para lista encadeada
typedef struct
{
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

// Estrutura para pilha
typedef struct
{
    No *topo;
    int tamanho;
} Pilha;

// Estrutura para fila
typedef struct
{
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

// Estrutura para nó de árvore binária
typedef struct NoArvore
{
    Dado dado;
    struct NoArvore *esquerda;
    struct NoArvore *direita;
} NoArvore;

// Estrutura para árvore binária
typedef struct
{
    NoArvore *raiz;
    int tamanho;
} ArvoreBinaria;

// Estrutura para nó de grafo
typedef struct NoGrafo
{
    int vertice;
    struct NoGrafo *proximo;
} NoGrafo;

// Estrutura para grafo
typedef struct
{
    int num_vertices;
    NoGrafo **lista_adjacencia;
} Grafo;

// Estrutura para entrada da tabela hash
typedef struct EntradaHash
{
    char *chave;
    Dado valor;
    struct EntradaHash *proximo;
} EntradaHash;

// Estrutura para tabela hash
typedef struct
{
    int tamanho;
    EntradaHash **tabela;
} TabelaHash;

// Funções para lista encadeada
Lista *criar_lista(void);
void destruir_lista(Lista *lista, void (*destruir_dado)(Dado));
void inserir_lista(Lista *lista, Dado dado);
void remover_lista(Lista *lista, Dado dado, CompararDado comparar);
Dado buscar_lista(Lista *lista, Dado dado, CompararDado comparar);
void imprimir_lista(Lista *lista, ImprimirDado imprimir);

// Funções para pilha
Pilha *criar_pilha(void);
void destruir_pilha(Pilha *pilha, void (*destruir_dado)(Dado));
void empilhar(Pilha *pilha, Dado dado);
Dado desempilhar(Pilha *pilha);
Dado topo_pilha(Pilha *pilha);
bool pilha_vazia(Pilha *pilha);

// Funções para fila
Fila *criar_fila(void);
void destruir_fila(Fila *fila, void (*destruir_dado)(Dado));
void enfileirar(Fila *fila, Dado dado);
Dado desenfileirar(Fila *fila);
Dado frente_fila(Fila *fila);
bool fila_vazia(Fila *fila);

// Funções para árvore binária
ArvoreBinaria *criar_arvore(void);
void destruir_arvore(ArvoreBinaria *arvore, void (*destruir_dado)(Dado));
void inserir_arvore(ArvoreBinaria *arvore, Dado dado, CompararDado comparar);
void remover_arvore(ArvoreBinaria *arvore, Dado dado, CompararDado comparar);
Dado buscar_arvore(ArvoreBinaria *arvore, Dado dado, CompararDado comparar);
void percurso_em_ordem(ArvoreBinaria *arvore, ImprimirDado imprimir);
void percurso_pre_ordem(ArvoreBinaria *arvore, ImprimirDado imprimir);
void percurso_pos_ordem(ArvoreBinaria *arvore, ImprimirDado imprimir);

// Funções para grafo
Grafo *criar_grafo(int num_vertices);
void destruir_grafo(Grafo *grafo);
void adicionar_aresta(Grafo *grafo, int origem, int destino);
void remover_aresta(Grafo *grafo, int origem, int destino);
bool tem_aresta(Grafo *grafo, int origem, int destino);
void imprimir_grafo(Grafo *grafo);
void busca_em_profundidade(Grafo *grafo, int vertice_inicial);
void busca_em_largura(Grafo *grafo, int vertice_inicial);

// Funções para tabela hash
TabelaHash *criar_tabela_hash(int tamanho);
void destruir_tabela_hash(TabelaHash *tabela, void (*destruir_dado)(Dado));
void inserir_tabela_hash(TabelaHash *tabela, const char *chave, Dado valor);
Dado buscar_tabela_hash(TabelaHash *tabela, const char *chave);
void remover_tabela_hash(TabelaHash *tabela, const char *chave);
void imprimir_tabela_hash(TabelaHash *tabela, ImprimirDado imprimir);

#endif // ESTRUTURAS_H
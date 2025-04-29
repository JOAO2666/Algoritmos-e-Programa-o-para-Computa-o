/**
 * @file estruturas.c
 * @brief Implementação das estruturas de dados
 */

#include "estruturas.h"
#include <string.h>

// Funções auxiliares
static unsigned int hash(const char *chave, int tamanho)
{
    unsigned int hash = 0;
    int i;

    for (i = 0; chave[i] != '\0'; i++)
    {
        hash = 31 * hash + chave[i];
    }
    return hash % tamanho;
}

// Implementação da lista encadeada
Lista *criar_lista(void)
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

void inserir_lista(Lista *lista, Dado dado)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
}

void remover_lista(Lista *lista, Dado dado, int (*comparar)(Dado, Dado))
{
    No *atual = lista->inicio;
    No *anterior = NULL;

    while (atual != NULL)
    {
        if (comparar(atual->dado, dado) == 0)
        {
            if (anterior == NULL)
            {
                lista->inicio = atual->proximo;
            }
            else
            {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

Dado buscar_lista(Lista *lista, Dado dado, int (*comparar)(Dado, Dado))
{
    No *atual = lista->inicio;

    while (atual != NULL)
    {
        if (comparar(atual->dado, dado) == 0)
        {
            return atual->dado;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void imprimir_lista(Lista *lista, void (*imprimir)(Dado))
{
    No *atual = lista->inicio;

    while (atual != NULL)
    {
        imprimir(atual->dado);
        printf(" ");
        atual = atual->proximo;
    }
    printf("\n");
}

void destruir_lista(Lista *lista, void (*destruir)(Dado))
{
    No *atual = lista->inicio;
    No *proximo;

    while (atual != NULL)
    {
        proximo = atual->proximo;
        if (destruir != NULL)
        {
            destruir(atual->dado);
        }
        free(atual);
        atual = proximo;
    }
    free(lista);
}

// Implementação da pilha
Pilha *criar_pilha(void)
{
    return criar_lista();
}

void empilhar(Pilha *pilha, Dado dado)
{
    inserir_lista(pilha, dado);
}

Dado desempilhar(Pilha *pilha)
{
    if (pilha->inicio == NULL)
    {
        return NULL;
    }

    Dado dado = pilha->inicio->dado;
    No *temp = pilha->inicio;
    pilha->inicio = pilha->inicio->proximo;
    free(temp);
    return dado;
}

Dado topo_pilha(Pilha *pilha)
{
    return pilha->inicio ? pilha->inicio->dado : NULL;
}

int pilha_vazia(Pilha *pilha)
{
    return pilha->inicio == NULL;
}

void destruir_pilha(Pilha *pilha, void (*destruir)(Dado))
{
    destruir_lista(pilha, destruir);
}

// Implementação da fila
Fila *criar_fila(void)
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void enfileirar(Fila *fila, Dado dado)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;
    novo->proximo = NULL;

    if (fila->fim != NULL)
    {
        fila->fim->proximo = novo;
    }
    else
    {
        fila->inicio = novo;
    }
    fila->fim = novo;
}

Dado desenfileirar(Fila *fila)
{
    if (fila->inicio == NULL)
    {
        return NULL;
    }

    Dado dado = fila->inicio->dado;
    No *temp = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }

    free(temp);
    return dado;
}

Dado frente_fila(Fila *fila)
{
    return fila->inicio ? fila->inicio->dado : NULL;
}

int fila_vazia(Fila *fila)
{
    return fila->inicio == NULL;
}

void destruir_fila(Fila *fila, void (*destruir)(Dado))
{
    No *atual = fila->inicio;
    No *proximo;

    while (atual != NULL)
    {
        proximo = atual->proximo;
        if (destruir != NULL)
        {
            destruir(atual->dado);
        }
        free(atual);
        atual = proximo;
    }
    free(fila);
}

// Implementação da árvore binária
ArvoreBinaria *criar_arvore(void)
{
    ArvoreBinaria *arvore = (ArvoreBinaria *)malloc(sizeof(ArvoreBinaria));
    arvore->raiz = NULL;
    arvore->tamanho = 0;
    return arvore;
}

static void destruir_no_arvore(NoArvore *no, void (*destruir_dado)(Dado))
{
    if (no == NULL)
    {
        return;
    }

    destruir_no_arvore(no->esquerda, destruir_dado);
    destruir_no_arvore(no->direita, destruir_dado);

    if (destruir_dado != NULL)
    {
        destruir_dado(no->dado);
    }
    free(no);
}

void destruir_arvore(ArvoreBinaria *arvore, void (*destruir_dado)(Dado))
{
    destruir_no_arvore(arvore->raiz, destruir_dado);
    free(arvore);
}

static NoArvore *inserir_no_arvore(NoArvore *no, Dado dado, CompararDado comparar)
{
    if (no == NULL)
    {
        NoArvore *novo = (NoArvore *)malloc(sizeof(NoArvore));
        novo->dado = dado;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }

    if (comparar(dado, no->dado) < 0)
    {
        no->esquerda = inserir_no_arvore(no->esquerda, dado, comparar);
    }
    else
    {
        no->direita = inserir_no_arvore(no->direita, dado, comparar);
    }

    return no;
}

void inserir_arvore(ArvoreBinaria *arvore, Dado dado, CompararDado comparar)
{
    arvore->raiz = inserir_no_arvore(arvore->raiz, dado, comparar);
    arvore->tamanho++;
}

static NoArvore *remover_no_arvore(NoArvore *no, Dado dado, CompararDado comparar)
{
    if (no == NULL)
    {
        return NULL;
    }

    if (comparar(dado, no->dado) < 0)
    {
        no->esquerda = remover_no_arvore(no->esquerda, dado, comparar);
    }
    else if (comparar(dado, no->dado) > 0)
    {
        no->direita = remover_no_arvore(no->direita, dado, comparar);
    }
    else
    {
        if (no->esquerda == NULL)
        {
            NoArvore *temp = no->direita;
            free(no);
            return temp;
        }
        else if (no->direita == NULL)
        {
            NoArvore *temp = no->esquerda;
            free(no);
            return temp;
        }

        NoArvore *temp = no->direita;
        while (temp->esquerda != NULL)
        {
            temp = temp->esquerda;
        }

        no->dado = temp->dado;
        no->direita = remover_no_arvore(no->direita, temp->dado, comparar);
    }

    return no;
}

void remover_arvore(ArvoreBinaria *arvore, Dado dado, CompararDado comparar)
{
    arvore->raiz = remover_no_arvore(arvore->raiz, dado, comparar);
    arvore->tamanho--;
}

static Dado buscar_no_arvore(NoArvore *no, Dado dado, CompararDado comparar)
{
    if (no == NULL)
    {
        return NULL;
    }

    if (comparar(dado, no->dado) == 0)
    {
        return no->dado;
    }

    if (comparar(dado, no->dado) < 0)
    {
        return buscar_no_arvore(no->esquerda, dado, comparar);
    }

    return buscar_no_arvore(no->direita, dado, comparar);
}

Dado buscar_arvore(ArvoreBinaria *arvore, Dado dado, CompararDado comparar)
{
    return buscar_no_arvore(arvore->raiz, dado, comparar);
}

static void percurso_em_ordem_no(NoArvore *no, ImprimirDado imprimir)
{
    if (no == NULL)
    {
        return;
    }

    percurso_em_ordem_no(no->esquerda, imprimir);
    imprimir(no->dado);
    percurso_em_ordem_no(no->direita, imprimir);
}

void percurso_em_ordem(ArvoreBinaria *arvore, ImprimirDado imprimir)
{
    percurso_em_ordem_no(arvore->raiz, imprimir);
    printf("\n");
}

static void percurso_pre_ordem_no(NoArvore *no, ImprimirDado imprimir)
{
    if (no == NULL)
    {
        return;
    }

    imprimir(no->dado);
    percurso_pre_ordem_no(no->esquerda, imprimir);
    percurso_pre_ordem_no(no->direita, imprimir);
}

void percurso_pre_ordem(ArvoreBinaria *arvore, ImprimirDado imprimir)
{
    percurso_pre_ordem_no(arvore->raiz, imprimir);
    printf("\n");
}

static void percurso_pos_ordem_no(NoArvore *no, ImprimirDado imprimir)
{
    if (no == NULL)
    {
        return;
    }

    percurso_pos_ordem_no(no->esquerda, imprimir);
    percurso_pos_ordem_no(no->direita, imprimir);
    imprimir(no->dado);
}

void percurso_pos_ordem(ArvoreBinaria *arvore, ImprimirDado imprimir)
{
    percurso_pos_ordem_no(arvore->raiz, imprimir);
    printf("\n");
}

// Implementação do grafo
Grafo *criar_grafo(int num_vertices)
{
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    grafo->num_vertices = num_vertices;
    grafo->lista_adjacencia = (NoGrafo **)malloc(num_vertices * sizeof(NoGrafo *));

    for (int i = 0; i < num_vertices; i++)
    {
        grafo->lista_adjacencia[i] = NULL;
    }

    return grafo;
}

void destruir_grafo(Grafo *grafo)
{
    for (int i = 0; i < grafo->num_vertices; i++)
    {
        NoGrafo *atual = grafo->lista_adjacencia[i];
        while (atual != NULL)
        {
            NoGrafo *proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }
    free(grafo->lista_adjacencia);
    free(grafo);
}

void adicionar_aresta(Grafo *grafo, int origem, int destino)
{
    NoGrafo *novo = (NoGrafo *)malloc(sizeof(NoGrafo));
    novo->vertice = destino;
    novo->proximo = grafo->lista_adjacencia[origem];
    grafo->lista_adjacencia[origem] = novo;
}

void remover_aresta(Grafo *grafo, int origem, int destino)
{
    NoGrafo *anterior = NULL;
    NoGrafo *atual = grafo->lista_adjacencia[origem];

    while (atual != NULL && atual->vertice != destino)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL)
    {
        if (anterior == NULL)
        {
            grafo->lista_adjacencia[origem] = atual->proximo;
        }
        else
        {
            anterior->proximo = atual->proximo;
        }
        free(atual);
    }
}

bool tem_aresta(Grafo *grafo, int origem, int destino)
{
    NoGrafo *atual = grafo->lista_adjacencia[origem];
    while (atual != NULL)
    {
        if (atual->vertice == destino)
        {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

void imprimir_grafo(Grafo *grafo)
{
    for (int i = 0; i < grafo->num_vertices; i++)
    {
        printf("Vértice %d: ", i);
        NoGrafo *atual = grafo->lista_adjacencia[i];
        while (atual != NULL)
        {
            printf("%d ", atual->vertice);
            atual = atual->proximo;
        }
        printf("\n");
    }
}

void busca_em_profundidade(Grafo *grafo, int vertice_inicial)
{
    bool *visitado = (bool *)calloc(grafo->num_vertices, sizeof(bool));
    Pilha *pilha = criar_pilha();

    empilhar(pilha, (Dado)(long)vertice_inicial);
    visitado[vertice_inicial] = true;

    while (!pilha_vazia(pilha))
    {
        int vertice = (int)(long)desempilhar(pilha);
        printf("%d ", vertice);

        NoGrafo *atual = grafo->lista_adjacencia[vertice];
        while (atual != NULL)
        {
            if (!visitado[atual->vertice])
            {
                empilhar(pilha, (Dado)(long)atual->vertice);
                visitado[atual->vertice] = true;
            }
            atual = atual->proximo;
        }
    }

    free(visitado);
    destruir_pilha(pilha, NULL);
    printf("\n");
}

void busca_em_largura(Grafo *grafo, int vertice_inicial)
{
    bool *visitado = (bool *)calloc(grafo->num_vertices, sizeof(bool));
    Fila *fila = criar_fila();

    enfileirar(fila, (Dado)(long)vertice_inicial);
    visitado[vertice_inicial] = true;

    while (!fila_vazia(fila))
    {
        int vertice = (int)(long)desenfileirar(fila);
        printf("%d ", vertice);

        NoGrafo *atual = grafo->lista_adjacencia[vertice];
        while (atual != NULL)
        {
            if (!visitado[atual->vertice])
            {
                enfileirar(fila, (Dado)(long)atual->vertice);
                visitado[atual->vertice] = true;
            }
            atual = atual->proximo;
        }
    }

    free(visitado);
    destruir_fila(fila, NULL);
    printf("\n");
}

// Implementação da tabela hash
TabelaHash *criar_tabela_hash(int tamanho)
{
    TabelaHash *tabela = (TabelaHash *)malloc(sizeof(TabelaHash));
    tabela->tamanho = tamanho;
    tabela->tabela = (EntradaHash **)calloc(tamanho, sizeof(EntradaHash *));
    return tabela;
}

void destruir_tabela_hash(TabelaHash *tabela, void (*destruir_dado)(Dado))
{
    for (int i = 0; i < tabela->tamanho; i++)
    {
        EntradaHash *atual = tabela->tabela[i];
        while (atual != NULL)
        {
            EntradaHash *proximo = atual->proximo;
            free(atual->chave);
            if (destruir_dado != NULL)
            {
                destruir_dado(atual->valor);
            }
            free(atual);
            atual = proximo;
        }
    }
    free(tabela->tabela);
    free(tabela);
}

void inserir_tabela_hash(TabelaHash *tabela, const char *chave, Dado valor)
{
    unsigned int indice = hash(chave, tabela->tamanho);

    EntradaHash *entrada = (EntradaHash *)malloc(sizeof(EntradaHash));
    entrada->chave = strdup(chave);
    entrada->valor = valor;
    entrada->proximo = tabela->tabela[indice];

    tabela->tabela[indice] = entrada;
}

Dado buscar_tabela_hash(TabelaHash *tabela, const char *chave)
{
    unsigned int indice = hash(chave, tabela->tamanho);

    EntradaHash *atual = tabela->tabela[indice];
    while (atual != NULL)
    {
        if (strcmp(atual->chave, chave) == 0)
        {
            return atual->valor;
        }
        atual = atual->proximo;
    }

    return NULL;
}

void remover_tabela_hash(TabelaHash *tabela, const char *chave)
{
    unsigned int indice = hash(chave, tabela->tamanho);

    EntradaHash *anterior = NULL;
    EntradaHash *atual = tabela->tabela[indice];

    while (atual != NULL && strcmp(atual->chave, chave) != 0)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL)
    {
        if (anterior == NULL)
        {
            tabela->tabela[indice] = atual->proximo;
        }
        else
        {
            anterior->proximo = atual->proximo;
        }

        free(atual->chave);
        free(atual);
    }
}

void imprimir_tabela_hash(TabelaHash *tabela, ImprimirDado imprimir)
{
    for (int i = 0; i < tabela->tamanho; i++)
    {
        printf("Índice %d: ", i);
        EntradaHash *atual = tabela->tabela[i];
        while (atual != NULL)
        {
            printf("(%s, ", atual->chave);
            imprimir(atual->valor);
            printf(") ");
            atual = atual->proximo;
        }
        printf("\n");
    }
}
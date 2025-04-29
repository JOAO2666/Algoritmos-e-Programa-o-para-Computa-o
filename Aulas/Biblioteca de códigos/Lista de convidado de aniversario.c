#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONVIDADOS 100
#define TAM_NOME 16

// Função para inserir um nome na lista de convidados
int insere_nome(char nome[], char lista[][TAM_NOME], int qtd_convidados) {
    int i;
    // Verifica se o nome já está na lista
    for (i = 0; i < qtd_convidados; i++) {
        if (strcmp(lista[i], nome) == 0) {
            return 0; // Nome já existe na lista
        }
    }
    
    // Se não estiver cheio, adiciona o nome
    if (qtd_convidados < MAX_CONVIDADOS) {
        strcpy(lista[qtd_convidados], nome);
        return 1; // Nome foi adicionado
    }
    
    return 0; // Lista cheia (não adicionou)
}

// Função para contar convidados por letra inicial
int conta_letra(char letra, char lista[][TAM_NOME], int qtd_convidados) {
    int contador = 0;
    int i;
    for (i = 0; i < qtd_convidados; i++) {
        // Comparação case-insensitive
        if (tolower(lista[i][0]) == tolower(letra)) {
            contador++;
        }
    }
    return contador;
}

int main() {
    char Lista[MAX_CONVIDADOS][TAM_NOME];
    int qtd_convidados = 0;
    char nome[TAM_NOME];
    int i;
    
    printf("=== Cadastro de Convidados ===\n");
    printf("Digite os nomes dos convidados (ou 0 para encerrar):\n");
    
    // Loop para cadastrar convidados
    while (qtd_convidados < MAX_CONVIDADOS) {
        printf("Nome do convidado %d: ", qtd_convidados + 1);
        fgets(nome, TAM_NOME, stdin);
        
        // Remove o \n do final do nome
        nome[strcspn(nome, "\n")] = '\0';
        
        // Verifica se o usuário quer encerrar
        if (strcmp(nome, "0") == 0) {
            break;
        }
        
        // Tenta inserir o nome
        if (insere_nome(nome, Lista, qtd_convidados)) {
            qtd_convidados++;
            printf("Convidado adicionado com sucesso!\n");
        } else if (qtd_convidados >= MAX_CONVIDADOS) {
            printf("Limite de convidados atingido!\n");
            break;
        } else {
            printf("Este convidado já está na lista!\n");
        }
    }
    
    // Exibe a lista de convidados
    printf("\n=== Lista de Convidados ===\n");
    for (i = 0; i < qtd_convidados; i++) {
        printf("%d. %s\n", i + 1, Lista[i]);
    }
    
    // Exibe estatísticas
    printf("\n=== Estatísticas ===\n");
    printf("Total de convidados: %d\n", qtd_convidados);
    
    int com_R = conta_letra('R', Lista, qtd_convidados);
    printf("Convidados com nomes que começam com 'R': %d\n", com_R);
    
    return 0;
}

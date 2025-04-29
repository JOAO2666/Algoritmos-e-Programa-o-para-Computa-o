#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_ATLETAS 3000
#define TAM_NOME 30

// Variáveis globais
int matriz_resultados[NUM_ATLETAS][NUM_ATLETAS];
char nomes_atletas[NUM_ATLETAS][TAM_NOME];

// Função para preencher a matriz de resultados
void preencher(int matriz[NUM_ATLETAS][NUM_ATLETAS]) {
    int i, j;
    printf("Preenchendo a matriz de resultados...\n");
    for (i = 0; i < NUM_ATLETAS; i++) {
        for (j = 0; j < NUM_ATLETAS; j++) {
            if (i == j) {
                matriz[i][j] = 0; // Diagonal principal
            } else {
                matriz[i][j] = rand() % 3 - 1; // Gera -1, 0 ou 1 aleatoriamente
            }
        }
    }
    printf("Matriz preenchida!\n");
}

// Função para encontrar o atleta com mais vitórias
int maior_vitorias(int matriz[NUM_ATLETAS][NUM_ATLETAS]) {
    int max_vitorias = -1;
    int atleta_vencedor = 0;
    int i, j;
    
    for (i = 0; i < NUM_ATLETAS; i++) {
        int vitorias = 0;
        for (j = 0; j < NUM_ATLETAS; j++) {
            if (i != j && matriz[i][j] == 1) {
                vitorias++;
            }
        }
        if (vitorias > max_vitorias) {
            max_vitorias = vitorias;
            atleta_vencedor = i;
        }
    }
    return atleta_vencedor;
}

// Função para contar vitórias de um atleta
int numero_vitorias(int matriz[NUM_ATLETAS][NUM_ATLETAS], int i) {
    int vitorias = 0;
    int j;
    for (j = 0; j < NUM_ATLETAS; j++) {
        if (i != j && matriz[i][j] == 1) {
            vitorias++;
        }
    }
    return vitorias;
}

// Função para contar derrotas de um atleta
int numero_derrotas(int matriz[NUM_ATLETAS][NUM_ATLETAS], int i) {
    int derrotas = 0;
    int j;
    for (j = 0; j < NUM_ATLETAS; j++) {
        if (i != j && matriz[i][j] == -1) {
            derrotas++;
        }
    }
    return derrotas;
}

// Função para mostrar resultado de uma luta específica
void resultado(int matriz[NUM_ATLETAS][NUM_ATLETAS], int i, int j) {
    printf("\nResultado da luta:\n");
    printf("%s vs %s\n", nomes_atletas[i], nomes_atletas[j]);
    
    if (i == j) {
        printf("Nao e permitido um atleta lutar contra si mesmo!\n");
        return;
    }
    
    switch(matriz[i][j]) {
        case 1:
            printf("Vitoria de %s\n", nomes_atletas[i]);
            break;
        case -1:
            printf("Vitoria de %s\n", nomes_atletas[j]);
            break;
        case 0:
            printf("Empate entre %s e %s\n", nomes_atletas[i], nomes_atletas[j]);
            break;
        default:
            printf("Resultado invalido!\n");
    }
}

// Função para extrair o primeiro nome
void primeiro_nome(char nome_completo[], char primeiro_nome[]) {
    int i = 0;
    while (nome_completo[i] != ' ' && nome_completo[i] != '\0') {
        primeiro_nome[i] = nome_completo[i];
        i++;
    }
    primeiro_nome[i] = '\0';
}

int main() {
    int i, j;
    int opcao, atleta, atleta1, atleta2;
    int vitorias, derrotas, saldo;
    char primeiro[TAM_NOME];
    
    // Preenchimento dos nomes dos atletas
    printf("Cadastro de Atletas:\n");
    for (i = 0; i < NUM_ATLETAS; i++) {
        printf("Digite o nome completo do atleta %d: ", i+1);
        fgets(nomes_atletas[i], TAM_NOME, stdin);
        nomes_atletas[i][strcspn(nomes_atletas[i], "\n")] = '\0'; // Remove o \n
    }
    
    // Preencher a matriz de resultados
    preencher(matriz_resultados);
    
    do {
        printf("\nMenu:\n");
        printf("1 - Atleta com maior quantidade de vitorias\n");
        printf("2 - Saldo de vitorias de um atleta\n");
        printf("3 - Resultado de uma luta\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: {
                int atleta = maior_vitorias(matriz_resultados);
                int vitorias = numero_vitorias(matriz_resultados, atleta);
                printf("\nAtleta com mais vitorias:\n");
                printf("Nome: %s\n", nomes_atletas[atleta]);
                printf("Vitorias: %d\n", vitorias);
                break;
            }
            case 2: {
                printf("\nDigite o numero do atleta (1 a %d): ", NUM_ATLETAS);
                scanf("%d", &atleta);
                atleta--; // Ajusta para índice 0-based
                
                if (atleta >= 0 && atleta < NUM_ATLETAS) {
                    vitorias = numero_vitorias(matriz_resultados, atleta);
                    derrotas = numero_derrotas(matriz_resultados, atleta);
                    saldo = vitorias - derrotas;
                    
                    primeiro_nome(nomes_atletas[atleta], primeiro);
                    
                    printf("\nSaldo de vitorias de %s:\n", primeiro);
                    printf("Saldo: %d (Vitorias: %d, Derrotas: %d)\n", saldo, vitorias, derrotas);
                } else {
                    printf("Atleta invalido!\n");
                }
                break;
            }
            case 3: {
                printf("\nDigite o numero dos dois atletas (1 a %d): ", NUM_ATLETAS);
                scanf("%d %d", &atleta1, &atleta2);
                atleta1--;
                atleta2--;
                
                if (atleta1 >= 0 && atleta1 < NUM_ATLETAS && 
                    atleta2 >= 0 && atleta2 < NUM_ATLETAS) {
                    resultado(matriz_resultados, atleta1, atleta2);
                } else {
                    printf("Atletas invalidos!\n");
                }
                break;
            }
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);
    
    return 0;
}

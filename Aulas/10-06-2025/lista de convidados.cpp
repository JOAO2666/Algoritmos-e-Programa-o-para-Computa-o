#include <stdio.h>
#include <string.h>

#define MAX_CONVIDADOS 100
#define TAM_NOME 16 // 15 caracteres + 1 para o '\0'

/**
 * @brief Insere um nome na lista, evitando duplicatas.
 * @param Lista A matriz com os nomes dos convidados.
 * @param nome O nome a ser inserido.
 * @param qtd A quantidade atual de convidados.
 * @return 1 se o nome foi inserido com sucesso, 0 se o nome j� existia.
 */
int insere_nome(char Lista[][TAM_NOME], char nome[], int qtd) {
    // 1. Verifica se o nome j� est� na lista
    for (int i = 0; i < qtd; i++) {
        // A fun��o strcmp retorna 0 se as strings s�o iguais
        if (strcmp(nome, Lista[i]) == 0) {
            printf("\nErro: '%s' ja consta na lista.\n", nome);
            return 0; // Retorna 0 indicando que o nome j� existe
        }
    }

    // 2. Se n�o estiver, insere na lista
    strcpy(Lista[qtd], nome);
    printf("\n'%s' cadastrado com sucesso!\n", nome);
    return 1; // Retorna 1 indicando sucesso na inser��o
}

/**
 * @brief Conta quantos convidados na lista t�m o nome come�ando com uma letra espec�fica.
 * @param Lista A matriz com os nomes dos convidados.
 * @param letra A letra a ser verificada.
 * @param qtd A quantidade total de convidados na lista.
 * @return O n�mero de nomes que come�am com a letra.
 */
int conta_letra(char Lista[][TAM_NOME], char letra, int qtd) {
    int contador = 0;
    for (int i = 0; i < qtd; i++) {
        // Verifica se o primeiro caractere do nome � a letra desejada
        if (Lista[i][0] == letra) {
            contador++;
        }
    }
    return contador;
}

int main() {
    char Lista[MAX_CONVIDADOS][TAM_NOME];
    char nome_temp[TAM_NOME];
    char letra_busca = 'R';
    int qtd_convidados = 0;
    int continuar = 1;

    printf("--- Cadastro de Convidados ---\n");

    // Loop para cadastrar convidados at� o limite ou o usu�rio parar
    while (qtd_convidados < MAX_CONVIDADOS && continuar == 1) {
        printf("\nDigite o nome do convidado (ou '0' para parar): ");
        // Usamos fgets para ler nomes compostos e limpamos o buffer
        fgets(nome_temp, TAM_NOME, stdin);
        // Remove o caractere de nova linha '\n' que o fgets adiciona
        nome_temp[strcspn(nome_temp, "\n")] = 0;

        // Condi��o de parada
        if (strcmp(nome_temp, "0") == 0) {
            break;
        }

        // Tenta inserir o nome e atualiza a quantidade se for bem-sucedido
        if (insere_nome(Lista, nome_temp, qtd_convidados)) {
            qtd_convidados++;
        }
        
        // Pergunta se deseja continuar (opcional, j� que pode sair com '0')
        // printf("\nDeseja continuar cadastrando? (1-Sim / 0-Nao): ");
        // scanf("%d", &continuar);
        // getchar(); // Limpa o buffer de entrada para o pr�ximo fgets
    }

    // Impress�o dos resultados
    printf("\n\n--- Relatorio Final ---\n");
    printf("Lista de Convidados (%d no total):\n", qtd_convidados);
    for (int i = 0; i < qtd_convidados; i++) {
        printf("%d: %s\n", i + 1, Lista[i]);
    }

    int qtd_com_R = conta_letra(Lista, letra_busca, qtd_convidados);
    printf("\nQuantidade de convidados cujo nome comeca com '%c': %d\n", letra_busca, qtd_com_R);

    return 0;
}

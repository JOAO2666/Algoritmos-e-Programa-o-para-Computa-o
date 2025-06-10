#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do Tweet 
typedef struct tweet {
    int ID;
    char texto[141]; // 140 caracteres + 1 para o '\0'
} TTweet;

// Função simulada - não precisa ser implementada 
// Apenas retorna um número de tweets e preenche o vetor com dados de exemplo.
int listagemtweets(TTweet vetor[]) {
    // Dados de exemplo
    strcpy(vetor[0].texto, "Este eh um tweet de teste do usuario 101.");
    vetor[0].ID = 101;
    strcpy(vetor[1].texto, "Outro tweet, mas este eh bem longo para garantir que ele possa ser filtrado pelo seu tamanho e ser salvo no segundo arquivo.");
    vetor[1].ID = 202;
    strcpy(vetor[2].texto, "Tweet curto.");
    vetor[2].ID = 303;
    strcpy(vetor[3].texto, "Mais um tweet do usuario 101 para teste.");
    vetor[3].ID = 101;

    return 4; // Retorna a quantidade de tweets criados 
}

int main(void) {
    // Em vez de um ponteiro não inicializado, usamos um vetor estático
    // com um tamanho máximo razoável.
    TTweet vec[100];
    int id_usuario, tam_filtro, nTweets;
    FILE *arq1, *arq2;

    // Abrindo os arquivos em modo de escrita binária ("wb") 
    arq1 = fopen("arq1.bin", "wb");
    arq2 = fopen("arq2.bin", "wb");

    if (arq1 == NULL || arq2 == NULL) {
        printf("Erro ao abrir os arquivos de saida.\n");
        return 1;
    }

    // Carrega os tweets usando a função (simulada)
    nTweets = listagemtweets(vec);
    printf("%d tweets carregados para processamento.\n", nTweets);

    // Solicita o ID do usuário e o tamanho do filtro
    printf("Digite o ID do usuario a ser filtrado: ");
    scanf("%d", &id_usuario);
    printf("Digite o tamanho minimo (x) para filtrar tweets longos: ");
    scanf("%d", &tam_filtro);

    // Percorre o vetor de tweets para filtrar e salvar nos arquivos
    for (int i = 0; i < nTweets; i++) {
        // Filtro 1: Salva no arq1.bin se o ID do usuário corresponde
        if (vec[i].ID == id_usuario) {
            fwrite(&vec[i], sizeof(TTweet), 1, arq1);
        }

        // Filtro 2: Salva no arq2.bin se o comprimento do texto é maior que x
        // A função strlen retorna o tamanho da string 
        if (strlen(vec[i].texto) > tam_filtro) {
            fwrite(&vec[i], sizeof(TTweet), 1, arq2);
        }
    }

    // Fecha os arquivos
    fclose(arq1);
    fclose(arq2);

    printf("\nFiltros aplicados. Arquivos 'arq1.bin' e 'arq2.bin' foram gerados.\n");

    return 0;
}

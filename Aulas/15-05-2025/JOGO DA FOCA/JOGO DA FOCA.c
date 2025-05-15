#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Declaração das funções
FILE* abrirArq(char nome[], char modo[]);
void fecharArq(FILE *arq);
void adicionarDica();
void adicionarPalavra();

int main(int argc, char *argv[]) {
    FILE *temp; // Arquivo para armazenar e acessar as dicas
    
    temp = abrirArq("dicas.fc", "r");
    if (temp == NULL) {
        // Se não conseguiu abrir para leitura, talvez o arquivo não exista ainda
        // ele será criado quando adicionarmos uma dica
    } else {
        fecharArq(temp);
    }
    
    adicionarDica();
    return 0;
}

void adicionarDica() {
    char dica[201];
    char temp[201];
    char resp;
    bool erro = false; // para verificar se existe algum erro na funcao booleana
    
    do {
        system("cls"); // serve para limpar a tela (use "clear" para Linux)
        printf("\nDIGITE UMA DICA DE ATE 200 CARACTERES: ");
        fflush(stdin);
        scanf("%200[^\n]", dica);
        getchar(); // para consumir o \n deixado pelo scanf
        printf("\nDESEJA CONTINUAR COM A DICA %s? <S/N> ", dica);
        resp = getchar();
    } while (resp != 'S' && resp != 's');
    
    FILE *arq;
    strupr(dica); // converte para maiúsculas
    arq = abrirArq("dicas.fc", "r");
    
    if (arq != NULL) {
        while (!feof(arq)) {
            if (fscanf(arq, "%200[^\n]", temp) != 1) {
                break; // Se não conseguiu ler, sai do loop
            }
            getc(arq); // para consumir o \n após cada linha
            
            if (strcmp(dica, temp) == 0) {
                printf("\nEssa dica ja existe!");
                erro = true;
                break;
            }
        }
        fecharArq(arq);
    }
    
    if (!erro) {
        arq = abrirArq("dicas.fc", "a");
        if (arq != NULL) {
            fprintf(arq, "%s\n", dica);
            fecharArq(arq);
            printf("\nDica adicionada com sucesso!");
        }
    }
}

FILE* abrirArq(char nome[], char modo[]) {
    FILE *arq = fopen(nome, modo); // Declara arq
    if (arq == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", nome);
        return NULL; // Retorna NULL explicitamente
    }
    
    return arq; // Retorna ponteiro arq
}

void fecharArq(FILE *arq) {
    if (arq != NULL) {
        fclose(arq); // Fecha apenas se arq não for NULL
    } else {
        printf("Erro: Tentativa de fechar um arquivo NULL!\n");
    }
    printf("\nAPERTE UMA TECLA PARA VOLTAR AO MENU...");
    fflush(stdin);
    resp=getchar();
    
    void adcionarPalavra() {
    	char dica[201];
    	char resp;
    	bool erro;
    	do {
    	printf("DIGITE UMA PALAVRA: ");
    	fflush(stdin);
		scanf("");
    	printf("DIGITE UMA DICA: ");
    	fflush(stdin);
    	scanf("%200 [^\n]", dica);
	}while (resp!='S' && resp!= 's');
	printf("")
}

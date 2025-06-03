#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estudante {
    char nome[100];
    int idade;
    float nota;
};

int main(int argc, char *argv[]) {
    int N;
    struct Estudante *estudantes;
    FILE *p; 

    printf("Cadastre a quantidade de usuarios a serem informados: ");
    scanf("%d", &N);

    

    estudantes = (struct Estudante *) malloc(N * sizeof(struct Estudante));

    if (estudantes == NULL) {
        printf("Erro: nao foi possivel alocar memoria para os estudantes!\n");
        return 1;
    }
    
    printf("Memoria para %d estudantes alocada com sucesso!\n", N);

    p = fopen("estudantes.txt", "w");
    if (p == NULL) {
        printf("Erro na criacao do arquivo!\n");
        free(estudantes);
        return 1;
    } else {
        printf("Arquivo estudantes.txt aberto/criado com sucesso para gravacao!\n");
       
    }

    if (p != NULL) {
        fclose(p);
    }
    free(estudantes);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto {
    int codigo;
    char descricao[100];
    float preco;
};

int main(void) {
    struct produto *sobre_os_produtos;
    int produtos;
    FILE *p_arquivo;

    printf("digite uma quantiadade especifica de produtos: ");
    scanf("%d", &produtos);

    if (produtos <= 0 || produtos > 100) {
        printf("coloque outra quantidade!\n");
        return 1;
    }

    sobre_os_produtos = (struct produto *) malloc(produtos * sizeof(struct produto));

    if (sobre_os_produtos == NULL) {
        printf("Erro: Nao foi possivel alocar memoria para os produtos!\n");
        return 1;
    }

    printf("Memoria para %d produtos alocada com sucesso.\n", produtos);

    if (sobre_os_produtos != NULL) {
        free(sobre_os_produtos);
    }
    
    return 0;
}

#include <stdio.h>
#include <string.h>

#define TAM 10

struct Boletim {
    int ano;
    int codigo;
};

struct Carro {
    int codigo;
    char fabricante[50];
};

int main() {
    struct Boletim boletim[TAM];
    struct Carro carro[TAM];
    int i, ano_busca, contagem = 0;
    char fabricante_busca[50];

    // Preenchimento dos boletins
    printf("Preenchimento dos boletins de ocorrencia:\n");
    for (i = 0; i < TAM; i++) {
        printf("Boletim %d - Ano: ", i + 1);
        scanf("%d", &boletim[i].ano);
        printf("Boletim %d - Codigo do carro: ", i + 1);
        scanf("%d", &boletim[i].codigo);
    }

    // Preenchimento dos carros
    printf("\nPreenchimento dos carros:\n");
    for (i = 0; i < TAM; i++) {
        printf("Carro %d - Codigo: ", i + 1);
        scanf("%d", &carro[i].codigo);
        printf("Carro %d - Fabricante: ", i + 1);
        scanf(" %[^\n]s", carro[i].fabricante);
    }

    // Solicitação de ano e fabricante
    printf("\nDigite o ano de ocorrencia para busca: ");
    scanf("%d", &ano_busca);
    printf("Digite o fabricante para busca: ");
    scanf(" %[^\n]s", fabricante_busca);

    // Verificação e contagem
    for (i = 0; i < TAM; i++) {
        if (boletim[i].ano == ano_busca) {
            int j; // Declaração de j fora do for, compatível com C89, mas usaremos C99
            for (j = 0; j < TAM; j++) {
                if (carro[j].codigo == boletim[i].codigo && strcmp(carro[j].fabricante, fabricante_busca) == 0) {
                    contagem++;
                    break;
                }
            }
        }
    }

    // Exibição do resultado
    if (contagem > 0) {
        printf("\nQuantidade de registros encontrados: %d\n", contagem);
    } else {
        printf("\nNenhum registro encontrado.\n");
    }

    return 0;
}

#include <stdio.h>

int main() {
    int idade, maxIdade = 0;
    float renda, totalRenda = 0.0;
    char sexo;
    int totalPessoas = 0, totalFem = 0;

    printf("--- Censo da Cidade ---\n");
    printf("Digite a idade (ou um valor negativo para encerrar): ");
    scanf("%d", &idade);

    while (idade >= 0) {
        printf("Digite a renda: ");
        scanf("%f", &renda);

        // Valida��o da entrada do sexo
        do {
            printf("Digite o sexo (M/F): ");
            // O espa�o antes de %c ignora quebras de linha ou espa�os
            scanf(" %c", &sexo);
            if (sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f') {
                printf("Valor incorreto para sexo, digite novamente.\n");
            }
        } while (sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f');

        // Contabiliza os dados
        totalPessoas++;
        totalRenda += renda;

        if (sexo == 'F' || sexo == 'f') {
            totalFem++;
        }

        if (idade > maxIdade) {
            maxIdade = idade;
        }
        
        // Pede a idade para o pr�ximo cidad�o
        printf("\nProximo cidadao. Digite a idade (ou negativo para encerrar): ");
        scanf("%d", &idade);
    }

    // Exibe os resultados
    printf("\n--- Resultados do Censo ---\n");
    if (totalPessoas > 0) {
        printf("a) Total de pessoas cadastradas: %d\n", totalPessoas);
        printf("b) Proporcao de pessoas do sexo feminino: %.2f%%\n", ((float)totalFem / totalPessoas) * 100);
        printf("c) Idade da pessoa mais velha: %d anos\n", maxIdade);
        printf("d) Media da renda da populacao: R$ %.2f\n", totalRenda / totalPessoas);
    } else {
        printf("Nenhuma pessoa foi cadastrada.\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    int n; // número de regiões
    
    // a) Leia do teclado uma quantidade n de regiões
    printf("Digite a quantidade de regioes: ");
    scanf("%d", &n);
    
    char paisMaiorOuroGeral[3] = ""; // Armazena a sigla do país com maior % de ouro geral
    float maiorPercentualOuroGeral = -1.0; // Maior percentual de ouro geral
    
    // Para cada região
    for (int i = 0; i < n; i++) {
        int qid; // quantidade de países na região
        char paisMaiorOuroRegiao[3] = ""; // Sigla do país com maior % de ouro na região
        float maiorPercentualOuroRegiao = -1.0; // Maior percentual de ouro na região
        
        // b) Para cada região, leia do teclado a quantidade de países (qid) desta
        printf("\nRegiao %d\n", i+1);
        printf("Digite a quantidade de paises nesta regiao: ");
        scanf("%d", &qid);
        
        // Para cada país da região
        for (int j = 0; j < qid; j++) {
            char sigla[3]; // Sigla do país (2 caracteres + '\0')
            int ouro, prata, bronze; // Quantidade de medalhas
            
            // c) Para cada país, leia sua sigla e as quantidades de medalhas
            printf("\nPais %d da Regiao %d\n", j+1, i+1);
            printf("Digite a sigla do pais (2 caracteres): ");
            scanf("%s", sigla);
            sigla[2] = '\0'; // Garantir que a string termine corretamente
            
            printf("Digite a quantidade de medalhas de ouro: ");
            scanf("%d", &ouro);
            
            printf("Digite a quantidade de medalhas de prata: ");
            scanf("%d", &prata);
            
            printf("Digite a quantidade de medalhas de bronze: ");
            scanf("%d", &bronze);
            
            // Calcular total de medalhas e percentuais
            int totalMedalhas = ouro + prata + bronze;
            float percentualOuro = 0;
            float percentualPrata = 0;
            float percentualBronze = 0;
            
            if (totalMedalhas > 0) {
                percentualOuro = (float)ouro / totalMedalhas * 100;
                percentualPrata = (float)prata / totalMedalhas * 100;
                percentualBronze = (float)bronze / totalMedalhas * 100;
            }
            
            // d) Para cada país, calcule e exiba o % de medalhas de ouro, prata e bronze
            printf("\nEstatisticas para %s:\n", sigla);
            printf("Percentual de medalhas de ouro: %.2f%%\n", percentualOuro);
            printf("Percentual de medalhas de prata: %.2f%%\n", percentualPrata);
            printf("Percentual de medalhas de bronze: %.2f%%\n", percentualBronze);
            
            // Verificar se é o país com maior % de ouro na região
            if (percentualOuro > maiorPercentualOuroRegiao) {
                maiorPercentualOuroRegiao = percentualOuro;
                strcpy(paisMaiorOuroRegiao, sigla);
            }
            
            // Verificar se é o país com maior % de ouro geral
            if (percentualOuro > maiorPercentualOuroGeral) {
                maiorPercentualOuroGeral = percentualOuro;
                strcpy(paisMaiorOuroGeral, sigla);
            }
        }
        
        // e) Para cada região, imprima o país com o maior % de medalhas de ouro e também este %
        printf("\nPais com maior percentual de medalhas de ouro na Regiao %d:\n", i+1);
        printf("Sigla: %s\n", paisMaiorOuroRegiao);
        printf("Percentual de medalhas de ouro: %.2f%%\n", maiorPercentualOuroRegiao);
    }
    
    // f) No final do programa, exiba o país com maior % de medalhas de ouro (sigla e %)
    printf("\nPais com maior percentual de medalhas de ouro em todas as regioes:\n");
    printf("Sigla: %s\n", paisMaiorOuroGeral);
    printf("Percentual de medalhas de ouro: %.2f%%\n", maiorPercentualOuroGeral);
    
    return 0;
}
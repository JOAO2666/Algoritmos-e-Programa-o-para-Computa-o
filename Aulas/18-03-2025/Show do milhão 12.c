#include <stdio.h>

int main() {
    int bit, opcao, resposta;
    
    printf("\n=== Show do Milhao ===\n");
    printf("Para perguntas sobre Historia digite 1\n");
    printf("Para perguntas sobre Matematica digite 2\n");
    printf("Para perguntas sobre Ciencias digite 3\n");
    
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
    
    switch (opcao) {
        case 1:
            printf(" Historia 1\n");
            printf("Quem foi o primeiro presidente do Brasil?\n");
            printf("Getulio Vargas 1\n");
            printf("Floriano Peixoto 2\n");
            printf("Marechal Deodoro da Fonseca 3\n");
            scanf("%d", &resposta);
            
            switch (resposta) {
                case 1:
                    printf("Voce errou\n");
                    break;
                case 2:
                    printf("Voce errou\n");
                    break;
                case 3:
                    printf("Parabens voce acertou\n");
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
            }
            break;
            
        case 2:
            printf("Matematica 2 \n");
            printf("Quanto e 364 x 652?\n");
            printf("29323 1\n");
            printf("237328 2\n");
            printf("212312 3\n");
            scanf("%d", &resposta);
            
            switch (resposta) {
                case 1:
                    printf("Voce errou\n");
                    break;
                case 2:
                    printf("Parabens voce acertou\n");
                    break;
                case 3:
                    printf("Voce errou\n");
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
            }
            break;
            
        case 3:
            printf("Ciencias 3\n");
            printf("A polinizacao, que viabiliza o transporte do grao de polen de uma planta ate o estigma de outra e ela e feita por qual inseto?\n");
            printf("Anthophila 1\n");
            printf("Chiroptera 2\n");
            printf("Canis lupus 3\n");
            scanf("%d", &resposta);
            
            switch (resposta) {
                case 1:
                    printf("Voce acertou\n");
                    break;
                case 2:
                    printf("Voce errou\n");
                    break;
                case 3:
                    printf("Voce errou\n");
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
            }
            break;
            
        default:
            printf("\nOpcao invalida! Por favor, escolha entre 1, 2 ou 3.\n");
            break;
    }
    
    printf("\nObrigado por jogar Show do Milhao!\n");
    
    return 0;
}

#include <stdio.h>

int main() {
    int campeaoSelecionado;
    char golpe;
    int danoTotal = 0, danoQ = 0, golpesTeemo = 0, usoBraum = 0;

    printf("--- Bem-vindo a Liga das Lendas! ---\n");

    // O jogo tem 5 rounds 
    for (int i = 1; i <= 5; i++) {
        printf("\n--- ROUND %d ---\n", i);
        
        // Seleção e validação do campeão
        do {
            printf("Escolha o campeao (1-Teemo, 2-Ashe, 3-Braum): ");
            scanf("%d", &campeaoSelecionado);
            if (campeaoSelecionado < 1 || campeaoSelecionado > 3) {
                printf("Codigo incorreto, digite novamente.\n");
            }
        } while (campeaoSelecionado < 1 || campeaoSelecionado > 3);

        if (campeaoSelecionado == 3) {
            usoBraum++;
        }

        printf("Campeao selecionado. Escolha seu golpe.\n");
        
        // Loop de golpes dentro do round
        do {
            printf("Digite o golpe (Q, W, E) ou R para encerrar o round: ");
            scanf(" %c", &golpe); // Espaço para consumir newlines

            switch (golpe) {
                case 'Q': case 'q':
                    danoTotal += 10;
                    danoQ += 10;
                    if (campeaoSelecionado == 1) golpesTeemo++;
                    break;
                case 'W': case 'w':
                    danoTotal += 50;
                    if (campeaoSelecionado == 1) golpesTeemo++;
                    break;
                case 'E': case 'e':
                    danoTotal += 100;
                    if (campeaoSelecionado == 1) golpesTeemo++;
                    break;
                case 'R': case 'r':
                    printf("Round encerrado.\n");
                    break;
                default:
                    printf("Golpe invalido, sem dano.\n");
                    break;
            }
        } while (golpe != 'R' && golpe != 'r');
    }

    // Apresenta os resultados finais
    printf("\n--- FIM DE JOGO - ESTATISTICAS ---\n");
    printf("a) Dano total em todos os 5 rounds: %d\n", danoTotal);
    printf("b) Dano total utilizando o golpe Q: %d\n", danoQ);
    printf("c) Quantidade de golpes executados por Teemo: %d\n", golpesTeemo);
    printf("d) Proporcao de uso do campeao Braum: %.2f (%.0f%%)\n", (float)usoBraum / 5.0, ((float)usoBraum/5.0)*100);

    return 0;
}

#include <stdio.h>
#include <string.h>

// Função para imprimir os palitos na tela
void imprimir_palitos(int n) {
    printf("Palitos disponiveis (%d): ", n);
    for (int i = 0; i < n; i++) {
        printf("| ");
    }
    printf("\n");
}

int main() {
    char nome_j1[50], nome_j2[50];
    int total_palitos = 21;
    int jogador_atual = 1;
    int jogada;

    // 1) Pede o nome dos jogadores
    printf("--- Jogo do Palito ---\n");
    printf("Digite o nome do Jogador 1: ");
    scanf(" %[^\n]", nome_j1);
    printf("Digite o nome do Jogador 2: ");
    scanf(" %[^\n]", nome_j2);

    // 2) Loop principal do jogo
    while (total_palitos > 0) {
        // a) Imprime os palitos
        imprimir_palitos(total_palitos);

        // b) Solicita a jogada e valida a entrada
        char* nome_jogador_da_vez = (jogador_atual == 1) ? nome_j1 : nome_j2;
        int max_retirada = (total_palitos < 3) ? total_palitos : 3;

        do {
            printf("\n%s, quantos palitos deseja remover (1 a %d)? ", nome_jogador_da_vez, max_retirada);
            scanf("%d", &jogada);

            if (jogada < 1 || jogada > max_retirada) {
                printf("Jogada invalida! Tente novamente.\n");
            }
        } while (jogada < 1 || jogada > max_retirada);

        // c) Atualiza o total de palitos
        total_palitos -= jogada;

        // Se ainda restam palitos, troca o jogador
        if (total_palitos > 0) {
            jogador_atual = (jogador_atual == 1) ? 2 : 1;
        }
    }

    // 3) Anuncia o vencedor
    // Quem fez a última jogada (deixando 0 palitos) perdeu.
    // O vencedor é o outro jogador.
    printf("\n--- Fim de Jogo ---\n");
    if (jogador_atual == 1) {
        printf("O vencedor da partida foi: %s!\n", nome_j2);
    } else {
        printf("O vencedor da partida foi: %s!\n", nome_j1);
    }

    return 0;
}

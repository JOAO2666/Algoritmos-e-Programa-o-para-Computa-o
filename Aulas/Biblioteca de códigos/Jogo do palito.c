#include <stdio.h>
#include <string.h>

int main() {
    char jogador1[50], jogador2[50], jogador_atual[50];
    int palitos = 21;
    int jogador = 1; // Come�a com o jogador 1
    int palitos_remover;
    int i; // Declara��o movida para fora do loop
    
    // Pedir nomes dos jogadores
    printf("Digite o nome do Jogador 1: ");
    scanf("%s", jogador1);
    
    printf("Digite o nome do Jogador 2: ");
    scanf("%s", jogador2);
    
    // Loop principal do jogo
    while (palitos > 0) {
        // Mostrar palitos dispon�veis
        printf("\nPalitos dispon�veis: ");
        for (i = 0; i < palitos; i++) {
            printf("I ");
        }
        printf("\n");
        
        // Determinar jogador atual
        if (jogador == 1)
            strcpy(jogador_atual, jogador1);
        else
            strcpy(jogador_atual, jogador2);
        
        // Solicitar jogada
        do {
            printf("%s, quantos palitos deseja remover (1, 2 ou 3)? ", jogador_atual);
            scanf("%d", &palitos_remover);
            
            // Validar a jogada
            if (palitos_remover < 1 || palitos_remover > 3 || palitos_remover > palitos) {
                printf("Jogada inv�lida! Voc� deve remover entre 1 e 3 palitos (sem exceder os dispon�veis).\n");
            }
        } while (palitos_remover < 1 || palitos_remover > 3 || palitos_remover > palitos);
        
        // Atualizar quantidade de palitos
        palitos -= palitos_remover;
        
        // Verificar fim de jogo
        if (palitos == 0) {
            // O jogador atual removeu o �ltimo palito e perdeu
            printf("\nO �ltimo palito foi removido!\n");
            
            // Determinar vencedor (jogador oposto ao atual)
            if (jogador == 1)
                printf("\nVencedor: %s\n", jogador2);
            else
                printf("\nVencedor: %s\n", jogador1);
                
            break;
        }
        
        // Alternar para o pr�ximo jogador
        jogador = (jogador == 1) ? 2 : 1;
    }
    
    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    // Variáveis para guardar os dados do time atual
    char nome[50];
    int pontos, vitorias, gols_pro, gols_contra, saldo;

    // Variáveis para guardar os dados do primeiro colocado até o momento
    char nome_vencedor[50];
    int pontos_vencedor = -1; // Inicia com valor inválido 
    int vitorias_vencedor = -1;
    int saldo_vencedor = -1;

    char continuar;
    int primeiro_cadastro = 1;

    do {
        // a) Ler dados do time
        printf("\nDigite o nome da selecao: ");
        scanf(" %[^\n]", nome); // Lê o nome, incluindo espaços

        printf("Digite os pontos, vitorias, gols pro e gols contra de %s: ", nome);
        scanf("%d %d %d %d", &pontos, &vitorias, &gols_pro, &gols_contra);

        saldo = gols_pro - gols_contra; // Calcula o saldo de gols 

        // b) Imprime os dados digitados
        printf(" -> Time: %s, %d pontos, %d vitorias e um saldo de %d gols.\n", nome, pontos, vitorias, saldo);

        // Lógica para determinar o novo primeiro colocado
        int trocar_vencedor = 0;
        if (primeiro_cadastro) {
            trocar_vencedor = 1;
            primeiro_cadastro = 0;
        } else {
            if (pontos > pontos_vencedor) { // Critério 1: Pontos
                trocar_vencedor = 1;
            } else if (pontos == pontos_vencedor) {
                if (vitorias > vitorias_vencedor) { // Critério 2: Vitórias
                    trocar_vencedor = 1;
                } else if (vitorias == vitorias_vencedor) {
                    if (saldo > saldo_vencedor) { // Critério 3: Saldo de Gols
                        trocar_vencedor = 1;
                    }
                }
            }
        }
        
        // Se um novo vencedor foi encontrado, atualiza os dados
        if (trocar_vencedor) {
            strcpy(nome_vencedor, nome);
            pontos_vencedor = pontos;
            vitorias_vencedor = vitorias;
            saldo_vencedor = saldo;
        }

        // c) Pergunta se deseja continuar e valida a resposta
        do {
            printf("Deseja cadastrar outra selecao? (S/N): ");
            scanf(" %c", &continuar);
        } while (continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n');

    } while (continuar == 'S' || continuar == 's');

    // d) Imprime o vencedor final
    if (pontos_vencedor != -1) {
        printf("\n--- VENCEDOR ---\n");
        printf("%s, %d pontos, %d vitorias e um saldo de %d gols.\n", nome_vencedor, pontos_vencedor, vitorias_vencedor, saldo_vencedor);
    } else {
        printf("\nNenhuma selecao foi cadastrada.\n");
    }

    return 0;
}

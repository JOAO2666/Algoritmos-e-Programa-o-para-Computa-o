#include <stdio.h>
#include <string.h>

int main() {
    char nome_time[100], nome_vencedor[100];
    int pontos, vitorias, gols_favor, gols_contra, saldo_gols;
    int pontos_vencedor = -1, vitorias_vencedor = -1, saldo_vencedor = -1;
    char continuar;
    int primeiro_time = 1;

    do {
        // Leitura das informa��es do time
        printf("Digite o nome da sele��o: ");
        scanf("%s", nome_time);
        
        printf("Digite a pontua��o: ");
        scanf("%d", &pontos);
        
        printf("Digite o n�mero de vit�rias: ");
        scanf("%d", &vitorias);
        
        printf("Digite o n�mero de gols a favor: ");
        scanf("%d", &gols_favor);
        
        printf("Digite o n�mero de gols sofridos: ");
        scanf("%d", &gols_contra);
        
        // C�lculo do saldo de gols
        saldo_gols = gols_favor - gols_contra;
        
        // Mostrar dados do time atual
        printf("%s, %d pontos, %d vit�rias e um saldo de %d gols\n", 
               nome_time, pontos, vitorias, saldo_gols);
        
        // Verificar se � o primeiro time ou se � melhor que o atual vencedor
        if (primeiro_time || 
            pontos > pontos_vencedor || 
            (pontos == pontos_vencedor && vitorias > vitorias_vencedor) || 
            (pontos == pontos_vencedor && vitorias == vitorias_vencedor && saldo_gols > saldo_vencedor)) {
            
            strcpy(nome_vencedor, nome_time);
            pontos_vencedor = pontos;
            vitorias_vencedor = vitorias;
            saldo_vencedor = saldo_gols;
            primeiro_time = 0;
        }
        
        // Perguntar se deseja continuar
        do {
            printf("Deseja digitar informa��es de outra sele��o? (S/N): ");
            scanf(" %c", &continuar);
            continuar = toupper(continuar);  // Converte para mai�sculo
        } while (continuar != 'S' && continuar != 'N');
        
    } while (continuar == 'S');
    
    // Imprimir o vencedor
    printf("\nVencedor: %s, %d pontos, %d vit�rias e um saldo de %d gols\n", 
           nome_vencedor, pontos_vencedor, vitorias_vencedor, saldo_vencedor);
    
    return 0;
}

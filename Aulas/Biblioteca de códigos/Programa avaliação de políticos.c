#include <stdio.h>
#include <string.h>

int main() {
    int opcao;
    
    do {
        int n, i;
        int maxProcessos = -1;
        int politicoMaisProcessos = -1;
        char estadoMaisProcessos[3];
        int totalSemProcessos = 0;
        
        // 1. Solicitar a quantidade de políticos
        do {
            printf("Digite a quantidade de politicos a serem avaliados: ");
            scanf("%d", &n);
            
            if (n <= 0) {
                printf("Quantidade invalida! Digite um valor maior que zero.\n");
            }
        } while (n <= 0);
        
        // Arrays para armazenar os dados de todos os políticos
        int registros[n];
        char estados[n][3];
        int processos[n];
        int mandados[n];
        
        // 2. Coletar dados de cada político
        for (i = 0; i < n; i++) {
            printf("\n--- Politico %d ---\n", i+1);
            
            printf("Digite o numero de registro: ");
            scanf("%d", &registros[i]);
            
            printf("Digite os 2 caracteres do estado (ex: SP): ");
            scanf("%s", estados[i]);
            estados[i][2] = '\0'; // Garantir que a string termine corretamente
            
            printf("Digite a quantidade de processos criminais em andamento: ");
            scanf("%d", &processos[i]);
            
            printf("Ha algum mandado de prisao? (1 para sim, 0 para nao): ");
            scanf("%d", &mandados[i]);
            
            // 2.2 Verificar mandado de prisão
            if (mandados[i] == 1) {
                printf("Ligue para 190\n");
            }
            
            // Verificar se é o político com mais processos
            if (processos[i] > maxProcessos) {
                maxProcessos = processos[i];
                politicoMaisProcessos = registros[i];
                strcpy(estadoMaisProcessos, estados[i]);
            }
            
            // Contar políticos sem processos
            if (processos[i] == 0) {
                totalSemProcessos++;
            }
        }
        
        // 3. Exibir resultados
        printf("\n--- Resultados ---\n");
        
        if (politicoMaisProcessos != -1) {
            printf("Politico com mais processos criminais:\n");
            printf("Registro: %d\n", politicoMaisProcessos);
            printf("Estado: %s\n", estadoMaisProcessos);
            printf("Quantidade de processos: %d\n", maxProcessos);
        }
        
        float percentualSemProcessos = (float)totalSemProcessos / n * 100;
        printf("Percentual de politicos sem processos criminais: %.2f%%\n", percentualSemProcessos);
        
        // 4. Verificar se deseja fazer nova pesquisa
        printf("\nDeseja fazer uma nova pesquisa? (1 para sim, 0 para nao): ");
        scanf("%d", &opcao);
        
    } while (opcao == 1);
    
    printf("\nPrograma encerrado.\n");
    return 0;
}
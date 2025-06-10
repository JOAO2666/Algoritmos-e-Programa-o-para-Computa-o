#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados da aposta 
typedef struct {
    char CodLoterica[11], Cidade[31];
    float ValorAposta;
    int QtdNumeros;
    int *NumerosMarcados;
} Aposta;

// Função para escrever uma aposta no arquivo (struct + vetor dinâmico)
void escreveAposta(Aposta *a, FILE *fp) {
    // Escreve a parte fixa da struct (tudo exceto o ponteiro)
    fwrite(a, sizeof(Aposta) - sizeof(int*), 1, fp);
    // Escreve o vetor de números marcados logo em seguida
    fwrite(a->NumerosMarcados, sizeof(int), a->QtdNumeros, fp);
}

// Função para ler uma aposta do arquivo
int leAposta(Aposta *a, FILE *fp) {
    // Lê a parte fixa da struct
    if (fread(a, sizeof(Aposta) - sizeof(int*), 1, fp) != 1) {
        return 0; // Fim de arquivo ou erro
    }
    // Aloca memória para os números e os lê do arquivo
    a->NumerosMarcados = (int*) malloc(sizeof(int) * a->QtdNumeros);
    if (a->NumerosMarcados == NULL) {
        printf("Erro de alocacao de memoria ao ler aposta.\n");
        return 0;
    }
    if (fread(a->NumerosMarcados, sizeof(int), a->QtdNumeros, fp) != a->QtdNumeros) {
        free(a->NumerosMarcados);
        return 0; // Erro de leitura
    }
    return 1;
}

int main() {
    Aposta a;
    int i, j, acertos;
    int n4 = 0, n5 = 0, n6 = 0;
    int sorteados[6];
    float valor_arrecadado = 0;
    FILE *fpA;

    // Abre o arquivo para escrita 
    fpA = fopen("apostas.file", "wb");
    if (fpA == NULL) {
        printf("Erro ao criar o arquivo de apostas.\n");
        return 1;
    }

    printf("--- CADASTRO DE APOSTAS DA MEGA-SENA ---\n");
    // Laço de leitura das apostas 
    while (1) {
        printf("\nDigite o codigo da loterica (ou 'XXX' para parar): ");
        scanf("%s", a.CodLoterica);

        if (strcmp(a.CodLoterica, "XXX") == 0) {
            break; // Encerra o cadastro
        }

        printf("Digite a cidade: ");
        scanf("%s", a.Cidade);
        printf("Valor da aposta: R$ ");
        scanf("%f", &a.ValorAposta);
        
        do {
            printf("Digite a quantidade de numeros na aposta (6 a 15): ");
            scanf("%d", &a.QtdNumeros);
        } while (a.QtdNumeros < 6 || a.QtdNumeros > 15);

        // Alocação dinâmica para os números marcados 
        a.NumerosMarcados = (int*) malloc(sizeof(int) * a.QtdNumeros);
        if (a.NumerosMarcados == NULL) {
            printf("Erro de alocacao de memoria. Aposta cancelada.\n");
            continue;
        }

        printf("Digite os %d numeros marcados:\n", a.QtdNumeros);
        for (i = 0; i < a.QtdNumeros; i++) {
            scanf("%d", &a.NumerosMarcados[i]);
        }

        // Escreve a aposta no arquivo e libera a memória
        escreveAposta(&a, fpA);
        free(a.NumerosMarcados);
    }
    fclose(fpA);

    // Verificação dos resultados 
    printf("\n--- VERIFICACAO DO SORTEIO ---\n");
    printf("Digite os 6 numeros sorteados: ");
    for (i = 0; i < 6; i++) {
        scanf("%d", &sorteados[i]);
    }

    fpA = fopen("apostas.file", "rb");
    if (fpA == NULL) {
        printf("Erro ao reabrir o arquivo de apostas para verificacao.\n");
        return 1;
    }

    // Lê cada aposta do arquivo para verificação
    while (leAposta(&a, fpA)) {
        acertos = 0;
        for (i = 0; i < a.QtdNumeros; i++) {
            for (j = 0; j < 6; j++) {
                if (a.NumerosMarcados[i] == sorteados[j]) {
                    acertos++;
                    break;
                }
            }
        }

        // Contabiliza ganhadores 
        if (acertos == 4) n4++;
        if (acertos == 5) n5++;
        if (acertos == 6) n6++;

        valor_arrecadado += a.ValorAposta;
        free(a.NumerosMarcados); // Libera memória alocada por leAposta
    }

    // Impressão dos resultados 
    printf("\n--- RESULTADO FINAL ---\n");
    printf("a) Ganhadores:\n");
    printf("   - Com 6 acertos (Sena): %d\n", n6);
    printf("   - Com 5 acertos (Quina): %d\n", n5);
    printf("   - Com 4 acertos (Quadra): %d\n", n4);
    printf("b) Valor total arrecadado com as apostas: R$ %.2f\n", valor_arrecadado);
    
    fclose(fpA);
    return 0;
}

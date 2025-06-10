#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a) Definição da estrutura Smartphone 
typedef struct {
    char modelo[40];
    int memoriaMB;
    float processadorMHz;
    float cameraMpix;
    float bateria;
} Smartphone;

// a) Função para cadastrar um smartphone e salvar no arquivo
void cadastraSmartphone() {
    Smartphone phone;
    FILE *fp;

    printf("\n--- Novo Cadastro de Smartphone ---\n");
    printf("Modelo: ");
    getchar(); // Limpa o buffer antes de ler a string com espaços
    scanf("%39[^\n]", phone.modelo);
    printf("Memoria (MB): ");
    scanf("%d", &phone.memoriaMB);
    printf("Processador (MHz): ");
    scanf("%f", &phone.processadorMHz);
    printf("Camera (MPix): ");
    scanf("%f", &phone.cameraMpix);
    printf("Bateria (mAh): ");
    scanf("%f", &phone.bateria);

    // Abre o arquivo no modo "append binary" (adicionar ao final) 
    fp = fopen("cadastro.bin", "ab");
    if (fp != NULL) {
        fwrite(&phone, sizeof(Smartphone), 1, fp);
        fclose(fp);
        printf("Cadastro realizado com sucesso!\n");
    } else {
        printf("Erro: nao foi possivel abrir o arquivo para escrita!\n");
    }
}

// b) Função para pesquisar smartphones com base em requisitos mínimos
int pesquisaSmartphones(Smartphone reqMin) {
    FILE *fp;
    Smartphone phone;
    int contador = 0;

    fp = fopen("cadastro.bin", "rb");
    if (fp == NULL) {
        printf("Nao foi possivel abrir o arquivo de cadastro ou ele nao existe.\n");
        return 0;
    }

    printf("\n--- Smartphones Encontrados ---\n");
    // Lê cada smartphone do arquivo
    while (fread(&phone, sizeof(Smartphone), 1, fp) == 1) {
        // Compara com os requisitos mínimos 
        if (phone.memoriaMB >= reqMin.memoriaMB &&
            phone.processadorMHz >= reqMin.processadorMHz &&
            phone.cameraMpix >= reqMin.cameraMpix &&
            phone.bateria >= reqMin.bateria) {
            
            // Exibe os dados do smartphone compatível 
            printf("\nModelo: %s\n", phone.modelo);
            printf("  Memoria: %d MB\n", phone.memoriaMB);
            printf("  Processador: %.2f MHz\n", phone.processadorMHz);
            printf("  Camera: %.2f MPix\n", phone.cameraMpix);
            printf("  Bateria: %.0f mAh\n", phone.bateria);
            contador++;
        }
    }
    fclose(fp);

    if (contador == 0) {
        printf("Nenhum smartphone encontrado com os requisitos informados.\n");
    }

    return contador;
}


// c) Função principal
int main() {
    char resposta;
    Smartphone reqMin;
    int resultado;

    // i. Laço de cadastro 
    do {
        printf("\nDeseja cadastrar um novo smartphone? (s/n): ");
        // Adicionado espaço antes de %c para consumir o \n de leituras anteriores
        scanf(" %c", &resposta);

        if (resposta == 's' || resposta == 'S') {
            cadastraSmartphone();
        }
    } while (resposta == 's' || resposta == 'S');

    // ii. Solicita os requisitos para a pesquisa 
    printf("\n--- Pesquisa de Smartphones ---\n");
    printf("Informe os requisitos minimos para a pesquisa:\n");
    printf("Memoria minima (MB): ");
    scanf("%d", &reqMin.memoriaMB);
    printf("Processador minimo (MHz): ");
    scanf("%f", &reqMin.processadorMHz);
    printf("Camera minima (MPix): ");
    scanf("%f", &reqMin.cameraMpix);
    printf("Bateria minima (mAh): ");
    scanf("%f", &reqMin.bateria);

    // Chama a função de pesquisa e imprime o resultado
    resultado = pesquisaSmartphones(reqMin);
    printf("\nTotal de %d smartphone(s) encontrado(s).\n", resultado);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =================================================================
// 1º Quesito: Cadastro e Pesquisa de Smartphones
// =================================================================

// a) Definição da estrutura Smartphone
typedef struct
{
    char modelo[40];
    int memoriaMB;
    float processadorMHz;
    float cameraMpix;
    float bateria;
} Smartphone;

// a) Função para cadastrar um smartphone e salvar no arquivo
void cadastraSmartphone()
{
    Smartphone phone;
    FILE *fp;

    printf("\n--- Novo Cadastro de Smartphone ---\n");
    printf("Modelo: ");
    // getchar() é usado para consumir o newline deixado pelo scanf anterior no menu principal
    getchar();
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
    fp = fopen("cadastro_smartphones.bin", "ab");
    if (fp != NULL)
    {
        fwrite(&phone, sizeof(Smartphone), 1, fp);
        fclose(fp);
        printf("Cadastro realizado com sucesso!\n");
    }
    else
    {
        printf("Erro: nao foi possivel abrir o arquivo para escrita!\n");
    }
}

// b) Função para pesquisar smartphones com base em requisitos mínimos
int pesquisaSmartphones(Smartphone reqMin)
{
    FILE *fp;
    Smartphone phone;
    int contador = 0;

    fp = fopen("cadastro_smartphones.bin", "rb");
    if (fp == NULL)
    {
        printf("Nao foi possivel abrir o arquivo de cadastro ou ele nao existe.\n");
        return 0;
    }

    printf("\n--- Smartphones Encontrados ---\n");
    // Lê cada smartphone do arquivo
    while (fread(&phone, sizeof(Smartphone), 1, fp) == 1)
    {
        // Compara com os requisitos mínimos
        if (phone.memoriaMB >= reqMin.memoriaMB &&
            phone.processadorMHz >= reqMin.processadorMHz &&
            phone.cameraMpix >= reqMin.cameraMpix &&
            phone.bateria >= reqMin.bateria)
        {

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

    if (contador == 0)
    {
        printf("Nenhum smartphone encontrado com os requisitos informados.\n");
    }

    return contador;
}

// Função que executa a lógica do quesito 1
void executarQuesito1()
{
    char resposta;
    Smartphone reqMin;
    int resultado;

    printf("\n*** Executando Quesito 1: Cadastro e Pesquisa de Smartphones ***\n");

    // i. Laço de cadastro
    do
    {
        printf("\nDeseja cadastrar um novo smartphone? (s/n): ");
        // Adicionado espaço antes de %c para consumir o \n
        scanf(" %c", &resposta);

        if (resposta == 's' || resposta == 'S')
        {
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
}

// =================================================================
// 2º Quesito: Melhor e Pior Cliente
// =================================================================

// Estrutura Cliente
typedef struct
{
    char nome[30];
    char cpf[12];
    float volumeCompras;
    int anoCadastro;
} Cliente;

void preencherVetorClientes(Cliente vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("\n--- Dados do Cliente %d ---\n", i + 1);
        getchar(); // Limpa o buffer de entrada antes de ler o nome
        printf("Nome: ");
        scanf("%29[^\n]", vetor[i].nome);

        getchar(); // Limpa o buffer
        printf("CPF: ");
        scanf("%11[^\n]", vetor[i].cpf);

        printf("Volume de compras: ");
        scanf("%f", &vetor[i].volumeCompras);

        printf("Ano de cadastro: ");
        scanf("%d", &vetor[i].anoCadastro);
    }
}

void buscarMelhorPiorCliente(Cliente vetor[], int tamanho, char *nomeMelhor,
                             float *volumeMelhor, char *nomePior, float *volumePior)
{
    if (tamanho <= 0)
        return;

    // Inicializa com os dados do primeiro cliente
    strcpy(nomeMelhor, vetor[0].nome);
    *volumeMelhor = vetor[0].volumeCompras;
    strcpy(nomePior, vetor[0].nome);
    *volumePior = vetor[0].volumeCompras;

    // Percorre o resto do vetor
    for (int i = 1; i < tamanho; i++)
    {
        // Verifica se encontrou um cliente melhor (maior volume)
        if (vetor[i].volumeCompras > *volumeMelhor)
        {
            *volumeMelhor = vetor[i].volumeCompras;
            strcpy(nomeMelhor, vetor[i].nome);
        }
        // Verifica se encontrou um cliente pior (menor volume)
        if (vetor[i].volumeCompras < *volumePior)
        {
            *volumePior = vetor[i].volumeCompras;
            strcpy(nomePior, vetor[i].nome);
        }
    }
}

// Função que executa a lógica do quesito 2
void executarQuesito2()
{
    int qtd;
    Cliente *pVet;
    char nomeMelhor[30], nomePior[30];
    float volumeMelhor, volumePior;

    printf("\n*** Executando Quesito 2: Melhor e Pior Cliente ***\n");

    // c) Solicita a quantidade de clientes
    printf("Digite a quantidade de clientes a cadastrar: ");
    scanf("%d", &qtd);

    if (qtd <= 0)
    {
        printf("Quantidade invalida.\n");
        return;
    }
    // d) Cria o vetor dinamicamente
    pVet = (Cliente *)malloc(qtd * sizeof(Cliente));
    if (pVet == NULL)
    {
        printf("Erro de alocacao de memoria.\n");
        return;
    }

    // e) Preenche o vetor
    preencherVetorClientes(pVet, qtd);

    // f) Busca e imprime o melhor e o pior cliente
    buscarMelhorPiorCliente(pVet, qtd, nomeMelhor, &volumeMelhor, nomePior, &volumePior);

    printf("\n\n--- Relatorio de Clientes ---\n");
    printf("Melhor Cliente: %s (Volume de Compras: R$ %.2f)\n", nomeMelhor, volumeMelhor);
    printf("Pior Cliente:   %s (Volume de Compras: R$ %.2f)\n", nomePior, volumePior);

    // Libera a memória alocada
    free(pVet);
}

// =================================================================
// Função Principal (Menu)
// =================================================================

int main()
{
    int opcao;

    do
    {
        printf("\n\n--- MENU DE ATIVIDADES ---\n");
        printf("1. Cadastro e Pesquisa de Smartphones\n");
        printf("2. Melhor e Pior Cliente\n");
        printf("0. Sair\n");
        printf("---------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            executarQuesito1();
            break;
        case 2:
            executarQuesito2();
            break;
        case 0:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
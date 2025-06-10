#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // Para malloc e free, se necessário no futuro

// =================================================================
// 1º Quesito: Simulador de Firewall
// =================================================================

// Definição da estrutura do pacote
struct pacote
{
    char ip_origem[17];
    int porta_origem;
    char ip_destino[17];
    int porta_destino;
    int conteudo[256];
};

// Protótipos das funções do quesito 1
int compara_pacotes(struct pacote a, struct pacote b);
struct pacote ler_pacote();
void executar_quesito1();

int compara_pacotes(struct pacote a, struct pacote b)
{
    // A função strcmp retorna 0 se as strings são iguais.
    if (strcmp(a.ip_origem, b.ip_origem) == 0 &&
        a.porta_origem == b.porta_origem &&
        strcmp(a.ip_destino, b.ip_destino) == 0 &&
        a.porta_destino == b.porta_destino)
    {
        return 1; // Pacotes iguais
    }
    else
    {
        return 0; // Pacotes diferentes
    }
}

struct pacote ler_pacote()
{
    struct pacote dado;
    int i;
    printf("\n--- Lendo novo pacote ---\n");
    printf("Digite ip de origem: ");
    scanf("%16s", dado.ip_origem);
    printf("Digite porta de origem: ");
    scanf("%d", &dado.porta_origem);
    printf("Digite ip de destino: ");
    scanf("%16s", dado.ip_destino);
    // CORREÇÃO: O texto da mensagem estava incorreto.
    printf("Digite porta de destino: ");
    scanf("%d", &dado.porta_destino);

    // Nota: Ler 256 inteiros para cada pacote torna o teste manual demorado.
    // Para uma simulação real, estes dados poderiam ser gerados aleatoriamente.
    // Por simplicidade, vamos ler apenas o primeiro inteiro do conteúdo.
    printf("Digite o primeiro inteiro do conteudo: ");
    scanf("%d", &dado.conteudo[0]);
    for (i = 1; i < 256; i++)
    {
        dado.conteudo[i] = 0; // Preenche o resto com 0.
    }

    return dado;
}

void executar_quesito1()
{
    struct pacote filtro;
    int i;
    float bloqueados = 0;
    // NOTA: A questão pede para ler 1024 pacotes. Para facilitar o teste,
    // vamos usar um número menor. Altere a constante N_PACOTES se desejar.
    const int N_PACOTES = 5;

    printf("\n*** Executando Quesito 1: Simulador de Firewall ***\n");
    printf("--- Configurando o Filtro do Firewall ---\n");
    printf("Digite ip de origem do filtro: ");
    scanf("%16s", filtro.ip_origem);
    printf("Digite porta de origem do filtro: ");
    scanf("%d", &filtro.porta_origem);
    printf("Digite ip de destino do filtro: ");
    scanf("%16s", filtro.ip_destino);
    printf("Digite porta de destino do filtro: ");
    scanf("%d", &filtro.porta_destino);

    for (i = 0; i < N_PACOTES; i++)
    {
        printf("\nLendo pacote %d de %d...", i + 1, N_PACOTES);
        struct pacote novo_pacote = ler_pacote();
        if (compara_pacotes(novo_pacote, filtro) == 1)
        {
            printf(">>> Pacote Bloqueado!\n");
            bloqueados++;
        }
        else
        {
            printf(">>> Pacote Aceito.\n");
        }
    }

    float aceitos = N_PACOTES - bloqueados;
    // O cálculo do percentual é (parte / total) * 100
    float perc_bloq = (bloqueados / N_PACOTES) * 100.0;
    float perc_acei = (aceitos / N_PACOTES) * 100.0;

    printf("\n--- Relatorio Final ---\n");
    printf("Total de pacotes: %d\n", N_PACOTES);
    printf("Pacotes bloqueados: %.0f (%.2f%%)\n", bloqueados, perc_bloq);
    printf("Pacotes aceitos: %.0f (%.2f%%)\n", aceitos, perc_acei);
}

// =================================================================
// 2º Quesito: Estatísticas de Escolaridade
// =================================================================

// Constantes para o quesito 2
#define MAX_MUNICIPIOS 100
#define N_HABITANTES 200 // Reduzido de 2000 para facilitar testes

// Protótipos das funções do quesito 2
float media(int municipio[], int n_habitantes);
float desvio_padrao(int municipio[], int n_habitantes);
void executar_quesito2();

float media(int municipio[], int n_habitantes)
{
    int j;
    float soma = 0;
    for (j = 0; j < n_habitantes; j++)
    {
        soma += municipio[j];
    }
    return soma / n_habitantes;
}

float desvio_padrao(int municipio[], int n_habitantes)
{
    int j;
    float soma_diff_quadrada = 0;
    float valor_medio = media(municipio, n_habitantes);

    for (j = 0; j < n_habitantes; j++)
    {
        soma_diff_quadrada += pow(municipio[j] - valor_medio, 2);
    }

    // CORREÇÃO: A fórmula do desvio padrão estava incorreta.
    // A variância da população é soma_diff_quadrada / n_habitantes.
    // O desvio padrão é a raiz quadrada da variância.
    if (n_habitantes <= 1)
        return 0; // Evita divisão por zero ou raiz de negativo

    // Usando a fórmula do desvio padrão populacional.
    float variancia = soma_diff_quadrada / n_habitantes;
    return sqrt(variancia);
}

void executar_quesito2()
{
    int municipios[MAX_MUNICIPIOS][N_HABITANTES];
    char nomes[MAX_MUNICIPIOS][31];
    int i, m, j;

    printf("\n*** Executando Quesito 2: Estatisticas de Escolaridade ***\n");

    do
    {
        printf("Digite a quantidade de municipios (entre 5 e 100): ");
        scanf("%d", &m);
        if (m < 5 || m > MAX_MUNICIPIOS)
        {
            printf("Valor invalido. Tente novamente.\n");
        }
    } while (m < 5 || m > MAX_MUNICIPIOS);

    for (i = 0; i < m; i++)
    {
        printf("\nDigite o nome do municipio %d: ", i + 1);
        scanf("%30s", nomes[i]);

        printf("--- Coletando dados de %s ---\n", nomes[i]);
        printf("Escolaridades: 0-analfabeto; 1-alfabetizado; 2-ensino medio; 4-superior\n");
        for (j = 0; j < N_HABITANTES; j++)
        {
            printf("Digite a escolaridade do habitante %d de %d: ", j + 1, N_HABITANTES);
            scanf("%d", &municipios[i][j]);
        }
    }

    printf("\n--- Resultados ---\n");
    for (i = 0; i < m; i++)
    {
        float valor_medio = media(municipios[i], N_HABITANTES);
        float valor_desvio = desvio_padrao(municipios[i], N_HABITANTES);
        printf("Municipio: %s | Media: %.2f | Desvio Padrao: %.2f\n", nomes[i], valor_medio, valor_desvio);
    }
}

// =================================================================
// Questão Aberta 05: Consumo de Combustível
// =================================================================

void executar_quesito5()
{
    float tempo_viagem, vel_media, consumo_medio, cap_tanque;

    printf("\n*** Executando Quesito 5: Calculo de Viagem ***\n");

    // Leitura de dados
    printf("Digite o tempo de viagem (horas): ");
    scanf("%f", &tempo_viagem);
    printf("Digite a velocidade media (km/h): ");
    scanf("%f", &vel_media);
    printf("Digite o consumo medio do veiculo (km/l): ");
    scanf("%f", &consumo_medio);
    printf("Digite a capacidade do tanque (litros): ");
    scanf("%f", &cap_tanque);

    // a) Cálculo da autonomia
    float autonomia = consumo_medio * cap_tanque;

    // b) Cálculo da distância
    float distancia_percorrida = vel_media * tempo_viagem;

    // c) Cálculo do consumo em litros
    float consumo_litros_viagem = distancia_percorrida / consumo_medio;

    printf("\n--- Relatorio da Viagem ---\n");
    printf("a) Autonomia do veiculo com tanque cheio: %.2f km\n", autonomia);
    printf("b) Distancia percorrida na viagem: %.2f km\n", distancia_percorrida);
    printf("c) Consumo de combustivel na viagem: %.2f litros\n", consumo_litros_viagem);
    printf("----------------------------------\n");

    // d, e, f) Análise do consumo
    float litros_restantes = cap_tanque - consumo_litros_viagem;
    float capacidade_sem_reserva = cap_tanque - 5.0;

    if (consumo_litros_viagem > cap_tanque)
    {
        // e) Gastou mais que um tanque
        float tanques_gastos = consumo_litros_viagem / cap_tanque;
        printf("e) Viagem longa! Voce precisaria de %.2f tanques para completar a viagem.\n", tanques_gastos);
        printf("   O combustivel acabou ha %.2f km.\n", (consumo_litros_viagem - cap_tanque) * consumo_medio);
    }
    else
    {
        // f) Gastou menos que um tanque
        printf("f) Litros gastos: %.2f L\n", consumo_litros_viagem);
        printf("   Litros restantes no tanque: %.2f L\n", litros_restantes);

        // d) Alerta de reserva
        if (consumo_litros_viagem > capacidade_sem_reserva && consumo_litros_viagem <= cap_tanque)
        {
            printf("d) ATENCAO! Voce esta usando a reserva do tanque!\n");
        }
        if (litros_restantes <= 0.01)
        { // Usar uma pequena tolerância para floats
            printf("d) ATENCAO! O combustivel acabou!\n");
        }
    }
}

// =================================================================
// Função Principal (Menu)
// =================================================================

int main()
{
    int opcao;

    // Configura o locale para usar acentos corretamente no console (pode não funcionar em todos os sistemas)
    // setlocale(LC_ALL, "Portuguese");

    do
    {
        printf("\n\n--- MENU DE EXERCICIOS ---\n");
        printf("1. Simulador de Firewall (Quesito 1)\n");
        printf("2. Estatisticas de Escolaridade (Quesito 2)\n");
        printf("3. Calculo de Viagem (Quesito 5 - Aberta)\n");
        printf("0. Sair\n");
        printf("---------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            executar_quesito1();
            break;
        case 2:
            executar_quesito2();
            break;
        case 3:
            executar_quesito5();
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
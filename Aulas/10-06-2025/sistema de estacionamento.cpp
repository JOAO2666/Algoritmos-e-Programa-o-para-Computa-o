#include <stdio.h>
#include <math.h> // Necessário para a função ceil()

// Define o tamanho da matriz de estacionamento
#define N 25

// --- Protótipos das Funções (boa prática de programação) ---
void ZerarMatriz(float matriz[N][N]);
void InformarTempo(float matriz[N][N], int i, int j);
float ValorVaga(float matriz[N][N], int i, int j);

// --- Função Principal ---
int main() {
    float estacionamento[N][N];
    int opcao = 0; // Inicializa para garantir que o loop comece
    int fila, vaga;
    
    // CORREÇÃO 1: Variável declarada no início da função para evitar o erro "crosses initialization"
    float valor; 
    
    int resultado_scanf; // Para verificar a leitura do menu

    // Zera a matriz ao iniciar o programa
    ZerarMatriz(estacionamento);
    printf("Matriz de estacionamento inicializada.\n");

    do {
        // Apresenta o menu de forma repetitiva
        printf("\n--- MENU ESTACIONAMENTO ---\n");
        printf("1) Informar tempo de uma vaga\n");
        printf("2) Calcular valor de uma vaga\n");
        printf("3) Sair\n");
        printf("Escolha uma opcao: ");
        
        // CORREÇÃO 2: Tratamento de entrada para evitar loop infinito se o usuário digitar letras
        resultado_scanf = scanf("%d", &opcao);

        if (resultado_scanf != 1) { // Se o scanf não conseguiu ler um número
            printf("\nErro: Entrada invalida. Por favor, digite um numero (1, 2 ou 3).\n");
            // Limpa o buffer de entrada para remover os caracteres inválidos
            while (getchar() != '\n'); 
            opcao = 0;    // Garante que o programa não saia por engano
            continue;     // Pula o resto do loop e volta para o menu
        }

        switch (opcao) {
            case 1:
                printf("Digite a fila (0-24) e a vaga (0-24): ");
                scanf("%d %d", &fila, &vaga);
                InformarTempo(estacionamento, fila, vaga);
                break;
            case 2:
                printf("Digite a fila (0-24) e a vaga (0-24): ");
                scanf("%d %d", &fila, &vaga);
                
                // Agora apenas atribuímos o valor, pois a variável já foi declarada
                valor = ValorVaga(estacionamento, fila, vaga); 
                
                if (valor >= 0) { // Verifica se a posição era válida
                    printf("Valor a cobrar pela vaga (%d, %d): R$ %.2f\n", fila, vaga, valor);
                }
                break;
            case 3:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}


// --- Implementação das Funções ---

/**
 * @brief Inicializa todos os elementos da matriz com 0.0
 * @param matriz A matriz de estacionamento.
 */
void ZerarMatriz(float matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = 0.0f;
        }
    }
}

/**
 * @brief Solicita e armazena o tempo de estacionamento para uma vaga específica.
 * @param matriz A matriz de estacionamento.
 * @param i A fila (linha) da vaga.
 * @param j A coluna da vaga.
 */
void InformarTempo(float matriz[N][N], int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= N) {
        printf("Erro: Posicao (%d, %d) invalida.\n", i, j);
        return;
    }
    printf("Digite o tempo de estacionamento (em horas) para a vaga (%d, %d): ", i, j);
    scanf("%f", &matriz[i][j]);
    printf("Tempo registrado com sucesso.\n");
}

/**
 * @brief Calcula o valor a ser cobrado com base no tempo de uma vaga.
 * @param matriz A matriz de estacionamento.
 * @param i A fila (linha) da vaga.
 * @param j A coluna da vaga.
 * @return O valor a ser cobrado ou -1.0 se a posição for inválida.
 */
float ValorVaga(float matriz[N][N], int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= N) {
        printf("Erro: Posicao (%d, %d) invalida.\n", i, j);
        return -1.0f; // Retorna um valor de erro
    }

    float tempo = matriz[i][j];
    float preco = 0.0f;

    // Regras de tarifação
    if (tempo > 0 && tempo < 0.25) { // Tolerância de 15 min (0.25h)
        preco = 0.00;
    } else if (tempo >= 0.25 && tempo < 4) {
        preco = 6.00; // Valor fixo até 4h
    } else if (tempo >= 4 && tempo < 12) {
        // R$ 6,00 + R$ 2,00 por hora ou fração de hora acima de 4h
        float horas_extras = ceil(tempo - 4); // Arredonda para a próxima hora cheia
        preco = 6.00 + (horas_extras * 2.00);
    } else if (tempo >= 12) {
        // R$ 22,00 (pelas primeiras 12h) + R$ 10,00 por faixa de 12 horas adicional
        int faixas_12h = ceil(tempo / 12.0);
        preco = 22.00 + ((faixas_12h - 1) * 10.00);
    }
    
    return preco;
}

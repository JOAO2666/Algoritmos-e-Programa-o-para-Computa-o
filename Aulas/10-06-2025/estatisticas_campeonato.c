#include <stdio.h>
#include <string.h>

// Para testes, usamos um número menor de atletas. Para a versão final, mude para 3000.
#define N_ATLETAS 4
#define TAM_NOME 31

// Protótipos das Funções
void preencher(int matriz[N_ATLETAS][N_ATLETAS]);
int numero_vitorias(int matriz[N_ATLETAS][N_ATLETAS], int i);
int numero_derrotas(int matriz[N_ATLETAS][N_ATLETAS], int i);
int maior_vitorias(int matriz[N_ATLETAS][N_ATLETAS]);
void resultado(int matriz[N_ATLETAS][N_ATLETAS], char nomes[N_ATLETAS][TAM_NOME], int i, int j);
void limpar_buffer_entrada();

/**
 * Limpa o buffer de entrada do teclado (stdin).
 * Necessário para evitar problemas com leituras mistas de scanf e fgets.
 */
void limpar_buffer_entrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/**
 * a) Preenche a matriz com os resultados dos confrontos.
 */
void preencher(int matriz[N_ATLETAS][N_ATLETAS])
{
    printf("\n--- Preenchimento dos Resultados ---\n");
    printf("Digite o resultado (1 para vitoria do atleta i, -1 para vitoria do atleta j, 0 para empate):\n");
    for (int i = 0; i < N_ATLETAS; i++)
    {
        for (int j = i + 1; j < N_ATLETAS; j++)
        {
            printf("Resultado de Atleta %d vs Atleta %d: ", i, j);
            scanf("%d", &matriz[i][j]);
            // Garante a consistência: se i ganhou de j (1), j perdeu de i (-1)
            matriz[j][i] = -matriz[i][j];
        }
    }
}

/**
 * Retorna o número de vitórias do atleta i.
 */
int numero_vitorias(int matriz[N_ATLETAS][N_ATLETAS], int i)
{
    int vit = 0;
    for (int j = 0; j < N_ATLETAS; j++)
    {
        if (matriz[i][j] == 1)
        { // 1 representa vitória
            vit++;
        }
    }
    return vit;
}

/**
 * Retorna o número de derrotas do atleta i.
 */
int numero_derrotas(int matriz[N_ATLETAS][N_ATLETAS], int i)
{
    int derr = 0;
    for (int j = 0; j < N_ATLETAS; j++)
    {
        if (matriz[i][j] == -1)
        { // -1 representa derrota
            derr++;
        }
    }
    return derr;
}

/**
 * Retorna o ÍNDICE do atleta com o maior número de vitórias.
 */
int maior_vitorias(int matriz[N_ATLETAS][N_ATLETAS])
{
    int maior_indice = 0;
    // Inicializa com as vitórias do primeiro atleta
    int maior_vit = numero_vitorias(matriz, 0);

    for (int i = 1; i < N_ATLETAS; i++)
    {
        int vit_atuais = numero_vitorias(matriz, i);
        if (vit_atuais > maior_vit)
        {
            maior_vit = vit_atuais;
            maior_indice = i;
        }
    }
    return maior_indice;
}

/**
 * d) Imprime o resultado da luta entre os atletas i e j e seus nomes.
 */
void resultado(int matriz[N_ATLETAS][N_ATLETAS], char nomes[N_ATLETAS][TAM_NOME], int i, int j)
{
    printf("\n--- Resultado: %s vs %s ---\n", nomes[i], nomes[j]);
    if (matriz[i][j] == 1)
    {
        printf("Vitoria para %s!\n", nomes[i]);
    }
    else if (matriz[i][j] == -1)
    {
        printf("Vitoria para %s!\n", nomes[j]);
    }
    else
    {
        printf("A luta terminou em empate!\n");
    }
}

int main()
{
    char nomes[N_ATLETAS][TAM_NOME];
    int matriz_res[N_ATLETAS][N_ATLETAS] = {{0}}; // Inicializa a matriz com zeros
    int opcao, atleta1_idx, atleta2_idx;

    // Preenche o nome dos atletas
    printf("--- Cadastro de Atletas ---\n");
    limpar_buffer_entrada(); // Limpa qualquer resíduo antes de começar
    for (int i = 0; i < N_ATLETAS; i++)
    {
        printf("Digite o nome completo do atleta %d: ", i);
        fgets(nomes[i], TAM_NOME, stdin);
        // Remove a quebra de linha que o fgets adiciona
        nomes[i][strcspn(nomes[i], "\n")] = 0;
    }

    // Preenche a matriz de resultados
    preencher(matriz_res);

    // Menu de opções
    do
    {
        printf("\n--- MENU DE ESTATISTICAS ---\n");
        printf("1- Atleta com maior quantidade de vitorias\n");
        printf("2- Saldo de vitorias de um atleta\n");
        printf("3- Resultado de uma luta\n");
        printf("4- Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            int idx_vencedor = maior_vitorias(matriz_res);
            int vitorias = numero_vitorias(matriz_res, idx_vencedor);
            printf("\nAtleta com mais vitorias: %s (%d vitorias).\n", nomes[idx_vencedor], vitorias);
            break;
        }
        case 2:
        {
            printf("Digite o codigo (indice) do atleta (0 a %d): ", N_ATLETAS - 1);
            scanf("%d", &atleta1_idx);
            if (atleta1_idx >= 0 && atleta1_idx < N_ATLETAS)
            {
                int vit = numero_vitorias(matriz_res, atleta1_idx);
                int derr = numero_derrotas(matriz_res, atleta1_idx);
                char primeiro_nome[TAM_NOME];
                sscanf(nomes[atleta1_idx], "%s", primeiro_nome); // Extrai o primeiro nome
                printf("\nSaldo de vitorias de %s: %d\n", primeiro_nome, vit - derr);
            }
            else
            {
                printf("Indice invalido.\n");
            }
            break;
        }
        case 3:
        {
            printf("Digite os codigos (indices) dos dois atletas (ex: 0 1): ");
            scanf("%d %d", &atleta1_idx, &atleta2_idx);
            if (atleta1_idx >= 0 && atleta1_idx < N_ATLETAS && atleta2_idx >= 0 && atleta2_idx < N_ATLETAS)
            {
                resultado(matriz_res, nomes, atleta1_idx, atleta2_idx);
            }
            else
            {
                printf("Indices invalidos.\n");
            }
            break;
        }
        case 4:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            limpar_buffer_entrada(); // Limpa o buffer caso o usuário digite um caractere
            break;
        }
    } while (opcao != 4);

    return 0;
}
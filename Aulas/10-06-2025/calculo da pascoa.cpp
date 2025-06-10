#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Calcula o mês e o dia da Páscoa para um dado ano.
 * @param resp Vetor de 3 posições: resp[0]=ano, resp[1]=mês (a ser preenchido), resp[2]=dia (a ser preenchido).
 */
void calcula_pascoa(int resp[]) { [cite: 213]
    int ano = resp[0];
    int a, b, c, d, e;

    // Algoritmo de Gauss para o cálculo da Páscoa 
    a = ano % 19;
    b = ano % 4;
    c = ano % 7;
    d = (19 * a + 24) % 30;
    e = (2 * b + 4 * c + 6 * d + 5) % 7;

    if ((d + e) > 9) {
        resp[1] = 4; // Mês de Abril 
        resp[2] = d + e - 9;
    } else {
        resp[1] = 3; // Mês de Março 
        resp[2] = d + e + 22;
    }
}

/**
 * @brief Verifica se um intervalo de anos é válido (entre 1900 e 2099).
 * @return 1 se válido, 0 caso contrário.
 */
int checagem_ano(int ano_1, int ano_2) { [cite: 215]
    // Garante que ano_1 seja o menor e ano_2 o maior
    int min_ano = (ano_1 < ano_2) ? ano_1 : ano_2;
    int max_ano = (ano_1 > ano_2) ? ano_1 : ano_2;

    if (min_ano >= 1900 && max_ano <= 2099) {
        return 1;
    }
    return 0;
}

int main() {
    // A matriz precisa ter tamanho suficiente para o maior intervalo possível (2099-1900+1 = 200)
    int M[200][3];
    int ano_inf = 0, ano_sup = 0, valido = 0;
    
    // a. Pede e valida o intervalo de anos 
    while (valido == 0) {
        printf("Digite dois anos no intervalo [1900, 2099]: ");
        scanf("%d %d", &ano_inf, &ano_sup);
        valido = checagem_ano(ano_inf, ano_sup);
        if (!valido) {
            printf("Intervalo invalido. Tente novamente.\n");
        }
    }
    
    // Garante que ano_inf seja o menor
    if (ano_inf > ano_sup) {
        int temp = ano_inf;
        ano_inf = ano_sup;
        ano_sup = temp;
    }

    int total_anos = ano_sup - ano_inf + 1;
    int pascoa_em_marco = 0;

    // b. Calcula e armazena os dados para cada ano no intervalo 
    for (int i = 0; i < total_anos; i++) {
        M[i][0] = ano_inf + i;
        calcula_pascoa(M[i]); // A função preenche M[i][1] e M[i][2] 

        if (M[i][1] == 3) { // 3 representa Março 
            pascoa_em_marco++;
        }
    }

    // c. Imprime a matriz com os resultados 
    printf("\n--- Datas da Pascoa ---\n");
    printf("Ano\tMes\tDia\n");
    printf("----\t---\t---\n");
    for (int i = 0; i < total_anos; i++) {
        printf("%d\t%d\t%d\n", M[i][0], M[i][1], M[i][2]);
    }

    // d. Imprime o percentual 
    float percentual = 100.0f * pascoa_em_marco / total_anos;
    printf("\nPercentual de vezes em que a Pascoa ocorreu em Marco: %.2f%%\n", percentual);

    return 0;
}

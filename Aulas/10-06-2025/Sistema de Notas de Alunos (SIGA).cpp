#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um aluno
typedef struct aluno {
    int numero;
    float notas[5]; // 3 provas, 1 2a chamada, 1 final 
    float media;
    int situacao; // 0 a 4 
} TAluno;

// a) Fun��o para cadastrar as notas de um aluno 
TAluno cadastraNotas(void) {
    TAluno a;
    printf("\n--- Cadastro de Aluno ---\n");
    printf("Numero do aluno: ");
    scanf("%d", &a.numero);
    printf("Digite as 3 notas da 1a etapa (use -1 para falta): ");
    for (int i = 0; i < 3; i++) {
        scanf("%f", &a.notas[i]);
    }
    printf("Nota da 2a chamada (use -1 se nao fez): ");
    scanf("%f", &a.notas[3]);
    printf("Nota da prova final (use -1 se nao fez): ");
    scanf("%f", &a.notas[4]);
    return a;
}

// b) Fun��o para calcular provas perdidas e m�dia semestral
void calculaIndicadores(TAluno a, int* nProvasPerdidas, float* mediaSemestre) {
    *nProvasPerdidas = 0;
    *mediaSemestre = 0;
    int nNotasValidas = 0;

    // Considera as 3 primeiras notas + 2a chamada
    for (int i = 0; i < 4; i++) {
        if (a.notas[i] == -1) {
            if (i < 3) { // Provas perdidas s�o apenas as 3 primeiras
                (*nProvasPerdidas)++;
            }
        } else {
            if(i < 3 || a.notas[i] !=-1) { //Soma as notas das 3 provas ou da 2a chamada se houver
                *mediaSemestre += a.notas[i];
                nNotasValidas++;
            }
        }
    }
    // A m�dia � calculada sobre as provas que o aluno fez (at� 3)
     if (nNotasValidas > 0) {
        *mediaSemestre = (*mediaSemestre) / nNotasValidas;
    } else {
        *mediaSemestre = 0;
    }
}

int main(void) {
    TAluno a;
    int n, nProvasPerdidas;
    float mediaSem, mediaGlob;

    printf("Digite a quantidade de alunos a cadastrar: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        // a. e b. Chama as fun��es de cadastro e c�lculo
        a = cadastraNotas();
        calculaIndicadores(a, &nProvasPerdidas, &mediaSem);

        printf("\n-- Situacao do Aluno %d --\n", a.numero);

        // c. Atualiza a situa��o e a m�dia do aluno
        if (nProvasPerdidas >= 2) { // Situa��o 0: Reprovado por falta
            a.media = -1;
            a.situacao = 0;
            printf("Situacao: Reprovado por falta (%d provas perdidas).\n", nProvasPerdidas);
        } else {
            a.media = mediaSem;
            if (mediaSem < 3) { // Situa��o 1: Reprovado por m�dia
                a.situacao = 1;
                printf("Situacao: Reprovado por media. Media: %.2f\n", a.media);
            } else if (mediaSem >= 7) { // Situa��o 2: Aprovado por m�dia
                a.situacao = 2;
                printf("Situacao: Aprovado por media. Media: %.2f\n", a.media);
            } else { // Situa��o de prova final
                if (a.notas[4] != -1) {
                    mediaGlob = (mediaSem + a.notas[4]) / 2.0;
                    a.media = mediaGlob;
                    if (mediaGlob < 5) { // Situa��o 3: Reprovado na final
                        a.situacao = 3;
                        printf("Situacao: Reprovado na final. Media Final: %.2f\n", a.media);
                    } else { // Situa��o 4: Aprovado na final
                        a.situacao = 4;
                        printf("Situacao: Aprovado na final. Media Final: %.2f\n", a.media);
                    }
                } else {
                     printf("Situacao: Aluno nao realizou a prova final.\n");
                }
            }
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// ================ CONSTANTES ================
#define MAX 300
#define MAX_STR 100

// ================ PROT�TIPOS ================
void limparTela();
void pausar();
int menuPrincipal();

// M�dulos de quest�es
void estatisticasVetor();
void operacoesMatrizes();
void manipulacaoStrings();
void matematicaAvancada();
void estruturasDados();
void arquivosTexto();
void simulacaoProva1();
void simulacaoProva2();

// ================ MAIN ================
int main() {
    srand(time(NULL));
    
    int opcao;
    do {
        opcao = menuPrincipal();
        
        switch(opcao) {
            case 1: estatisticasVetor(); break;
            case 2: operacoesMatrizes(); break;
            case 3: manipulacaoStrings(); break;
            case 4: matematicaAvancada(); break;
            case 5: estruturasDados(); break;
            case 6: arquivosTexto(); break;
            case 7: simulacaoProva1(); break;
            case 8: simulacaoProva2(); break;
        }
    } while(opcao != 0);

    return 0;
}

// ================ FUN��ES AUXILIARES ================
void limparTela() {
    system("clear || cls");
}

void pausar() {
    printf("\nPressione ENTER para continuar...");
    while(getchar() != '\n');
    getchar();
}

int menuPrincipal() {
    limparTela();
    printf("======= MENU DE PROJETOS =======\n");
    printf("1. Estat�sticas de Vetores\n");
    printf("2. Opera��es com Matrizes\n");
    printf("3. Manipula��o de Strings\n");
    printf("4. Matem�tica Avan�ada\n");
    printf("5. Estruturas de Dados\n");
    printf("6. Manipula��o de Arquivos\n");
    printf("7. Simula��o de Prova 1\n");
    printf("8. Simula��o de Prova 2\n");
    printf("0. Sair\n");
    printf("=================================\n");
    
    int opcao;
    printf("Escolha o projeto: ");
    scanf("%d", &opcao);
    return opcao;
}

// ================ M�DULOS DE QUEST�ES ================

// 1. ESTAT�STICAS DE VETOR (Similar � sua 1� quest�o)
void estatisticasVetor() {
    limparTela();
    printf("=== ESTAT�STICAS DE VETOR ===\n\n");
    
    int n, vetor[MAX];
    float soma = 0;
    
    // Ler tamanho v�lido
    do {
        printf("Digite o tamanho do vetor (5-200): ");
        scanf("%d", &n);
    } while(n < 5 || n > 200);
    
    // Ler vetor ordenado
    printf("Digite os %d elementos ORDENADOS:\n", n);
    for(int i = 0; i < n; i++) {
        printf("Elemento %d: ", i+1);
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }
    
    // C�lculos
    float media = soma / n;
    float mediana;
    
    if(n % 2 == 1) {
        mediana = vetor[n/2];
    } else {
        mediana = (vetor[n/2 - 1] + vetor[n/2]) / 2.0;
    }
    
    int pares = 0, impares = 0;
    for(int i = 0; i < n; i++) {
        if(vetor[i] % 2 == 0) pares++;
        else impares++;
    }
    
    // Resultados
    printf("\n=== RESULTADOS ===\n");
    printf("M�dia: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Pares: %d\n", pares);
    printf("�mpares: %d\n", impares);
    
    pausar();
}

// 2. OPERA��ES COM MATRIZES (Similar � sua 2� quest�o)
void operacoesMatrizes() {
    limparTela();
    printf("=== OPERA��ES COM MATRIZES ===\n\n");
    
    int m, n, opcao;
    float matriz[MAX][MAX], escalar;
    
    // Ler dimens�es
    do {
        printf("Linhas (2-300): ");
        scanf("%d", &m);
        printf("Colunas (2-300): ");
        scanf("%d", &n);
    } while(m < 2 || m > MAX || n < 2 || n > MAX);
    
    // Ler matriz
    printf("\nDigite os elementos da matriz %dx%d:\n", m, n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }
    
    // Menu de opera��es
    do {
        limparTela();
        printf("=== MENU DE OPERA��ES ===\n");
        printf("1. Diagonal principal\n");
        printf("2. Matriz transposta\n");
        printf("3. Multiplicar por escalar\n");
        printf("4. Somar escalar\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                if(m != n) {
                    printf("Erro: A matriz n�o � quadrada!\n");
                } else {
                    printf("\nDiagonal principal:\n");
                    for(int i = 0; i < m; i++) {
                        printf("%.2f ", matriz[i][i]);
                    }
                }
                pausar();
                break;
                
            case 2:
                printf("\nMatriz transposta:\n");
                for(int j = 0; j < n; j++) {
                    for(int i = 0; i < m; i++) {
                        printf("%8.2f ", matriz[i][j]);
                    }
                    printf("\n");
                }
                pausar();
                break;
                
            case 3:
                printf("Valor escalar: ");
                scanf("%f", &escalar);
                printf("\nMatriz multiplicada por %.2f:\n", escalar);
                for(int i = 0; i < m; i++) {
                    for(int j = 0; j < n; j++) {
                        printf("%8.2f ", matriz[i][j] * escalar);
                    }
                    printf("\n");
                }
                pausar();
                break;
                
            case 4:
                printf("Valor escalar: ");
                scanf("%f", &escalar);
                printf("\nMatriz somada com %.2f:\n", escalar);
                for(int i = 0; i < m; i++) {
                    for(int j = 0; j < n; j++) {
                        printf("%8.2f ", matriz[i][j] + escalar);
                    }
                    printf("\n");
                }
                pausar();
                break;
        }
    } while(opcao != 0);
}

// 3. MANIPULA��O DE STRINGS
void manipulacaoStrings() {
    limparTela();
    printf("=== MANIPULA��O DE STRINGS ===\n\n");
    
    char str1[MAX_STR], str2[MAX_STR];
    int opcao;
    
    printf("Digite a primeira string: ");
    scanf(" %[^\n]", str1);
    printf("Digite a segunda string: ");
    scanf(" %[^\n]", str2);
    
    do {
        limparTela();
        printf("=== OPERA��ES COM STRINGS ===\n");
        printf("1. Comparar strings\n");
        printf("2. Concatenar strings\n");
        printf("3. Tamanho das strings\n");
        printf("4. Converter para mai�sculas\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                if(strcmp(str1, str2) == 0) {
                    printf("As strings s�o iguais.\n");
                } else {
                    printf("As strings s�o diferentes.\n");
                }
                pausar();
                break;
                
            case 2:
                printf("String concatenada: %s\n", strcat(str1, str2));
                pausar();
                break;
                
            case 3:
                printf("Tamanho de '%s': %lu\n", str1, strlen(str1));
                printf("Tamanho de '%s': %lu\n", str2, strlen(str2));
                pausar();
                break;
                
            case 4:
                for(int i = 0; str1[i]; i++) {
                    str1[i] = toupper(str1[i]);
                }
                for(int i = 0; str2[i]; i++) {
                    str2[i] = toupper(str2[i]);
                }
                printf("Strings em mai�sculas:\n%s\n%s\n", str1, str2);
                pausar();
                break;
        }
    } while(opcao != 0);
}

// 4. MATEM�TICA AVAN�ADA
void matematicaAvancada() {
    limparTela();
    printf("=== MATEM�TICA AVAN�ADA ===\n\n");
    
    int opcao;
    do {
        limparTela();
        printf("=== MENU MATEM�TICA ===\n");
        printf("1. Fatorial\n");
        printf("2. Fibonacci\n");
        printf("3. N�meros primos\n");
        printf("4. Pot�ncia/raiz\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: {
                int n;
                printf("N�mero para fatorial: ");
                scanf("%d", &n);
                
                long fat = 1;
                for(int i = 1; i <= n; i++) {
                    fat *= i;
                }
                printf("%d! = %ld\n", n, fat);
                pausar();
                break;
            }
            
            case 2: {
                int n;
                printf("Quantos termos Fibonacci: ");
                scanf("%d", &n);
                
                printf("S�rie: ");
                long a = 0, b = 1, c;
                for(int i = 0; i < n; i++) {
                    printf("%ld ", a);
                    c = a + b;
                    a = b;
                    b = c;
                }
                printf("\n");
                pausar();
                break;
            }
            
            // Implementar outros casos...
        }
    } while(opcao != 0);
}

// 5. ESTRUTURAS DE DADOS
void estruturasDados() {
    // Implementar estruturas como:
    // - Structs de alunos
    // - Listas encadeadas simples
    // - Pilhas e filas b�sicas
}

// 6. MANIPULA��O DE ARQUIVOS
void arquivosTexto() {
    // Implementar:
    // - Gravar dados em arquivo
    // - Ler dados de arquivo
    // - Processar conte�do
}

// 7. SIMULA��O DE PROVA 1
void simulacaoProva1() {
    // Implementar quest�es no estilo da sua prova
    // com tempo limitado (simula��o real)
}

// 8. SIMULA��O DE PROVA 2
void simulacaoProva2() {
    // Outro modelo de prova com diferentes quest�es
}

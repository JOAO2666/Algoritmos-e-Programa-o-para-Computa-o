/*
 * GUIA COMPLETO DE PROGRAMAÇÃO EM C
 * Este código demonstra os conceitos fundamentais da linguagem C
 */

/* 
 * BIBLIOTECAS ESSENCIAIS
 * Inclusão de bibliotecas padrão que serão necessárias para a maioria dos programas
 */
#include <stdio.h>   // Para funções de entrada e saída (printf, scanf)
#include <stdlib.h>  // Para funções gerais como alocação de memória (malloc, free)
#include <string.h>  // Para manipulação de strings (strlen, strcpy)
#include <math.h>    // Para funções matemáticas (sqrt, pow)

/*
 * CONSTANTES E MACROS
 * Definição de valores constantes e macros para uso no programa
 */
#define PI 3.14159
#define MAX 100
#define QUADRADO(x) ((x) * (x))  // Macro para calcular o quadrado de um número

/*
 * DECLARAÇÃO DE TIPOS PERSONALIZADOS
 * Exemplos de como criar tipos personalizados com struct, enum e typedef
 */

// Estrutura para armazenar informações de um ponto no plano cartesiano
typedef struct {
    float x;
    float y;
} Ponto;

// Estrutura para armazenar informações de um aluno
typedef struct {
    char nome[50];
    int idade;
    float notas[3];
    float media;
} Aluno;

// Enumeração para representar dias da semana
typedef enum {
    DOMINGO = 1,
    SEGUNDA,  // = 2 implicitamente
    TERCA,    // = 3 implicitamente
    QUARTA,   // = 4 implicitamente
    QUINTA,   // = 5 implicitamente
    SEXTA,    // = 6 implicitamente
    SABADO    // = 7 implicitamente
} DiaSemana;

/*
 * PROTÓTIPOS DE FUNÇÕES
 * Declaração das funções que serão utilizadas no programa
 */
void exibirMenu();
int somar(int a, int b);
float calcularMedia(float *notas, int quantidade);
void trocar(int *a, int *b);
int fatorial(int n);
void ordenarVetor(int vetor[], int tamanho);
float calcularDistancia(Ponto p1, Ponto p2);
void imprimirAluno(Aluno aluno);
void manipularArquivos();

/*
 * FUNÇÃO PRINCIPAL (MAIN)
 * Ponto de entrada do programa
 */
int main() {
    printf("==== PROGRAMA DEMONSTRATIVO DE C ====\n\n");
    
    // VARIÁVEIS - Demonstração de declaração e uso de variáveis de diferentes tipos
    printf("1. VARIÁVEIS\n");
    int idade = 20;             // Variável para armazenar números inteiros
    float altura = 1.75;        // Variável para armazenar números reais
    char genero = 'M';          // Variável para armazenar um caractere
    char nome[50] = "Carlos";   // Array de caracteres (string)
    
    printf("Nome: %s\n", nome);
    printf("Idade: %d anos\n", idade);
    printf("Altura: %.2f metros\n", altura);
    printf("Gênero: %c\n\n", genero);
    
    // OPERADORES - Demonstração de operadores aritméticos
    printf("2. OPERADORES ARITMÉTICOS\n");
    int a = 10, b = 3;
    printf("a = %d, b = %d\n", a, b);
    printf("Soma: a + b = %d\n", a + b);
    printf("Subtração: a - b = %d\n", a - b);
    printf("Multiplicação: a * b = %d\n", a * b);
    printf("Divisão (inteira): a / b = %d\n", a / b);
    printf("Resto da divisão: a %% b = %d\n", a % b);
    printf("Incremento: a++ = %d\n", a++);
    printf("Valor de a após incremento: %d\n\n", a);
    
    // ESTRUTURAS DE CONTROLE - Demonstração de estruturas condicionais e de repetição
    printf("3. ESTRUTURAS DE CONTROLE\n");
    
    // if-else: estrutura condicional
    printf("3.1 Estrutura if-else\n");
    int numero = 15;
    if (numero > 0) {
        printf("O número %d é positivo\n", numero);
    } else if (numero < 0) {
        printf("O número %d é negativo\n", numero);
    } else {
        printf("O número é zero\n");
    }
    
    // switch-case: estrutura de múltipla escolha
    printf("\n3.2 Estrutura switch-case\n");
    DiaSemana hoje = QUARTA;
    switch (hoje) {
        case DOMINGO:
            printf("Hoje é domingo\n");
            break;
        case SEGUNDA:
            printf("Hoje é segunda-feira\n");
            break;
        case TERCA:
            printf("Hoje é terça-feira\n");
            break;
        case QUARTA:
            printf("Hoje é quarta-feira\n");
            break;
        case QUINTA:
            printf("Hoje é quinta-feira\n");
            break;
        case SEXTA:
            printf("Hoje é sexta-feira\n");
            break;
        case SABADO:
            printf("Hoje é sábado\n");
            break;
        default:
            printf("Dia inválido\n");
    }
    
    // for: laço de repetição com contador
    printf("\n3.3 Laço for\n");
    printf("Contagem de 1 a 5: ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    // while: laço de repetição com condição de entrada
    printf("\n3.4 Laço while\n");
    int contador = 5;
    printf("Contagem regressiva: ");
    while (contador > 0) {
        printf("%d ", contador);
        contador--;
    }
    printf("\n");
    
    // do-while: laço de repetição com condição de saída
    printf("\n3.5 Laço do-while\n");
    contador = 1;
    printf("Números ímpares até 10: ");
    do {
        if (contador % 2 != 0) {
            printf("%d ", contador);
        }
        contador++;
    } while (contador <= 10);
    printf("\n\n");
    
    // ARRAYS - Demonstração de declaração e manipulação de arrays
    printf("4. ARRAYS\n");
    
    // Array unidimensional (vetor)
    int numeros[5] = {10, 20, 30, 40, 50};
    printf("4.1 Vetor de inteiros: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    
    // Array bidimensional (matriz)
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    printf("\n4.2 Matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // FUNÇÕES - Demonstração de chamadas de funções
    printf("5. FUNÇÕES\n");
    int resultadoSoma = somar(10, 20);
    printf("5.1 Resultado da soma de 10 e 20: %d\n", resultadoSoma);
    
    // Demonstração de função com cálculo
    float notasAluno[3] = {7.5, 8.0, 9.5};
    float mediaAluno = calcularMedia(notasAluno, 3);
    printf("5.2 Média das notas: %.2f\n", mediaAluno);
    
    // Demonstração de ponteiros em funções
    int x = 5, y = 10;
    printf("\n5.3 Antes da troca: x = %d, y = %d\n", x, y);
    trocar(&x, &y);  // Passando os endereços de x e y
    printf("5.3 Depois da troca: x = %d, y = %d\n", x, y);
    
    // Demonstração de função recursiva
    int num = 5;
    printf("\n5.4 Fatorial de %d = %d\n\n", num, fatorial(num));
    
    // PONTEIROS - Demonstração de declaração e uso de ponteiros
    printf("6. PONTEIROS\n");
    int valor = 100;
    int *ponteiro = &valor;  // Ponteiro recebe o endereço de valor
    
    printf("6.1 Valor da variável: %d\n", valor);
    printf("6.2 Endereço da variável: %p\n", &valor);
    printf("6.3 Valor do ponteiro (endereço armazenado): %p\n", ponteiro);
    printf("6.4 Valor apontado pelo ponteiro: %d\n", *ponteiro);
    
    // Modificando o valor através do ponteiro
    *ponteiro = 200;
    printf("6.5 Valor da variável após modificação pelo ponteiro: %d\n\n", valor);
    
    // ALOCAÇÃO DINÂMICA DE MEMÓRIA - Demonstração de malloc, realloc e free
    printf("7. ALOCAÇÃO DINÂMICA DE MEMÓRIA\n");
    
    // Alocação de um bloco de memória para um inteiro
    int *ptr = (int *) malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Erro na alocação de memória\n");
        return 1;
    }
    
    *ptr = 500;
    printf("7.1 Valor alocado dinamicamente: %d\n", *ptr);
    
    // Realocação para um array de 5 inteiros
    ptr = (int *) realloc(ptr, 5 * sizeof(int));
    if (ptr == NULL) {
        printf("Erro na realocação de memória\n");
        return 1;
    }
    
    // Preenchendo o array realocado
    for (int i = 0; i < 5; i++) {
        ptr[i] = (i + 1) * 10;
    }
    
    printf("7.2 Array alocado dinamicamente: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    
    // Liberando a memória alocada
    free(ptr);
    printf("7.3 Memória liberada com sucesso!\n\n");
    
    // STRUCTS - Demonstração de uso de structs
    printf("8. STRUCTS E TIPOS PERSONALIZADOS\n");
    
    // Usando a struct Ponto
    Ponto p1 = {1.0, 2.0};
    Ponto p2 = {4.0, 6.0};
    
    printf("8.1 Distância entre os pontos (%.1f, %.1f) e (%.1f, %.1f): %.2f\n", 
           p1.x, p1.y, p2.x, p2.y, calcularDistancia(p1, p2));
    
    // Usando a struct Aluno
    Aluno estudante;
    strcpy(estudante.nome, "Maria Silva");
    estudante.idade = 22;
    estudante.notas[0] = 8.5;
    estudante.notas[1] = 7.0;
    estudante.notas[2] = 9.5;
    estudante.media = calcularMedia(estudante.notas, 3);
    
    printf("\n8.2 Informações do aluno:\n");
    imprimirAluno(estudante);
    
    // OPERAÇÕES COM ARQUIVOS - Demonstração de operações com arquivos
    printf("\n9. OPERAÇÕES COM ARQUIVOS\n");
    manipularArquivos();
    
    printf("\n==== FIM DO PROGRAMA ====\n");
    return 0;
}

/*
 * IMPLEMENTAÇÃO DAS FUNÇÕES
 */

// Função para exibir um menu de opções
void exibirMenu() {
    printf("Menu de Opções:\n");
    printf("1. Inserir dados\n");
    printf("2. Consultar dados\n");
    printf("3. Atualizar dados\n");
    printf("4. Remover dados\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

// Função que recebe dois inteiros e retorna a soma
int somar(int a, int b) {
    return a + b;
}

// Função que calcula a média de um array de notas
float calcularMedia(float *notas, int quantidade) {
    float soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += notas[i];
    }
    return soma / quantidade;
}

// Função que troca os valores de duas variáveis usando ponteiros
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função recursiva para calcular o fatorial de um número
int fatorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

// Função para ordenar um vetor em ordem crescente (algoritmo Bubble Sort)
void ordenarVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Função que calcula a distância entre dois pontos
float calcularDistancia(Ponto p1, Ponto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Função para imprimir os dados de um aluno
void imprimirAluno(Aluno aluno) {
    printf("Nome: %s\n", aluno.nome);
    printf("Idade: %d anos\n", aluno.idade);
    printf("Notas: %.1f, %.1f, %.1f\n", aluno.notas[0], aluno.notas[1], aluno.notas[2]);
    printf("Média: %.2f\n", aluno.media);
}

// Função que demonstra operações com arquivos
void manipularArquivos() {
    FILE *arquivo;
    char texto[] = "Exemplo de texto para gravar no arquivo.";
    char buffer[100];
    
    // Abrindo arquivo para escrita
    arquivo = fopen("exemplo.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }
    
    // Escrevendo no arquivo
    fprintf(arquivo, "%s\n", texto);
    fprintf(arquivo, "Segunda linha do arquivo.\n");
    
    // Fechando o arquivo
    fclose(arquivo);
    printf("9.1 Arquivo criado e texto gravado com sucesso!\n");
    
    // Abrindo arquivo para leitura
    arquivo = fopen("exemplo.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }
    
    // Lendo e exibindo o conteúdo do arquivo
    printf("9.2 Conteúdo do arquivo:\n");
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL) {
        printf("%s", buffer);
    }
    
    // Fechando o arquivo
    fclose(arquivo);
}
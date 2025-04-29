#include <stdio.h>
#include <stdlib.h> // Para system("pause"), malloc, etc.
#include <string.h> // Para fun��es de string

/* ESTRUTURA B�SICA DE UM PROGRAMA EM C */
int main() {
    // ==============================================
    // 1. DECLARA��O DE VARI�VEIS
    // ==============================================
    int idade = 20;
    float peso = 65.5;
    char letra = 'A';
    double pi = 3.1415926535;
    
    // ==============================================
    // 2. ENTRADA E SA�DA (printf e scanf)
    // ==============================================
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Voc� tem %d anos.\n", idade);
    
    // ==============================================
    // 3. ESTRUTURAS CONDICIONAIS
    // ==============================================
    if (idade >= 18) {
        printf("Maior de idade.\n");
    } else {
        printf("Menor de idade.\n");
    }
    
    // Exemplo com switch-case
    switch (idade) {
        case 18:
            printf("Acabou de virar adulto!\n");
            break;
        default:
            printf("Outra idade\n");
    }
    
    // ==============================================
    // 4. LA�OS DE REPETI��O
    // ==============================================
    // For loop
    printf("Contagem de 1 a 10:\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    // While loop
    int contador = 5;
    printf("Contagem regressiva:\n");
    while (contador > 0) {
        printf("%d... ", contador);
        contador--;
    }
    printf("Fogo!\n");
    
    // ==============================================
    // 5. FUN��ES
    // ==============================================
    // Prot�tipo da fun��o
    int quadrado(int num);
    
    // Chamando a fun��o
    int resultado = quadrado(5);
    printf("O quadrado de 5 �: %d\n", resultado);
    
    // ==============================================
    // 6. VETORES E STRINGS
    // ==============================================
    int numeros[5] = {1, 2, 3, 4, 5};
    char nome[50] = "Maria";
    
    printf("Terceiro n�mero: %d\n", numeros[2]);
    printf("Nome: %s\n", nome);
    
    // ==============================================
    // 7. EXEMPLO DE CALCULADORA
    // ==============================================
    float num1, num2;
    char operador;
    
    printf("\n=== CALCULADORA ===\n");
    printf("Digite o primeiro n�mero: ");
    scanf("%f", &num1);
    
    printf("Digite a opera��o (+, -, *, /): ");
    scanf(" %c", &operador);
    
    printf("Digite o segundo n�mero: ");
    scanf("%f", &num2);
    
    switch (operador) {
        case '+':
            printf("Resultado: %.2f\n", num1 + num2);
            break;
        case '-':
            printf("Resultado: %.2f\n", num1 - num2);
            break;
        case '*':
            printf("Resultado: %.2f\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("Resultado: %.2f\n", num1 / num2);
            } else {
                printf("Erro: divis�o por zero!\n");
            }
            break;
        default:
            printf("Operador inv�lido!\n");
    }
    
    system("pause");
    return 0;
}

// ==============================================
// DEFINI��O DE FUN��ES
// ==============================================
int quadrado(int num) {
    return num * num;
}

/*
DICAS PARA O SIMULADO:

1. Sempre compile e teste seu c�digo
2. Use printf para debug: printf("DEBUG: x = %d", x);
3. Se n�o souber completo, fa�a a parte que sabe
4. Leia as mensagens de erro do compilador
5. Formate seu c�digo com indenta��o

CHECKLIST ANTES DE ENTREGAR:
[ ] 1. Meu c�digo compila sem erros?
[ ] 2. Testei com diferentes valores?
[ ] 3. Verifiquei condi��es de borda?
[ ] 4. Coloquei system("pause") se necess�rio?
[ ] 5. Formatei o c�digo corretamente?
*/

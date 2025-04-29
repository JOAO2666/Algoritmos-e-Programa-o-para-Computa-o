#include <stdio.h>
#include <stdlib.h> // Para system("pause"), malloc, etc.
#include <string.h> // Para funções de string

/* ESTRUTURA BÁSICA DE UM PROGRAMA EM C */
int main() {
    // ==============================================
    // 1. DECLARAÇÃO DE VARIÁVEIS
    // ==============================================
    int idade = 20;
    float peso = 65.5;
    char letra = 'A';
    double pi = 3.1415926535;
    
    // ==============================================
    // 2. ENTRADA E SAÍDA (printf e scanf)
    // ==============================================
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Você tem %d anos.\n", idade);
    
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
    // 4. LAÇOS DE REPETIÇÃO
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
    // 5. FUNÇÕES
    // ==============================================
    // Protótipo da função
    int quadrado(int num);
    
    // Chamando a função
    int resultado = quadrado(5);
    printf("O quadrado de 5 é: %d\n", resultado);
    
    // ==============================================
    // 6. VETORES E STRINGS
    // ==============================================
    int numeros[5] = {1, 2, 3, 4, 5};
    char nome[50] = "Maria";
    
    printf("Terceiro número: %d\n", numeros[2]);
    printf("Nome: %s\n", nome);
    
    // ==============================================
    // 7. EXEMPLO DE CALCULADORA
    // ==============================================
    float num1, num2;
    char operador;
    
    printf("\n=== CALCULADORA ===\n");
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    
    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &operador);
    
    printf("Digite o segundo número: ");
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
                printf("Erro: divisão por zero!\n");
            }
            break;
        default:
            printf("Operador inválido!\n");
    }
    
    system("pause");
    return 0;
}

// ==============================================
// DEFINIÇÃO DE FUNÇÕES
// ==============================================
int quadrado(int num) {
    return num * num;
}

/*
DICAS PARA O SIMULADO:

1. Sempre compile e teste seu código
2. Use printf para debug: printf("DEBUG: x = %d", x);
3. Se não souber completo, faça a parte que sabe
4. Leia as mensagens de erro do compilador
5. Formate seu código com indentação

CHECKLIST ANTES DE ENTREGAR:
[ ] 1. Meu código compila sem erros?
[ ] 2. Testei com diferentes valores?
[ ] 3. Verifiquei condições de borda?
[ ] 4. Coloquei system("pause") se necessário?
[ ] 5. Formatei o código corretamente?
*/

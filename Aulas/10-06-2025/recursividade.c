#include <stdio.h>
#include <string.h>

//--- Declarações das Funções Recursivas ---
int fatorial(int n);
int somaNaturais(int n);
int fibonacci(int n);
long potencia(int base, int expoente);
void inverterString(char *str, int tamanho);
int mdc(int a, int b);
int somaDigitos(int n);
int ehPrimo(int n);
int contarDigitos(int n);
int termoPA(int a1, int r, int n);

//--- Funções "Wrapper" para os exercícios (lidam com input/output) ---

void exercicio_fatorial()
{
    int num;
    printf("\n--- Exercicio 1: Fatorial ---\n");
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &num);
    if (num < 0)
    {
        printf("Erro: Fatorial nao definido para numeros negativos.\n");
    }
    else
    {
        printf("O fatorial de %d e: %d\n", num, fatorial(num));
    }
}

void exercicio_soma_naturais()
{
    int num;
    printf("\n--- Exercicio 2: Soma dos N primeiros numeros ---\n");
    printf("Digite um numero N: ");
    scanf("%d", &num);
    if (num < 0)
    {
        printf("Erro: Numero deve ser positivo.\n");
    }
    else
    {
        printf("A soma dos primeiros %d numeros naturais e: %d\n", num, somaNaturais(num));
    }
}

void exercicio_fibonacci()
{
    int num;
    printf("\n--- Exercicio 3: Sequencia de Fibonacci ---\n");
    printf("Digite o termo da sequencia de Fibonacci que deseja encontrar: ");
    scanf("%d", &num);
    if (num <= 0)
    {
        printf("Erro: O termo deve ser um numero positivo.\n");
    }
    else
    {
        printf("O termo %d da sequencia de Fibonacci e: %d\n", num, fibonacci(num));
    }
}

void exercicio_potencia()
{
    int base, expoente;
    printf("\n--- Exercicio 4: Potenciacao ---\n");
    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente (inteiro nao-negativo): ");
    scanf("%d", &expoente);
    if (expoente < 0)
    {
        printf("Erro: O expoente nao pode ser negativo para esta implementacao.\n");
    }
    else
    {
        printf("%d elevado a %d e: %ld\n", base, expoente, potencia(base, expoente));
    }
}

void exercicio_inverter_string()
{
    char str[100];
    printf("\n--- Exercicio 5: Inverter String ---\n");
    printf("Digite uma palavra ou frase: ");
    getchar(); // Consome o '\n' deixado pelo scanf anterior
    scanf("%[^\n]", str);
    printf("String invertida: ");
    inverterString(str, strlen(str));
    printf("\n");
}

void exercicio_mdc()
{
    int a, b;
    printf("\n--- Exercicio 6: MDC (Maximo Divisor Comum) ---\n");
    printf("Digite o primeiro numero: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);
    printf("O MDC de %d e %d e: %d\n", a, b, mdc(a, b));
}

void exercicio_soma_digitos()
{
    int num;
    printf("\n--- Exercicio 7: Soma dos Digitos ---\n");
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    printf("A soma dos digitos de %d e: %d\n", num, somaDigitos(num < 0 ? -num : num));
}

void exercicio_eh_primo()
{
    int num;
    printf("\n--- Exercicio 8: Verificar se e Primo ---\n");
    printf("Digite um numero para verificar: ");
    scanf("%d", &num);
    if (ehPrimo(num))
    {
        printf("%d e um numero primo.\n", num);
    }
    else
    {
        printf("%d nao e um numero primo.\n", num);
    }
}

void exercicio_contar_digitos()
{
    int num;
    printf("\n--- Exercicio 9: Contar Digitos de um Inteiro ---\n");
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    if (num == 0)
    {
        printf("O numero de digitos em 0 e: 1\n");
    }
    else
    {
        printf("O numero de digitos em %d e: %d\n", num, contarDigitos(num < 0 ? -num : num));
    }
}

void exercicio_pa()
{
    int a1, r, n;
    printf("\n--- Exercicio 10: Progressao Aritmetica ---\n");
    printf("Digite o primeiro termo (a1): ");
    scanf("%d", &a1);
    printf("Digite a razao (r): ");
    scanf("%d", &r);
    printf("Digite o termo (n) que deseja encontrar: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("O termo a ser encontrado deve ser positivo.\n");
    }
    else
    {
        printf("O %do termo da PA e: %d\n", n, termoPA(a1, r, n));
    }
}

//--- Função Principal com o Menu ---
int main()
{
    int opcao;
    do
    {
        printf("\n\n--- LISTA DE EXERCICIOS - RECURSIVIDADE ---\n");
        printf("1. Fatorial de um Numero\n");
        printf("2. Soma dos N primeiros numeros\n");
        printf("3. Sequencia de Fibonacci\n");
        printf("4. Potencia de um Numero\n");
        printf("5. Inverter uma String\n");
        printf("6. MDC (Maximo Divisor Comum)\n");
        printf("7. Somatorio dos Digitos de um Numero\n");
        printf("8. Verificar se um Numero e Primo\n");
        printf("9. Numero de Digitos de um Inteiro\n");
        printf("10. N-esimo Termo de uma Progressao Aritmetica\n");
        printf("0. Sair\n");
        printf("------------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            exercicio_fatorial();
            break;
        case 2:
            exercicio_soma_naturais();
            break;
        case 3:
            exercicio_fibonacci();
            break;
        case 4:
            exercicio_potencia();
            break;
        case 5:
            exercicio_inverter_string();
            break;
        case 6:
            exercicio_mdc();
            break;
        case 7:
            exercicio_soma_digitos();
            break;
        case 8:
            exercicio_eh_primo();
            break;
        case 9:
            exercicio_contar_digitos();
            break;
        case 10:
            exercicio_pa();
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

//--- Implementação das Funções Recursivas ---

// 1. Fatorial de um Número
int fatorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fatorial(n - 1);
}

// 2. Soma dos N primeiros números
int somaNaturais(int n)
{
    if (n == 0)
        return 0;
    else
        return n + somaNaturais(n - 1);
}

// 3. Sequência de Fibonacci
int fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// 4. Potência de um Número
long potencia(int base, int expoente)
{
    if (expoente == 0)
        return 1;
    else
        return base * potencia(base, expoente - 1);
}

// 5. Inverter uma String
void inverterString(char *str, int tamanho)
{
    if (tamanho == 0)
        return;
    printf("%c", str[tamanho - 1]);
    inverterString(str, tamanho - 1);
}

// 6. MDC (Máximo Divisor Comum) - Algoritmo de Euclides
int mdc(int a, int b)
{
    if (b == 0)
        return a;
    else
        return mdc(b, a % b);
}

// 7. Somatório dos Dígitos de um Número
int somaDigitos(int n)
{
    if (n == 0)
        return 0;
    else
        return (n % 10) + somaDigitos(n / 10);
}

// 8. Verificar se um Número é Primo (função auxiliar)
int ehPrimoAux(int n, int divisor)
{
    if (divisor == 1)
        return 1; // É primo
    else if (n % divisor == 0)
        return 0; // Não é primo
    else
        return ehPrimoAux(n, divisor - 1);
}

int ehPrimo(int n)
{
    if (n <= 1)
        return 0; // 0, 1 e negativos não são primos
    else
        // Inicia a verificação a partir de n/2 para otimizar
        return ehPrimoAux(n, n / 2);
}

// 9. Número de Digitos de um Inteiro
int contarDigitos(int n)
{
    if (n < 10)
        return 1;
    else
        return 1 + contarDigitos(n / 10);
}

// 10. Calcular o N-ésimo Termo de uma Progressão Aritmética
int termoPA(int a1, int r, int n)
{
    if (n == 1)
        return a1;
    else
        return r + termoPA(a1, r, n - 1);
}
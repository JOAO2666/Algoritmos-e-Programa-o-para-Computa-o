#include <stdio.h>

// Funcao f(x) = x^2 - 2x 
float func(float x)
{
    // CORRECAO: O 'X' maiusculo foi trocado por 'x' minusculo.
    return (x * x - 2 * x);
}

// Funcao primitiva F(x) = (x^3 / 3) - x^2 
float prim(float x)
{
    // CORRECAO: O 'X' maiusculo foi trocado por 'x' minusculo.
    return (x * x * x / 3.0 - x * x);
}

// Calcula a integral exata usando a primitiva: F(b) - F(a) 
float integral(float a, float b)
{
    return (prim(b) - prim(a));
}

// Calcula a area de um retangulo 
float areaRet(float l, float h)
{
    return (l * h);
}

int main()
{
    float a, b, pas;
    float soma_riemann = 0.0;
    float x;

    // Leitura dos limites de integracao (a, b) e do passo (pas) 
    printf("Digite os valores de a, b, pas: ");
    scanf("%f %f %f", &a, &b, &pas);

    // Verifica se o limite 'a' eh maior que 'b' 
    if (a > b)
    {
        printf("Erro: a > b\n");
    }
    else
    {
        // Laco para calcular a Soma de Riemann (aproximacao da area) 
        for (x = a; x < b; x = x + pas)
        {
            // A largura eh 'pas' e a altura eh 'func(x)'
            soma_riemann = soma_riemann + areaRet(pas, func(x));
        }

        // Imprime o valor exato da integral e o valor aproximado pela soma 
        // CORRECAO: O especificador de formato na segunda linha foi corrigido de "\eta n" para "\n"
        printf("Valor da Integral (Exato) = %.2f\n", integral(a, b));
        printf("Valor da Soma de Riemann (Aprox.) = %.2f\n", soma_riemann);
    }

    return 0;
}

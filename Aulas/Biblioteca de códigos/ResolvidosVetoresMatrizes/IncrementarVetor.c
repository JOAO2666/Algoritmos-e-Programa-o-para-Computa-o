#include <stdio.h>

void incrementar(float num[], int n, float valor)
{
    int i;
    for(i = 0; i < n; i++)
        num[i] = num[i] + valor;
}
int main()
{
    float numeros[10];
    int i;
    for(i = 0; i < 10; i++)
        scanf("%f", &numeros[i]);

    incrementar(numeros, 10, 1.5);

    for(i = 0; i < 10; i++)
        printf("%f ", numeros[i]);

    return 0;
}

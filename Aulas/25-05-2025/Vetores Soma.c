#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
int i, soma;
soma = 0;
int numeros[3];
numeros[0] = 20032;
numeros[1] = 2023;
numeros[2] = 10;
i = 0;
while (i < 3) {
	soma = soma + numeros[i];
	i = i + 1;
}
printf("%d", soma);
	return 0;
}

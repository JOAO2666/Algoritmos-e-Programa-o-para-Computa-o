#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void imprime(int *v) {
	int i;
	for ( i = 0; i < TAM; i++) {
		printf("v[%d] = %d\n", i,v[i]);
	}
}
int main() {
	int vetor[TAM];
	int i;
	for (i = 0; i < TAM; i++) {
		printf("Digite o elemento %d: ", i);
		scanf("%d", &vetor[i]);
	}
	imprime(vetor);
	return 0;
}

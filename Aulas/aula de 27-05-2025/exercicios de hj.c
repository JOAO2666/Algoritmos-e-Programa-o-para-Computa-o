#include <stdio.h>
#include <stdlib.h>
#define TAM 10

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void imprime (int v[]) {
	int i;
	for (i = 0; i < TAM; i++) {
		printf(" v[%d] = %d\n", i,v[i]);
	}
}
int main(int argc, char *argv[]) {
	int vetor [TAM];
	int i;
	for (i = 0; i < TAM; i++) {
		printf("Digite o elemento %d: ",i);
		scanf("%d",&vetor[i]);
	}
	imprime(vetor);	
	return 0;
}

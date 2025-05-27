#include<stdio.h> 


int somar_vetor_v1(int v[], int tamanho) {
	int soma = 0;
	for( int i = 0; i < tamanho; i++) {
		soma += v[i];
	}
	return soma;
}

int main () {
	int meus_numeros[] = {10,20,30,40,50};
	int tamanho = sizeof(meus_numeros) / sizeof(meus_numeros[0]);
	
	int resultado1 = somar_vetor_v1(meus_numeros, tamanho);
	printf("Soma (versão 1): %d\n", resultado1); 
	return 0;
}

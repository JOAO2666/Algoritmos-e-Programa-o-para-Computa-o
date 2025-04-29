#include <stdio.h>

int main () {
	int i;
	int numeros [3];
	for (i = 0; i < 3; i++){
		printf("Entre um numero> ");
		scanf("%d", &numeros[i]);
		
	}
	
	for (i = 0; i < 3; i++) {
		printf("Numero: %d\n", numeros[i]);
	}
	
	return 0;
} 

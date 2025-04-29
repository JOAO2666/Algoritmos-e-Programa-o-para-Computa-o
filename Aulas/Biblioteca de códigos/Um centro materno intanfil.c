#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float peso_gestacao;
	int qtd_semanas;
	int meses;
	
	printf("Quantos gramas o feto tem na gestacao: ");
	scanf("%f", &peso_gestacao);
	
	printf("Quantas semanas tem a gestaçao: ");
	scanf("%d", &qtd_semanas);
	
	if (peso_gestacao < 100 || qtd_semanas < 28) {
		printf("O parto nao devera ser ralizado, reavaliar clinicamente!!");
	}
	
	meses = qtd_semanas / 4;
	
	if (peso_gestacao > 2500 && meses > 7) {
		printf("Parto Normal!!");
	}
	if (peso_gestacao > 2500 && meses <= 7) {
		printf("Parto Cesariana!!");
	}
	if (peso_gestacao >= 1500 && peso_gestacao <= 2000 && meses > 9) {
		printf("Parto Normal!!");
	}
	else {
		printf("Parto Cesariana!!");
	}
	
	return 0;
}


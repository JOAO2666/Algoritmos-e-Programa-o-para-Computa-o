#include <stdio.h>

int main () {
	float notas[3], soma, media;
	int i, acimaDaMedia;
	soma = 0;
	for (i = 0; i < 3; i++) {
	    printf("Entre a nota: ");
		scanf("%f", &notas[i]);
		soma = soma + notas[i];
	}
	media = soma / 3;
	acimaDaMedia = 0;
	for (i = 0; i < 3; i++) {
		if (notas[i] > media) { 
			acimaDaMedia = acimaDaMedia + 1;
	
		}
	}
    printf("Meda : %.2f\n", media);
    printf("Acima da media: &d", acimaDaMedia);
    return 0;
} 

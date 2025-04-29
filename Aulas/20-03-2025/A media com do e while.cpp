#include <stdio.h>

int main ()
{
	float nota1,nota2,nota3, media;
	char digito;
	
	do {
		
		printf("Digite as tres notas do aluno: ");
		scanf("%f %f %f", &nota1, &nota2, &nota3);
		
		media = (nota1 + nota2 + nota3)/3;
		
		printf("A media eh: %f\n", media);
		
		printf("continuar? (s/n):");
		scanf("%c",&digito);
	} while (digito == 's');

	return 0;
}

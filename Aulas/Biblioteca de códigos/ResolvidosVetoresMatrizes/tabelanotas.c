#include <stdio.h>

int main() {
	float nota1, nota2, nota3, media;
	float max1=0, max2=0, max3=0, maxmedia=0;
	char c;
	int i=1;

	do {
		printf("Digite as notas do %do aluno:", i);

		scanf("%f%f%f", &nota1, &nota2, &nota3);
		media = (nota1 + nota2 + nota3)/3;

        if (nota1>max1)
            max1 = nota1;
        if (nota2>max2)
            max2 = nota2;
        if (nota3>max3)
            max3 = nota3;
        if (media>maxmedia)
            maxmedia = media;

		i++;
		printf("Deseja continuar (s/n)?");
		scanf(" %c", &c);
	} while (c=='s');

    printf("\n| 1o Ex  | 2o Ex  | 3oEx  | Media |\n");
    printf("| Maior  | Maior  | Maior | Maior |\n");
    printf("| %.2f   | %.2f   | %.2f  | %.2f  |\n", max1, max2, max3, maxmedia);
	return 0;
}

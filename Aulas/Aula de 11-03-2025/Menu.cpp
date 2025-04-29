#include <stdio.h>
int main () {
int opcao;
opcao = 1;
while (opcao !=3){
	printf ("Menu\n");
	printf ("1. Oi\n");
	printf ("2. Ola\n");
	printf ("3. Tchau\n");
	printf ("Dgite sua opcao: ");
	scanf ("%d", &opcao);
	if (opcao == 1) {
		printf ("Oi\n\n");
	}
	if (opcao == 2) {
		printf ("Ola\n\n");
	}
	if (opcao == 3) {
		printf ("Tchau");
	}
}
return 0;
}

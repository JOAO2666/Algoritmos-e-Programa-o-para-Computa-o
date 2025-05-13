#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *p;
	p = fopen ("arquivo.txt", "w");
	if (p == NULL) {
		printf("Erro na criacao!\n");
	}	
	else {
	printf("Criacao com sucesso!\n");
	fclose(p);
}
	
	return 0;
}

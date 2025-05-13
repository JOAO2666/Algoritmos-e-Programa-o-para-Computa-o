#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct ponto {
	float x;
	float y;
}P;
int main () {
	P p1 = {1.0, 3.0};
	P p2 = {2.0, 4.0};
	FILE* p;
	p = fopen("arquivo.bin", "wb");
	if (p == NULL) {
		printf("Erro ao criar arquivo\n");
	}
	else {
		fwrite(&p1,sizeof(p1), 1, p);
		fwrite(&p2,sizeof(p2),1,p);
		fclose(p);
	}
	
	return 0;
}

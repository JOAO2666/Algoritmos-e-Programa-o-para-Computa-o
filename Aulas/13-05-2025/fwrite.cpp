#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *p;
	int x;
	x = 14;
	p = fopen ("arquivo.bin"," wb");
	if (p == NULL) {
		printf("Erro na criar arquivo!\n");
	}	
	else {
	fwrite(&x, sizeof(x),1,p);
	fclose(p);
}
	
	return 0;
}

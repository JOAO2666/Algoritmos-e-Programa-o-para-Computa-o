#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
		for (i=0; i<256; i++) {
			printf("O codigo ASCII DE '%C'  eh %d\n",i,i);
		}
	
	return 0;
}

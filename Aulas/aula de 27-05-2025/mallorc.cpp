#include <stdio.h>
#include <stdlib.h>

int main () {
	int *p;
	p = (int *) malloc(sizeof(int));
	
	if (p != NULL) {
		*p = 30;
		printf("O valor armazenado em p �: %d\n", *p);
		
		free(p);
		p = NULL;
	} else {
		printf("Falha ao colocar mem�ria!\n");
	} 
	
	return 0;
}

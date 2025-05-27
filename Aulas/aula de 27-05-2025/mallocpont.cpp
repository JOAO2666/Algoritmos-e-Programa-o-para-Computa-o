#include <stdio.h>
#include <stdlib.h>

int main () {
	int *p;
	printf("p antes do malloc = %p\n", (void *)p);
	
	p = (int *) malloc(sizeof(int));
	
	printf("p depois do malloc = %p\n", (void *)p);
	
	
	if (p != NULL) {
	
		printf("Erro ao alocar memoria!\n");
		return 1;
}
	*p = 30;
	
	printf("*p = %d\n", *p);
	
	free(p); 
	
	return 0;
}

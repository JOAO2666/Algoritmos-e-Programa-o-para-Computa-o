#include <stdio.h>
#include <stdlib.h>

int f (int argumento) {
	int resultado;
	resultado = 2 * argumento;
	return resultado;

}
int main () {
	int x, dobro;
	printf("Entre x: ");
	scanf("%d", &x);
	dobro = f (x);
	printf("%d", dobro);
	return 0;
}

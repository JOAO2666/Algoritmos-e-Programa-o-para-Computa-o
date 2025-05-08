#include <stdio.h>
#include <stdlib.h>
void troca (int a, int b) {
	int aux;
	aux = a;
	a = b;
	b = aux;
}

int main(int argc, char *argv[]) {
	int x, y;
   printf("Digite 2 numeros: ");
   scanf("%d %d", &x, &y);
   troca(x,y);
   printf("x = &d, y = %d", x, y);
    return 0;
}

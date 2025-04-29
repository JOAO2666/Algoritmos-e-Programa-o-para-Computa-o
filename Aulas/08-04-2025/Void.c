#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int dobro (int x);

int main(int argc, char *argv[]) {
	int n,d;
	printf("Entre n: ");
	scanf("%d", &n);
	d = dobro (n);
	printf("%d\n", d);
	return 0;
}

int dobro (int x) {
	x = 2 * x;
	return x;
}

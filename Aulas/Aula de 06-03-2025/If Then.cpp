#include<stdio.h>
int main () {
int x, y, maior;
printf("Entre 2 numeros: ");
scanf("%d %d", &x,&y);
if (y >= x) {
	maior = y;
}
	if (x >= y) {
	maior = x;
}
printf("Maior = %d\n", maior);
return 0;
}

#include <stdio.h>

int main()
{
	float num,media,soma=0;
	int i,n;
	printf("Digite o maximo de entradas: ");
	scanf("%d",&n);
	
	for(i=1; i<n; i++) {
		printf("Entre o valor %d (-1 para finalizar): ",i);
		scanf("%f", &num);
		if(num<0.0) break;
		soma=soma+num;
	}
	media=soma/(i-1);
	printf("Media = %f\n", media);
}

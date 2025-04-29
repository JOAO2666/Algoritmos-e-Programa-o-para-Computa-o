#include <stdio.h>

int main ()
{
	int i, num,produto;
	for(i=1,produto=1; i<=5; i++){
		printf("Entre o valor %d:,i");
		scanf("%d",&num);
		
		if(num==0) continue;
		produto*=num;
		printf("Produto parcial: %d\n",produto);
	}
	printf("Produto final: %d\n, produto");
}

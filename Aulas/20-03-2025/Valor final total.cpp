#include <stdio.h>

int main()
{
   	int i, j;
	int total=0;

	for (i=0; i<2; i++) {
		for (j=0; j<3; j++) {
			total = total + 1;
			printf("i: %d j: %d total: %d\n",i,j, total);
        }
	}		
   printf("O valor final de total e: %d\n", total);
}

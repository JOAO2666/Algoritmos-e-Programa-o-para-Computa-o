#include <stdio.h>

int main()
{
    int vetor[100];
    int i;

    for (i=0; i<100; i++) {

        if (i%2==0)
            vetor[i] = 0;
        else
            vetor[i] = 1;
    }

    for (i=0; i<100; i++)
        printf("vetor[%d] = %d\n", i, vetor[i]);

    return 0;
}

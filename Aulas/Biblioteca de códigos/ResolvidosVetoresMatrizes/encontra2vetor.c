#include <stdio.h>
#include <stdlib.h>

int *encontra2(int *p1, int *p2) {

    while (p1<=p2) {
        if (*p1 == 2)
            return p1;
        p1++;
    }

    return NULL;
}

int main()
{
    int vet[10] = {1,2,3,4,2,4,5,6,2,0};
    int *p;

    p = encontra2(&vet[0], &vet[9]);
    while (p!=NULL) {
        printf("Endereco: %d, valor = %d\n", p, *p);
        p = encontra2(p+1, &vet[9]);
    }
    return 0;
}

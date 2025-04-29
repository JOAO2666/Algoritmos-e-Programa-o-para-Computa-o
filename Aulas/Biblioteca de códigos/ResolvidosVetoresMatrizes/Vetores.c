#include <stdio.h>

int aprovado(float nota, float media)
{
    int resultado = 0;
    if ( nota >= media)
        resultado = 1;
    return resultado;
}
int main()
{
    float notas[] = {6.5,5.0,7.5,9.4,3.8};
    int i ;
    for(i = 0; i < 5; i++)
    {
        if (aprovado(notas[i],7.0) == 1)
            printf("Aluno %d: aprovado\n",i);
        else
            printf("Aluno %d: REPROVADO\n",i);
    }
}

/*
void incrementar(float num[], int n, float valor)
{
    int i;
    for(i = 0; i < n; i++)
        num[i] = num[i] + valor;
}
int main()
{
    float numeros[10];
    int i ;
    for(i = 0; i < 10; i++)
        scanf("%f", &numeros[i]);

    incrementar(numeros, 10, 1.5);

    for(i = 0; i < 10; i++)
        printf("%f ", numeros[i]);

    return 0;
}

/*
float media(int n, float num[])
{
    int i;
    float s = 0.0;
    for(i = 0; i < n; i++)
        s = s + num[i] ;
    return s/n ;
}

int main()
{
    float numeros[10] ;
    float med;
    int i ;
    for(i = 0; i < 10; i++)
        scanf (“%f”, &numeros[i]) ;
    med = media(10, numeros ) ;
    ...
}


#define TOTAL_ALUNOS 10

int main()
{
    float nota[TOTAL_ALUNOS];
    float soma = 0;
    int i;

    for (i = 0; i < TOTAL_ALUNOS; i++) {
        printf("Entre com a %da. nota: ", (i + 1));
        scanf("%f", &nota[i]);
        soma = soma + nota[i];
    }
    printf("Média da disciplina = %f", soma/TOTAL_ALUNOS);
    return 0;
}


int main() {
    int pares[20];
    int i, somaPares = 0;
    for (i = 0; i <= 20; i++)     {
        pares[i] = 2 * i ;
        somaPares = somaPares + pares[i];
    }
    ...
}

    int v[]= {5,10,15,20,25};

    int  nAlunos = 10;
    printf ("entre com o número de alunos");
    scanf ("%d", &nAlunos); 
    int  notas[nAlunos];
    ...


int main()
{
    int i, vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (i = 0; i < 10; i++) {
        printf("%d\n", vetor[i]);
    }
    return 0;
}



int main()
{
    float nota[5];
    float soma = 0;
    int i;

    for (i = 0; i < 5; i++) {
        printf("Entre com a %da. nota: ", (i + 1));
        scanf("%f", &nota[i]);
        soma = soma + nota[i];
    }
    printf("Média da disciplina = %f", soma/5);
}


int main()
{
    float  nota1, nota2, nota3, nota4, nota5;
    printf("Entre com a 1a. nota:");
    scanf("%f", &nota1);
    printf("Entre com a 2a. nota:");
    scanf("%f", &nota2);
    printf("Entre com a 3a. nota:");
    scanf("%f", &nota3);
    printf("Entre com a 4a. nota:");
    scanf("%f", &nota4);
    printf("Entre com a 5a. nota:");
    scanf("%f", &nota5);
    printf("Média = %f",(nota1+nota2+nota3+nota4+nota5)/5);
}

*/

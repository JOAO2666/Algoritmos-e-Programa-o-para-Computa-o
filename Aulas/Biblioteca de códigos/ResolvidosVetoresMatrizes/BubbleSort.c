
void bubbleSort(int vetor[], int n) {
  int d, swap, trocou;

  do
  {
    trocou = 0;
    for (d = 0 ; d < n-1; d++)
    {
      if (vetor[d] > vetor[d+1]) // Utilize "<" para ordem crescente
      {
        swap       = vetor[d];
        vetor[d]   = vetor[d+1];
        vetor[d+1] = swap;
        trocou = 1;
      }
    }
  } while (trocou);
}

int main()
{
  int vetor[100], i, n;

  printf("Informe a quantidade de elementos (maximo 100): ");
  scanf("%d", &n);
  if (n>100) n = 100;

  printf("Digite %d inteiros:\n", n);

  for (i = 0; i < n; i++)
    scanf("%d", &vetor[i]);

  bubbleSort(vetor, n);

  printf("Valores ordenados:\n");

  for (i = 0 ; i < n ; i++ )
     printf("%d ", vetor[i]);

  return 0;
}

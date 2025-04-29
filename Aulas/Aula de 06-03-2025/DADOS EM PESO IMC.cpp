#include <stdio.h>
#include <string.h>
#define texto "Entrada e saida de dados."

int main() {
    printf("%s\n", texto);
    
    int idade = 0;
    float altura, peso, imc;
    char nome[50] = "";
    
    printf("Digite a idade:\n");
    scanf("%d", &idade);
    
    printf("Digite a altura:\n");
    scanf("%f", &altura);
    
    printf("Digite o peso:\n");
    scanf("%f", &peso);
    
    imc = eso / (altura * altura);
    printf("%f", imc);
        
   getchar();
    
    printf("Digite o nome:\n");
    fgets(nome, 50, stdin);
    
    nome[strcspn(nome, "\n")] = '\0';
    
    printf("Dados informados:\n");
    printf("Idade: %d.\n", idade);
    printf("altura: %.2f.\n", altura);
    printf("Nome: %s.\n", nome);
    printf("peso: %f.\n", peso);
    

    return 0;
}

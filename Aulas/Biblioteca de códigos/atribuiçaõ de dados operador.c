#include <stdio.h>
#include <string.h>
#define texto "Entrada e saida de dados."

int main() {
    printf("%s\n", texto);
    
    int idade = 0;
    float altura = 0.0;
    char nome[50] = "";
    
    printf("Digite a idade:\n");
    scanf("%d", &idade);
    
    printf("Digite a altura:\n");
    scanf("%f", &altura);
    
    getchar();
    
    printf("Digite o nome:\n");
    fgets(nome, 50, stdin);
    
    nome[strcspn(nome, "\n")] = '\0';
    
    printf("Dados informados:\n");
    printf("Idade: %d.\n", idade);
    printf("Altura: %.2f.\n", altura);
    printf("Nome: %s.\n", nome);
    
    return 0;
}

#include <stdio.h>

int main() {
   
    int idade;
    float renda;
    char sexo;
    
 
    int total = 0;
    int mulheres = 0;
    int maior_idade = 0;
    float soma_renda = 0;
    

    int idade_maxima = 60;
    
   
    float proporcao_mulheres;
    float media_renda;
    
    printf("SISTEMA DE CENSO\n");
    printf("Digite idade negativa para encerrar\n\n");
    
  
    while (1) {
        printf("Pessoa %d\n", total + 1);
      
        printf("Digite a idade: ");
        scanf("%d", &idade);
        
      
        if (idade < 0) {
            break;
        }
        
       
        if (idade > idade_maxima) {
            printf("Idade muito alta! Máximo: %d\n", idade_maxima);
            continue;
        }
        
      
        printf("Digite a renda: ");
        scanf("%f", &renda);
        
        
        printf("Digite o sexo (M ou F): ");
        scanf(" %c", &sexo);
        
       
        if (sexo == 'm') sexo = 'M';
        if (sexo == 'f') sexo = 'F';
        
    
        if (sexo != 'M' && sexo != 'F') {
            printf("Sexo inválido! Digite novamente.\n");
            continue;
        }
        
       
        total++;
        
        if (sexo == 'F') {
            mulheres++;
        }
        
        if (idade > maior_idade) {
            maior_idade = idade;
        }
        
        soma_renda += renda;
        
        printf("Pessoa cadastrada!\n\n");
    }
    
    
    proporcao_mulheres = 0;
    if (total > 0) {
        proporcao_mulheres = (float)mulheres / total;
    }
    
    /* Calcula a média da renda */
    media_renda = 0;
    if (total > 0) {
        media_renda = soma_renda / total;
    }
    
    /* Mostra os resultados DAS PESSOAS*/
    printf("\nRESULTADOS:\n");
    printf("a) Total de pessoas: %d\n", total);
    printf("b) Proporção de mulheres: %.2f\n", proporcao_mulheres);
    printf("c) Maior idade: %d\n", maior_idade);
    printf("d) Média da renda: R$ %.2f\n", media_renda);
    
    return 0;
}

#include <stdio.h>

int main() {
    int bit,opcao;resposta
    
	printf("\n=== Show do Milhao ===\n");
    printf(" Para perguntas sobre História digite 1 n");
	printf(" Para perguntas sobre Matemática digite 2 n");
	printf(" Para perguntas sobre Ciências digite 3 n");
	
	printf(" Digite sua opção");
	scanf("%d", &opcao,&resposta);
	
    switch (opcao) {
    	case 1:
           printf(" Quem foi o primeiro presidente do Brasil?");
	       printf(" Getúlio vagas 1 n");
		   printf(" Floriano Peixoto 2");
	       printf(" marechal Deodoro Fonseca 3");
	  	      scanf("%d", &resposta);
            
            switch (resposta) {
				 case 1:
				 	printf(" Parabéns vc acertou");
				 break;
				 case 2:
				 	printf(" Vc errou");
				 break;
				 case 3:
				 	printf(" Parabéns vc acertou");
				 break;
				 
				 
		 Case 2:
			printf("\n======MATEMÁTICA====\n");
			printf("Quanto é 364 x 652?");
			printf("29323 1");
			printf("2373287	2");
			printf("212312 3");
		 	scanf("%d", &resposta);
            
            switch (resposta) {
				 	case 1:
				 		printf(" vc errou");
				 	break;
					case 2:
				 		printf(" Parabéns vc acertou");
					break;
					case 3:
				 		printf(" Parabéns vc acertou");
				 	break;
				
		Case 3:
			printf("\n======Ciências=====\n");
			printf("A polinização, que viabiliza o transporte do grão de pólen de uma planta até o estigma de outra e ela é feita por qual inseto?");
			printf("Anthophila 1");
			printf("Chiroptera 2");
			printf("Canis lupus 3");
		 	scanf("%d", &resposta);
            
            switch (resposta) {
				 	case 1:
				 		printf(" vc acertou");
				 	break;
					case 2:
				 		printf(" errou vc errou");
					break;
					case 3:
				 		printf(" vc errou");
				 	break;		
     default:
            printf("\nOpcao! Por favor, escolha entre 1, 2 ou 3.\n");
            break;
    }
    
    printf("\nObrigado por jogar Show do Milhao!\n");

    return 0;

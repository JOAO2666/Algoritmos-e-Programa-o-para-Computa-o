#include <stdio.h>

int main() {
    int bit,opcao;resposta
    
	printf("\n=== Show do Milhao ===\n");
    printf(" Para perguntas sobre Hist�ria digite 1 n");
	printf(" Para perguntas sobre Matem�tica digite 2 n");
	printf(" Para perguntas sobre Ci�ncias digite 3 n");
	
	printf(" Digite sua op��o");
	scanf("%d", &opcao,&resposta);
	
    switch (opcao) {
    	case 1:
           printf(" Quem foi o primeiro presidente do Brasil?");
	       printf(" Get�lio vagas 1 n");
		   printf(" Floriano Peixoto 2");
	       printf(" marechal Deodoro Fonseca 3");
	  	      scanf("%d", &resposta);
            
            switch (resposta) {
				 case 1:
				 	printf(" Parab�ns vc acertou");
				 break;
				 case 2:
				 	printf(" Vc errou");
				 break;
				 case 3:
				 	printf(" Parab�ns vc acertou");
				 break;
				 
				 
		 Case 2:
			printf("\n======MATEM�TICA====\n");
			printf("Quanto � 364 x 652?");
			printf("29323 1");
			printf("2373287	2");
			printf("212312 3");
		 	scanf("%d", &resposta);
            
            switch (resposta) {
				 	case 1:
				 		printf(" vc errou");
				 	break;
					case 2:
				 		printf(" Parab�ns vc acertou");
					break;
					case 3:
				 		printf(" Parab�ns vc acertou");
				 	break;
				
		Case 3:
			printf("\n======Ci�ncias=====\n");
			printf("A poliniza��o, que viabiliza o transporte do gr�o de p�len de uma planta at� o estigma de outra e ela � feita por qual inseto?");
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

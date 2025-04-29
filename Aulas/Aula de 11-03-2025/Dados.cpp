#include<stdio.h>
int main() {
	int senha, tentativas;
	senha = 123;
	tentativas = 0;
	printf("Digite a senha de 6 digitos: ");
	while ((senha < 10000 || senha > 999999) && tentativas < 3) {
		scanf("%d",&senha);
		tentativas = tentativas + 1;
		if (senha < 10000 || senha > 999999) {
		printf("A senha deve ter 6 digitos.\n");
		if (tentativas ==3) {
			printf("Máximo de 3 tentativas realizadas.");
		}
		else {
			printf("Digite novamente: ");
		}
	}
}
return 0;
}

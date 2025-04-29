#include <stdio.h>

int main() {
   
    int campeao;
    char golpe;
    int dano_total = 0;
    int golpes_q = 0;
    int usos_teemo = 0;
    int usos_braum = 0;
    int round; 
    
    printf("JOGO LIGA DAS LENDAS");
    

    for (round = 1; round <= 5; round++) {
        printf("ROUND %d\n", round);
        
       
        printf("Escolha seu campeão:\n");
        printf("1 - Teemo\n");
        printf("2 - Ashe\n");
        printf("3 - Braum\n");
        printf("Digite (1-3): ");
        scanf("%d", &campeao);
        
        if (campeao < 1 || campeao > 3) {
            printf("Campeão inválido! Usando Teemo.\n");
            campeao = 1;
        }
       
        if (campeao == 1) {
            usos_teemo++;
        }
        else if (campeao == 3) {
            usos_braum++;
        }
        
        printf("Digite o golpe (Q, W, E ou R): ");
        scanf(" %c", &golpe);
     
        if (golpe >= 'a' && golpe <= 'z') {
            golpe = golpe - 32;  
        }
        
      
        int dano = 0; 
        
        if (golpe == 'Q') {
            dano = 10;
            golpes_q++;
        }
        else if (golpe == 'W') {
            dano = 50;
        }
        else if (golpe == 'E') {
            dano = 100;
        }
        else if (golpe == 'R') {
            printf("Golpe R encerra o round sem dano.\n");
        }
        else {
            printf("Golpe inválido! Sem dano.\n");
        }
        
       
        dano_total += dano;
        
        printf("Dano neste round: %d\n\n", dano);
    }
    
    
    float proporcao_braum = (float)usos_braum / 5;
    
   
    int dano_golpe_q = golpes_q * 10;
    
    
    printf("RESULTADOS FINAIS:\n");
    printf("a) Dano total: %d\n", dano_total);
    printf("b) Dano total do golpe Q: %d\n", dano_golpe_q);
    printf("c) Golpes do campeão Teemo: %d\n", usos_teemo);
    printf("d) Proporção de uso do Braum: %.2f\n", proporcao_braum);
    
    return 0;
}

#include <stdio.h>
#include <conio.h>

int main() {
    int d1, m1, a1;
    int d2, m2, a2;
    
    printf("Digite a primeira data: ");
    scanf("%d %d %d", &d1, &m1, &a1);
    
    if ((d1 > 0) && (d1 < 32) && (m1 > 0) && (m1 < 13) && (a1 > 0) && (a1 < 2012)) {
        printf("Digite a segunda data: ");
        scanf("%d %d %d", &d2, &m2, &a2);
        
        if ((d2 > 0) && (d2 < 32) && (m2 > 0) && (m2 < 13) && (a2 > 1900) && (a2 < 2012)) {
            if (a1 > a2)
                printf("A maior data eh: %d/%d/%d", d1, m1, a1);
            else if (a2 > a1)
                printf("A maior data eh: %d/%d/%d", d2, m2, a2);
            else if (m1 > m2)
                printf("A maior data eh: %d/%d/%d", d1, m1, a1);
            else if (m2 > m1)
                printf("A maior data eh: %d/%d/%d", d2, m2, a2);
            else if (d1 > d2)
                printf("A maior data eh: %d/%d/%d", d1, m1, a1);
            else if (d2 > d1)
                printf("A maior data eh: %d/%d/%d", d2, m2, a2);
            else
                printf("A duas datas sao iguais!");
        }
        else 
            printf("Segunda data invalida");
    }
    else 
        printf("Primeira data invalida");
    
    getch();
    return 0;
}

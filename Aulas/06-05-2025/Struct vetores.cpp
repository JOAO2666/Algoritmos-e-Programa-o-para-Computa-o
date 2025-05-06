#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct coord { 
    int x, y;
};

void zera(struct coord c[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        c[i].x = 0;
        c[i].y = 0;
    }
}


int main() {
    struct coord v[3];
    zera(v, 3);
    return 0;
}

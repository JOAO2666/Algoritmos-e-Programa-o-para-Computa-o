#include <stdio.h>
float metade(float x) {
 return (x/2);
}
int main() {
 float x, calculo;
 x = 32;
 calculo = metade(metade(metade(x)));
 printf("calculo = %.2f",calculo);
 return 0;
}

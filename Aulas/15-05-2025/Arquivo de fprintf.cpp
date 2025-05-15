#include<stdio.h>
int main() {
 FILE *p;
 int i;
 p = fopen("arquivo.txt","w");
 if (p == NULL) {
 printf("Erro na criacao!\n");

}
 else {
 i = 14;
 fprintf(p,"%d",i);
 fclose(p);

}
 return 0; }

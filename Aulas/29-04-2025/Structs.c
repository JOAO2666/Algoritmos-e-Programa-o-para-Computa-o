#include <stdio.h>
#include <stdlib.h>

struct socio {  // defina um novo tipo de chamada struc socio
    int mat;    // Matr�cula
    int id;     // Idade
    float alt;  // Altura
};

int main() {
    struct socio s; // cria uma vari�vel's' do tipo 'struct socio'
    
    printf("Entre a matricula, idade e altura: ");  //L� tres valores do usu�rio e armazena nos campos da struct
    scanf("%d %d %f", &s.mat, &s.id, &s.alt);  // Corrigido aqui
    
    // Exibe os valores armazenados na struct
    printf("Matricula: %d\n", s.mat);
    printf("Idade: %d\n", s.id);
    printf("Altura: %.2f", s.alt);

    return 0;
}

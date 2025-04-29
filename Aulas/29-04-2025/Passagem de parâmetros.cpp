#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Adicionado para usar strcpy

struct pessoa {
    char nome[4]; // Array de caracteres com tamanho 4 (3 letras + '\0')
};

// Função que modifica o nome na struct
struct pessoa salva_nome(struct pessoa p) {  // Corrigido o nome da função
    strcpy(p.nome, "ABC"); // Corrigido a sintaxe do strcpy
    return p; // Corrigido "retun" para "return"
}

int main() {
    struct pessoa p;
    strcpy(p.nome, "XYZ"); // Inicializa o nome com "XYZ"
    
    p = salva_nome(p); // Corrigido "P" para "p" (case-sensitive)
    
    printf("%s", p.nome); // Imprimirá "ABC"
    return 0;
}

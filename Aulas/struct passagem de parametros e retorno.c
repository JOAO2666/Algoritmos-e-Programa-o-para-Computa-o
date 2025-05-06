#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

void exibirAluno(struct Aluno aluno) {
    printf("Nome: %s, Idade: %d, Nota: %.2f\n", aluno.nome, aluno.idade, aluno.nota);
    aluno.nota = 10.0; // Altera a cópia, não o original
}

int main() {
    struct Aluno aluno1;
    strcpy(aluno1.nome, "João");
    aluno1.idade = 20;
    aluno1.nota = 8.5;

    exibirAluno(aluno1);
    printf("Nota original após função: %.2f\n", aluno1.nota); // Continua 8.5

    return 0;
}

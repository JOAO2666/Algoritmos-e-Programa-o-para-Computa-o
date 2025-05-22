#include <stdio.h>
#include <stdlib.h> // Geralmente incluído para system("pause") ou exit()

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct ponto {
    float x;
    float y;
} P; // Define um tipo P que é uma struct ponto

int main () {
    P pto; // Declara uma variável 'pto' do tipo P (struct ponto)
    FILE* p = fopen("arq_vetor.bin", "rb"); // Tenta abrir o arquivo "arq_vetor.bin" para leitura binária ("rb")

    if (p == NULL) { // Verifica se o arquivo foi aberto com sucesso
        printf("Erro ao abrir o arquivo!\n"); // Se p for NULL, o arquivo não pôde ser aberto
        // return 1; // É uma boa prática retornar um valor diferente de 0 em caso de erro
    } else { // Se o arquivo foi aberto com sucesso
        printf("Arquivo aberto com sucesso! Lendo o conteúdo:\n");
        // Loop para ler o arquivo enquanto fread retornar 1 (leu 1 estrutura)
        while (fread(&pto, sizeof(P), 1, p) == 1) {
            // &pto: endereço da variável onde os dados lidos serão armazenados
            // sizeof(P): tamanho de uma estrutura P (quantos bytes ler)
            // 1: número de itens desse tamanho a serem lidos
            // p: ponteiro para o arquivo
            printf("(%.2f, %.2f)\n", pto.x, pto.y); // Imprime as coordenadas x e y do ponto lido
        }

        rewind(p); // Reposiciona o ponteiro do arquivo para o início do arquivo

        printf("\nrewind() executado! Lendo o arquivo de novo:\n");
        // Loop para ler o arquivo novamente desde o início
        while (fread(&pto, sizeof(P), 1, p) == 1) {
            printf("(%.2f, %.2f)\n", pto.x, pto.y); // Imprime as coordenadas
        }

        fclose(p); // Fecha o arquivo, liberando os recursos
        printf("\nArquivo fechado.\n");
    }
    return 0; // Indica que o programa terminou com sucesso
}

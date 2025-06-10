#include <stdio.h>
#include <string.h>

// Estruturas de dados fornecidas
typedef struct pais {
    int codPais;
    char nome[30], sigla[3];
} TPais;

typedef struct atleta {
    char nome[50];
    int medOuro, medPrata, medBronze;
    int codPais;
} TAtleta;

typedef struct relatorio {
    char nomeP[30], nomeA[50];
    int numMed;
} TRelatorio;

int main(void) {
    FILE *a, *p, *r;
    TPais tp;
    TAtleta ta;
    TRelatorio tr;
    int med_total;

    // Abre os arquivos de leitura ("rb") e escrita ("wb")
    a = fopen("atletas.bin", "rb");
    p = fopen("pais.bin", "rb");
    r = fopen("relatorio.bin", "wb");

    if (a == NULL || p == NULL || r == NULL) {
        printf("Erro na abertura dos arquivos!\n");
        return 1;
    }

    // Para cada país no arquivo pais.bin...
    while (fread(&tp, sizeof(TPais), 1, p) > 0) {
        tr.numMed = -1; // Inicia o contador de medalhas do melhor atleta como -1 
        rewind(a); // Volta ao início do arquivo de atletas para cada país 

        // ...percorre todo o arquivo de atletas para encontrar o melhor
        while (fread(&ta, sizeof(TAtleta), 1, a) > 0) {
            // Verifica se o atleta pertence ao país atual
            if (tp.codPais == ta.codPais) {
                med_total = ta.medOuro + ta.medPrata + ta.medBronze;

                // Se o total de medalhas deste atleta for maior que o melhor atual...
                if (med_total > tr.numMed) {
                    // ...atualiza os dados do melhor atleta
                    tr.numMed = med_total;
                    strcpy(tr.nomeP, tp.nome); // strcpy copia uma string para outra 
                    strcpy(tr.nomeA, ta.nome);
                }
            }
        }

        // Após verificar todos os atletas para um país, se um melhor foi encontrado,
        // escreve o registro no arquivo de relatório.
        if (tr.numMed != -1) {
            fwrite(&tr, sizeof(TRelatorio), 1, r);
        }
    }

    // Fecha todos os arquivos após o término dos laços
    fclose(a);
    fclose(p);
    fclose(r);
    
    printf("Relatorio 'relatorio.bin' gerado com sucesso.\n");

    return 0;
}

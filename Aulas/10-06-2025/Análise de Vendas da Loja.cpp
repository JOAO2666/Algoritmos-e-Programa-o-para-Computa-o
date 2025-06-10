#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estruturas de dados para Produto e Nota Fiscal
struct Produto {
    int cod_produto;
    char nome[30];
    float custo;
};

struct NotaFiscal {
    int numero_nota;
    int cod_produto;
    int quantidade;
    char data[11];
    float preco_unitario;
};

/**
 * @brief Calcula e imprime a rentabilidade média de cada produto.
 */
void rentabilidades(FILE *produto, FILE *nota) {
    struct Produto p;
    struct NotaFiscal n;
    float rentabilidade_total;
    int qtd_notas;

    printf("--- Relatorio de Rentabilidade Media por Produto ---\n");

    // Para cada produto no arquivo...
    fseek(produto, 0, SEEK_SET); // Garante que o ponteiro está no início
    while (fread(&p, sizeof(struct Produto), 1, produto) == 1) {
        rentabilidade_total = 0.0;
        qtd_notas = 0;
        
        // ...percorre todo o arquivo de notas
        fseek(nota, 0, SEEK_SET);
        while (fread(&n, sizeof(struct NotaFiscal), 1, nota) == 1) {
            // Se a nota fiscal é do produto atual...
            if (p.cod_produto == n.cod_produto) {
                // ...calcula a rentabilidade desta venda e acumula
                rentabilidade_total += (n.preco_unitario - p.custo) / p.custo;
                qtd_notas++;
            }
        }

        // Se houve notas para este produto, calcula e imprime a média
        if (qtd_notas > 0) {
            float rentabilidade_media = (rentabilidade_total / qtd_notas) * 100;
            printf("Produto: %-20s | Rentabilidade Media: %.2f%%\n", p.nome, rentabilidade_media);
        }
    }
}

/**
 * @brief Encontra e imprime o produto mais vendido em unidades.
 */
void mais_vendido(FILE *produto, FILE *nota) {
    struct Produto p;
    struct NotaFiscal n;
    int maior_qtd_vendida = -1;
    char nome_mais_vendido[30];

    printf("\n--- Relatorio de Produto Mais Vendido ---\n");

    // Para cada produto...
    fseek(produto, 0, SEEK_SET);
    while (fread(&p, sizeof(struct Produto), 1, produto) == 1) {
        int qtd_total_produto = 0;
        
        // ...soma todas as quantidades vendidas dele a partir das notas
        fseek(nota, 0, SEEK_SET);
        while (fread(&n, sizeof(struct NotaFiscal), 1, nota) == 1) {
            if (p.cod_produto == n.cod_produto) {
                qtd_total_produto += n.quantidade;
            }
        }

        // Se a quantidade total deste produto for a maior até agora...
        if (qtd_total_produto > maior_qtd_vendida) {
            // ...atualiza o mais vendido
            maior_qtd_vendida = qtd_total_produto;
            strcpy(nome_mais_vendido, p.nome);
        }
    }

    // Imprime o resultado final
    if (maior_qtd_vendida != -1) {
        printf("Produto mais vendido: %s\n", nome_mais_vendido);
        printf("Total de unidades vendidas: %d\n", maior_qtd_vendida);
    } else {
        printf("Nenhuma venda registrada.\n");
    }
}

// Função auxiliar para criar arquivos de exemplo
void criar_arquivos_exemplo() {
    FILE *f_prod = fopen("produto.dat", "wb");
    FILE *f_nota = fopen("nota.dat", "wb");

    struct Produto produtos[] = {
        {101, "Camisa Polo", 50.00},
        {102, "Calca Jeans", 80.00},
        {103, "Tenis Esportivo", 150.00}
    };
    fwrite(produtos, sizeof(struct Produto), 3, f_prod);

    struct NotaFiscal notas[] = {
        {1, 101, 2, "10/05/2024", 80.00}, // Rentabilidade: (80-50)/50 = 0.6
        {2, 102, 5, "11/05/2024", 120.00},// Rentabilidade: (120-80)/80 = 0.5
        {3, 101, 1, "12/05/2024", 90.00}, // Rentabilidade: (90-50)/50 = 0.8
        {4, 103, 3, "13/05/2024", 200.00} // Rentabilidade: (200-150)/150 = 0.33
    };
    fwrite(notas, sizeof(struct NotaFiscal), 4, f_nota);
    
    fclose(f_prod);
    fclose(f_nota);
}

int main() {
    // Apenas para teste, cria os arquivos com dados
    criar_arquivos_exemplo();
    
    FILE *produto, *nota;

    // Abre os arquivos em modo de leitura binária ("rb")
    produto = fopen("produto.dat", "rb");
    nota = fopen("nota.dat", "rb");

    if (produto == NULL || nota == NULL) {
        printf("Erro na abertura dos arquivos!\n");
        return 1;
    }

    // Chama as funções de análise
    rentabilidades(produto, nota);
    mais_vendido(produto, nota);

    // Fecha os arquivos
    fclose(produto);
    fclose(nota);
    return 0;
}

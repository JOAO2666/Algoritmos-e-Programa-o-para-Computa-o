#include <stdio.h>
#include <string.h>

// Definicao da estrutura para armazenar os dados do cliente 
typedef struct Pessoa
{
    char nome[31], cpf[12];
    int idade, telefone;
} TPessoa;

// Definicao da estrutura para armazenar os dados do debito 
typedef struct Debito
{
    char cpf[12];
    char entrada[11];
    float valor;
} TDebito;

int main(void)
{
    FILE *pe, *de, *re;
    TPessoa p;
    TDebito d;

    // Abertura dos arquivos de leitura (clientes, debitos) e escrita (relatorio)
    pe = fopen("clientes.txt", "r");
    de = fopen("debitos.txt", "r");
    re = fopen("relatorio.txt", "w");

    // Verifica se os arquivos foram abertos com sucesso 
    if (pe == NULL || de == NULL || re == NULL)
    {
        printf("Erro na abertura/criacao dos arquivos\n");
        return -1;
    }
    else
    {
        // Loop para ler cada cliente do arquivo "clientes.txt"
        // A leitura continua enquanto fscanf conseguir ler 4 itens por linha
        while (fscanf(pe, "%s %s %d %d", p.nome, p.cpf, &p.idade, &p.telefone) == 4)
        {
            // Verifica se a idade do cliente eh superior a 60 anos 
            if (p.idade > 60)
            {
                // Para cada cliente com mais de 60 anos, procuramos seu debito
                // O ponteiro do arquivo de debitos eh reiniciado para o comeco
                rewind(de);

                // Loop para ler cada debito do arquivo "debitos.txt"
                while (fscanf(de, "%s %s %f", d.cpf, d.entrada, &d.valor) == 3)
                {
                    // Compara o CPF do cliente com o CPF do debito e verifica o valor 
                    if (strcmp(p.cpf, d.cpf) == 0 && d.valor > 50000.00)
                    {
                        // Se as condicoes forem atendidas, escreve os dados no relatorio 
                        fprintf(re, "%s %s %.2f\n", p.nome, p.cpf, d.valor);
                        // Interrompe a busca por debitos para este cliente, pois ja foi encontrado
                        break;
                    }
                }
            }
        }

        // Fecha todos os arquivos abertos
        fclose(pe);
        fclose(de);
        fclose(re);
    }

    return 0;
}

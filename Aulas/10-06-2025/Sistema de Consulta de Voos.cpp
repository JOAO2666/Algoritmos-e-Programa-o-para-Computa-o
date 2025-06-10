#include <stdio.h>
#include <string.h>

// Definição das estruturas 
typedef struct {
    char nome[41], passaporte[11];
    int cpf, idade;
} Passageiro;

typedef struct {
    // ---- A CORREÇÃO ESTÁ AQUI ----
    // Aumentado de 7 para 8 para caber strings como "G3-1000" (7 chars + '\0')
    char voo[8], origem[21], destino[21], assento[4];
    int cpf;
} Ticket;

// Função para criar arquivos de exemplo para teste
void criarArquivosDeExemplo() {
    FILE *fpP = fopen("passageiro.file", "wb");
    FILE *fpT = fopen("ticket.file", "wb");

    if (fpP == NULL || fpT == NULL) {
        printf("Erro ao criar arquivos de exemplo.\n");
        return;
    }

    Passageiro passageiros[] = {
        {"Maria Clara", "BR12345678", 111222333, 30},
        {"Joao Silva", "PT87654321", 444555666, 45},
        {"Ana Souza", "US11223344", 777888999, 25}
    };
    Ticket tickets[] = {
        {"G3-1000", "SAO", "RIO", "15A", 111222333},
        {"AD-2000", "RIO", "SSA", "22B", 444555666},
        {"G3-1000", "SAO", "RIO", "15B", 777888999},
        {"LA-3000", "BSB", "MAO", "10C", 111222333}
    };
    fwrite(passageiros, sizeof(Passageiro), 3, fpP);
    fwrite(tickets, sizeof(Ticket), 4, fpT);

    fclose(fpP);
    fclose(fpT);
}

// a) Imprime todas as passagens de um dado passageiro
void procuraPorPassageiro(char nome[]) {
    Passageiro p;
    Ticket t;
    FILE* fpP = fopen("passageiro.file", "rb");
    FILE* fpT = fopen("ticket.file", "rb");

    if (fpP == NULL || fpT == NULL) {
        printf("Nao foi possivel abrir os arquivos de consulta.\n");
        return;
    }

    int encontrou_passageiro = 0;
    while (fread(&p, sizeof(Passageiro), 1, fpP) == 1) {
        if (strcmp(p.nome, nome) == 0) {
            encontrou_passageiro = 1;
            printf("\nPassagens encontradas para %s (CPF: %d):\n", p.nome, p.cpf);
            
            rewind(fpT); // Reinicia o arquivo de tickets para cada passageiro
            
            int encontrou_ticket = 0;
            while (fread(&t, sizeof(Ticket), 1, fpT) == 1) {
                if (p.cpf == t.cpf) { // Associa pelo CPF
                    printf("  - Voo: %s, Origem: %s, Destino: %s, Assento: %s\n", t.voo, t.origem, t.destino, t.assento);
                    encontrou_ticket = 1;
                }
            }
            if (!encontrou_ticket) {
                printf("  - Nenhuma passagem encontrada para este passageiro.\n");
            }
        }
    }

    if (!encontrou_passageiro) {
        printf("Passageiro '%s' nao encontrado.\n", nome);
    }

    fclose(fpP);
    fclose(fpT);
}

// b) Imprime todos os passageiros de um dado voo
void procuraPorVoo(char codigoVoo[]) {
    Passageiro p;
    Ticket t;
    FILE* fpP = fopen("passageiro.file", "rb");
    FILE* fpT = fopen("ticket.file", "rb");

    if (fpP == NULL || fpT == NULL) {
        printf("Nao foi possivel abrir os arquivos de consulta.\n");
        return;
    }

    printf("\nPassageiros encontrados no voo %s:\n", codigoVoo);
    int encontrou_voo = 0;
    while (fread(&t, sizeof(Ticket), 1, fpT) == 1) {
        if (strcmp(t.voo, codigoVoo) == 0) {
            encontrou_voo = 1;
            
            rewind(fpP); // Reinicia o arquivo de passageiros para cada ticket
            
            while (fread(&p, sizeof(Passageiro), 1, fpP) == 1) {
                if (t.cpf == p.cpf) {
                    printf("  - Nome: %s, CPF: %d, Passaporte: %s\n", p.nome, p.cpf, p.passaporte);
                    break; 
                }
            }
        }
    }
    
    if (!encontrou_voo) {
        printf("  - Nenhum passageiro ou voo encontrado com este codigo.\n");
    }

    fclose(fpP);
    fclose(fpT);
}


// c) Função principal com menu
int main() {
    criarArquivosDeExemplo();

    int opcao;
    char nome[41], voo[8]; // Aumentado para 8 para ser consistente com a struct

    do {
        printf("\n--- SISTEMA DE CONSULTA DE VOOS ---\n");
        printf("1- Procura por passageiro\n");
        printf("2- Procura por voo\n");
        printf("3- Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado (o Enter)

        switch (opcao) {
            case 1:
                printf("Digite o nome completo do passageiro: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0; // Remove o Enter do final de fgets
                procuraPorPassageiro(nome);
                break;
            case 2:
                printf("Digite o codigo do voo: ");
                scanf("%s", voo);
                procuraPorVoo(voo);
                break;
            case 3:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}

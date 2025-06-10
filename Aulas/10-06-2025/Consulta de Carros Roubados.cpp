#include <stdio.h>
#include <string.h>

// Definição correta das estruturas
typedef struct {
    int codigo_bo;
    char nome[31];
    int ano_ocorrencia;
    char descricao[100];
} Boletim;

typedef struct {
    int codigo_bo;
    char placa[8];
    char modelo[21];
    int ano_fabricacao;
    char marca[11];
} Carro;

// Função para criar arquivos de exemplo
void criarArquivosDeExemploCarros() {
    FILE *fbo = fopen("bo.file", "wb");
    FILE *fcar = fopen("carro.file", "wb");
    if (fbo && fcar) {
        Boletim bos[] = {
            {101, "Joao", 2023, "Roubo a mao armada"},
            {102, "Maria", 2022, "Furto qualificado"},
            {103, "Carlos", 2023, "Veiculo furtado em estacionamento"}
        };
        Carro carros[] = {
            {101, "ABC1234", "Civic", 2020, "Honda"},
            {102, "DEF5678", "Corolla", 2021, "Toyota"},
            {103, "GHI9012", "Onix", 2022, "Chevrolet"}
        };
        fwrite(bos, sizeof(Boletim), 3, fbo);
        fwrite(carros, sizeof(Carro), 3, fcar);
    }
    fclose(fbo);
    fclose(fcar);
}

int main() {
    Boletim bol;
    Carro car;
    FILE *fbo, *fcar;
    int ano, qtd = 0;
    char marca_busca[11];

    // Cria os arquivos de teste
    criarArquivosDeExemploCarros();

    // Abrir os arquivos para leitura binária
    fbo = fopen("bo.file", "rb");
    fcar = fopen("carro.file", "rb");

    if (fbo == NULL || fcar == NULL) {
        printf("Erro ao abrir arquivos\n");
        return 1;
    }

    // Solicita os dados ao usuário 
    printf("Digite o ano de ocorrencia: ");
    scanf("%d", &ano);
    printf("Digite a marca do carro: ");
    scanf("%10s", marca_busca); // Usar %10s para segurança contra overflow

    // Para cada BO, verifica o ano
    while (fread(&bol, sizeof(Boletim), 1, fbo) > 0) {
        if (bol.ano_ocorrencia == ano) {
            rewind(fcar); // Volta ao início do arquivo de carros para cada BO

            // Procura o carro correspondente
            while (fread(&car, sizeof(Carro), 1, fcar) > 0) {
                // Verifica se o código do BO e a marca do carro correspondem 
                if (bol.codigo_bo == car.codigo_bo && strcmp(car.marca, marca_busca) == 0) {
                    qtd++;
                    break; // Encontrou o carro, pode parar de procurar por este BO
                }
            }
        }
    }
    
    // Os arquivos devem ser fechados aqui, fora e depois dos laços de leitura
    fclose(fbo);
    fclose(fcar);

    // Exibe o resultado final
    if (qtd > 0) {
        printf("\nQuantidade de registros encontrados: %d\n", qtd);
    } else {
        printf("\nNenhum registro encontrado.\n");
    }

    return 0;
}

/**
 * @file main.c
 * @brief Programa principal do Framework para Simulados
 * @author Seu Nome
 * @version 1.0
 * @date 2024
 *
 * Este programa fornece um conjunto completo de funções para auxiliar na resolução
 * de questões de simulado, incluindo funções matemáticas, manipulação de strings,
 * estruturas de dados, algoritmos, física, química e recursos auxiliares.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matematica.h"
#include "strings.h"

// Definição do tipo Dado (usado nas estruturas de dados)
typedef void *Dado;

// Protótipos das funções do menu
void menu_principal(void);
void menu_matematica(void);
void menu_strings(void);
void menu_estruturas_dados(void);
void menu_algoritmos(void);
void menu_fisica(void);
void menu_quimica(void);
void menu_recursos_auxiliares(void);

int main()
{
    printf("===========================================\n");
    printf("    FRAMEWORK PARA SIMULADOS - v1.0\n");
    printf("===========================================\n\n");

    menu_principal();

    return 0;
}

void menu_principal(void)
{
    int opcao;

    do
    {
        printf("\nMENU PRINCIPAL\n");
        printf("1. Matemática\n");
        printf("2. Strings\n");
        printf("3. Estruturas de Dados\n");
        printf("4. Ordenação e Busca\n");
        printf("5. Física e Química\n");
        printf("6. Arquivos\n");
        printf("7. Temporizadores\n");
        printf("8. Verificação de Respostas\n");
        printf("9. Interface do Usuário\n");
        printf("0. Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            menu_matematica();
            break;
        case 2:
            menu_strings();
            break;
        case 3:
            menu_estruturas_dados();
            break;
        case 4:
            menu_algoritmos();
            break;
        case 5:
            menu_fisica();
            break;
        case 6:
            menu_quimica();
            break;
        case 7:
            menu_recursos_auxiliares();
            break;
        case 8:
            // menu_verificacao_respostas();
            break;
        case 9:
            // menu_interface_usuario();
            break;
        case 0:
            printf("\nEncerrando o programa...\n");
            break;
        default:
            printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menu_matematica(void)
{
    int opcao;
    double a, b, c, resultado;
    double x, x1, x2;
    int i; // Declaração movida para o início

    do
    {
        printf("\nMENU DE MATEMÁTICA\n");
        printf("1. Operações Aritméticas Básicas\n");
        printf("2. Funções Trigonométricas\n");
        printf("3. Cálculo de Áreas e Volumes\n");
        printf("4. Resolução de Equações\n");
        printf("5. Estatística Básica\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: // Operações Aritméticas
            printf("\nDigite dois números: ");
            scanf("%lf %lf", &a, &b);
            printf("Soma: %.2lf\n", soma(a, b));
            printf("Subtração: %.2lf\n", subtracao(a, b));
            printf("Multiplicação: %.2lf\n", multiplicacao(a, b));
            printf("Divisão: %.2lf\n", divisao(a, b));
            break;

        case 2: // Funções Trigonométricas
            printf("\nDigite um ângulo em graus: ");
            scanf("%lf", &a);
            printf("Seno: %.4lf\n", seno(a));
            printf("Cosseno: %.4lf\n", cosseno(a));
            printf("Tangente: %.4lf\n", tangente(a));
            break;

        case 3: // Cálculo de Áreas e Volumes
            printf("\n1. Área do Retângulo\n");
            printf("2. Área do Triângulo\n");
            printf("3. Área do Círculo\n");
            printf("4. Volume do Cubo\n");
            printf("5. Volume da Esfera\n");
            printf("Escolha uma figura: ");
            scanf("%d", &opcao);

            switch (opcao)
            {
            case 1:
                printf("Digite base e altura: ");
                scanf("%lf %lf", &a, &b);
                printf("Área: %.2lf\n", area_retangulo(a, b));
                break;
            case 2:
                printf("Digite base e altura: ");
                scanf("%lf %lf", &a, &b);
                printf("Área: %.2lf\n", area_triangulo(a, b));
                break;
            case 3:
                printf("Digite o raio: ");
                scanf("%lf", &a);
                printf("Área: %.2lf\n", area_circulo(a));
                break;
            case 4:
                printf("Digite o lado: ");
                scanf("%lf", &a);
                printf("Volume: %.2lf\n", volume_cubo(a));
                break;
            case 5:
                printf("Digite o raio: ");
                scanf("%lf", &a);
                printf("Volume: %.2lf\n", volume_esfera(a));
                break;
            default:
                printf("Opção inválida!\n");
            }
            break;

        case 4: // Resolução de Equações
            printf("\n1. Equação do 1º Grau\n");
            printf("2. Equação do 2º Grau\n");
            printf("Escolha o tipo: ");
            scanf("%d", &opcao);

            if (opcao == 1)
            {
                printf("Digite os coeficientes a e b (ax + b = 0): ");
                scanf("%lf %lf", &a, &b);
                if (resolve_equacao_primeiro_grau(a, b, &x))
                {
                    printf("x = %.2lf\n", x);
                }
                else
                {
                    printf("Equação sem solução!\n");
                }
            }
            else if (opcao == 2)
            {
                printf("Digite os coeficientes a, b e c (ax² + bx + c = 0): ");
                scanf("%lf %lf %lf", &a, &b, &c);
                if (resolve_equacao_segundo_grau(a, b, c, &x1, &x2))
                {
                    printf("x1 = %.2lf\n", x1);
                    printf("x2 = %.2lf\n", x2);
                }
                else
                {
                    printf("Equação sem solução real!\n");
                }
            }
            break;

        case 5: // Estatística Básica
            printf("\nDigite o tamanho do conjunto de dados: ");
            scanf("%d", &opcao);
            double *dados = (double *)malloc(opcao * sizeof(double));
            printf("Digite os dados (um por linha):\n");
            for (i = 0; i < opcao; i++)
            {
                scanf("%lf", &dados[i]);
            }
            printf("Média: %.2lf\n", media(dados, opcao));
            printf("Mediana: %.2lf\n", mediana(dados, opcao));
            printf("Moda: %.2lf\n", moda(dados, opcao));
            printf("Desvio Padrão: %.2lf\n", desvio_padrao(dados, opcao));
            free(dados);
            break;

        case 0:
            break;

        default:
            printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menu_strings(void)
{
    int opcao;
    char texto[1000];
    char padrao[100];
    char antigo[100];
    char novo[100];
    char *resultado;

    do
    {
        printf("\nMENU DE MANIPULAÇÃO DE STRINGS\n");
        printf("1. Contagem de Caracteres, Palavras e Parágrafos\n");
        printf("2. Busca de Padrões\n");
        printf("3. Substituição de Substrings\n");
        printf("4. Funções Auxiliares\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        // Limpar o buffer do teclado
        while (getchar() != '\n')
            ;

        switch (opcao)
        {
        case 1: // Contagem
            printf("\nDigite um texto (máx 1000 caracteres):\n");
            fgets(texto, sizeof(texto), stdin);
            texto[strcspn(texto, "\n")] = 0; // Remove o \n do final

            printf("Número de caracteres: %d\n", contar_caracteres(texto));
            printf("Número de palavras: %d\n", contar_palavras(texto));
            printf("Número de parágrafos: %d\n", contar_paragrafos(texto));
            break;

        case 2: // Busca de padrões
            printf("\nDigite um texto (máx 1000 caracteres):\n");
            fgets(texto, sizeof(texto), stdin);
            texto[strcspn(texto, "\n")] = 0;

            printf("Digite o padrão a ser buscado: ");
            fgets(padrao, sizeof(padrao), stdin);
            padrao[strcspn(padrao, "\n")] = 0;

            int posicao = buscar_substring(texto, padrao);
            if (posicao != -1)
            {
                printf("Padrão encontrado na posição %d\n", posicao);
                printf("Número de ocorrências: %d\n", contar_ocorrencias(texto, padrao));
            }
            else
            {
                printf("Padrão não encontrado!\n");
            }
            break;

        case 3: // Substituição
            printf("\nDigite um texto (máx 1000 caracteres):\n");
            fgets(texto, sizeof(texto), stdin);
            texto[strcspn(texto, "\n")] = 0;

            printf("Digite o texto a ser substituído: ");
            fgets(antigo, sizeof(antigo), stdin);
            antigo[strcspn(antigo, "\n")] = 0;

            printf("Digite o novo texto: ");
            fgets(novo, sizeof(novo), stdin);
            novo[strcspn(novo, "\n")] = 0;

            resultado = substituir_substring(texto, antigo, novo);
            printf("Texto resultante:\n%s\n", resultado);
            free(resultado);
            break;

        case 4: // Funções auxiliares
            printf("\nDigite um texto (máx 1000 caracteres):\n");
            fgets(texto, sizeof(texto), stdin);
            texto[strcspn(texto, "\n")] = 0;

            printf("\n1. Converter para maiúsculas\n");
            printf("2. Converter para minúsculas\n");
            printf("3. Remover espaços\n");
            printf("4. Verificar se é palíndromo\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opcao);

            switch (opcao)
            {
            case 1:
                resultado = to_uppercase(texto);
                printf("Texto em maiúsculas: %s\n", resultado);
                free(resultado);
                break;
            case 2:
                resultado = to_lowercase(texto);
                printf("Texto em minúsculas: %s\n", resultado);
                free(resultado);
                break;
            case 3:
                resultado = remover_espacos(texto);
                printf("Texto sem espaços: %s\n", resultado);
                free(resultado);
                break;
            case 4:
                if (eh_palindromo(texto))
                {
                    printf("O texto é um palíndromo!\n");
                }
                else
                {
                    printf("O texto não é um palíndromo.\n");
                }
                break;
            default:
                printf("Opção inválida!\n");
            }
            break;

        case 0:
            break;

        default:
            printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menu_estruturas_dados(void)
{
    int opcao;
    int valor;
    char chave[100];
    Dado dado;

    // Funções de impressão e comparação para inteiros
    void imprimir_int(Dado d)
    {
        printf("%d", (int)(long)d);
    }

    int comparar_int(Dado d1, Dado d2)
    {
        return (int)(long)d1 - (int)(long)d2;
    }

    do
    {
        printf("\nMENU DE ESTRUTURAS DE DADOS\n");
        printf("1. Lista Encadeada\n");
        printf("2. Pilha\n");
        printf("3. Fila\n");
        printf("4. Árvore Binária\n");
        printf("5. Grafo\n");
        printf("6. Tabela Hash\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        { // Lista Encadeada
            Lista *lista = criar_lista();
            int sub_opcao;

            do
            {
                printf("\nMENU DE LISTA ENCADEADA\n");
                printf("1. Inserir elemento\n");
                printf("2. Remover elemento\n");
                printf("3. Buscar elemento\n");
                printf("4. Imprimir lista\n");
                printf("0. Voltar\n");
                printf("\nEscolha uma opção: ");
                scanf("%d", &sub_opcao);

                switch (sub_opcao)
                {
                case 1:
                    printf("Digite um número inteiro: ");
                    scanf("%d", &valor);
                    inserir_lista(lista, (Dado)(long)valor);
                    break;
                case 2:
                    printf("Digite o número a ser removido: ");
                    scanf("%d", &valor);
                    remover_lista(lista, (Dado)(long)valor, comparar_int);
                    break;
                case 3:
                    printf("Digite o número a ser buscado: ");
                    scanf("%d", &valor);
                    dado = buscar_lista(lista, (Dado)(long)valor, comparar_int);
                    if (dado != NULL)
                    {
                        printf("Elemento encontrado: %d\n", (int)(long)dado);
                    }
                    else
                    {
                        printf("Elemento não encontrado!\n");
                    }
                    break;
                case 4:
                    printf("Lista: ");
                    imprimir_lista(lista, imprimir_int);
                    break;
                case 0:
                    break;
                default:
                    printf("Opção inválida!\n");
                }
            } while (sub_opcao != 0);

            destruir_lista(lista, NULL);
            break;
        }

        case 2:
        { // Pilha
            Pilha *pilha = criar_pilha();
            int sub_opcao;

            do
            {
                printf("\nMENU DE PILHA\n");
                printf("1. Empilhar\n");
                printf("2. Desempilhar\n");
                printf("3. Ver topo\n");
                printf("4. Imprimir pilha\n");
                printf("0. Voltar\n");
                printf("\nEscolha uma opção: ");
                scanf("%d", &sub_opcao);

                switch (sub_opcao)
                {
                case 1:
                    printf("Digite um número inteiro: ");
                    scanf("%d", &valor);
                    empilhar(pilha, (Dado)(long)valor);
                    break;
                case 2:
                    dado = desempilhar(pilha);
                    if (dado != NULL)
                    {
                        printf("Elemento desempilhado: %d\n", (int)(long)dado);
                    }
                    else
                    {
                        printf("Pilha vazia!\n");
                    }
                    break;
                case 3:
                    dado = topo_pilha(pilha);
                    if (dado != NULL)
                    {
                        printf("Topo da pilha: %d\n", (int)(long)dado);
                    }
                    else
                    {
                        printf("Pilha vazia!\n");
                    }
                    break;
                case 4:
                    printf("Pilha: ");
                    while (!pilha_vazia(pilha))
                    {
                        dado = desempilhar(pilha);
                        printf("%d ", (int)(long)dado);
                    }
                    printf("\n");
                    break;
                case 0:
                    break;
                default:
                    printf("Opção inválida!\n");
                }
            } while (sub_opcao != 0);

            destruir_pilha(pilha, NULL);
            break;
        }

        case 3:
        { // Fila
            Fila *fila = criar_fila();
            int sub_opcao;

            do
            {
                printf("\nMENU DE FILA\n");
                printf("1. Enfileirar\n");
                printf("2. Desenfileirar\n");
                printf("3. Ver frente\n");
                printf("4. Imprimir fila\n");
                printf("0. Voltar\n");
                printf("\nEscolha uma opção: ");
                scanf("%d", &sub_opcao);

                switch (sub_opcao)
                {
                case 1:
                    printf("Digite um número inteiro: ");
                    scanf("%d", &valor);
                    enfileirar(fila, (Dado)(long)valor);
                    break;
                case 2:
                    dado = desenfileirar(fila);
                    if (dado != NULL)
                    {
                        printf("Elemento desenfileirado: %d\n", (int)(long)dado);
                    }
                    else
                    {
                        printf("Fila vazia!\n");
                    }
                    break;
                case 3:
                    dado = frente_fila(fila);
                    if (dado != NULL)
                    {
                        printf("Frente da fila: %d\n", (int)(long)dado);
                    }
                    else
                    {
                        printf("Fila vazia!\n");
                    }
                    break;
                case 4:
                    printf("Fila: ");
                    while (!fila_vazia(fila))
                    {
                        dado = desenfileirar(fila);
                        printf("%d ", (int)(long)dado);
                    }
                    printf("\n");
                    break;
                case 0:
                    break;
                default:
                    printf("Opção inválida!\n");
                }
            } while (sub_opcao != 0);

            destruir_fila(fila, NULL);
            break;
        }

        case 4:
        { // Árvore Binária
            ArvoreBinaria *arvore = criar_arvore();
            int sub_opcao;

            do
            {
                printf("\nMENU DE ÁRVORE BINÁRIA\n");
                printf("1. Inserir elemento\n");
                printf("2. Remover elemento\n");
                printf("3. Buscar elemento\n");
                printf("4. Percorrer em ordem\n");
                printf("5. Percorrer pré-ordem\n");
                printf("6. Percorrer pós-ordem\n");
                printf("0. Voltar\n");
                printf("\nEscolha uma opção: ");
                scanf("%d", &sub_opcao);

                switch (sub_opcao)
                {
                case 1:
                    printf("Digite um número inteiro: ");
                    scanf("%d", &valor);
                    inserir_arvore(arvore, (Dado)(long)valor, comparar_int);
                    break;
                case 2:
                    printf("Digite o número a ser removido: ");
                    scanf("%d", &valor);
                    remover_arvore(arvore, (Dado)(long)valor, comparar_int);
                    break;
                case 3:
                    printf("Digite o número a ser buscado: ");
                    scanf("%d", &valor);
                    dado = buscar_arvore(arvore, (Dado)(long)valor, comparar_int);
                    if (dado != NULL)
                    {
                        printf("Elemento encontrado: %d\n", (int)(long)dado);
                    }
                    else
                    {
                        printf("Elemento não encontrado!\n");
                    }
                    break;
                case 4:
                    printf("Percorrendo em ordem: ");
                    percurso_em_ordem(arvore, imprimir_int);
                    break;
                case 5:
                    printf("Percorrendo pré-ordem: ");
                    percurso_pre_ordem(arvore, imprimir_int);
                    break;
                case 6:
                    printf("Percorrendo pós-ordem: ");
                    percurso_pos_ordem(arvore, imprimir_int);
                    break;
                case 0:
                    break;
                default:
                    printf("Opção inválida!\n");
                }
            } while (sub_opcao != 0);

            destruir_arvore(arvore, NULL);
            break;
        }

        case 5:
        { // Grafo
            int num_vertices;
            printf("Digite o número de vértices do grafo: ");
            scanf("%d", &num_vertices);

            Grafo *grafo = criar_grafo(num_vertices);
            int sub_opcao;

            do
            {
                printf("\nMENU DE GRAFO\n");
                printf("1. Adicionar aresta\n");
                printf("2. Remover aresta\n");
                printf("3. Verificar aresta\n");
                printf("4. Imprimir grafo\n");
                printf("5. Busca em profundidade\n");
                printf("6. Busca em largura\n");
                printf("0. Voltar\n");
                printf("\nEscolha uma opção: ");
                scanf("%d", &sub_opcao);

                int origem, destino;
                switch (sub_opcao)
                {
                case 1:
                    printf("Digite a origem e o destino da aresta: ");
                    scanf("%d %d", &origem, &destino);
                    adicionar_aresta(grafo, origem, destino);
                    break;
                case 2:
                    printf("Digite a origem e o destino da aresta: ");
                    scanf("%d %d", &origem, &destino);
                    remover_aresta(grafo, origem, destino);
                    break;
                case 3:
                    printf("Digite a origem e o destino da aresta: ");
                    scanf("%d %d", &origem, &destino);
                    if (tem_aresta(grafo, origem, destino))
                    {
                        printf("A aresta existe!\n");
                    }
                    else
                    {
                        printf("A aresta não existe!\n");
                    }
                    break;
                case 4:
                    imprimir_grafo(grafo);
                    break;
                case 5:
                    printf("Digite o vértice inicial: ");
                    scanf("%d", &valor);
                    printf("Busca em profundidade: ");
                    busca_em_profundidade(grafo, valor);
                    break;
                case 6:
                    printf("Digite o vértice inicial: ");
                    scanf("%d", &valor);
                    printf("Busca em largura: ");
                    busca_em_largura(grafo, valor);
                    break;
                case 0:
                    break;
                default:
                    printf("Opção inválida!\n");
                }
            } while (sub_opcao != 0);

            destruir_grafo(grafo);
            break;
        }

        case 6:
        { // Tabela Hash
            int tamanho;
            printf("Digite o tamanho da tabela hash: ");
            scanf("%d", &tamanho);

            TabelaHash *tabela = criar_tabela_hash(tamanho);
            int sub_opcao;

            do
            {
                printf("\nMENU DE TABELA HASH\n");
                printf("1. Inserir elemento\n");
                printf("2. Remover elemento\n");
                printf("3. Buscar elemento\n");
                printf("4. Imprimir tabela\n");
                printf("0. Voltar\n");
                printf("\nEscolha uma opção: ");
                scanf("%d", &sub_opcao);

                switch (sub_opcao)
                {
                case 1:
                    printf("Digite a chave: ");
                    scanf("%s", chave);
                    printf("Digite o valor (número inteiro): ");
                    scanf("%d", &valor);
                    inserir_tabela_hash(tabela, chave, (Dado)(long)valor);
                    break;
                case 2:
                    printf("Digite a chave: ");
                    scanf("%s", chave);
                    remover_tabela_hash(tabela, chave);
                    break;
                case 3:
                    printf("Digite a chave: ");
                    scanf("%s", chave);
                    dado = buscar_tabela_hash(tabela, chave);
                    if (dado != NULL)
                    {
                        printf("Valor encontrado: %d\n", (int)(long)dado);
                    }
                    else
                    {
                        printf("Chave não encontrada!\n");
                    }
                    break;
                case 4:
                    imprimir_tabela_hash(tabela, imprimir_int);
                    break;
                case 0:
                    break;
                default:
                    printf("Opção inválida!\n");
                }
            } while (sub_opcao != 0);

            destruir_tabela_hash(tabela, NULL);
            break;
        }

        case 0:
            break;

        default:
            printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

// Implementações dos outros menus serão adicionadas posteriormente
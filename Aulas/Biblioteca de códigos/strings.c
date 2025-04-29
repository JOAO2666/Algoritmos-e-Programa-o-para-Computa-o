/**
 * @file strings.c
 * @brief Implementação das funções de manipulação de strings
 */

#include "strings.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Contagem de caracteres, palavras e parágrafos
int contar_caracteres(const char *texto)
{
    return strlen(texto);
}

int contar_palavras(const char *texto)
{
    int contador = 0;
    int i;
    int dentro_palavra = 0;

    for (i = 0; texto[i] != '\0'; i++)
    {
        if (isspace(texto[i]))
        {
            dentro_palavra = 0;
        }
        else if (!dentro_palavra)
        {
            dentro_palavra = 1;
            contador++;
        }
    }
    return contador;
}

int contar_paragrafos(const char *texto)
{
    int contador = 0;
    int i;

    for (i = 0; texto[i] != '\0'; i++)
    {
        if (texto[i] == '\n' || (i > 0 && texto[i - 1] == '\n' && !isspace(texto[i])))
        {
            contador++;
        }
    }
    return contador > 0 ? contador : 1;
}

// Busca de padrões em textos
int buscar_substring(const char *texto, const char *padrao)
{
    const char *resultado = strstr(texto, padrao);
    return resultado ? (int)(resultado - texto) : -1;
}

int contar_ocorrencias(const char *texto, const char *padrao)
{
    int contador = 0;
    const char *pos = texto;

    while ((pos = strstr(pos, padrao)) != NULL)
    {
        contador++;
        pos++;
    }
    return contador;
}

// Substituição de substrings
char *substituir_substring(const char *texto, const char *antigo, const char *novo)
{
    int tam_texto = strlen(texto);
    int tam_antigo = strlen(antigo);
    int tam_novo = strlen(novo);
    int ocorrencias = contar_ocorrencias(texto, antigo);

    // Calcula o tamanho necessário para o novo texto
    int tam_final = tam_texto + ocorrencias * (tam_novo - tam_antigo) + 1;
    char *resultado = (char *)malloc(tam_final);

    const char *pos = texto;
    char *dest = resultado;

    while (*pos)
    {
        if (strncmp(pos, antigo, tam_antigo) == 0)
        {
            strcpy(dest, novo);
            dest += tam_novo;
            pos += tam_antigo;
        }
        else
        {
            *dest++ = *pos++;
        }
    }
    *dest = '\0';

    return resultado;
}

// Funções auxiliares
char *to_uppercase(const char *texto)
{
    int tamanho = strlen(texto);
    char *resultado = (char *)malloc(tamanho + 1);
    int i;

    for (i = 0; texto[i] != '\0'; i++)
    {
        resultado[i] = toupper(texto[i]);
    }
    resultado[tamanho] = '\0';
    return resultado;
}

char *to_lowercase(const char *texto)
{
    int tamanho = strlen(texto);
    char *resultado = (char *)malloc(tamanho + 1);
    int i;

    for (i = 0; texto[i] != '\0'; i++)
    {
        resultado[i] = tolower(texto[i]);
    }
    resultado[tamanho] = '\0';
    return resultado;
}

char *remover_espacos(const char *texto)
{
    int tamanho = strlen(texto);
    char *resultado = (char *)malloc(tamanho + 1);
    int j = 0;
    int i;

    for (i = 0; texto[i] != '\0'; i++)
    {
        if (!isspace(texto[i]))
        {
            resultado[j++] = texto[i];
        }
    }
    resultado[j] = '\0';
    return resultado;
}

int eh_palindromo(const char *texto)
{
    char *temp = remover_espacos(texto);
    int tamanho = strlen(temp);
    int i;

    for (i = 0; i < tamanho / 2; i++)
    {
        if (tolower(temp[i]) != tolower(temp[tamanho - 1 - i]))
        {
            free(temp);
            return 0;
        }
    }
    free(temp);
    return 1;
}
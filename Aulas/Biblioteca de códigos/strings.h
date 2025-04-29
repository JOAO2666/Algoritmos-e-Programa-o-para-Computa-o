/**
 * @file strings.h
 * @brief Cabeçalho para funções de manipulação de strings
 */

#ifndef STRINGS_H
#define STRINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Contagem de caracteres, palavras e parágrafos
int contar_caracteres(const char *texto);
int contar_palavras(const char *texto);
int contar_paragrafos(const char *texto);

// Busca de padrões em textos
int buscar_substring(const char *texto, const char *padrao);
int contar_ocorrencias(const char *texto, const char *padrao);

// Substituição de substrings
char *substituir_substring(const char *texto, const char *antigo, const char *novo);

// Funções auxiliares
char *to_uppercase(const char *texto);
char *to_lowercase(const char *texto);
char *remover_espacos(const char *texto);
int eh_palindromo(const char *texto);

#endif // STRINGS_H
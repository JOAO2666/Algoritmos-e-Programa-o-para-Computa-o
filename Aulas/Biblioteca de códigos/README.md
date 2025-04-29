# Framework para Simulados em C

Este é um framework desenvolvido em C para auxiliar na resolução de questões de simulado. O projeto contém um conjunto completo de funções organizadas em diferentes módulos, cada um responsável por uma área específica de conhecimento.

## Módulos Disponíveis

1. **Matemática**
   - Funções aritméticas básicas
   - Funções trigonométricas
   - Cálculo de áreas e volumes
   - Resolução de equações
   - Manipulação de matrizes e vetores
   - Estatística básica

2. **Manipulação de Strings**
   - Contagem de caracteres, palavras e parágrafos
   - Busca de padrões em textos
   - Substituição de substrings
   - Funções auxiliares (maiúsculas/minúsculas, remoção de espaços, etc.)

3. **Estruturas de Dados** (em desenvolvimento)
   - Listas
   - Pilhas
   - Filas
   - Árvores binárias
   - Grafos
   - Tabelas hash

4. **Algoritmos** (em desenvolvimento)
   - Ordenação
   - Busca

5. **Física** (em desenvolvimento)
   - Mecânica
   - Termodinâmica
   - Eletromagnetismo
   - Conversão de unidades

6. **Química** (em desenvolvimento)
   - Conversão de massa/mol
   - Balanceamento de equações
   - Cálculo de pH e pOH

## Como Compilar

Para compilar o projeto, você precisará de um compilador C (como GCC) instalado em seu sistema. Execute os seguintes comandos:

```bash
gcc -c matematica.c
gcc -c strings.c
gcc -c main.c
gcc -o simulados main.o matematica.o strings.o -lm
```

## Como Usar

O programa possui uma interface de menu interativa que permite acessar todas as funcionalidades disponíveis. Basta executar o programa compilado:

```bash
./simulados
```

## Exemplos de Uso

### Matemática
```c
#include "matematica.h"

int main() {
    double resultado = soma(5.0, 3.0);
    printf("5 + 3 = %lf\n", resultado);
    
    double area = area_circulo(2.0);
    printf("Área do círculo com raio 2: %lf\n", area);
    
    return 0;
}
```

### Strings
```c
#include "strings.h"

int main() {
    const char *texto = "Olá, mundo!";
    int palavras = contar_palavras(texto);
    printf("Número de palavras: %d\n", palavras);
    
    char *maiusculo = to_uppercase(texto);
    printf("Texto em maiúsculas: %s\n", maiusculo);
    free(maiusculo);
    
    return 0;
}
```

## Licença

Este projeto está licenciado sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.

## Autor

Seu Nome - seu.email@exemplo.com 
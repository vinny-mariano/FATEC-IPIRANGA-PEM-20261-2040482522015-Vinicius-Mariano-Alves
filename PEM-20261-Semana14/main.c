/*----------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                   *
 * - Fatec Ipiranga - ADS Vespertino                                                *
 * - Professor: Veríssimo                                                           *
 * - Disciplina: Programação Estruturada e Modular (PEM)                            *
 * - Atividade: Semana 14 - Exercício 13 (main)                                     *
 * - Objetivo: Ponto de entrada do programa para testar os casos do módulo de       *
 * strings, validando as saídas requisitadas pelo roteiro.                          *
 *----------------------------------------------------------------------------------*/

#include <stdio.h>
#include "stringutil.h"

int main() {
    char caso1_vogais[] = "Estruturada";
    char caso2_vogais[] = "FATEC";

    char caso1_inverter[] = "Autonomia";
    char caso2_inverter[] = "PEM";

    char caso1_palindromo[] = "arara";
    char caso2_palindromo[] = "computador";

    printf("=== TESTE: contaVogais ===\n");
    printf("String: '%s' -> Vogais: %d\n", caso1_vogais, contaVogais(caso1_vogais));
    printf("String: '%s' -> Vogais: %d\n", caso2_vogais, contaVogais(caso2_vogais));

    printf("\n=== TESTE: inverteCString ===\n");
    printf("Original: '%s' ", caso1_inverter);
    inverteCString(caso1_inverter);
    printf("-> Invertida: '%s'\n", caso1_inverter);

    printf("Original: '%s' ", caso2_inverter);
    inverteCString(caso2_inverter);
    printf("-> Invertida: '%s'\n", caso2_inverter);

    printf("\n=== TESTE: ePalindromo ===\n");
    printf("String: '%s' -> %s\n", caso1_palindromo, ePalindromo(caso1_palindromo) ? "E Palindromo" : "Nao e Palindromo");
    printf("String: '%s' -> %s\n", caso2_palindromo, ePalindromo(caso2_palindromo) ? "E Palindromo" : "Nao e Palindromo");

    return 0;
}

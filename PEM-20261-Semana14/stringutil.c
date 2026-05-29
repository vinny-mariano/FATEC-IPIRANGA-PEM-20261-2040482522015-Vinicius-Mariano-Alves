/*----------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                   *
 * - Fatec Ipiranga - ADS Vespertino                                                *
 * - Professor: Veríssimo                                                           *
 * - Disciplina: Programação Estruturada e Modular (PEM)                            *
 * - Atividade: Semana 14 - Exercício 13 (.c)                                       *
 * - Objetivo: Implementação das funções de contagem de vogais, inversão in-place   *
 * e verificação de palíndromos sem o uso de funções externas da string.h.          *
 *----------------------------------------------------------------------------------*/

#include "stringutil.h"

int contaVogais(char *s) {
    int contador = 0;
    int i = 0;

    while (*(s + i) != '\0') {
        char c = *(s + i);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            contador++;
        }
        i++;
    }
    return contador;
}

void inverteCString(char *s) {
    int fim = 0;
    int inicio = 0;
    char aux;

    while (*(s + fim) != '\0') {
        fim++;
    }
    fim--;

    while (inicio < fim) {
        aux = *(s + inicio);
        *(s + inicio) = *(s + fim);
        *(s + fim) = aux;
        inicio++;
        fim--;
    }
}

int ePalindromo(char *s) {
    int inicio = 0;
    int fim = 0;

    while (*(s + fim) != '\0') {
        fim++;
    }
    fim--;

    while (inicio < fim) {
        if (*(s + inicio) != *(s + fim)) {
            return 0;
        }
        inicio++;
        fim--;
    }
    return 1;
}

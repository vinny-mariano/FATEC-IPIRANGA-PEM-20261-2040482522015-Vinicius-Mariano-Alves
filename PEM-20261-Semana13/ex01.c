/*-------------------------------------------------------------------------------------------*                                                           *
 * - Fatec Ipiranga - Ads Vespertino                                                         *
 * - Autor: Vinícius Mariano Alves                                                           *
 * - Atividade PEM - Semana 13 - Dia 21/05/2026                                              *
 * - Objetivo: Declarar variáveis int, float, char com seus ponteiros, imprimir valores      *
 * e endereços de memória.                                                                   *
 *-------------------------------------------------------------------------------------------*/
#include <stdio.h>

int main() {
    int a = 53;
    float b = 19.99;
    char c = 'X';

    int *ptr_a = &a;
    float *ptr_b = &b;
    char *ptr_c = &c;

    printf("--- Variavel Inteira ---\n");
    printf("Valor da variavel: %d\n", a);
    printf("Endereco da variavel: %p\n", (void*)&a);
    printf("Endereco no ponteiro: %p\n", (void*)ptr_a);
    printf("Valor pelo ponteiro: %d\n\n", *ptr_a);

    printf("--- Variavel Float ---\n");
    printf("Valor da variavel: %.2f\n", b);
    printf("Endereco da variavel: %p\n", (void*)&b);
    printf("Endereco no ponteiro: %p\n", (void*)ptr_b);
    printf("Valor pelo ponteiro: %.2f\n\n", *ptr_b);

    printf("--- Variavel Char ---\n");
    printf("Valor da variavel: %c\n", c);
    printf("Endereco da variavel: %p\n", (void*)&c);
    printf("Endereco no ponteiro: %p\n", (void*)ptr_c);
    printf("Valor pelo ponteiro: %c\n", *ptr_c);

    return 0;
}
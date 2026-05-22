/*-------------------------------------------------------------------------------------------* 
 * - Autor: Vinícius Mariano Alves                                                           *
 * - Fatec Ipiranga - Ads Vespertino                                                         *
 * - Atividade PEM - Semana 13 - Dia 21/05/2026                                              *
 * - Objetivo: Multiplicar elementos de um vetor por 2 utilizando ponteiros e aritmética,    *
 * sem uso de índices [].                                                                  *
 *-------------------------------------------------------------------------------------------*/
#include <stdio.h>

int main() {
    int vetor[5] = {2, 4, 6, 8, 10};
    int *p = vetor;
    int i;

    printf("Vetor antes: ");
    for(i = 0; i < 5; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");

    for(i = 0; i < 5; i++) {
        *(p + i) = *(p + i) * 2;
    }

    printf("Vetor depois: ");
    for(i = 0; i < 5; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");

    return 0;
}
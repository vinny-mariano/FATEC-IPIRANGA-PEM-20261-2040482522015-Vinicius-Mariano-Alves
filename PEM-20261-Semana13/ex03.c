/*-------------------------------------------------------------------------------------------* 
 * - Autor: Vinícius Mariano Alves                                                           *
 * - Fatec Ipiranga - Ads Vespertino                                                         *
 * - Atividade PEM - Semana 13 - Dia 21/05/2026                                              *
 * - Objetivo: Implementar uma função que troca o conteúdo de duas variáveis inteiras        *
 * utilizando ponteiros.                                                                     *
 *-------------------------------------------------------------------------------------------*/
#include <stdio.h>

void trocar(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    int x = 10;
    int y = 20;

    printf("Antes da troca:\n x = %d, y = %d\n", x, y);

    trocar(&x, &y);

    printf("Depois da troca:\n x = %d, y = %d\n", x, y);

    return 0;
}
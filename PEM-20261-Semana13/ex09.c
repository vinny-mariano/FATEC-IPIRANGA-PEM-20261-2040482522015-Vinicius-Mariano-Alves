/*-------------------------------------------------------------------------------------------* 
 * - Autor: Vinícius Mariano Alves                                                           *
 * - Fatec Ipiranga - Ads Vespertino                                                         *
 * - Atividade PEM - Semana 13 - Dia 21/05/2026                                              *
 * - Objetivo: Implementar função in-place que inverte a ordenação de um array usando dois   *
 * ponteiros (inicio e fim).                                                                 *
 *-------------------------------------------------------------------------------------------*/
#include <stdio.h>

void inverter(int *arr, int n) {
    int *inicio = arr;
    int *fim = arr + (n - 1);
    int aux;

    while(inicio < fim) {
        aux = *inicio;
        *inicio = *fim;
        *fim = aux;
        
        inicio++;
        fim--;
    }
}

int main() {
    int array[7] = {1, 2, 3, 4, 5, 6, 7};
    int i;

    printf("Antes da inversao: ");
    for(i = 0; i < 7; i++) printf("%d ", array[i]);
    printf("\n");

    inverter(array, 7);

    printf("Depois da inversao: ");
    for(i = 0; i < 7; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}
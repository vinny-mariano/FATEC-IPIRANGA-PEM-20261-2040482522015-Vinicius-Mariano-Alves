/*-------------------------------------------------------------------------------------------* 
 * - Autor: Vinícius Mariano Alves                                                           *
 * - Fatec Ipiranga - Ads Vespertino                                                         *
 * - Atividade PEM - Semana 13 - Dia 21/05/2026                                              *
 * - Objetivo: Percorrer um array de 8 inteiros usando aritmética de ponteiros, obtendo      *
 * soma, média, maior, menor e endereços.                                                    *
 *-------------------------------------------------------------------------------------------*/
#include <stdio.h>

int main() {
    int arr[8] = {12, 45, 7, 22, 19, 83, 4, 31};
    int *p = arr;
    int i;

    int soma = 0;
    int maior = *p;
    int menor = *p;

    for(i = 0; i < 8; i++) {
        int valorAtual = *(p + i);
        soma += valorAtual;

        if(valorAtual > maior) maior = valorAtual;
        if(valorAtual < menor) menor = valorAtual;

        printf("Elemento %d | Endereco: %p | Valor: %d\n", i, (void*)(p + i), valorAtual);
    }

    printf("\nSoma: %d\n", soma);
    printf("Media: %.2f\n", (float)soma / 8);
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    return 0;
}
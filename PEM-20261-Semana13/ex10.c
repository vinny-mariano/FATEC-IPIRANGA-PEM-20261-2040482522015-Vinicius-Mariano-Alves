/*-------------------------------------------------------------------------------------------* 
 * - Autor: Vinícius Mariano Alves                                                           *
 * - Fatec Ipiranga - Ads Vespertino                                                         *
 * - Atividade PEM - Semana 13 - Dia 21/05/2026                                              *
 * - Objetivo: Buscar o maior elemento de uma matriz 4x4 mapeando de forma linear através    *
 * de um único ponteiro.                                                                     *
 *-------------------------------------------------------------------------------------------*/
#include <stdio.h>

int main() {
    int matriz[4][4] = {
        {10, 23, 15, 7},
        {4,  88, 12, 19},
        {31, 54, 6,  9},
        {42, 11, 73, 2}
    };

    int *p = &matriz[0][0];
    int maior = *p;
    int indiceMaior = 0;
    int i;

    for(i = 0; i < 16; i++) {
        if(*(p + i) > maior) {
            maior = *(p + i);
            indiceMaior = i;
        }
    }

    int linha = indiceMaior / 4;
    int coluna = indiceMaior % 4;

    printf("Maior valor: %d\n", maior);
    printf("Posicao: Linha %d, Coluna %d\n", linha, coluna);

    return 0;
}
/*-------------------------------------------------------------------------------------------* 
 * - Autor: Vinícius Mariano Alves                                                           *
 * - Fatec Ipiranga - Ads Vespertino                                                         *
 * - Atividade PEM - Semana 13 - Dia 21/05/2026                                              *
 * - Objetivo: Calcular a diferença aritmética de ponteiros entre duas posições e iterar     *
 * exibindo os elementos internos.                                                           *
 *-------------------------------------------------------------------------------------------*/
#include <stdio.h>

int main() {
    double arr[10] = {10.5, 20.5, 30.5, 40.5, 50.5, 60.5, 70.5, 80.5, 90.5, 100.5};
    double *p3 = &arr[2]; // 3º elemento
    double *p8 = &arr[7]; // 8º elemento

    long int diferenca = p8 - p3;
    printf("Diferenca entre os ponteiros: %ld\n", diferenca);

    /* O compilador realiza o cálculo subtraindo os endereços de memória e dividindo o 
     * resultado pelo tamanho do tipo de dado apontado (sizeof(double) = 8 bytes). 
     * Dessa forma, o resultado final mostra a quantidade de elementos que separam os 
     * dois ponteiros, e não uma distância apenas em bytes.
     */

    printf("Elementos no intervalo: ");
    double *ptr;
    for(ptr = p3; ptr <= p8; ptr++) {
        printf("%.1f ", *ptr);
    }
    printf("\n");

    return 0;
}
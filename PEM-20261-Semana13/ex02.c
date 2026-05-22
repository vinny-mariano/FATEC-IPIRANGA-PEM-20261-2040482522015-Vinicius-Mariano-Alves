/*-------------------------------------------------------------------------------------------* 
 * - Autor: Vinícius Mariano Alves                                                            *
 * - Fatec Ipiranga - Ads Vespertino                                                         *
 * - Atividade PEM - Semana 13 - Dia 21/05/2026                                              *
 * - Objetivo: Imprimir o tamanho em bytes de ponteiros para int, float, double e char       *
 * e explicar o motivo do tamanho via comentário.                                            *
 *-------------------------------------------------------------------------------------------*/
#include <stdio.h>

int main() {
    printf("Tamanho do ponteiro para int: %zu bytes\n", sizeof(int*));
    printf("Tamanho do ponteiro para float: %zu bytes\n", sizeof(float*));
    printf("Tamanho do ponteiro para double: %zu bytes\n", sizeof(double*));
    printf("Tamanho do ponteiro para char: %zu bytes\n", sizeof(char*));

    /* COMENTÁRIO EXPLICATIVO:
     * O tamanho do ponteiro não varia com o tipo apontado.
     * Isso acontece porque um ponteiro armazena apenas um endereço de memória, e não o valor do dado.
     * O espaço necessário para guardar um endereço depende da arquitetura do sistema operacional e processador 
     * (sendo 4 bytes em 32 bits e 8 bytes em 64 bits).
    */

    return 0;
}
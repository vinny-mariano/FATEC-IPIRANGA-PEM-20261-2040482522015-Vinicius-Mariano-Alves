/*--------------------------------------------------------------------------------------------* 
 * - Autor: Vinícius Mariano Alves                                                            *
 * - Fatec Ipiranga - Ads Vespertino                                                          *
 * - Atividade PEM - Semana 13 - Dia 21/05/2026                                               *
 * - Objetivo: Passar referências de variáveis para uma função calcular e armazenar múltiplos *
 * dados estatísticos.                                                                        *
 *--------------------------------------------------------------------------------------------*/
#include <stdio.h>

void estatisticas(int *v, int n, int *soma, float *media, int *maior, int *menor) {
    *soma = 0;
    *maior = *(v + 0);
    *menor = *(v + 0);
    int i;

    for(i = 0; i < n; i++) {
        int atual = *(v + i);
        *soma += atual;
        if(atual > *maior) *maior = atual;
        if(atual < *menor) *menor = atual;
    }
    *media = (float)(*soma) / n;
}

int main() {
    int dados[6] = {14, 32, 8, 25, 41, 19};
    int s, max, min;
    float med;

    estatisticas(dados, 6, &s, &med, &max, &min);

    printf("Resultados extraidos:\n");
    printf("Soma total: %d\n", s);
    printf("Media: %.2f\n", med);
    printf("Maior: %d\n", max);
    printf("Menor: %d\n", min);

    return 0;
}
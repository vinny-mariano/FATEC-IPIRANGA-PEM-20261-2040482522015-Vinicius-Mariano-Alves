/*-------------------------------------------------------------------------------------------* 
 * - Autor: Vinícius Mariano Alves                                                           *
 * - Fatec Ipiranga - Ads Vespertino                                                         *
 * - Atividade PEM - Semana 13 - Dia 21/05/2026                                              *
 * - Objetivo: Implementar e exibir passos do Selection Sort operando integralmente através  *
 * de aritmética de ponteiros.                                                               *
 *-------------------------------------------------------------------------------------------*/
#include <stdio.h>

void trocarAux(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int n) {
    int i, j, k;
    for (i = 0; i < n - 1; i++) {
        int *minPtr = arr + i;
        for (j = i + 1; j < n; j++) {
            if (*(arr + j) < *minPtr) {
                minPtr = arr + j;
            }
        }
        if (minPtr != (arr + i)) {
            trocarAux(arr + i, minPtr);
            
            // Impressão obrigatória a cada troca efetuada
            printf("Troca realizada: ");
            for (k = 0; k < n; k++) printf("%d ", *(arr + k));
            printf("\n");
        }
    }
}

int main() {
    int arr[8] = {50, 20, 40, 10, 80, 30, 70, 60};
    int i;

    printf("Estado Inicial : ");
    for (i = 0; i < 8; i++) printf("%d ", arr[i]);
    printf("\n\n");

    selectionSort(arr, 8);

    printf("\nEstado Ordenado: ");
    for (i = 0; i < 8; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
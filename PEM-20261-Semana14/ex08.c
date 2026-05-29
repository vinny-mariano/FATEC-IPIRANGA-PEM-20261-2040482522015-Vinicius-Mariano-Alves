/*----------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                   *
 * - Fatec Ipiranga - ADS Vespertino                                                *
 * - Professor: Veríssimo                                                           *
 * - Disciplina: Programação Estruturada e Modular (PEM)                            *
 * - Atividade: Semana 14 - Exercício 08                                            *
 * - Objetivo: Manipular um vetor de tamanho N fixado por diretiva de compilação,   *
 * extraindo estatísticas de extremos, paridade, inversão e busca linear.           *
 *----------------------------------------------------------------------------------*/

#include <stdio.h>

#define N 8

int main() {
    int vetor_original[N];
    int vetor_invertido[N];
    int maior, menor;
    int indice_maior = 0, indice_menor = 0;
    int pares = 0, impares = 0;
    int chave_busca, encontrado = -1;
    int i;

    printf("Digite %d valores inteiros:\n", N);
    for (i = 0; i < N; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &vetor_original[i]);
    }

    printf("\nVetor original: [ ");
    for (i = 0; i < N; i++) {
        printf("%d ", vetor_original[i]);
    }
    printf("]\n");

    maior = vetor_original[0];
    menor = vetor_original[0];

    for (i = 0; i < N; i++) {
        if (vetor_original[i] > maior) {
            maior = vetor_original[i];
            indice_maior = i;
        }
        if (vetor_original[i] < menor) {
            menor = vetor_original[i];
            indice_menor = i;
        }

        if (vetor_original[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }

    for (i = 0; i < N; i++) {
        vetor_invertido[i] = vetor_original[N - 1 - i];
    }

    printf("\nDigite um valor para buscar no vetor: ");
    scanf("%d", &chave_busca);

    for (i = 0; i < N; i++) {
        if (vetor_original[i] == chave_busca) {
            encontrado = i;
            break;
        }
    }

    printf("\n--- RESULTADOS DA ANALISE ---\n");
    printf("Maior valor: %d (Encontrado no indice [%d])\n", maior, indice_maior);
    printf("Menor valor: %d (Encontrado no indice [%d])\n", menor, indice_menor);
    printf("Quantidade de numeros pares: %d\n", pares);
    printf("Quantidade de numeros impares: %d\n", impares);

    printf("Vetor invertido: [ ");
    for (i = 0; i < N; i++) {
        printf("%d ", vetor_invertido[i]);
    }
    printf("]\n");

    if (encontrado != -1) {
        printf("Busca Linear: O valor %

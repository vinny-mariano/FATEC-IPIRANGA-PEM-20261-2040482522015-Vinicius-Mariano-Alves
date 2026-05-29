/*----------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                   *
 * - Fatec Ipiranga - ADS Vespertino                                                *
 * - Professor: Veríssimo                                                           *
 * - Disciplina: Programação Estruturada e Modular (PEM)                            *
 * - Atividade: Semana 14 - Exercício 07                                            *
 * - Objetivo: Declarar um vetor de 10 elementos float, ler os valores e calcular,  *
 * em um loop único após a leitura, a média, maior, menor e a soma acima da média.  *
 *----------------------------------------------------------------------------------*/

#include <stdio.h>

int main() {
    float numeros[10];
    float somaTotal = 0.0f;
    float media = 0.0f;
    float maior, menor;
    float somaAcimaMedia = 0.0f;
    int i;

    printf("Digite 10 numeros reais (float):\n");
    
    printf("Posicao [0]: ");
    scanf("%f", &numeros[0]);
    somaTotal = numeros[0];
    maior = numeros[0];
    menor = numeros[0];

    for (i = 1; i < 10; i++) {
        printf("Posicao [%d]: ", i);
        scanf("%f", &numeros[i]);
        somaTotal += numeros[i];

        if (numeros[i] > maior) {
            maior = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    media = somaTotal / 10.0f;

    for (i = 0; i < 10; i++) {
        if (numeros[i] > media) {
            somaAcimaMedia += numeros[i];
        }
    }

    printf("\n--- RELATORIO ESTATISTICO ---\n");
    printf("Media aritmetica: %.2f\n", media);
    printf("Maior valor encontrado: %.2f\n", maior);
    printf("Menor valor encontrado: %.2f\n", menor);
    printf("Soma dos valores acima da media: %.2f\n", somaAcimaMedia);

    return 0;
}

/*----------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                   *
 * - Fatec Ipiranga - ADS Vespertino                                                *
 * - Professor: Veríssimo                                                           *
 * - Disciplina: Programação Estruturada e Modular (PEM)                            *
 * - Atividade: Semana 14 - Exercício 01                                            *
 * - Objetivo: Calcular a média ponderada de 3 notas com pesos, formatar a saída    *
 * e exibir o tamanho dos tipos primitivos na memória RAM.                          *
 *----------------------------------------------------------------------------------*/

#include <stdio.h>

int main(){

        int p1, p2, p3;
        double n1, n2, n3, media;

    printf("INSIRA O PESO E O VALOR DA PRIMEIRA NOTA\n");
    printf("PESO:");
    scanf("%d", &p1);
    printf("\n");
    printf("NOTA:");
    scanf("%lf", &n1);

    printf("INSIRA O PESO E O VALOR DA SEGUNDA NOTA\n");
    printf("PESO:");
    scanf("%d", &p2);
    printf("\n");
    printf("NOTA:");
    scanf("%lf", &n2);

    printf("INSIRA O PESO E O VALOR DA TERCEIRA NOTA\n");
    printf("PESO:");
    scanf("%d", &p3);
    printf("\n");   
    printf("NOTA:");
    scanf("%lf", &n3);

        media = (n1*p1 + n2*p2 + n3*p3) / (p1 + p2 + p3);

    printf("A media ponderada considerando os pesos e os valores de cada nota informada e:\n %.2lf\n", media);

    printf("Tamanho da variável int: %zu bytes\n", sizeof(int));

    printf("Tamanho da variável double: %zu bytes\n", sizeof(double));


    return 0;
}

/*----------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                   *
 * - Fatec Ipiranga - ADS Vespertino                                                *
 * - Professor: Veríssimo                                                           *
 * - Disciplina: Programação Estruturada e Modular (PEM)                            *
 * - Atividade: Semana 14 - Exercício 11                                            *
 * - Objetivo: Percorrer um vetor de 6 inteiros usando exclusivamente aritmética de *
 * ponteiros, exibindo endereços em hexadecimal, somando e dobrando os valores.     *
 *----------------------------------------------------------------------------------*/

#include <stdio.h>

int main() {
    int vetor[6] = {10, 20, 30, 40, 50, 60};
    int *p = vetor;
    int soma = 0;
    int i;

    printf("=== LEITURA EXCLUSIVA COM PONTEIROS ===\n\n");
    for (i = 0; i < 6; i++) {
        printf("Elemento: %d | Endereco: %p\n", *(p + i), (void *)(p + i));
        soma += *(p + i);
    }

    printf("\nSoma total dos elementos: %d\n", soma);

    for (i = 0; i < 6; i++) {
        *(p + i) = *(p + i) * 2;
    }

    printf("\n=== VETOR MODIFICADO IN-PLACE (DOBRO) ===\n\n");
    for (i = 0; i < 6; i++) {
        printf("Elemento alterado: %d | Endereco: %p\n", *(p + i), (void *)(p + i));
    }

    printf("\n--- CONFIRMACAO DE ARITMETICA DE MEMORIA ---\n");
    printf("Tamanho do tipo int nesta maquina: %zu bytes\n", sizeof(int));
    printf("Diferenca fisica medida entre indices consecutivos: %ld bytes\n", 
           (long int)(p + 1) - (long int)(p));

    return 0;
}

/*----------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                   *
 * - Fatec Ipiranga - ADS Vespertino                                                *
 * - Professor: Veríssimo                                                           *
 * - Disciplina: Programação Estruturada e Modular (PEM)                            *
 * - Atividade: Semana 14 - Exercício 06                                            *
 * - Objetivo: Ler um número inteiro positivo, gerar e exibir sua Sequência de      *
 * Collatz correspondente, e contabilizar o número de passos até atingir 1.        *
 *----------------------------------------------------------------------------------*/

#include <stdio.h>

int main() {
    int n;
    int passos = 0; 

    
    printf("Informe um numero inteiro positivo para iniciar a sequencia: ");
    scanf("%d", &n);

    // Validação
    while (n <= 0) {
        printf("\n[ERRO] O valor deve ser estritamente positivo (maior que zero)!\n");
        printf("Tente novamente: ");
        scanf("%d", &n);
    }

    // Exibe o numero digitado pelo usuário)
    printf("\nSequencia gerada: %d", n);

    while (n > 1) {
        
        if (n % 2 == 0) {
            n = n / 2;
        } 
        else {
            n = 3 * n + 1;
        }

        printf(" -> %d", n);
        
        //contador de iterações
        passos++;
    }

    printf("\n\nNumero total de passos necessarios: %d\n", passos);

    return 0;
}

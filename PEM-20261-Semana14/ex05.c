/*----------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                   *
 * - Fatec Ipiranga - ADS Vespertino                                                *
 * - Professor: Veríssimo                                                           *
 * - Disciplina: Programação Estruturada e Modular (PEM)                            *
 * - Atividade: Semana 14 - Exercício 05                                            *
 * - Objetivo: Gerar a tabuada completa de 1 a 10 usando laços aninhados (for e     *
 * while), controlando a repetição do programa principal com do-while.              *
 *----------------------------------------------------------------------------------*/

#include <stdio.h>

int main() {
    char opcao; // Variável para controlar se o usuário deseja continuar ('S' ou 'N')
    int i, j;   // Variáveis de controle dos laços (i para o multiplicando, j para o multiplicador)

    // LAÇO EXTERNO (do-while): Garante que o programa rode pelo menos uma vez
    do {
        printf("\n=== TABUADA COMPLETA (1 a 10) ===\n\n");

        // LAÇO INTERMEDIÁRIO (for): Controla qual tabuada está sendo gerada
        for (i = 1; i <= 10; i++) {
            printf("--- Tabuada do %d ---\n", i);
            
            j = 1; 

            // LAÇO INTERNO (while): Executa as multiplicações de 1 a 10 para a tabuada atual
            while (j <= 10) {
                printf("%d x %d = %d\n", i, j, i * j);
                j++; // Incremento manual obrigatório no while para evitar loop infinito
            }
            printf("\n"); // Quebra de linha para separar visualmente as tabuadas
        }

        printf("Deseja continuar gerando as tabuadas? (S/N): ");
        // O espaço antes de %c é vital no papel para limpar o buffer do '\n' (Enter)
        scanf(" %c", &opcao); 

    // O laço do-while avalia a condição no final. Se for diferente de 'N' e 'n', repete todo o programa.
    } while (opcao != 'N' && opcao != 'n');

    printf("\nPrograma encerrado com sucesso!\n");

    return 0;
}

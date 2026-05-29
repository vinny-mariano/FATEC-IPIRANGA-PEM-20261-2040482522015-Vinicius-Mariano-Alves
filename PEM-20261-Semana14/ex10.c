/*----------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                   *
 * - Fatec Ipiranga - ADS Vespertino                                                *
 * - Professor: Veríssimo                                                           *
 * - Disciplina: Programação Estruturada e Modular (PEM)                            *
 * - Atividade: Semana 14 - Exercício 10                                            *
 * - Objetivo: Representar um tabuleiro 4x4, exibir em grade, calcular as diagonais *
 * principal e secundária, e verificar a simetria em relação à diagonal principal.  *
 *----------------------------------------------------------------------------------*/

#include <stdio.h>

int main() {
    int tabuleiro[4][4] = {
        {1, 2, 3, 4},
        {2, 5, 6, 7},
        {3, 6, 8, 1},
        {4, 7, 1, 8}
    };
    int i, j;
    int simetrica = 1;

    printf("=== TABULEIRO DO JOGO DA MEMORIA ===\n\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%3d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n--- DIAGONAL PRINCIPAL ---\n");
    for (i = 0; i < 4; i++) {
        printf("%d ", tabuleiro[i][i]);
    }
    printf("\n");

    printf("\n--- DIAGONAL SECUNDARIA ---\n");
    for (i = 0; i < 4; i++) {
        printf("%d ", tabuleiro[i][3 - i]);
    }
    printf("\n");

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (tabuleiro[i][j] != tabuleiro[j][i]) {
                simetrica = 0;
                break;
            }
        }
        if (!simetrica) {
            break;
        }
    }

    printf("\n--- ANALISE DE SIMETRIA ---\n");
    if (simetrica) {
        printf("Todos os pares estao em posições simetricas em relacao a diagonal principal.\n");
    } else {
        printf("Os pares NAO estao em posicoes simetricas em relacao a diagonal principal.\n");
    }

    return 0;
}

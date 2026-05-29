/*----------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                   *
 * - Fatec Ipiranga - ADS Vespertino                                                *
 * - Professor: Veríssimo                                                           *
 * - Disciplina: Programação Estruturada e Modular (PEM)                            *
 * - Atividade: Semana 14 - Exercício 09                                            *
 * - Objetivo: Declarar e ler duas matrizes 3x3 de inteiros, calcular o seu produto *
 * matricial utilizando um loop triplo e exibir os resultados alinhados.            *
 *----------------------------------------------------------------------------------*/

#include <stdio.h>

int main() {
    int A[3][3];
    int B[3][3];
    int C[3][3];
    int i, j, k;

    printf("--- PREENCHIMENTO DA MATRIZ A (3x3) ---\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Matriz A [%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\n--- PREENCHIMENTO DA MATRIZ B (3x3) ---\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Matriz B [%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    /* CORRESPONDÊNCIA DOS ÍNDICES COM A DEFINIÇÃO ALGÉBRICA:
     * C[i][j] = Σ A[i][k] × B[k][j]
     * * - 'i' mapeia as linhas de A e C. Ele fixa a linha horizontal que será multiplicada.
     * - 'j' mapeia as colunas de B e C. Ele fixa a coluna vertical que receberá a multiplicação.
     * - 'k' representa o somatório (Σ). Ele percorre os elementos da linha de A e os elementos da coluna de B
     * simultaneamente, fazendo o casamento de índices A[i][k] e B[k][j].
     */
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            C[i][j] = 0; // Vital inicializar o acumulador da posição antes do somatório 'k'
            for (k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\n=== MATRIZ A ===\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%5d\t", A[i][j]);
        }
        printf("\n");
    }

    printf("\n=== MATRIZ B ===\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%5d\t", B[i][j]);
        }
        printf("\n");
    }

    printf("\n=== MATRIZ PRODUTO C (A x B) ===\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%5d\t", C[i][j]); // %5d garante o alinhamento das colunas com espaçamento fixo
        }
        printf("\n");
    }

    return 0;
}

/*----------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                   *
 * - Fatec Ipiranga - ADS Vespertino                                                *
 * - Professor: Veríssimo                                                           *
 * - Disciplina: Programação Estruturada e Modular (PEM)                            *
 * - Atividade: Semana 14 - Exercício 15                                            *
 * - Objetivo: Resolver o problema da Torre de Hanói usando recursividade,          *
 * contando os movimentos e validando a fórmula matemática 2^n - 1.                 *
 *----------------------------------------------------------------------------------*/

#include <stdio.h>

// Variável global acumuladora para registrar os movimentos na pilha de execução
int total_movimentos = 0;

void hanoi(int n, char origem, char destino, char auxiliar) {
    // CASO BASE: Quando resta apenas o menor disco, ele é movido diretamente sem ramificar a pilha
    if (n == 1) {
        printf("Mova disco 1 de %c para %c\n", origem, destino);
        total_movimentos++;
        return;
    }

    // PASSO RECURSIVO (Parte 1): Move N-1 discos da Origem para o Auxiliar, usando o Destino como suporte
    hanoi(n - 1, origem, auxiliar, destino);

    // Movimento do disco atual (o maior da chamada corrente) para o Destino definitivo
    printf("Mova disco %d de %c para %c\n", n, origem, destino);
    total_movimentos++;

    // PASSO RECURSIVO (Parte 2): Move os N-1 discos do Auxiliar para o Destino, usando a Origem como suporte
    hanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    int n;
    long int calculo_teorico = 1;
    int i;

    printf("Digite o numero de discos (1 a 10): ");
    scanf("%d", &n);

    // Validação do intervalo conforme exigido no roteiro
    while (n < 1 || n > 10) {
        printf("[ERRO] Por favor, informe um valor entre 1 e 10: ");
        scanf("%d", &n);
    }

    printf("\n=== SEQUENCIA DE MOVIMENTOS ===\n\n");
    hanoi(n, 'A', 'C', 'B'); // 'A' = Origem, 'C' = Destino, 'B' = Auxiliar

    // Cálculo manual de 2^n para evitar o uso de pow() da math.h
    for (i = 0; i < n; i++) {
        calculo_teorico *= 2;
    }
    calculo_teorico -= 1; // Aplicação da fórmula 2^n - 1

    printf("\n=== ANALISE ESTATISTICA COMPROVATORIA ===\n");
    printf("Total de movimentos medidos em tempo de execucao: %d\n", total_movimentos);
    printf("Previsao teorica da equacao (2^%d - 1): %ld\n", n, calculo_teorico);

    if (total_movimentos == calculo_teorico) {
        printf("Resultado: Confirmado! O numero de movimentos coincide com a previsao matematica.\n");
    } else {
        printf("Resultado: Erro na verificacao matematica.\n");
    }

    return 0;
}

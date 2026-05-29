/*----------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                   *
 * - Fatec Ipiranga - ADS Vespertino                                                *
 * - Professor: Veríssimo                                                           *
 * - Disciplina: Programação Estruturada e Modular (PEM)                            *
 * - Atividade: Semana 14 - Exercício 16                                            *
 * - Objetivo: Implementar busca linear recursiva e soma por divisão e conquista,   *
 * monitorando o número de chamadas e a profundidade máxima da pilha (Stack).       *
 *----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Variáveis globais para monitoramento da Busca Recursiva
int chamadas_busca = 0;
int prof_atual_busca = 0;
int prof_max_busca = 0;

// Variáveis globais para monitoramento da Soma Recursiva
int chamadas_soma = 0;
int prof_atual_soma = 0;
int prof_max_soma = 0;

int buscaRec(int *v, int n, int chave) {
    chamadas_busca++;
    prof_atual_busca++;
    if (prof_atual_busca > prof_max_busca) {
        prof_max_busca = prof_atual_busca;
    }

    // CASO BASE 1: O vetor acabou e o elemento não foi encontrado
    if (n <= 0) {
        prof_atual_busca--;
        return -1;
    }

    // CASO BASE 2: O elemento foi encontrado na posição atual (testando de trás para frente)
    if (*(v + (n - 1)) == chave) {
        int indice_encontrado = n - 1;
        prof_atual_busca--;
        return indice_encontrado;
    }

    // PASSO RECURSIVO: Reduz o tamanho do vetor inspecionado, chamando a si mesma para o restante
    int resultado = buscaRec(v, n - 1, chave);
    prof_atual_busca--;
    return resultado;
}

int somaRec(int *v, int ini, int fim) {
    chamadas_soma++;
    prof_atual_soma++;
    if (prof_atual_soma > prof_max_soma) {
        prof_max_soma = prof_atual_soma;
    }

    // CASO BASE: O intervalo reduziu-se a um único elemento
    if (ini == fim) {
        int valor = *(v + ini);
        prof_atual_soma--;
        return valor;
    }

    // PASSO RECURSIVO: Divide o intervalo ao meio e ramifica as chamadas
    int meio = (ini + fim) / 2;
    int soma_esquerda = somaRec(v, ini, meio);
    int soma_direita = somaRec(v, meio + 1, fim);

    prof_atual_soma--;
    return soma_esquerda + soma_direita;
}

int main() {
    int vetor[12];
    int i, chave_usuario, indice_resultado, soma_total;

    // Inicializa o gerador de números aleatórios com a semente do tempo atual
    srand((unsigned int)time(NULL));

    // Preenche o vetor com números aleatórios entre 1 e 50
    for (i = 0; i < 12; i++) {
        *(vetor + i) = (rand() % 50) + 1;
    }

    printf("=== VETOR DE 12 ELEMENTOS ALEATORIOS ===\n[ ");
    for (i = 0; i < 12; i++) {
        printf("%d ", *(vetor + i));
    }
    printf("]\n\n");

    // Processamento da Soma Recursiva
    soma_total = somaRec(vetor, 0, 11);
    printf("Soma Total do Vetor: %d\n", soma_total);
    printf("-> Total de chamadas recursivas na soma: %d\n", chamadas_soma);
    printf("-> Profundidade maxima da pilha na soma: %d\n\n", prof_max_soma);

    // Entrada para a Busca
    printf("Informe um valor para buscar no vetor: ");
    scanf("%d", &chave_usuario);

    // Processamento da Busca Recursiva
    indice_resultado = buscaRec(vetor, 12, chave_usuario);

    if (indice_resultado != -1) {
        printf("\nBusca Recursiva: O valor %d foi encontrado no indice [%d].\n", chave_usuario, indice_resultado);
    } else {
        printf("\nBusca Recursiva: O valor %d nao existe no vetor.\n", chave_usuario);
    }
    printf("-> Total de chamadas recursivas na busca: %d\n", chamadas_busca);
    printf("-> Profundidade maxima da pilha na busca: %d\n", prof_max_busca);

    return 0;
}

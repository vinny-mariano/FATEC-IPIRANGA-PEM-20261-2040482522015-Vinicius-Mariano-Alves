/*----------------------------------------------------------*
* FATEC Ipiranga                                            *
* Disciplina: Programaçao Estruturada e Modular             *
* Prof. Veríssimo                                           *
*-----------------------------------------------------------*
* Objetivo do Programa: Refatoração com Ponteiros           *
* Data - 25/04/2026                                         *
* Autor: Vinícius Mariano Alves                             *
*----------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PASTAS 50
#define LIMITE_ALERTA 300.0

typedef struct {
    char nome[50];
    float tamanho_proprio;
    float tamanho_total;
    int subpastas_indices[10];
    int qtd_sub;
} Pasta;

Pasta drive[MAX_PASTAS];

float processarHierarquia(Pasta *p, int nivel_atual, int limite_profundidade) {
    if (p == NULL || nivel_atual > limite_profundidade) {
        return 0;
    }

    p->tamanho_total = p->tamanho_proprio;

    for (int i = 0; i < nivel_atual; i++) {
        printf("  "); 
    }
    
    printf("|-- %s [Proprio: %.2f GB]", p->nome, p->tamanho_proprio);
    
    if (p->tamanho_proprio > LIMITE_ALERTA) {
        printf(" [!] ALERTA: GARGALO");
    }
    printf("\n");

    for (int i = 0; i < p->qtd_sub; i++) {
        int filho_idx = p->subpastas_indices[i];
        p->tamanho_total += processarHierarquia(&drive[filho_idx], nivel_atual + 1, limite_profundidade);
    }

    return p->tamanho_total;
}

int main() {
    clock_t t;

    strcpy(drive[0].nome, "RAIZ");
    drive[0].tamanho_proprio = 10.0;
    drive[0].qtd_sub = 2;
    drive[0].subpastas_indices[0] = 1; 
    drive[0].subpastas_indices[1] = 2; 

    strcpy(drive[1].nome, "Projetos_TI");
    drive[1].tamanho_proprio = 50.0;
    drive[1].qtd_sub = 1;
    drive[1].subpastas_indices[0] = 3; 

    strcpy(drive[2].nome, "Backups_Antigos");
    drive[2].tamanho_proprio = 350.0; 
    drive[2].qtd_sub = 0;

    strcpy(drive[3].nome, "Videos_Aulas");
    drive[3].tamanho_proprio = 280.0;
    drive[3].qtd_sub = 0;

    int limite;
    printf("Defina o limite de profundidade: ");
    if (scanf("%d", &limite) != 1) return 0;

    printf("\n--- RELATORIO DE HIERARQUIA INTELIGENTE ---\n");
    
    t = clock();
    processarHierarquia(&drive[0], 0, limite);
    t = clock() - t;

    printf("-------------------------------------------\n");
    
    double tempo_execucao = ((double)t) / CLOCKS_PER_SEC;
    printf("Tempo (Ponteiros): %f segundos\n", tempo_execucao);
    printf("Ciclos: %ld\n", (long)t);

    return 0;
}

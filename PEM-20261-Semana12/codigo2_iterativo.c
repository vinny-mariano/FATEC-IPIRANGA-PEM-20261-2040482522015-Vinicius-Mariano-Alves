/*----------------------------------------------------------*
* FATEC Ipiranga                                            *
* Disciplina: Programaçao Estruturada e Modular             *
* Prof. Veríssimo                                           *
*-----------------------------------------------------------*
* Objetivo do Programa: Refatoração utilizando iteratividade*
* Data - 25/04/2026                                         *
* Autor: Vinícius Mariano Alves                             *
*----------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PASTAS 4
#define LIMITE_ALERTA 300.0

typedef struct {
    char nome[50];
    float tamanho_proprio;
    float tamanho_total;
    int pai_indice;
    int nivel; 
} Pasta;

Pasta drive[MAX_PASTAS];

void processarIterativo(int limite_profundidade) {
    for (int i = 0; i < MAX_PASTAS; i++) {
        drive[i].tamanho_total = drive[i].tamanho_proprio;
    }

    for (int i = MAX_PASTAS - 1; i > 0; i--) {
        int pai = drive[i].pai_indice;
        if (pai != -1) {
            drive[pai].tamanho_total += drive[i].tamanho_total;
        }
    }

    printf("\n--- RELATORIO ITERATIVO ---\n");
    for (int i = 0; i < MAX_PASTAS; i++) {
        if (drive[i].nivel <= limite_profundidade) {
            for (int j = 0; j < drive[i].nivel; j++) {
                printf("  ");
            }
            printf("|-- %s [%.2f GB]", drive[i].nome, drive[i].tamanho_total);
            if (drive[i].tamanho_total > LIMITE_ALERTA) {
                printf(" [!] ALERTA: GARGALO");
            }
            printf("\n");
        }
    }
}

int main() {
    clock_t t;

    strcpy(drive[0].nome, "RAIZ");
    drive[0].tamanho_proprio = 10.0;
    drive[0].pai_indice = -1;
    drive[0].nivel = 0;

    strcpy(drive[1].nome, "Projetos_TI");
    drive[1].tamanho_proprio = 50.0;
    drive[1].pai_indice = 0;
    drive[1].nivel = 1;

    strcpy(drive[2].nome, "Backups_Antigos");
    drive[2].tamanho_proprio = 350.0;
    drive[2].pai_indice = 0;
    drive[2].nivel = 1;

    strcpy(drive[3].nome, "Videos_Aulas");
    drive[3].tamanho_proprio = 280.0;
    drive[3].pai_indice = 1;
    drive[3].nivel = 2;

    int limite;
    printf("Defina o limite de profundidade: ");
    if (scanf("%d", &limite) != 1) return 0;

    t = clock();
    processarIterativo(limite);
    t = clock() - t;
    
    printf("---------------------------\n");
    
    double tempo_execucao = ((double)t) / CLOCKS_PER_SEC;
    printf("Tempo (Iterativo): %f segundos\n", tempo_execucao);
    printf("Ciclos: %ld\n", (long)t);

    return 0;
}

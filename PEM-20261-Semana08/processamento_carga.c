/*-------------------------------------------------------------------------------------------* 
 * - Nome: Vinícius Mariano Alves                                                            *
 * - Fatec Ipiranga - Ads Vespertino                                                         *
 * - Atividade PEM - Semana 8 - Dia 23/04/2026                                               *
 * - Objetivo: Produção de um programa para processamento de carga                           *
 *-------------------------------------------------------------------------------------------*/

#include<stdio.h>

void processarCarga(float *p, int tam){
    float media = 0;
    float total = 0;
    float acima = 0;
    for(int i = 0 ; i < tam; i++){
        total += *(p + i);
    }
    media = total / tam;
    printf("\n\nMedia %.2f\n", media);
    
    for(int i = 0 ; i < tam ; i++){
        if(*(p + i) > media * 1.10){
            printf("\n\t%do pacote esta acima da media", i+1);
            *(p + i) = *(p + i) * 0.95;
        }
    }
    printf("\n");
    printf("\nPesos corrigidos: ");
    for(int i = 0 ; i < tam; i++){
        printf("%.2f, ", *(p + i));
    }

}

int main(){

    float pesos[] = {100.5, 200.7, 150.2, 130.6, 120.7, 112.4, 185.5, 147.7, 167.2, 179.1};
    float *p = pesos;

    printf("\nPesos da carga: ");
    for(int i = 0 ; i<10; i++){
        printf("Peso: %.2f | Endereco: %p, ", *(p + i), &pesos[i]);
    }
    
    processarCarga(pesos, 10);

    return 0;
}

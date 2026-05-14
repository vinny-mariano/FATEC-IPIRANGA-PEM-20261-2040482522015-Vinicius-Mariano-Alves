#include <stdio.h>
#include "interface.h"
#include "recursao.h"

int main(){

float n1,n2;

int opEscolhida = menu();

switch(opEscolhida){

    case 1:
        printf("=== Soma ===\n");    
        printf("Infrome o primeiro numumero: \n");
        scanf("%f", &n1);
        printf("Infrome o segundo numumero: \n");
        scanf("%f", &n2);

        printf("O resultado da soma e: %.2&f\n", som(&n1, &n2));
        break;
    
    case 2:
        printf("=== Subtracao ===\n");    
        printf("Infrome o primeiro numumero: \n");
        scanf("%f", &n1);
        printf("Infrome o segundo numumero: \n");
        scanf("%f", &n2);

        printf("O resultado da subtracao e: %.2&f\n", sub(&n1, &n2));
        break;
    
    case 3:
        printf("=== Multiplicacao ===\n");
        printf("Infrome o primeiro numumero: \n");
        scanf("%f", &n1);
        printf("Infrome o segundo numumero: \n");
        scanf("%f", &n2);

        printf("O resultado da multiplicacao e: %.2&f \n", mult(&n1, &n2));
        break;

    case 4:
        printf("=== Divisao ===\n");
        printf("Infrome o primeiro numumero: \n");
        scanf("%f", &n1);
        printf("Infrome o segundo numumero: \n");
        scanf("%f", &n2);

        printf("O resultado da soma e: %.2&f\n", div(&n1, &n2));
        break;
    
    default:
        printf("Opcao invalida");
    
}

    return 0;
}
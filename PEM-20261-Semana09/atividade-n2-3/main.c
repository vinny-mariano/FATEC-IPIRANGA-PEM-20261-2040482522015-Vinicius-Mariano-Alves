#include <stdio.h>
#include "interface.h"
#include "recursao.h"

int main(){

float n1,n2;
int int1,int2;

int opEscolhida = menu();

switch(opEscolhida){

    case 1:
        printf("=== Soma ===\n");    
        printf("Informe o primeiro numumero: \n");
        scanf("%f", &n1);
        printf("Infrome o segundo numumero: \n");
        scanf("%f", &n2);

        printf("O resultado da soma e: %.2f\n", som(&n1, &n2));
        break;
    
    case 2:
        printf("=== Subtracao ===\n");    
        printf("Informe o primeiro numumero: \n");
        scanf("%f", &n1);
        printf("Informe o segundo numumero: \n");
        scanf("%f", &n2);

        printf("O resultado da subtracao e: %.2f\n", sub(&n1, &n2));
        break;
    
    case 3:
        printf("=== Multiplicacao ===\n");
        printf("Informe o primeiro numumero: \n");
        scanf("%f", &n1);
        printf("Informe o segundo numumero: \n");
        scanf("%f", &n2);

        printf("O resultado da multiplicacao e: %.2f \n", mult(&n1, &n2));
        break;

    case 4:
        printf("=== Divisao ===\n");
        printf("Informe o primeiro numumero: \n");
        scanf("%f", &n1);
        printf("Informe o segundo numumero: \n");
        scanf("%f", &n2);

        printf("O resultado da divisao e: %.2f\n", div(&n1, &n2));
        break;

    case 5:
        printf("=== Conversao, Decimal para Binario ===\n");
        printf("Informe um numero inteiro para ser convertido: \n");
        scanf("%d", &int1);

        printf("O numero informado convetido para binario e: "); 
        decToBin(int1);
        break;

    case 6:
        printf("=== Potenciacao ===\n");
        printf("Informe um numero inteiro para a base: \n");
        scanf("%d", &int1);
        printf("Informe um numero inteiro para o expoente: \n");
        scanf("%d", &int2);

        printf("%d elevado a %d e: %d", int1, int2, potencia(int1, int2));
        break;

    case 7:
        printf("=== Somar Digitos ===\n");
        printf("Informe um numero inteiro para ter seus digitos somados: \n");
        scanf("%d", &int1);
        printf("A soma dos digitos do numero informado e: %d", somaDigitos(int1));
        break;

    default:
        printf("Opcao invalida");
    
}

    return 0;
}
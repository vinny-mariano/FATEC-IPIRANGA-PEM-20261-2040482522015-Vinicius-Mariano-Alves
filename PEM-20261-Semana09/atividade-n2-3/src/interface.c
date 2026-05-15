#include <stdio.h>
#include "interface.h"

int menu(){
    int opcao;
    
    while (1){
    printf("=== Calculadora===\n");
    printf("Selecione uma opcao no menu (utilize numeros):\n");
    printf("1. Soma\n");
    printf("2. Subtracao\n");
    printf("3. Multiplicacao\n");
    printf("4. Divisao\n");
    printf("5. Conversão de Decimal para Binário\n");
    printf("6. Potenciacao\n");
    printf("7. Somar Digitos\n");

    scanf("%d", &opcao);

    return opcao;

    }


} 
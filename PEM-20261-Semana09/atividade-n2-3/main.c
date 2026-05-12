#include <stdio.h>
#include "interface.h"
#include "recursao.h"

int main(){

float n1,n2;

int opEscolhida = menu();

switch(opEscolhida > 0){

    case 1:
        printf("Infrome o primeiro numumero: ", som(&n1, &n2));
        break;
    
    case 2:
        sub();
        break;
    
    case 3:
        mult();
        break;

    case 4:
        div();
        break
    
    default:
        printf("Opcao invalida");
    
}




    return 0;
}
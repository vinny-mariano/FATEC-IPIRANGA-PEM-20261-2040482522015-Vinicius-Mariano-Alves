#include <stdio.h>
#include "recursao.h"

float som(float *a, float *b){ //soma

    if(*b<=0){
        return *a;
    }

    *a=*a+1;
    *b=*b-1;

    return som(a, b);
}

float sub(float *a, float *b){ //subtração
    if(*b==0){
        return *a;
    }

    *a=*a-1;
    *b=*b-1;

    return sub(a, b);
}

float mult(float *a, float *b){ //multiplicação
    if(*b==0){
        return 0;
    }

    *b = *b-1;

    return *a + mult(a, b);
} 

float div(float *a, float *b){ //divisão
    
    if(*b==0){
        return 0;
    }
    else if(*a<*b){
        return 0;
    }

    *a=*a-*b;
    
    return 1 + div(a, b);
}

void decToBin(int n){
    if( n > 1 ){
        decToBin( n / 2 );
    }
        
    printf("%d", n%2); 
}


int potencia(int base, int exp){
    if(exp==0){
        return 1;
    }
    
    return base * potencia(base, exp - 1 );
}

int somaDigitos(int n){
    if(n==0){
        return 0;
    }

    return n%10 + somaDigitos(n/10);
}

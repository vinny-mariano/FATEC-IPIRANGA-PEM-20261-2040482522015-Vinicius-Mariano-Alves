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
    return sub(*a-1, *b-1);
}

 float mult(float *a, float *b){ /multiplicação
    if(*b==0){
        return 0;
    }
    return *a + mult(*a, *b-1);
} 

float div(float *a, float *b){ //divisão
    
    if(*b==0){
        return 0;
    }
    else if(*a<*b){
        return 0;
    }
    
    return 1 + div((*a-*b), *b);
}

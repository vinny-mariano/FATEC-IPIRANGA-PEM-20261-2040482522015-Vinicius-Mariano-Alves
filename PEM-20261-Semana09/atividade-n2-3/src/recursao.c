#include "recursao.h"

float som(float *a, float *b){
    if(b<=0){
        return a;
    }
    return som(a*+1, b*-1);
}

float sub(float *a, float *b){
    if(*b==0){
        return *a;
    }
    return sub(*a-1, *b-1);
}

 float mult(float *a, float *b){
    if(*b==0){
        return 0;
    }
    return *a + mult(*a, *b-1);
} 

float div(float *a, float *b){
    
    if(*b==0){
        return 0;
    }
    else if(*a<*b){
        return 0;
    }
    
    return 1 + div((*a-*b), *b);
}

/*----------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                   *
 * - Fatec Ipiranga - ADS Vespertino                                                *
 * - Professor: Veríssimo                                                           *
 * - Disciplina: Programação Estruturada e Modular (PEM)                            *
 * - Atividade: Semana 14 - Exercício 02                                            *
 * - Objetivo: Converter centímetros inseridos pelo usuário para metros,            *
 * quilômetros e milhas, aplicando validação robusta contra estouro de memória.     *
 *----------------------------------------------------------------------------------*/

#include <stdio.h>

int main(){

    int cm;
    float m;
    double km, mile;

    printf("Informe um valor positivo em centimetros para ser convertido\n VALOR LIMITE (2.147.483.647)\n");
    scanf("%d", &cm);

    while(cm < 0 || cm > 2147483647){
        printf("Informe um valor positivo em centimetros dentro do valor limite!");
        scanf("%d", &cm); 
    }
    
    //O uso do while garante que o programa continue ativo aceitndo apenas valores que cumpram com a regra estabelecida 

    m = cm / 100.0;
    km = m /1000.0;
    mile = km / 1.60934;

    printf("O valor informado em metros e: %.2f", m);
    printf("O valor informado em quilometros é: %.2lf", km);
    printf("O valor informado em milhas e: %.2lf", mile);


    return 0;
}

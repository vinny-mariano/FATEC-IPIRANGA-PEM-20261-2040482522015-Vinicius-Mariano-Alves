/*----------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                   *
 * - Fatec Ipiranga - ADS Vespertino                                                *
 * - Professor: Veríssimo                                                           *
 * - Disciplina: Programação Estruturada e Modular (PEM)                            *
 * - Atividade: Semana 14 - Exercício 03                                            *
 * - Objetivo: Calcular o IMC a partir do peso e altura, tratando entradas          *
 * inválidas e classificando o resultado com condicionais encadeadas.        *
 *----------------------------------------------------------------------------------*/

#include <stdio.h>

int main() {
    
    double peso, altura, imc;

    printf("Digite o seu peso (kg): ");
    scanf("%lf", &peso);
    printf("Digite a sua altura (m): ");
    scanf("%lf", &altura);

    // VALIDAÇÃO DE ENTRADA
    if (peso <= 0 || altura <= 0) {
        printf("\nPeso e altura devem ser valores maiores que zero!\n");
    } 
    else {
        imc = peso / (altura * altura);

        printf("\nSeu IMC e: %.2lf\n", imc);

        if (imc < 18.5) {
            printf("Classificacao: Abaixo do peso\n");
        } 
        else if (imc < 25.0) {
            printf("Classificacao: Peso normal\n");
        } 
        else if (imc < 30.0) {
            printf("Classificacao: Sobrepeso\n");
        } 
        else {
            printf("Classificacao: Obesidade\n");
        }
    }

    return 0;
}

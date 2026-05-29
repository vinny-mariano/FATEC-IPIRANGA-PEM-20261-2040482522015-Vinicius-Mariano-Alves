/*---------------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                        *
 * - Fatec Ipiranga - ADS Vespertino                                                     *
 * - Professor: Veríssimo                                                                *
 * - Disciplina: Programação Estruturada e Modular (PEM)                                 *
 * - Atividade: Semana 14 - Exercício 04                                                 *
 * - Objetivo: Validar um triângulo e classificá-lo por seus lados                       *
 * (Equilátero/Isósceles/Escaleno) e por seus ângulos (Retângulo/Obtusângulo/Acutângulo).*
 *---------------------------------------------------------------------------------------*/

#include <stdio.h>

int main() {
    double A, B, C;
    double maior, lado2, lado3;

    printf("Informe os tres lados do triangulo:\n");
    printf("Lado A: ");
    scanf("%lf", &A);
    printf("Lado B: ");
    scanf("%lf", &B);
    printf("Lado C: ");
    scanf("%lf", &C);

    // VERIFICAÇÃO DA ESTRUTURA DO TRIANGULO
    if ((A < B + C) && (B < A + C) && (C < A + B)) {
        
        printf("\nOs valores formam um triangulo valido!\n");

        // CLASSIFICAÇÃO USANDO O TAMANHO DOS LADOS
        if ((A == B) && (B == C)) {
            printf("Classificacao por Lados: Equilatero\n");
        } 
        else if ((A == B) || (B == C) || (A == C)) {
            printf("Classificacao por Lados: Isosceles\n");
        } 
        else {
            printf("Classificacao por Lados: Escaleno\n");
        }

        // IdentificaÇÃO Do maior lado
        if (A >= B && A >= C) {
            maior = A; lado2 = B; lado3 = C;
        } else if (B >= A && B >= C) {
            maior = B; lado2 = A; lado3 = C;
        } else {
            maior = C; lado2 = A; lado3 = B;
        }

        // CLASSIFICAÇÃO DOS ÂNGULOS
        double quadradoMaior = maior * maior;
        double somaQuadradosLados = (lado2 * lado2) + (lado3 * lado3);

        if (quadradoMaior == somaQuadradosLados) {
            printf("Classificacao por Angulos: Retangulo\n");
        } 
        else if (quadradoMaior > somaQuadradosLados) {
            printf("Classificacao por Angulos: Obtusangulo\n");
        } 
        else {
            printf("Classificacao por Angulos: Acutangulo\n");
        }

    } else {
        // Se a validação falhar, o bloco principal é ignorado.
        printf("\nOs valores informados nao cumprem a desigualdade triangular. Nao e um triangulo!\n");
    }

    return 0;
}

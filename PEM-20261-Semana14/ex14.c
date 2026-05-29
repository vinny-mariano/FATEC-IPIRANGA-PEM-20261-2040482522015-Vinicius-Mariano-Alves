/*----------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                   *
 * - Fatec Ipiranga - ADS Vespertino                                                *
 * - Professor: Veríssimo                                                           *
 * - Disciplina: Programação Estruturada e Modular (PEM)                            *
 * - Atividade: Semana 14 - Exercício 14                                            *
 * - Objetivo: Implementar uma calculadora modular com menu interativo, utilizando  *
 * protótipos, Algoritmo de Euclides, potência, testes de primos e binários.        *
 *----------------------------------------------------------------------------------*/

#include <stdio.h>

// DECLARAÇÃO DOS PROTÓTIPOS DAS FUNÇÕES (Contratos pré-main)
int calcularMdc(int a, int b);
long int calcularPotencia(int base, int expoente);
int verificarPrimo(int n);
void decimalParaBinario(int decimal, char *buffer);

int main() {
    int opcao;
    int num1, num2;
    char resultado_binario[33]; // Buffer de tamanho suficiente para 32 bits + '\0'

    do {
        printf("\n=== CALCULADORA MODULAR INTERATIVA ===\n");
        printf("1. Maximo Divisor Comun (MDC)\n");
        printf("2. Potencia Inteira\n");
        printf("3. Verificar Numero Primo\n");
        printf("4. Conversao Decimal -> Binario\n");
        printf("0. Sair do Programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nDigite o primeiro numero inteiro: ");
                scanf("%d", &num1);
                printf("Digite o segundo numero inteiro: ");
                scanf("%d", &num2);
                printf("O MDC entre %d e %d e: %d\n", num1, num2, calcularMdc(num1, num2));
                break;

            case 2:
                printf("\nDigite a base (inteiro): ");
                scanf("%d", &num1);
                printf("Digite o expoente (inteiro positivo): ");
                scanf("%d", &num2);
                if (num2 < 0) {
                    printf("[ERRO] O expoente nao pode ser negativo nesta funcao.\n");
                } else {
                    printf("%d elevado a %d e: %ld\n", num1, num2, calcularPotencia(num1, num2));
                }
                break;

            case 3:
                printf("\nDigite um numero inteiro positivo: ");
                scanf("%d", &num1);
                if (verificarPrimo(num1)) {
                    printf("O numero %d E primo.\n", num1);
                } else {
                    printf("O numero %d NAO e primo.\n", num1);
                }
                break;

            case 4:
                printf("\nDigite um numero decimal positivo: ");
                scanf("%d", &num1);
                if (num1 < 0) {
                    printf("[ERRO] Digite um numero maior ou igual a zero.\n");
                } else {
                    decimalParaBinario(num1, resultado_binario);
                    printf("O numero %d em binario e: %s\n", num1, resultado_binario);
                }
                break;

            case 0:
                printf("\nEncerrando o sistema da calculadora modular...\n");
                break;

            default:
                printf("\n[ERRO] Opcao invalida! Escolha um item do menu.\n");
        }

    } while (opcao != 0);

    return 0;
}

/*----------------------------------------------------------------------------------*
 * Parâmetros: int a, int b -> Os dois números inteiros para o cálculo.            *
 * Retorno: int -> O valor do Máximo Divisor Comum encontrado.                     *
 * Complexidade Algorítmica: O(log(min(a, b))) -> Tempo logarítmico (Euclides).     *
 *----------------------------------------------------------------------------------*/
int calcularMdc(int a, int b) {
    int resto;
    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

/*----------------------------------------------------------------------------------*
 * Parâmetros: int base -> O número base, int expoente -> Grau da potência.         *
 * Retorno: long int -> O resultado do cálculo da exponenciação.                   *
 * Complexidade Algorítmica: O(n) onde n é o valor do expoente -> Tempo linear.     *
 *----------------------------------------------------------------------------------*/
long int calcularPotencia(int base, int expoente) {
    long int resultado = 1;
    int i;
    for (i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

/*----------------------------------------------------------------------------------*
 * Parâmetros: int n -> O número inteiro a ser testado.                             *
 * Retorno: int -> Retorna 1 se o número for primo, ou 0 caso contrário.            *
 * Complexidade Algorítmica: O(sqrt(n)) -> Tempo baseado na raiz quadrada de n.      *
 *----------------------------------------------------------------------------------*/
int verificarPrimo(int n) {
    int i;
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    for (i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

/*----------------------------------------------------------------------------------*
 * Parâmetros: int decimal -> O número base, char *buffer -> Vetor de string.       *
 * Retorno: void -> A alteração e escrita são realizadas in-place via ponteiro.    *
 * Complexidade Algorítmica: O(log2(n)) -> Baseado nas divisões sucessivas por 2.  *
 *----------------------------------------------------------------------------------*/
void decimalParaBinario(int decimal, char *buffer) {
    int i = 0;
    int inicio = 0;
    int fim;
    char aux;

    if (decimal == 0) {
        *(buffer + 0) = '0';
        *(buffer + 1) = '\0';
        return;
    }

    while (decimal > 0) {
        *(buffer + i) = (decimal % 2) + '0'; // Converte o resto numérico (0 ou 1) para char ('0' ou '1')
        decimal /= 2;
        i++;
    }
    *(buffer + i) = '\0';

    fim = i - 1;
    while (inicio < fim) {
        aux = *(buffer + inicio);
        *(buffer + inicio) = *(buffer + fim);
        *(buffer + fim) = aux;
        inicio++;
        fim--;
    }
}

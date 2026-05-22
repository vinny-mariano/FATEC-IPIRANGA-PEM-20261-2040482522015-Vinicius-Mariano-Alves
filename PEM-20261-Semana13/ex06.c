/*-------------------------------------------------------------------------------------------* 
 * - Autor: Vinícius Mariano Alves                                                           *
 * - Fatec Ipiranga - Ads Vespertino                                                         *
 * - Atividade PEM - Semana 13 - Dia 21/05/2026                                              *
 * - Objetivo: Manipular campos de um struct Produto por ponteiro comparando as sintaxes     *
 * (*p).campo e p->campo.                                                                  *
 *-------------------------------------------------------------------------------------------*/
#include <stdio.h>

struct Produto {
    char nome[40];
    float preco;
    int estoque;
};

int main() {
    struct Produto cafe;
    struct Produto *p = &cafe;

    // Escrita e Leitura usando obrigatoriamente (*p).campo
    (*p).preco = 150.00f;
    (*p).estoque = 30;
    printf("Via (*p): Preco = %.2f, Estoque = %d\n", (*p).preco, (*p).estoque);

    // Escrita e Leitura usando obrigatoriamente p->campo
    p->preco = 135.50f;
    p->estoque = 45;
    printf("Via p->  : Preco = %.2f, Estoque = %d\n", p->preco, p->estoque);

    return 0;
}
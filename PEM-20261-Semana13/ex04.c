/*---------------------------------------------------------------------------------------------* 
 * - Autor: Vinícius Mariano Alves                                                             *
 * - Fatec Ipiranga - Ads Vespertino                                                           *
 * - Atividade PEM - Semana 13 - Dia 21/05/2026                                                *
 * - Objetivo: Criar um struct Aluno, popular uma instância e exibir o endereço de cada campo  *
 * explicando a disposição consecutiva.                                                        *
 *---------------------------------------------------------------------------------------------*/
#include <stdio.h>

struct Aluno {
    char nome[50];
    int matricula;
    float media;
};

int main() {
    struct Aluno aluno = {"Vinicius Alves", 002015, 8.9f};

    printf("Endereco do campo 'nome': %p\n", (void*)&aluno.nome);
    printf("Endereco do campo 'matricula': %p\n", (void*)&aluno.matricula);
    printf("Endereco do campo 'media': %p\n", (void*)&aluno.media);

    /* COMENTÁRIO EXPLICATIVO:
     * Os endereços na memória são sequenciais, mas podem não ser consecutivos 
     * devido ao Alinhamento de Memória (Data Alignment).
     * O compilador adiciona espaços vazios (padding) para que os tipos de dados fiquem alinhados
     * com o tamanho de palavra nativo da CPU, otimizando o desempenho do hardware.
     */

    return 0;
}
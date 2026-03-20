/*-------------------------------------------------------------------------------------------* 
 * - Nome: Vinícius Mariano Alves                                                            *
 * - Fatec Ipiranga - Ads Vespertino                                                         *
 * - Atividade PEM - Semana 4 - Dia 12/03/2026                                               *
 * - Objetivo: Produção de um algoritmo em linguagem de programação estruturada              *
 * (C ou similar), aplicando conceitos de manipulação de matrizes multidimensionais,         *
 * estruturas de repetição, condicionais e controle de fluxo..                               *
 *-------------------------------------------------------------------------------------------*/


#include <stdio.h>  // Biblioteca padrão para entrada e saída (printf, scanf)

// Função que recebe a matriz do tabuleiro e verifica se há um vencedor
int verificarVitoria(char tab[3][3]) {
    for (int i = 0; i < 3; i++) {
        // Verifica as 3 linhas: se os 3 elementos da linha 'i' são iguais
        if (tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2]) return 1;
        // Verifica as 3 colunas: se os 3 elementos da coluna 'i' são iguais
        if (tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i]) return 1;
    }
    
    // Verifica a diagonal principal (topo-esquerda para baixo-direita)
    if (tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]) return 1;
    
    // Verifica a diagonal secundária (topo-direita para baixo-esquerda)
    if (tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0]) return 1;

    return 0; // Se ninguém venceu, retorna 0
}

int main() {
    char jogador1, jogador2, simboloAtual;
    int posi, linha, coluna;
    // Inicializa o tabuleiro com os números das posições para facilitar a escolha
    char tabuleiro[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    // Escolha do símbolo pelo primeiro jogador
    printf("Jogador 1, escolha seu simbolo (X ou O): ");
    while (1) { // Loop infinito até que uma escolha válida seja feita
        scanf(" %c", &jogador1); // O espaço antes de %c limpa o 'buffer' (evita ler o Enter anterior)
        if (jogador1 == 'x' || jogador1 == 'X') {
            jogador1 = 'X'; jogador2 = 'O'; // Se J1 é X, J2 é O
            break;
        } else if (jogador1 == 'o' || jogador1 == 'O' || jogador1 == '0') {
            jogador1 = 'O'; jogador2 = 'X'; // Se J1 é O, J2 é X
            break;
        } else {
            printf("Escolha invalida! Digite X ou O: ");
        }
    }

    printf("Jogador 1: [%c] vs Jogador 2: [%c]\n", jogador1, jogador2);

    // Loop que controla as 9 rodadas possíveis do jogo
    for (int jogadas = 0; jogadas < 9; jogadas++) {
        
        // Alternância de turnos: se a jogada for par, é o J1; se for ímpar, é o J2
        simboloAtual = (jogadas % 2 == 0) ? jogador1 : jogador2;

        // Desenha visualmente o tabuleiro na tela
        printf("\nTabuleiro Atual:\n");
        for (int i = 0; i < 3; i++) {
            printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
            if (i < 2) printf("---|---|---\n"); // Desenha a divisória horizontal
        }

        // Loop de validação da jogada
        while (1) {
            printf("\nJogador [%c], informe a posicao (1-9): ", simboloAtual);
            scanf("%d", &posi);

            // Cálculo matemático para converter 1-9 em coordenadas (0-2) da matriz
            linha = (posi - 1) / 3;
            coluna = (posi - 1) % 3;

            // Valida se a posição existe e se ainda tem um número (não foi ocupada por X ou O)
            if (posi >= 1 && posi <= 9 && tabuleiro[linha][coluna] != 'X' && tabuleiro[linha][coluna] != 'O') {
                tabuleiro[linha][coluna] = simboloAtual; // Marca a jogada no tabuleiro
                break; // Sai do loop de validação
            } else {
                printf("Posicao invalida ou ocupada! Tente novamente.");
            }
        }

        // Chama a função para checar se a última jogada encerrou o jogo
        if (verificarVitoria(tabuleiro)) {
            printf("\n--- FIM DE JOGO ---\n");
            printf("Parabens! O Jogador [%c] venceu!\n", simboloAtual);
            
            // Desenha o tabuleiro uma última vez para mostrar a vitória
            for (int i = 0; i < 3; i++) {
                printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
                if (i < 2) printf("---|---|---\n");
            }
            return 0; // Finaliza o programa vitorioso
        }
    }

    // Se o loop de 9 jogadas terminar sem retorno, deu empate
    printf("\nDeu Velha! Ninguem venceu.\n");
    return 0;
}

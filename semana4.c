#include <stdio.h>
#include <stdlib.h>

// Função para verificar se alguém venceu
int verificarVitoria(char tab[3][3]) {
    for (int i = 0; i < 3; i++) {
        // Linhas e Colunas
        if (tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2]) return 1;
        if (tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i]) return 1;
    }
    // Diagonais
    if (tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]) return 1;
    if (tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0]) return 1;

    return 0;
}

int main() {
    char jogador1, jogador2, simboloAtual;
    int posi, linha, coluna;
    char tabuleiro[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    // Escolha do símbolo inicial
    printf("Jogador 1, escolha seu simbolo (X ou O): ");
    while (1) {
        scanf(" %c", &jogador1);
        if (jogador1 == 'x' || jogador1 == 'X') {
            jogador1 = 'X'; jogador2 = 'O';
            break;
        } else if (jogador1 == 'o' || jogador1 == 'O' || jogador1 == '0') {
            jogador1 = 'O'; jogador2 = 'X';
            break;
        } else {
            printf("Escolha invalida! Digite X ou O: ");
        }
    }

    printf("Jogador 1: [%c] vs Jogador 2: [%c]\n", jogador1, jogador2);

    // Loop principal do jogo (máximo 9 jogadas)
    for (int jogadas = 0; jogadas < 9; jogadas++) {
        
        // Define de quem é a vez
        simboloAtual = (jogadas % 2 == 0) ? jogador1 : jogador2;

        // Desenha o tabuleiro
        printf("\nTabuleito Atual:\n");
        for (int i = 0; i < 3; i++) {
            printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
            if (i < 2) printf("---|---|---\n");
        }

        // Pede a jogada e valida
        while (1) {
            printf("\nJogador [%c], informe a posicao (1-9): ", simboloAtual);
            scanf("%d", &posi);

            linha = (posi - 1) / 3;
            coluna = (posi - 1) % 3;

            // Verifica se a posição é válida e se não está ocupada
            if (posi >= 1 && posi <= 9 && tabuleiro[linha][coluna] != 'X' && tabuleiro[linha][coluna] != 'O') {
                tabuleiro[linha][coluna] = simboloAtual;
                break; // Jogada válida, sai do while
            } else {
                printf("Posicao invalida ou ocupada! Tente novamente.");
            }
        }

        // Verifica se houve vitória
        if (verificarVitoria(tabuleiro)) {
            printf("\n--- FIM DE JOGO ---\n");
            printf("Parabens! O Jogador [%c] venceu!\n", simboloAtual);
            
            // Mostra o tabuleiro final
            for (int i = 0; i < 3; i++) {
                printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
                if (i < 2) printf("---|---|---\n");
            }
            return 0; // Encerra o programa
        }
    }

    printf("\nDeu Velha! Ninguem venceu.\n");
    return 0;
}
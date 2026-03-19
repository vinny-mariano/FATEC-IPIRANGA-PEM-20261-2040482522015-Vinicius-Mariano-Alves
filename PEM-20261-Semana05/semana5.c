/*-------------------------------------------------------------------------------------------* 
 * - Nome: Vinícius Mariano Alves                                                            *
 * - Fatec Ipiranga - Ads Vespertino                                                         *
 * - Atividade PEM - Semana 5 - Dia 14/03/2026                                               *
 * - Objetivo: Desenvolva um código (linguagem C) que, a partir do tabuleiro montado, simule *
 * os 3 lances do "Xeque Pastor".                                                            *
 *-------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

//Constantes para definir o tamanho do tabuleiro e facilitar a manutenção do código
#define LINHAS 8 
#define COLUNAS 8 
    
    //Função para a exbição do tabuleiro utilizando loops aninhados
    //Função para a exbição do tabuleiro utilizando loops aninhados
    //Função para a exbição do tabuleiro utilizando loops aninhados
    void exibirTabuleiro(char tabuleiro[LINHAS][COLUNAS][8]) {
        printf("\n------------------------ TABULEIRO -------------------------\n");
        for (int i = 0; i < LINHAS; i++){
            // Adicionei dois espaços antes dos traços para alinhar com o número
            printf("   -----  -----  -----  -----  -----  -----  -----  -----   \n");
            printf("%d ", 8-i); 
            for (int j = 0; j < COLUNAS; j++){
                printf("%s", tabuleiro[i][j]);
            }
            printf("\n");
        }
        // Rodapé do tabuleiro
        printf("   -----  -----  -----  -----  -----  -----  -----  -----   \n");
        // Espaçamento preciso para as letras (5 espaços entre elas)
        printf("     A      B      C      D      E      F      G      H      \n");
        printf("-------------------------------------------------------------\n");        
    }

    void realizarJogada(char tabuleiro[LINHAS][COLUNAS][8], int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){

        //Copia a string em uma posição e cola em outra 
        strcpy(tabuleiro[linhaDestino][colunaDestino], tabuleiro[linhaOrigem][colunaOrigem]);
        
        //Marca a posição de onde a peça saiu
        strcpy(tabuleiro[linhaOrigem][colunaOrigem], "|[...]|");

    }


    int main(){

        //Declaração da matriz com as posições do tabuleiro (Ajustado para Dama na Coluna D)
        char tabuleiro[LINHAS][COLUNAS][8] = {
            {"|[Tp1]|", "|[Cp2]|", "|[Bp3]|", "|[Dp4]|", "|[Rp5]|", "|[Bp6]|", "|[Cp7]|", "|[Tp8]|"},
            {"|[Pp1]|", "|[Pp2]|", "|[Pp3]|", "|[Pp4]|", "|[Pp5]|", "|[Pp6]|", "|[Pp7]|", "|[Pp8]|"},
            {"|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|"},
            {"|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|"},
            {"|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|"},
            {"|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|", "|[   ]|"},
            {"|[Pb1]|", "|[Pb2]|", "|[Pb3]|", "|[Pb4]|", "|[Pb5]|", "|[Pb6]|", "|[Pb7]|", "|[Pb8]|"},
            {"|[Tb1]|", "|[Cb2]|", "|[Bb3]|", "|[Db4]|", "|[Rb5]|", "|[Bb6]|", "|[Cb7]|", "|[Tb8]|"}
        };
        
        //Chamada da função que exibe o estado inicial do tabuleiro 
        exibirTabuleiro(tabuleiro);

        //PRIMEIRA JOGADA: Brancas movem Peão para e4
        // Origem: Linha 6, Coluna 4 (e2) -> Destino: Linha 4, Coluna 4 (e4)
        realizarJogada(tabuleiro, 6, 4, 4, 4);
        printf("\nJOGADA 1 (Brancas: Peao para E4): \n");
        exibirTabuleiro(tabuleiro);

        // Pretas jogam e5: Sai da linha 1 para a linha 3
        realizarJogada(tabuleiro, 1, 4, 3, 4); 
        printf("\nJOGADA 1 (Pretas: Peao para E5): \n");
        exibirTabuleiro(tabuleiro);

        //Brancas jogam Bispo para C4
        //Origem: Linha 7, Coluna 5 (f1) -> Destino: Linha 4, Coluna 2 (c4)
        realizarJogada(tabuleiro, 7, 5, 4, 2);
        printf("\nJOGADA 2 (Brancas: Bispo para C4):\n");
        exibirTabuleiro(tabuleiro);

        //Pretas jogam Cavalo para C6
        //Origem: Linha 0, Coluna 1 (b8) -> Destino: Linha 2, Coluna 2 (c6)
        realizarJogada(tabuleiro, 0, 1, 2, 2);
        printf("\nJOGADA 2 (Pretas: Cavalo para C6):\n");
        exibirTabuleiro(tabuleiro);

        //Brancas jogam Dama para H5
        //Origem: Linha 7, Coluna 3 (d1) -> Destino: Linha 3, Coluna 7 (h5)
        realizarJogada(tabuleiro, 7, 3, 3, 7);
        printf("\nJOGADA 3 (Brancas: Dama para H5):\n");
        exibirTabuleiro(tabuleiro);

        //Pretas jogam Bispo para C5
        //Origem: Linha 0, Coluna 5 (f8) -> Destino: Linha 3, Coluna 2 (c5)
        realizarJogada(tabuleiro, 0, 5, 3, 2);
        printf("\nJOGADA 3 (Pretas: Bispo para C5):\n");
        exibirTabuleiro(tabuleiro);

        //Brancas jogam Dama Captura Peão em F7
        //Origem: Linha 3, Coluna 7 (h5) -> Destino: Linha 1, Coluna 5 (f7)
        realizarJogada(tabuleiro, 3, 7, 1, 5);
        printf("\nJOGADA 4 (Brancas: Dama Captura Peao em F7 - XEQUE-MATE!):\n");
        exibirTabuleiro(tabuleiro);

    return 0;
}

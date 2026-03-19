/*-------------------------------------------------------------------------------------------*
 * - Nome: Vinícius Mariano Alves                                                            *
 * - Fatec Ipiranga - Ads Vespertino                                                         *
 * - Atividade PEM - Semana 4 - Dia 27/02/2026                                               *
 * - Objetivo: Produção de um algoritmo em linguagem de programação estruturada              *
 * (C ou similar), que faça contagem de palavras.                                            *               
 *-------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
 
 
int main()
{
    char frase [20];
    printf("Digite uma frase qualquer: ");
     fgets(frase,sizeof(frase),stdin);
     printf("a frase digitada foi: %s\n ",frase);
     int palavras=0;
     int tamanho;
     int i;
     tamanho = strlen(frase);
     for (i=0;i<tamanho;i++){
         if(frase[i] == ' ' && frase [i+1] != ' '){
             palavras++;
         }
     }
       palavras = palavras +1 ;
       printf("o numero de palavras presente nessa frase e: %d", palavras);

 
    return 0;
}

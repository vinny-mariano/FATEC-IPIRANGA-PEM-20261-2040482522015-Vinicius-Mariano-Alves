#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

    //Struct Pizza
    struct Pizza{
        float preco;
        char sabor[20];
    };

    //Escolher sabor
    struct Pizza escolherSabor(int opcao){
        struct Pizza p;
        
        if (opcao ==1){
            p.preco = 39.99;
            strcpy(p.sabor, "Marguerita");
        }
        else if (opcao == 2){
            p.preco = 38.99;
            strcpy(p.sabor, "Calabresa");
        }
        else if (opcao == 3){
            p.preco = 45.99;
            strcpy(p.sabor, "Palmito");
        }
        else {
            printf("Erro");
        }

        return p;
        
    }

    //Struct Pedido que contém a pizza escolhida e o id do pedido
    struct Pedido{

        int id;
        struct Pizza pizzaEscolhida;
    };

    void imprimirRecibo(struct Pedido p) {
        printf("\n\n*---===<<< Recibo >>>===---*");
        printf("\nID: %d", p.id);
        printf("\nSabor: %s", p.pizzaEscolhida.sabor);
        printf("\nPreco: R$ %.2f", p.pizzaEscolhida.preco);
        printf("\n----------------------------\n");
    }
    

    void exibirMenu(){
        printf("\n>>>=== MENU ===<<<");
        printf("\n");
        printf("\n1. Pizza Maguerita - R$ 39.99");
        printf("\n2. Pizza Calabresa - R$ 38.99");
        printf("\n3. Pizza Palmito - R$ 45.99");
        printf("\n");
    }
    
    int main(){

        char bemVindo[31] = "Bem vindo a pizzaria Bate-Papo.";
        char escolha[31] = "\nEscolha uma opcao do menu: \n";
        int opcao, confirmar;
        struct Pedido novoPedido;
        
        srand(time(NULL));
        novoPedido.id = (rand() % 5000) +1;
        

        //Chamada de boas vindas
        for (int i = 0; i<bemVindo[i]; i++){
            printf("%c", bemVindo[i]);
            for(int j=0 ; j<60000000; j++){
            }
        }

        //Escolha uma opcao do menu:
        printf("\n");
        
        for (int i = 0; i<escolha[i]; i++){
            printf("%c", escolha[i]);
            for(int j=0 ; j<50000000; j++){
            }
        }


        do {

        //Exibição do menu
        exibirMenu();
        scanf("%d", &opcao);

            //Validação de input de opcao
            while(opcao < 1 || opcao > 3 ){
                printf("\nInforme uma opcao valida\n");
                printf("\n");
                exibirMenu();
                scanf("%d", &opcao);
            }
        
            novoPedido.pizzaEscolhida = escolherSabor(opcao);

            imprimirRecibo(novoPedido);

            printf("\nConfirar pedido? ( 1 - Sim / 0 - Alterar ): ");
            scanf("%d", &confirmar);
        
        }while (confirmar == 0);

        printf("\nPedido enviado para a cozinha!\n");
        
    return 0;
}
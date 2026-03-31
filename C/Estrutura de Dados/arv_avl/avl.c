#include <stdio.h>
#include "arv_avl.h"

int main(){
    printf("\n=====MENU=====");
    int op, valor;
    Avl* raiz = NULL;

    do{
        printf("\n 0. Sair \n 1.Inserir\n 2.Imprimir\n");
        printf("\nOp: ");
        scanf("%d", &op);
        switch (op){
        case 0:
            printf("\nPrograma finalizado.\n");
            break;
        case 1:
            printf("\nValor: ");
            scanf("%d", &valor);
            raiz = Avl_insercao(raiz, valor);
            break;
        case 2:
            //avl_imprimir(raiz, 1);
            imprima_estrutura(raiz, 1);
            break;
        default:
            break;
        }
    } while(op!=0);

    return 0;
}
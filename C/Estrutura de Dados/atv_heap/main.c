#include <stdio.h>
#include "heap.h"
#define MAX 9
int main(){
    int S[MAX] = {0};
    int opcao = 1;
    int n = 0;
    int p, i;

    do{
        printf("\n\x1b[38;2;0;180;2550m------------HEAP--MENU------------\x1b[0m");
        printf("\n\x1b[38;2;255;255;255m 1. Criar\x1b[0m");
        printf("\n\x1b[38;2;255;255;255m 2. Inserir\x1b[0m");
        printf("\n\x1b[38;2;255;255;255m 3. Consultar Prioridade Maxima\x1b[0m");
        printf("\n\x1b[38;2;255;255;255m 4. Remover/Extrair maior Prioridade\x1b[0m");
        printf("\n\x1b[38;2;255;255;255m 5. Aumentar Prioridade\x1b[0m");  
        printf("\n\x1b[38;2;255;255;255m 6. Imprimir seu vetor HEAP\x1b[0m");
        printf("\n\x1b[38;2;255;255;255m 7. Ordenar usando HEAP\x1b[0m");
        printf("\n\x1b[38;2;255;255;255m 0. Sair\x1b[0m");
        printf("\n\x1b[38;2;0;180;2550m----------------------------------\x1b[0m\n");

        printf("\n\x1b[38;2;255;255;0m -> Qual sua Opcao: \x1b[0m");
        scanf("%d", &opcao);  
           
        switch (opcao){
         
            // Construcao do max Heap.
            case 1:
                printf("\n\x1b[38;2;0;180;2550m[--- CONSTRUIR UM MAX HEAP ---]\x1b[0m");
                construir_max_heap(n, S);
                printf("\n\x1b[38;2;0;255;0m-> MAX HEAP CONSTRUIDO\x1b[0m\n");

                break;

            // Inserir.
            case 2:
                printf("\n\x1b[38;2;0;180;2550m[--- INSERIR ELEMENTO ---]\x1b[0m\n");
                printf("\n\x1b[38;2;255;255;0m-> Digite um elemento: \x1b[0m");
                scanf("%d", &p);
                inserir(&n, S, &p);
                printf("\n\x1b[38;2;0;255;0m-> Elemento Inserido\x1b[0m\n");
                break;

            // Consulta ao elemento de maior priridade.
            case 3:
                printf("\n\x1b[38;2;0;180;2550m[--- CONSULTA DO ELEMENTO DE MAIOR PRIORIDADE ---]\x1b[0m");
                printf("\n\x1b[38;2;0;255;0m-> ELEMENTO DE MAIOR PRIORIDADE: %d\x1b[0m\n", maior_prioridade(S));
                break;

            // Remocao do elemento de maior prioridade.
            case 4:
                extrair_max(&n, S);
                printf("\n\x1b[38;2;0;255;0m[-> ELEMENTO DE MAIOR PRIORIDADE REMOVIDA]\x1b[0m\n");
                break;

            // Aumentar a prioridade de um elemento
            case 5:
                printf("\n\x1b[38;2;0;180;2550m[--- AUMENTAR PRIORIDADE DE UM ELEMENTO ---]\x1b[0m\n");
                printf("\x1b[38;2;255;255;0m-> Digite o indice do elemento: \x1b[0m");
                scanf("%d", &i);

                printf("\x1b[38;2;255;255;0m-> Digite um novo valor: \x1b[0m");
                scanf("%d", &p);

                aumenta_prioridade(n, S, i, p);
                
                break;

            // Imprimir o HEAP.
            case 6:
                printf("\n\x1b[38;2;0;180;2550m[--- IMPRIMIR HEAP ---]\x1b[0m\n");
                imprimir(n, S);
                break;
            // Encerrando o programa.
            case 0:
                printf("\n====================");
                printf("\nSAINDO DO PROGRAMA");
                printf("\n====================");
                break;

            default:
                printf("\n\x1b[38;2;255;0;0m Digite uma opcao valida.\x1b[0m");
        }

    } while(opcao != 0);

    return 0;

}
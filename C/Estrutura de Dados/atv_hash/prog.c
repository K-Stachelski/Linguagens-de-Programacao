// Utilizar a biblioteca criada e testar com as entradas.
#include <stdio.h>
#include "mhash.h"
#include <string.h>

int main(){
    int escolha = 1;
    char nome[50];
    Celula T[MAX]; // Tabela criada ou seja o vetor de tamanho N.
    int m = MAX;
    float md = 0;

    // Menu
    do{
        printf("\n===============");
        printf("\n1. Criar");
        printf("\n2. Buscar");
        printf("\n3. Insere");
        printf("\n4. Remove");
        printf("\n0. Sair\n");
        printf("=================");

        // O que deseja fazer.
        printf("\n=== Qual sua Opcao: ");
        scanf("%d", &escolha);

        // Qual Elemento quer inserir, remover ou buscar.
        int x;
        float md = 0;

        switch(escolha){
            // CRIACAO DA TABELA
            case 1:
                Criar(T);
                printf("===TABELA CRIADA===\n");
                break;

            // BUSCA
            case 2:
                printf("\n=== Qual Chave deseja buscar: ");
                scanf("%d", &x);
                printf("\n=== Elemento esta na posicao %d ===", Busca(MAX, T, x));
                break;

            // INSERCAO
            case 3:
                printf("\n=== Insira uma Chave: ");
                scanf("%d", &x);
                
                printf("\n=== Insira seu Nome: ");
                scanf("%s", nome);

                printf("\n=== Media de Desempenho: ");
                scanf("%f", &md);

                Inserir(MAX, T , x, nome, md);
                break;

            // REMOVER
            case 4:
                printf("\n=== Qual Chave deseja remover: ");
                scanf("%d", &x);
                Remover(MAX, T, x);
                break;
            
            case 5:
                imprimir(m, T);

            case 0:
                printf("\nSAINDO\n");
                break;         
                 
            default:
                printf("\nDIGITE UMA OPCAO VALIDA\n");
        }
    } while(escolha);
    return 0;
}
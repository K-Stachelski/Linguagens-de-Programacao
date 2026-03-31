#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "avl_library.h"

int main(){
    Avl* raiz = NULL;    
    Aluno *aluno;

    int op, valor, idade;

    do{
        printf("\n====BEM VINDO AO MENU DA ARVORE AVL====\n");
        printf("\n0. Sair. \n1. Insercao. \n2. Remocao. \n3. Atualizar. \n4. Impressao.\n");

        printf("\nOpcao: ");
        scanf("%d", &op);

        switch (op){
        case 0:
            printf("\n===Programa-Finalizado===\n\n");
            break;
        
        // Insercao.
        case 1:
            aluno = malloc(sizeof(aluno));
            printf("\n===Adicionar-informacoes-do-Aluno===");
            printf("\n-> Nome: ");
            scanf("%s", aluno->nome);

            printf("\n-> Insira o RGA: ");
            scanf("%d", &aluno->RGA);

            printf("\n-> Data de nascimento: ");
            scanf("%s", aluno->data_nascimento);

            printf("\n-> Insira o Ano de Ingresso: ");
            scanf("%d", &aluno->ano_ingresso);

            printf("\n-> Codigo do Curso: ");
            scanf("%d", &aluno->codigo_curso);

            raiz = Avl_insercao(raiz, aluno);

            break;
        
        // Remover.
        case 2:
            printf("\n===Remover-Informacoes-do-Aluno===");
            printf("\n-> Informe o RGA: ");
            scanf("%d", &valor);
            avl_remocao(raiz, valor);
            break;
        
        // Atualizar;
        case 3: 

            break;
        
        // Imprimir
        case 4:
            avl_imprimir(raiz, 1);
            break;

        default:
            break;
        }
    }while(op!=0);

    return 0;
}
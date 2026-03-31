#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "avl_library.h"

/*  Trabalho 2 de Estrutura de Dados 
   * Aluno: Kimberlly L. Stachelski Canhete Turma: 03
   * Professor: Marco Aurelio Stefanes
   * objetivo: fazer uma arvore AvL de Cadastro de Estudantes.

*/

// printf(\x1b[38;2;255;0;0m MENSAGEM \x1b[0m\n);
void verificar_tipo(int verificar){
    if(verificar == 0){
        printf("\n\x1b[38;2;255;60;0m =>ERRO: numero digitado nao é do tipo INT...\n=>ABORTANDO PROGRAMA... \x1b[0m\n");
        exit(1);
    }
}

int main(){
    Avl* raiz = NULL;    
    Aluno *aluno;
    Aluno *novo_dado;

    int op, valor, RGA, verificar;
    printf("\n\x1b[38;2;100;200;255m=======================================");
    printf("\n====BEM VINDO AO MENU DA ARVORE AVL====\n");
    printf("=======================================\x1b[0m");

    do{
        printf("\n\x1b[38;2;255;255;100m====O-QUE-DESEJA-FAZER====\x1b[0m");
        printf("\n0 - Sair. \n1 - Insercao. \n2 - Remocao. \n3 - Atualizar. \n4 - Impressao.\n");

        printf("\nOpcao: ");
        verificar = scanf("%d", &op);
        verificar_tipo(verificar);
        getchar();

        switch (op){
        case 0:
            printf("\n\x1b[38;2;255;100;0m===Programa-Finalizado===\x1b[0m\n\n");
            break;
        
        // Insercao.
        case 1:
            aluno = malloc(sizeof(Aluno));

            printf("\n\x1b[38;2;255;255;100m===Informacoes do Aluno===\x1b[0m");
            printf("\n-> Nome: ");
            fgets(aluno->nome, sizeof(aluno->nome), stdin);
            aluno->nome[strcspn(aluno->nome, "\n")] = 0;

            printf("-> Data de nascimento: ");
            fgets(aluno->data_nascimento, sizeof(aluno->data_nascimento), stdin);
            aluno->data_nascimento[strcspn(aluno->data_nascimento, "\n")] = 0;

            printf("-> Insira o RGA: ");
            verificar = scanf("%d", &aluno->RGA);
            verificar_tipo(verificar);
            getchar(); // Remover o \n que o Enter deixa quando o Usuario termina de digitar.

            printf("-> Insira o Ano de Ingresso: ");
            verificar = scanf("%d", &aluno->ano_ingresso);
            verificar_tipo(verificar);
            getchar(); // Remover o \n que o Enter deixa quando o Usuario termina de digitar.

            printf("-> Codigo do Curso: ");
            scanf("%d", &aluno->codigo_curso);
            verificar_tipo(verificar);
            getchar(); // Remover o \n que o Enter deixa quando o Usuario termina de digitar.
            
            raiz = Avl_insercao(raiz, aluno);

            break;
        
        // Remover.
        case 2:
            printf("\n\x1b[38;2;255;255;100m===Remover-Aluno===\x1b[0m");

            printf("\n-> Informe o RGA: ");
            verificar = scanf("%d", &valor);
            verificar_tipo(verificar);

            raiz = avl_remocao(raiz, valor);
            
            break;
        
        // Atualizar;
        case 3: 
            printf("\n\x1b[38;2;255;255;100m===Atualizar-Informacao-do-Aluno\x1b[0m");
            printf("\n=> Digite o RGA: ");
            scanf("%d", &RGA);
            verificar_tipo(verificar);

            getchar();
            novo_dado = malloc(sizeof(Aluno));

            novo_dado->RGA = RGA; // Lembrando que o RGA por ser a chave nao pode ser alterado.

            // Alterar Nome.
            printf("=> Novo Nome: ");
            fgets(novo_dado->nome, sizeof(novo_dado->nome), stdin);
            novo_dado->nome[strcspn(novo_dado->nome, "\n")] = 0;

            // Alterar Data de nascimento.
            printf("=> Nova data de Nascimento: ");
            fgets(novo_dado->data_nascimento, sizeof(novo_dado->data_nascimento), stdin);
            novo_dado->data_nascimento[strcspn(novo_dado->data_nascimento, "\n")] = 0;

            // Alterar Codigo do Curso.
            printf("=> Novo Codigo do Curso: ");
            scanf("%d", &novo_dado->codigo_curso);
            verificar_tipo(verificar);
            getchar();

            // Alterar Ano de Ingresso.
            printf("=> Ano de Ingresso: ");
            scanf("%d", &novo_dado->ano_ingresso);
            verificar_tipo(verificar);
            getchar();

            raiz = avl_atualizar(raiz, RGA, novo_dado);

            free(novo_dado);

            break;
        
        // Imprimir
        case 4:
            avl_imprimir(raiz, 1);
            break;

        default:
            printf("\n\x1b[38;2;255;60;0m=========DIGITE-UM-VALOR-VALIDO=========\x1b[0m");
            break;
        }
    }while(op!=0);

    return 0;
}
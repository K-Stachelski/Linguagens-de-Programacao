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

Avl* criar_no(Aluno *x){
    Avl* Novo = malloc(sizeof(Avl));

    if(Novo == NULL){
        printf("\n\x1b[38;2;255;60;0mErro na alocacao de memoria.\n");
        printf("\nAbortando programa...\x1b[0m");
        exit(1);

    }else{
        Novo->aluno = x;
        Novo->esq = NULL;
        Novo->dir = NULL;
        Novo->alt = 0;
    }

    return Novo;
}

// Saber qual a maior subarvore que tem dentro da nossa propria arvore.
int maior(int x, int y){
    return (x > y)? x: y;
}
int Avl_alt(Avl *raiz){
    if(raiz == NULL){
        return -1;
    }else{
        return raiz->alt;
    }
}

// Saber que lado precisa ser balanceado baseado na sua altura.
int fator_balanceamento(Avl* raiz){
    if(raiz){
        return (Avl_alt(raiz->esq) - Avl_alt(raiz->dir));
    }else{
        return 0;
    }
}
// Rotacao a Esquerda.
Avl* rot_esq(Avl* raiz){
    Avl *y, *filho;

    // Troca de valores.
    y = raiz->dir;

    // Para caso exista um filho do NO q esta sendo rotacionado, salva ele e coloca um apontador.
    filho = y->esq;

    y->esq = raiz;
    raiz->dir = filho;
    
    // Recalculando a altura da arvore.
    raiz->alt = maior(Avl_alt(raiz->esq), Avl_alt(raiz->dir)) + 1;
    y->alt = maior(Avl_alt(y->esq), Avl_alt(y->dir)) + 1;

    return y;

}

// Rotacao a direita.
Avl* rot_dir(Avl* raiz){
    Avl *y, *filho;

    y = raiz->esq;
    filho = y->dir;

    y->dir = raiz;
    raiz->esq = filho;

    raiz->alt = maior(Avl_alt(raiz->esq), Avl_alt(raiz->dir))+ 1;
    y->alt = maior(Avl_alt(y->esq), Avl_alt(y->dir)) + 1;

    return y;
}

// Rotacao Duplas
Avl* rot_esq_dir(Avl* raiz){
    raiz->esq = rot_esq(raiz->esq);
    return rot_dir(raiz);   
}

Avl* rot_dir_esq(Avl* raiz){
    raiz->dir = rot_dir(raiz->dir);
    return rot_esq(raiz);
}

// Balancear a arvore.
Avl* avl_balanceamento(Avl* raiz){
    int fb = fator_balanceamento(raiz);

    // Rotacao simples a esquerda e a direita.
    if(fb < -1 && fator_balanceamento(raiz->dir) <= 0){
        raiz = rot_esq(raiz);
    }else if(fb > 1 && fator_balanceamento(raiz->esq) >= 0){
        raiz = rot_dir(raiz);
    }
    // Rotacao dupla a direita e a esquerda.
    else if(fb > 1 && fator_balanceamento(raiz->esq) < 0){
        raiz = rot_esq_dir(raiz);
    }else if(fb < -1 && fator_balanceamento(raiz->dir) > 0){
        raiz = rot_dir_esq(raiz);
    }
    
    return raiz;  
}

Avl* Avl_insercao(Avl* raiz, Aluno *x){
    // Arvore vazia. Ele cria um NO baseado no elemento que o usuario queira inserir.
    if(raiz == NULL) 
        return criar_no(x);
     
    // Criando os filhos esquerdo e direito.
    else{
        if(x->RGA < raiz->aluno->RGA)
            raiz->esq = Avl_insercao(raiz->esq,x);

        else if(x->RGA > raiz->aluno->RGA)
            raiz->dir = Avl_insercao(raiz->dir,x);
        
        else
            printf("\n\x1b[38;2;255;60;0mERRO: Insercao nao realizada\n=>POR-FAVOR-INSIRA-UM-DADO-CORRETO\n\x1b[0m");      
    }

    // Calcula a altura com os valores atualizados.
    raiz->alt = maior(Avl_alt(raiz->esq), Avl_alt(raiz->dir)) + 1;

    // Verifica se necessita balancear a arvore.
    raiz = avl_balanceamento(raiz);

    return raiz;
}

Avl* avl_remocao(Avl* raiz, int x){ // Aviso: A variavel x é uma chave, o qual a chave é o RGA do ALUNO.
    if(raiz == NULL){
        printf("\x1b[38;2;255;60;0mERRO: RGA nao encontrado\x1b[0m\n");
        return NULL;
    }else{
        // Remocao de NOS sem filhos.
        if(raiz->aluno->RGA == x){
            if(raiz->esq == NULL && raiz->dir == NULL){
                free(raiz->aluno);
                free(raiz);

                printf("\x1b[38;2;0;255;60m=>REMOCAO-FEITA-COM-SUCESSO<=\x1b[0m\n");
                return NULL;
            }

            // Remocao de NOS com 2 filhos.
            else{
                if(raiz->esq != NULL && raiz->dir != NULL){
                    Avl* aux =  raiz->esq;
                    while(aux->dir != NULL)
                        aux = aux->dir;

                    // Troca dos dados.
                    Aluno *temporario;
                    temporario = raiz->aluno;
                    raiz->aluno = aux->aluno;
                    aux->aluno = temporario;

                    // Remocao do NO.
                    raiz->esq = avl_remocao(raiz->esq, temporario->RGA);

                    return raiz; 

                // Remocao de NOS com um filho.    
                }else{
                    Avl* aux;
                    if(raiz->esq == NULL)
                        aux = raiz->dir;
                    else
                        aux = raiz->esq;
                    free(raiz);

                    return aux;
                }
            }
        }else{
            if(x < raiz->aluno->RGA){
                raiz->esq = avl_remocao(raiz->esq, x);

            }else{
                raiz->dir = avl_remocao(raiz->dir, x);
            }
        }
    }

    raiz->alt = maior(Avl_alt(raiz->esq), Avl_alt(raiz->dir)) + 1;
    raiz = avl_balanceamento(raiz);
    return raiz;
} 

void imprimir_info(Aluno *aluno){
    printf("->Nome[%s] Nascimento[%s] RGA[%d] Ingresso[%d] Curso[Cod[%d]]", aluno->nome, aluno->data_nascimento, aluno->RGA, aluno->ano_ingresso, aluno->codigo_curso);
}

void avl_imprimir(Avl*raiz, int nivel){
    if(raiz){
        avl_imprimir(raiz->dir, nivel + 1);
        printf("\n\n");
        
        for(int i = 0; i < nivel; i++)
            printf("\t");
        
        imprimir_info(raiz->aluno);
        avl_imprimir(raiz->esq, nivel + 1);
    }
}

Avl* avl_atualizar(Avl* raiz, int RGA, Aluno* novo_dado){
    if (raiz == NULL){ 
        printf("\n\x1b[38;2;255;60;0mERRO: Aluno com RGA[%d] nao encontrado.\x1b[0m", RGA);
        return NULL;
    }
    // Busca pelo RGA o qual deseja alterar.
    if(RGA < raiz->aluno->RGA){ // Caso 1: Se o RGA do NO atual for menor do que deseja alterar.
        raiz->esq = avl_atualizar(raiz->esq, RGA, novo_dado); // A busca permanecera indo pela subarvore esquerda.
    
    }else if(RGA > raiz->aluno->RGA){ // Caso 2: Se o RGA for maior.
        raiz->dir = avl_atualizar(raiz->dir, RGA, novo_dado); // A busca permanece na subarvore direita.
    }
    else{ // RGA foi encontrado.
        strcpy(raiz->aluno->nome, novo_dado->nome);

        strcpy(raiz->aluno->data_nascimento, novo_dado->data_nascimento);

        raiz->aluno->codigo_curso = novo_dado->codigo_curso;
        raiz->aluno->ano_ingresso = novo_dado->ano_ingresso;

        printf("\x1b[38;2;0;255;60m ATUALIZACAO-FEITA-COM-SUCESSO\x1b[0m\n");
    }

    return raiz;
}
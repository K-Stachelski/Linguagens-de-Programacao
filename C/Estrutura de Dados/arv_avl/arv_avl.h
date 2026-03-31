#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct avl{
    int valor;
    struct avl *esq, *dir;
    int alt;
    
} Avl;

Avl* criar_no(int x){
    Avl* Novo = malloc(sizeof(Avl));

    if(Novo == NULL){
        printf("\nErro na alocacao de memoria.\n");
        printf("\nAbortando programa.");
        exit(1);
    }
    else{
        Novo->valor = x;
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

Avl* Avl_insercao(Avl* raiz, int x){
    // Arvore vazia. Ele cria um NO baseado no elemento que o usuario queira inserir.
    if(raiz == NULL) 
        return criar_no(x);
     
    // Criando os filhos esquerdo e direito.
    else{
        if(x < raiz->valor) // Erro: segmatation fault.
            raiz->esq = Avl_insercao(raiz->esq,x);

        else if(x > raiz->valor)
            raiz->dir = Avl_insercao(raiz->dir,x);
        
        else
            printf("\nInsercao nao realizada.\n");
        
    }

    // Calcula a altura com os valores atualizados.
    raiz->alt = maior(Avl_alt(raiz->esq), Avl_alt(raiz->dir)) + 1;

    // Verifica se necessita balancear a arvore.
    raiz = avl_balanceamento(raiz);

    return raiz;
}

Avl* avl_remocao(Avl* raiz, int x){
    if(raiz == NULL){
        printf("\nValor desaparecido.\n");
        return NULL;
    }else{
        // Remocao de NOS sem filhos.
        if(raiz->valor == x){
            if(raiz->esq == NULL && raiz->dir == NULL){
                printf("\nFolha sumiu.\n");
                return NULL;
            }

            // Remocao de NOS com 2 filhos.
            else{
                if(raiz->esq != NULL && raiz->dir != NULL){
                    Avl* aux =  raiz->esq;
                    while(aux->dir != NULL)
                        aux = aux->dir;
                    raiz->valor = aux->valor;
                    aux->valor = x;
                    printf("\nTroca de elementos bem sucedida.\n");
                    raiz->esq = avl_remocao(raiz->esq, x);
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
            if(x < raiz->valor){
                raiz->esq = avl_remocao(raiz->esq, x);

            }else{
                raiz->dir = avl_remocao(raiz->dir, x);
            }
        }

        raiz->alt = maior(Avl_alt(raiz->esq), Avl_alt(raiz->dir)) + 1;

        raiz = avl_balanceamento(raiz);
    }

    return raiz;
}
void padding (char ch, int n) {
    for (int i = 0; i < n; i++) putchar(ch);
}

void imprima_estrutura(Avl *raiz, int nivel) {
    int i;
    if (raiz == NULL) {
        padding('\t', nivel);
        puts ("~");
    } else {
        imprima_estrutura(raiz->dir, nivel + 1);
        padding('\t', nivel);
        printf("%d\n", raiz->valor);
        imprima_estrutura(raiz->esq, nivel + 1);
    }
}

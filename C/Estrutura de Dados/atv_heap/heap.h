#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#define MAX 9
// Criar um Heap (Heap é uma arvore).
int pai(int i){
    if (i == 0)
        return 0;
    else
        return (i - 1) / 2;
}

int filho_esquerdo(int i){
    return i * 2 + 1;
}

int filho_direito(int i){
    return i * 2 + 2;
}

int maior_prioridade(int S[MAX]){
    return S[0];
}
// Troca de variaveis.
void troca(int *n, int *p){
    int aux;
    aux = *n;
    *n = *p;
    *p = aux;

}
void desce(int n, int S[MAX], int i){
    int e, d, maior;

    e = filho_esquerdo(i);
    d = filho_direito(i);

    maior = i;

    if(e < n && S[e] > S[maior])
        maior = e;
    
    if(d < n && S[d] > S[maior])
        maior = d;

    if(maior != i){
        troca(&S[i], &S[maior]);
        desce(n, S, maior);
    }
}

void construir_max_heap(int n, int S[MAX]){
    int i;
    for(i = n/2 - 1; i>= 0; i++)
        desce(n, S, i);
}

int extrair_max(int *n, int S[MAX]){
    int maior;
    if(*n > 0){
        maior = S[0];
        S[0] = S[*n - 1];
        *n = *n - 1;
        desce(*n, S, 0);
        return maior;
    }
    else
        return INT_MIN;
}

void sobe(int n, int S[MAX], int i){
    while(S[pai(i)] < S[i] && i > 0){
        troca(&S[i], &S[pai(i)]);
        i = pai(i);
    } 
}

void aumenta_prioridade(int n, int S[MAX], int i, int p){
    if(p < S[i]){
        printf("\x1b[38;2;255;0;0m TENTATIVA DE AUMENTAR PRIORIDADE FALHOU.\x1b[0m\n");
    }
    else{
        S[i] = p;
        sobe(n, S, i);
        printf("\x1b[38;2;0;255;0m-> O ELEMENTO ESTA COM PRIORIDADE MAIOR\x1b[0m\n");
    }
}

void inserir(int *n, int S[MAX], int *p){
    S[*n] = *p;
    *n = *n + 1;
    sobe(*n, S, *n - 1);
}

int imprimir (int n, int S[MAX]){
    int i;
    if (n == 0)
        printf("\x1b[38;2;255;0;0m [-> HEAP NAO EXISTE <-]\x1b[0m\n");

    for(i = 0; i < n; i++){
        printf("\n\x1b[38;2;0;255;0mS[%d] = %d\x1b[0m\n", i, S[i]);
    }

}

// Algoritmos do HASH. Utilizado como Algoritmo de Busca.
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#define MAX 53
#define OCUPADA 'o'
#define VAZIA 'v'
#define REMOVIDA 'r'

struct cel{
    char estado; // INDICA SE O LOCAL DA TABELA ESTA OCUPADA OU NAO.
    int chave; // RGA.
    char *nome; // NOME DO ALUNO.
    float md; // MEDIA DE DESEMPENHO.
}; 
typedef struct cel Celula;

/*void imprimir(int m, Celula T[MAX]){
    for(int i = 0; i < m; i++){
        printf("=== T[%d]: %d\n== Media de Desempenho: %d\n", i, T.chave, T.md);
    }
}*/

int h(int chave, int i){
    return (chave + i) % MAX;
}

void Criar(Celula T[MAX]){
    for(int i = 0; i < MAX; i++){
        T[i].estado = VAZIA;
        T[i].chave = -1;
    }
}

int Inserir(int m, Celula T[MAX], int x, char nome[], float md){
    int i, j;
    i = 0;
    do{
        j = h(x, i);
        if(T[j].estado != OCUPADA){
            T[j].chave = x;          
            T[j].nome = (char*)malloc(strlen(nome) + 1);         
            strcpy(T[j].nome, nome);  
            T[j].md = md;       
            T[j].estado = OCUPADA;           
            return j;
        }
        else
            i++;

    } while (i != m);

    return m;
}

int Busca(int m, Celula T[MAX], int x){
    int i, j;
    i = 0;
    do{
        j = h(x, i);
        if (T[j].chave == x && T[j].estado == OCUPADA)
            return j;
        else
            i++;
    } while(T[j].estado != VAZIA && i != m);
    return m; 
}

int Remover(int m, Celula T[MAX], int x){
    int i, j;
    i = 0;
    do{
        j = h(x, i);
        if(T[j].estado == OCUPADA){
            if(T[j].chave == x){
                T[j].estado = REMOVIDA;
                return j;
            }
            else{
                i++;
            }
        }
        else{
            i = m;
            break;
        }    
    } while(i != m); 
    return m;
}
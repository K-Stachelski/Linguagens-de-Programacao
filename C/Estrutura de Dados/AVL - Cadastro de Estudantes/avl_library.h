/*  Trabalho 2 de Estrutura de Dados 
   * Aluno: Kimberlly L. Stachelski Canhete Turma: 03
   * Professor: Marco Aurelio Stefanes
   * objetivo: fazer uma arvore AvL de Cadastro de Estudantes.

*/

#ifndef AVL_LIBRARY_H
#define AVL_LIBRARY_H

// Definicao da estrutura Aluno
typedef struct aluno {
    int RGA, ano_ingresso, codigo_curso; // RGA é a Chave.
    char nome[60];
    char data_nascimento[15]; // Formato: "DD/MM/AAAA"
 
} Aluno;

typedef struct avl {
    Aluno *aluno;
    struct avl *esq, *dir;
    int alt;
} Avl;

// Cria um novo nó com os dados do aluno (ponteiro para Aluno)
Avl* criar_no(Aluno *x);

// Insere um aluno na árvore AVL
Avl* Avl_insercao(Avl* raiz, Aluno *x);

// Remove um aluno da árvore AVL com base no RGA
Avl* avl_remocao(Avl* raiz, int rga);

// Função para imprimir a árvore AVL em formato estruturado
void avl_imprimir(Avl* raiz, int nivel);

// Atualizar alguma informacao do aluno.
Avl* avl_atualizar(Avl* raiz, int RGA, Aluno* novo_dado);

// Imprime os dados de um aluno
void imprimir_info(Aluno *aluno);

// ========== Funções auxiliares ==========
int maior(int x, int y);
int Avl_alt(Avl *raiz);
int fator_balanceamento(Avl* raiz);

Avl* rot_esq(Avl* raiz);
Avl* rot_dir(Avl* raiz);
Avl* rot_esq_dir(Avl* raiz);
Avl* rot_dir_esq(Avl* raiz);

Avl* avl_balanceamento(Avl* raiz);

#endif // AVL_LIBRARY_H

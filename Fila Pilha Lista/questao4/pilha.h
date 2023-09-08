#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct elemento{
    char info;
    struct elemento* prox;
}Elemento;

typedef struct pilha{
    char descricao[50];
    Elemento* prim;
}Pilha;

Pilha* pilha_cria (void);
int pilha_vazia (Pilha* p);
void pilha_push (Pilha* p, char v);
int pilha_pop (Pilha* p);
void pilha_libera (Pilha* p);
void pilha_imprime (Pilha* p);

#endif // PILHA_H_INCLUDED

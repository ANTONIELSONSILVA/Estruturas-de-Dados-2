#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "pilha.h"

Pilha* pilha_cria (void)
{
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

int pilha_vazia (Pilha* p)
{
    if(p->prim == NULL)
        return 1;
    return 0;
}

void pilha_push (Pilha* p, char v)
{
    Elemento *novo;
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = v;
    novo->prox = p->prim;
    p->prim = novo;
}

int pilha_pop (Pilha* p)
{
    Elemento *t;
    float v;

    if (pilha_vazia(p)){
        printf("Pilha vazia.\n");
        return 0;
    }


    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;
}

void pilha_libera (Pilha* p)
{
    Elemento *t, *q = p->prim;

    while(q!=NULL)
    {
        t = q->prox;
        free(q);
        q = t;
    }

    free(p);
}

void pilha_imprime (Pilha* p){

    Elemento *q = p->prim, *t;

 while(q!=NULL)
    {
        t = q->prox;
        printf("%c", q->info );
        q = t;
    }
}

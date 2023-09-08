#include <stdio.h>
#include <stdlib.h>

#include "fila_lista.h"

#include "lista.h"

Fila* cria (void)
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

Elemento* inserir_fim (Elemento* fim, Elemento* lst)
{
    int qtd=0,i=0;

    Elemento*p = (Elemento*) malloc(sizeof(Elemento));
    Elemento*aux;

    for (aux = lst; aux != NULL; aux = aux->prox)
    {
        qtd++;
    }

    p->info = (int*) malloc(qtd * sizeof(int));
    for (aux = lst; aux != NULL; aux = aux->prox)
    {
        p->info[i] = aux->info;
        i++;
    }
    p->info[i] = NULL;
    p->prox = NULL;
    if (fim != NULL)
        fim->prox = p;

    return p;
}

Elemento* retirar_inicio (Elemento* ini)
{
    Elemento* p = ini->prox;
    free(ini);
    return p;
}

void insere (Fila* f, Elemento* lst)
{

    f->fim = inserir_fim(f->fim, lst);
    if (f->ini == NULL)
        f->ini = f->fim;
}

int retira (Fila* f)
{
    int v;
    if (vazia(f))
    {
        printf("Fila vazia.\n");
        exit(1);
    }
    v = f->ini->info;
    f->ini = retirar_inicio(f->ini);
    if (f->ini == NULL)

        f->fim = NULL;
    return v;
}

int vazia (Fila* f)
{
    return (f->ini==NULL);
}


void libera (Fila* f)
{
    Elemento* q = f->ini;
    while (q!=NULL)
    {
        Elemento*t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}

void imprime (Fila* f, Elemento *lst)
{
    Elemento* q;
    int i = 0, j=0;

    for (q = f->ini; q != NULL; q=q->prox)
    {

        printf("\nFila na posicao ->[%d]\n", j);
        while(q->info[i] != NULL)
        {
            printf("%d->", q->info[i]);
            i++;
        }
        i = 0;
        j++;

        printf("NULL\n");

    }

    printf("\n");

}



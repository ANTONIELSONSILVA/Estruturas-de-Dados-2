#include <stdio.h>
#include <stdlib.h>

#include "fila_lista.h"
#include "lista.h"

//funcao responsavel pela criacao de listas
Elemento* lst_cria(void)
{
    return NULL;
}

//funcao responsavel pela impressao de listas
Elemento* lst_insere (Elemento* lst, int val)
{
    Elemento* novo =(Elemento*)malloc(sizeof(Elemento));
    novo->info = val;
    novo->prox = lst;
    return novo;
}

void lst_imprime (Elemento* lst)
{
    Elemento* p;
    for (p = lst; p != NULL; p = p->prox)
        //printf("info = %d\n", p->info);
        printf("%d -> ", p->info);
    printf("NULL\n");
}

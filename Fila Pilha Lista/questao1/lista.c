#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "lista.h"

//funcao responsavel pela criacao de listas
Elemento* lst_cria(void)
{
    return NULL;
}

//funcao responsavel pela impressao de listas
void lst_imprime (Elemento* lst)
{
    Elemento* p;
    int area;

    printf("\nSequência das áreas\n");

    for (p = lst; p != NULL; p = p->prox)
    {
        area = p->pt_r->h * p->pt_r->w;
        printf("%d->", area);
    }
    printf("NULL\n");
}

//funcao insercao
Elemento *lst_insere (Elemento* lst,int h, int w)
{

    //elemento recebe lista vazia
    Elemento* p = lst;

    //ponteiro para o elemento anterior - recebe NULL
    Elemento *ant = NULL;

    //ponteiro para a lista atualizada
    Elemento *lst_atual = lst;

    //elemento criado para testar tamanho da area com Elemento*p - recebe a lista
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));;

    //aloca espacos para retangulo
    novo->pt_r = (Retangulo*)malloc(sizeof(Retangulo));

    //recebem os valores da altura e largura passados por parametro
    novo->pt_r->h = h;
    novo->pt_r->w = w;


    //condicao para ordenacao de lista
    while(p != NULL && p->pt_r->h * p->pt_r->w < novo->pt_r->h * novo->pt_r->w)
    {
        ant = p;
        p = p->prox;
    }


    if(ant == NULL)
    {
        novo->prox = lst;
        lst_atual = novo;
    }

    else
    {
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return lst_atual;
}

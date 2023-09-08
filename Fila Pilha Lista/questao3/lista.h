#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "fila_lista.h"

struct elemento
{
    int *info;
    struct Elemento* prox;
};
typedef struct elemento Elemento;

//funcoes referentes às operações com listas

//cria uma lista vazia
Elemento* lst_cria(void);

//insere elementos na lista
Elemento *lst_insere (Elemento* lst, int v);

//imprime a lista
void lst_imprime (Elemento* lst);


#endif // LISTA_H_INCLUDED

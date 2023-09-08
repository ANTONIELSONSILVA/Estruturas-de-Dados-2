#ifndef FILA_LISTA_H_INCLUDED
#define FILA_LISTA_H_INCLUDED

#include "lista.h"

struct fila {

    Elemento* ini;
    Elemento* fim;
};
typedef struct fila Fila;

//funcoes referentes �s opera��es com fila

//cria uma fila
Fila* cria (void);

//inser��o no final da fila
Elemento* inserir_fim (Elemento* fim, Elemento* lst);

//remocao no inicio
Elemento* retirar_inicio (Elemento* ini);

//inser��o na fila - chama a funcao inserir_fim() para ajustar o ponteiro da inser�ao no fim
void insere (Fila* f, Elemento* lst);

//retira elementos do inicio
int retira (Fila* f);

//verifica se a fila esta vazia
int vazia (Fila* f);

//libera memoria
void libera (Fila* f);

//imprime a fila
void imprime (Fila* f, Elemento *lst);


#endif // FILA_LISTA_H_INCLUDED

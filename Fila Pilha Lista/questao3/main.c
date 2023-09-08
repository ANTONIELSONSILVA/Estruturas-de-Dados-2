#include <stdio.h>
#include <stdlib.h>

#include "fila_lista.h"
#include "lista.h"


int main (void)
{
    Elemento* lst;

    Fila* f = cria();

    printf("\nInserindo( Lista 1)\n");
    lst = lst_cria();   //cria e inicializa lista como vazia
    lst = lst_insere(lst, 23);
    lst = lst_insere(lst, 45);
    lst = lst_insere(lst, 10);
    lst = lst_insere(lst, 58);
    lst = lst_insere(lst, 33);

    insere(f,lst);
    imprime(f,lst);


    printf("\nInserindo(Lista 2)\n");
    lst = lst_cria();   //cria e inicializa lista como vazia
    lst = lst_insere(lst, 3);
    lst = lst_insere(lst, 67);
    lst = lst_insere(lst, 56);
    lst = lst_insere(lst, 22);

    insere(f,lst);
    imprime(f,lst);


    printf("\nInserindo(Lista 3)\n");
    lst = lst_cria();   //cria e inicializa lista como vazia
    lst = lst_insere(lst, 7);
    lst = lst_insere(lst, 5);
    lst = lst_insere(lst, 6);
    lst = lst_insere(lst, 2);

    insere(f,lst);
    imprime(f,lst);

    printf("\nRetirando primeiro elemento da fila (Lista 1)\n");
    retira(f);
    imprime(f,lst);

    lst = lst_cria();   //cria e inicializa lista como vazia
    lst = lst_insere(lst, 1);
    lst = lst_insere(lst, 9);
    lst = lst_insere(lst, 33);
    lst = lst_insere(lst, 44);

    insere(f,lst);
    printf("\nInserindo lista no fim \n");
    imprime(f,lst);

    lst = lst_cria();  //cria e inicializa lista como vazia
    lst = lst_insere(lst, 133);
    lst = lst_insere(lst, 99);
    lst = lst_insere(lst, 3);
    lst = lst_insere(lst, 44);

    insere(f,lst);
    printf("\nInserindo nova lista no fim \n");
    imprime(f,lst);

    printf("\nRetirando primeiro elemento da fila (Lista 1)\n");
    retira(f);
    imprime(f,lst);

    printf("\nRetirando segundo elemento da fila (Lista 2)\n");
    retira(f);
    imprime(f,lst);

    printf("\nRetirando terceiro elemento da fila (Lista 3)\n");
    retira(f);
    imprime(f,lst);

    printf("\nRetirando quarto e ultimo elemento da fila (Lista 4)\n");
    retira(f);
    if (vazia(f))
    {
        printf("Fila vazia.\n");
        exit(1);
    }

}

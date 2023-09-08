#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Deque* Initialize(void)
{
    Deque* d = (Deque*) malloc(sizeof(Deque));

    if (d != NULL)
    {

        d->ini = 0;
        d->fim = 0;

    }
    return d;
}

int Full(Deque *d)
{
    if(d->fim == MAX)
    {
        printf("\nDEQUE CHEIO\n");
        return 1;
    }
    return 0;
}

int Empty(Deque *d)
{
    if(d->fim == 0)
    {
        printf("\nDEQUE VAZIO\n");
        return 1;
    }
    return 0;
}

Deque* EnqueueF(Deque* d, int v)
{
    int ant;

    if (d->fim == MAX)
    {
        printf("Capacidade do DEQUE estourou.\n");
        exit(1);
    }
    ant = (d->ini - 1 + MAX) % MAX;
    d->data[ant] = v;
    d->ini = ant;

    d->fim++;

    return d;

}
Deque* EnqueueR(Deque *d, int v)
{
    int fim;
    if (d->fim == MAX)
    {
        printf("Capacidade da fila estourou.\n");
        exit(1);
    }
    fim = (d->ini + d->fim) % MAX;
    d->data[fim] = v;

    d->fim++;

    return d;
}


void Print(Deque *d)
{
    int i;
    int ini, fim;

    if (Empty(d))
    {

        return;
    }

    ini = d->ini;

    fim = (ini + d->fim - 1) % MAX;

    for (i=ini; i!=fim; i=(i+1)%MAX)
    {
        printf("%i->", d->data[i]);
    }
    printf("%i", d->data[i]);

}


int DequeueF(Deque *d)
{
    int v;
    if (Empty(d))
    {
        exit(1);
    }

    v = d->data[d->ini];
    d->ini = (d->ini + 1) % MAX;
    d->fim--;
    return v;
}

int DequeueR(Deque *d)
{
    int v;
    if (Empty(d))
    {
        exit(1);
    }

    v = d->data[d->fim];

    d->fim--;
    return v;
}

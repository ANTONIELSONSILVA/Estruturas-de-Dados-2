#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "fila.h"

int main()
{
    Deque *d;

    setlocale(LC_ALL, "");
    d = Initialize();

    printf("\n\n1) Inserção de elementos no inicio\n");

    printf("\nInserindo 1° elemento no início do DEQUE");
    d = EnqueueF(d, 1);

    printf("\n");
    Print(d);

    printf("\nInserindo 2° elemento no início do DEQUE");
    d = EnqueueF(d, 2);

    printf("\n");
    Print(d);

    printf("\nInserindo 3 elementos no início do DEQUE");
    d = EnqueueF(d, 3);
    d = EnqueueF(d, 4);
    d = EnqueueF(d, 5);

    printf("\n");
    Print(d);

    printf("\n\n2) Verifica DEQUE cheio");
    Full(d);

    printf("\n3) Remoção de elementos no final do deque\n");

    printf("\nRetirando o primeiro elemento do final do deque\n");
    DequeueR(d);

    printf("\n");
    Print(d);

    printf("\n\nRetirando o segundo elemento do final do deque\n");
    DequeueR(d);

    printf("\n");
    Print(d);

    printf("\n\n4) Inserção de elementos no final do deque\n");

    printf("\nInserindo primeiro elemento no final do Deque");
    d = EnqueueR(d, 8);

    printf("\n");
    Print(d);

    printf("\nInserindo segundo elemento no final do Deque");
    d = EnqueueR(d, 9);

    printf("\n");
    Print(d);

    printf("\n\n5) Remoção de elementos no inicio do deque\n");

    printf("\nRetirando o primeiro elemento do inicio do deque\n");
    DequeueF(d);

    printf("\n");
    Print(d);

    printf("\n\nRetirando o segundo elemento do inicio do deque\n");
    DequeueF(d);

    printf("\n");
    Print(d);

    printf("\n\n6)Nova remoção de elementos no final do deque\n");

    printf("\nRetirando o elemento do fim do deque\n");
    DequeueR(d);

    printf("\n");
    Print(d);

    printf("\nRetirando o elemento do fim do deque\n");
    DequeueR(d);

    printf("\n");
    Print(d);

    printf("\n\nRetirando o elemento do inicio/fim do deque\n");
    DequeueR(d);

    printf("\nVerifica DEQUE vazio\n");
    Empty(d);

    printf("\nInserindo qtd max no início do DEQUE\n");
    d = EnqueueF(d, 7);
    d = EnqueueF(d, 2);
    d = EnqueueF(d, 8);
    d = EnqueueF(d, 1);
    d = EnqueueF(d, 9);

    printf("\n");
    Print(d);

    printf("\n\nVerifica DEQUE cheio\n");
    Full(d);
    printf("\n");

    printf("\nInserindo e estourando a capacidade do deque");
    printf("\n\n");
    d = EnqueueF(d, 7);
    printf("\n");

}

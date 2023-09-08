#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#define MAX 5

typedef struct _deque
{

    int data[MAX];
    int ini,fim;

} Deque;

Deque* Initialize(void); // Torna a deque vazia .
int Empty(Deque *d); // Determina se o deque está vazio.
int Full(Deque *d); // Determina se o deque está cheio.
Deque* EnqueueF(Deque *d, int v); //Insere um elemento no início do deque .
Deque* EnqueueR(Deque *d, int v); // Insere um elemento no fim do deque.
int DequeueR(Deque *d); // Remove o elemento no final do deque.
int DequeueF(Deque *d); // Remove o elemento no início do deque.
void Print(Deque *d); // Imprime os elementos do deque.


#endif // FILA_H_INCLUDED

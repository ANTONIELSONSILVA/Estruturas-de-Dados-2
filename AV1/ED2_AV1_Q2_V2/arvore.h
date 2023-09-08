#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED


typedef struct pilha {
    int topo;
    int tamanhoMaximo;
    char* elemento;
}Pilha;

Pilha* criar(int maximo)
{
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->tamanhoMaximo = maximo;
    pilha->topo = -1;
    pilha->elemento = (char*)malloc(pilha->tamanhoMaximo * sizeof(char)); // Pegar em codigo ASCII
    return pilha;
}

typedef struct noArvore
{
    char data;
    struct noArvore *esquerda, *direita;
}NoArvore;

int pilha_cheia(Pilha* pilha);

void push(Pilha* pilha, int item);

int pop(Pilha* pilha);

int valor_topo(Pilha* pilha);

int precedencia(char operador);

int converte_polonesa(char* infixo);

void converte_posfixo(char *str);

void print2DUtil(NoArvore *raiz, int espaco);

NoArvore* arvore_insere(NoArvore *no, char posfixo, char direcao);

int arvore_direcao(NoArvore *no);

int arvore_direcao(NoArvore *no);

void insere_operador (NoArvore* no, char posfixo, int flag);

void insere_operando(NoArvore* no, char posfixo, int flag);

NoArvore* arvore_operacao(NoArvore *no, char posfixo, int flag);

#endif // ARVORE_H_INCLUDED

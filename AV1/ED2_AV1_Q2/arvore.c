#include "arvore.h"

int pilha_cheia(Pilha* pilha)
{
    if(pilha->topo == pilha->tamanhoMaximo - 1)
    {
        printf("Pilha cheia\n");
    }

    return pilha->topo == pilha->tamanhoMaximo - 1;
}

int pilha_vazia(Pilha* pilha) // Checa se a pilha está vazia
{
    return pilha->topo == -1;
}


void push(Pilha* pilha, int item) // Empilha um elemento
{
    if (pilha_cheia(pilha))
    {
        return;
    }
    pilha->elemento[++pilha->topo] = item;
}

int pop(Pilha* pilha) // Desempilha um elemento retornando o valor
{
    if (pilha_vazia(pilha))
    {
        return -1;
    }
    return pilha->elemento[pilha->topo--];
}

int valor_topo(Pilha* pilha) // Retorna o valor do topo da pilha
{
    if (pilha_vazia(pilha))
    {
        return -1;
    }
    return pilha->elemento[pilha->topo];
}


int precedencia(char operador) // Retorna a precedência de cada sinal
{
    if (operador == '+' || operador == '-')
    {
        return 1;
    }
    else if(operador == '*' || operador == '/')
    {
        return 2;
    }
    else
    {
        return -1;
    }
}


int converte_polonesa(char* infixo) // Converte de infixo para pós-fixo
{
    int contador = 0;

    Pilha* pilha = criar(strlen(infixo));
    if(!pilha)
    {
        return -1;
    }

    for (int i = 0; infixo[i] != '\0'; ++i)
    {
        if (isalpha(infixo[i]) || isdigit(infixo[i]))
        {
            infixo[contador++] = infixo[i];
        }

        else if (infixo[i] == '(')
        {
            push(pilha, infixo[i]);
        }

        else if (infixo[i] == ')')
        {
            while (!pilha_vazia(pilha) && valor_topo(pilha) != '(')
                infixo[contador++] = pop(pilha);
            if (!pilha_vazia(pilha) && valor_topo(pilha) != '(')
                return -1;
            else
                pop(pilha);
        }
        else
        {
            while (!pilha_vazia(pilha) && precedencia(infixo[i]) <= precedencia(valor_topo(pilha)))
                infixo[contador++] = pop(pilha);
            push(pilha, infixo[i]);
        }

    }

    while (!pilha_vazia(pilha))
    {
        infixo[contador++] = pop(pilha);
    }

    infixo[contador] = '\0'; // Delimita o fim da string para não ficar caracteres bugados
    return 0;
}

void converte_posfixo(char *str)
{
    //converte em posfixo
    converte_polonesa(str);
    // reverte a string
    strrev(str);
}

void print2DUtil(NoArvore *raiz, int espaco) // Printa uma arvore da esquerda para direita (2D)
{
    if (raiz == NULL)
    {
        return;
    }

    espaco += 10;

    print2DUtil(raiz->direita, espaco);

    printf("\n");
    for (int i = 10; i < espaco; i++)
    {
        printf(" ");
    }

    printf("%c\n", raiz->data);

    print2DUtil(raiz->esquerda, espaco);
}

int arvore_direcao(NoArvore *no) // Checa qual lado está vázio, com preferência ao lado esquerdo
{
    if (no->esquerda == NULL)
    {
        return -1;
    }
    else if (no->direita == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

NoArvore* arvore_insere(NoArvore *no, char posfixo, char direcao) // Insere o valor na arvore em um dos lados
{
    if (no == NULL)
    {
        no = (NoArvore *)malloc(sizeof(NoArvore));
        no->data = posfixo;
        no->esquerda = no->direita = NULL;
    }
    else if (direcao < 0) // Se o lado esquerdo está vázio
    {
        no->esquerda = arvore_insere(no->esquerda, posfixo, -1);
    }
    else if (direcao > 0)  // Se o lado direito está vázio
    {
        no->direita = arvore_insere(no->direita, posfixo, 1);
    }
    return no;
}

void insere_arvore (NoArvore* no, char posfixo, int flag)
{
    if(arvore_direcao(no) < 0)  // Caso o da esquerda esteja vazio
    {
        arvore_insere(no, posfixo, -1);
    }
    else if((flag > 0) && (no->esquerda->data == '+' || no->esquerda->data == '*' || no->esquerda->data == '-' || no->esquerda->data == '/') && (arvore_direcao(no) > 0))
    { // Checa se o valor do nó da esquerda é algum operador, caso seja, irá dar preferência a ele
        insere_arvore(no->esquerda, posfixo, flag);
    }
    else if ((arvore_direcao(no) > 0))    // Caso o da direita esteja vazio
    {
        arvore_insere(no, posfixo, 1);
    }
    else    //Caso os dois lados estiverem ocupados
    {
        if (no->direita->data == '+' || no->direita->data == '*' || no->direita->data == '-' || no->direita->data == '/')
        {
            no = no->direita;
            insere_arvore(no, posfixo, flag);
        }
        else if(no->esquerda->data == '*' || no->esquerda->data == '+' || no->esquerda->data == '/' || no->esquerda->data == '-')
        {
            no = no->esquerda;
            insere_arvore(no, posfixo, flag);
        }
    }
}

NoArvore* arvore_operacao(NoArvore *no, char posfixo, int flag)
{

    if (no == NULL)
    {
        no = (NoArvore *)malloc(sizeof(NoArvore));
        no->data = posfixo;
        no->esquerda = no->direita = NULL;
    }
    else
    {
        insere_arvore(no, posfixo, flag);
    }

    return no;
}

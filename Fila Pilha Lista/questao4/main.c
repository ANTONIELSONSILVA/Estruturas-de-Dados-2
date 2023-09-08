#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "pilha.h"
#define TAM 5

void AcertaPilha(char vet_pilha[]);//Faz as operações verificando as prioridades
int Prioridade(char c, char t);//verifica as prioridades

int main()
{

    setlocale(LC_ALL,"");
    int x=0;
     char vet_pilha[TAM];

    do{
    printf("\nEntre com a expressão -> ");
    gets(vet_pilha);
    AcertaPilha(vet_pilha);
    x++;
    }while(x<TAM);
    return 0;
}


void AcertaPilha(char vet_pilha[])
{

    Pilha *p;
    int i = 0;
    char c,t;

    p = pilha_cria ();
    pilha_push(p, '(');

    do
    {
        c = vet_pilha[i];
        i++;

        if((c >= 'a' || c >= 'A')&& (c<='z' || c<='Z'))
        {
            printf("%c", c);
        }
        else if(c == '(')
        {
            pilha_push(p, '(');
        }
        else if(c == ')' || c == '\0')
        {
            do
            {
                t = pilha_pop(p);
                if(t != '(')
                    printf("%c", t);
            }
            while(t != '(');
        }
        else if(c == '+' || c == '-' ||
                c == '*' || c == '/' ||
                c == '^' )
        {
            while(1)
            {
                t = pilha_pop(p);
                if(Prioridade(c,t))
                {
                    pilha_push(p, t);
                    pilha_push(p, c);
                    break;
                }
                else
                {
                    printf("%c", t);
                }
            }
        }
    }
    while(c != '\0');
    printf("\n");
    pilha_libera (p);
}
int Prioridade(char c, char t)
{
    int pc,pt;

    if(c == '*' || c == '/')
        pc = 2;
    else if(c == '+' || c == '-')
        pc = 1;
    else if(c == '(')
        pc = 5;
    else if(c != '*' && c != '/'&&c != '+' && c != '-' && c != '^' )
        pc = 4;

    if(c != '*' && c != '/'&&c != '+' && c != '-' && c != '^' )
        pt = 4;
    else if(t == '*' || t == '/')
        pt = 2;
    else if(t == '+' || t == '-')
        pt = 1;
    else if(t == '(')
        pt = 0;

    return (pc > pt);
}


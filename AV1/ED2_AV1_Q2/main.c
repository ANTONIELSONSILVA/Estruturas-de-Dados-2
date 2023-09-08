#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "arvore.c"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int flag = 0, i;
    char posfixo[255];
    scanf("%s", posfixo);
    printf("Infixo -> %s\n", posfixo);
    converte_posfixo(posfixo);

    printf("Pós-fixo -> %s\n\n\n", posfixo);

    NoArvore *no = NULL;

    for(i = 0; i < strlen(posfixo); i++)
    {

        flag = 0;

        if((isalpha(posfixo[i]) &&  isalpha(posfixo[i+1]) && isalpha(posfixo[i+2])) || (isdigit(posfixo[i+1]) &&  isdigit(posfixo[i+2]) && isdigit(posfixo[i+3]))) // Trata de algumas excessões
        {
            flag = 1;
            no = arvore_operacao(no, posfixo[i], flag);
            i++;
        }
        else if((isalpha(posfixo[i]) &&  isalpha(posfixo[i+1])) || (isdigit(posfixo[i]) &&  isdigit(posfixo[i+1])))
        {
            flag = 1;
            no = arvore_operacao(no, posfixo[i], flag);
            i++;
        } else if((isalpha(posfixo[i]) || isdigit(posfixo[i])) && (posfixo[i-1] == '*' || posfixo[i-1] == '+' || posfixo[i-1] == '-' || posfixo[i-1] == '/') && (posfixo[i-2] == '*' || posfixo[i-2] == '+' || posfixo[i-2] == '-' || posfixo[i-2] == '/')){
            flag = 1;
            no = arvore_operacao(no, posfixo[i], flag);
            i++;
        } else if((isalpha(posfixo[i]) || isdigit(posfixo[i])) && ((posfixo[i-1] == '*' || posfixo[i-1] == '+' || posfixo[i-1] == '-' || posfixo[i-1] == '/') && (posfixo[i+1] == '*' || posfixo[i+1] == '+' || posfixo[i+1] == '-' || posfixo[i+1] == '/'))){
            flag = 1;
            no = arvore_operacao(no, posfixo[i], flag);
            i++;
        } else if((posfixo[i] == '*' || posfixo[i] == '+' || posfixo[i] == '-' || posfixo[i] == '/') && (posfixo[i+1] == '*' || posfixo[i+1] == '+' || posfixo[i+1] == '-' || posfixo[i+1] == '/') && (posfixo[i-1] == '*' || posfixo[i-1] == '+' || posfixo[i-1] == '-' || posfixo[i-1] == '/')){
            flag = 1;
            no = arvore_operacao(no, posfixo[i], flag);
            i++;
        }

        no = arvore_operacao(no, posfixo[i], flag);

    }

    print2DUtil(no, 0);


    return 0;
}

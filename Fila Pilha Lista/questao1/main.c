#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"

int item_menu(void); //criacao do menu principal
Elemento * le_altura_largura(Elemento *lst, int h, int w); //faz a leitura da largura e altura
Elemento* retira_na_ordem(Elemento *lst, int m, int n); //retira elementos m e n
void encontra_Kesimo(Elemento *lst, int k); //encontra o k-ésimo termo
Elemento* lst_intersecao (Elemento* lst,Elemento* lst2); //busca interseção entre duas listas

int main()
{

    setlocale(LC_ALL,"");

    int  m=0, n=0, item, h=0, w=0, k=0;

    Elemento *lst;
    Elemento *lst_a;

    lst =  lst_cria();
    for(;;)
    {

        system("cls");
        item = item_menu();
        switch(item)
        {
        case 1:

            system("cls");
            lst = le_altura_largura(lst,h,w);
            system("cls");
            lst_imprime (lst);
            system("pause");

            break;
        case 2:
            system("cls");
            lst_imprime (lst);
            retira_na_ordem(lst,m,n);
            lst_imprime (lst);
            system("pause");

            break;
        case 3:
            system("cls");
            lst_imprime (lst);
            encontra_Kesimo(lst, k);
            system("pause");
            break;
        case 4:
            system("cls");
            lst_a = lst_intersecao (lst,lst_a);
            system("cls");
            break;
        case 5:
            exit(0);
            break;
        }
    }
}
            //--------------FUNCOES UTILIZADAS PARA RESOULUÇÃO DAS QUESTOES ----------------------------------//

int item_menu(void)
{
    char s[80];
    int c;

    printf("\n");
    printf("Menu:\n");
    printf("1. Inserir Retângulos - Letra A\n");
    printf("2. Retirar M-N - Letra B\n");
    printf("3. Encontrar K-ésimo - Letra D\n");
    printf("4. Interseção - Letra E \n");
    printf("5. Sair\n");

    do
    {
        printf("\nEntre com sua escolha: ");
        gets(s);
        c = atoi(s);
    }
    while(c<0 || c>5);

    return c;
}


Elemento * le_altura_largura(Elemento *lst, int h, int w)
{

    int qtd, i, x;
    printf("quantos retangulos deseja inserir? \n");
    scanf("%d", &qtd);

    printf("Entre com 1 para preenchimento aleatorio ou 0 para manual? \n");
    scanf("%d", &x);
    if(x == 0)
    {
        for(i=0; i<qtd; i++)
        {

            printf("Entre com o valor da altura: \n");
            scanf("%d", &h);

            printf("Entre com o valor da largura: \n");
            scanf("%d", &w);
            lst = lst_insere(lst, h, w);
        }
    }
    else
    {
        for(i=0; i<qtd; i++)
        {

            h = rand() % 10;
            w = rand() % 10;
            lst = lst_insere(lst, h, w);
        }
    }
    return lst;
}


Elemento* retira_na_ordem(Elemento *lst, int m, int n)
{

    Elemento *p = lst;
    Elemento *ant;
    Elemento *t;

    int cont = 0, cont2 = 0;

    printf("\n\nEntre com o valor de M: \n");
    scanf("%d", &m);
    printf("Entre com o valor de N: \n");
    scanf("%d", &n);
    while(1)
    {
        do
        {
            if(p == NULL)
            {
                ant->prox = p;
                break;
            }
            ant = p;
            p = p->prox;
            cont++;
        }
        while(cont < m);

        do
        {
            if(p == NULL)
            {
                ant->prox = p;
                break;
            }
            t = p->prox;
            free(p->pt_r);
            free(p);
            p = t;
            cont2++;
        }
        while(cont2 < n);

        if(p == NULL)
        {
            ant->prox = p;
            break;
        }
        else if(p->prox == NULL)
        {
            ant->prox = p;
            break;
        }
        else
        {
            cont = 0;
            cont2 = 0;
            ant->prox = p;
        }

    }

    return lst;
}


void encontra_Kesimo(Elemento *lst, int k)
{
    int receptor, i = 0, area,  x;
    Elemento* p = lst;

    printf("\nDigite 0: buscar manualmente \n");
    printf("Digite 1: buscar aleatoriamente\n");
    scanf("%d", &x);

    if(x==0)
    {
        printf("Entre com a posicao do k-ésimo termo: \n");
        scanf("%d", &k);
    }
    else
    {
        k = rand()%10;
    }

    for(p = lst; p != NULL; p = p->prox)
    {
        i++;
    }

    receptor = i - k;

    if( receptor < 0)
    {
        printf("\n\nK maior que tamanho da lista!\n\n");
        return;
    }

    i = -1;
    for(p = lst; p != NULL; p = p->prox)
    {
        i++;
        if(i == receptor)
        {
            printf("\n");
            printf("\nKésimo:%d\n", k);
            printf("Retangulo =  %d\n", i+1);
            printf("Altura = %d\n", p->pt_r->h);
            printf("Largura = %d\n", p->pt_r->w);
            area = p->pt_r->h * p->pt_r->w;
            printf("Area = %d\n", area);
        }

    }
}

Elemento* lst_intersecao (Elemento* lst, Elemento* lst2)
{
    Elemento *p;
    Elemento *p2 = NULL;
    Elemento *lst3 = NULL;

    int h,w,j=0,i, x;

    for (p = lst; p != NULL; p = p->prox)
    {
        j++;
    }
    if(j ==0)
    {
        printf("\nÉ preciso criar a lista principal primeiro \n");
        system("pause");
        return lst;
    }

    printf("\nÉ preciso criar uma nova lista\n");

    printf("\nEntre com 1 se deseja preencher aleatoriamente ou 0 manualmente\n");
    scanf("%d", &x);

    if(x == 1)
    {
        for(i=0; i<j; i++)
        {
            h = rand()%10;
            w = rand()%10;
            p2 = lst_insere(p2, h, w);
        }
    }
    else
    {
        for(i=0; i<j; i++)
        {

            printf("Entre com o valor da altura: \n");
            scanf("%d", &h);

            printf("Entre com o valor da largura: \n");
            scanf("%d", &w);
            p2 = lst_insere(p2, h, w);
        }

    }
    printf("Lista 1:");
    lst_imprime (lst);
    printf("Lista 2:");
    lst_imprime (p2);

    for (p = lst; p != NULL; p = p->prox)
    {

        if(p->pt_r->h * p->pt_r->w == p2->pt_r->h * p2->pt_r->w)
        {

            lst3 = lst_insere(lst3, p2->pt_r->h, p2->pt_r->w);
        }
        p2 = p2 -> prox;
    }

    if(lst3 == NULL)
    {
        printf("\nNão há interseção entre as áreas\n");
        system("pause");

    }
    else
    {
        printf("\nInterseção das areas\n");
        lst_imprime (lst3);
        printf("\n");
        system("pause");
    }
    return lst3;
}

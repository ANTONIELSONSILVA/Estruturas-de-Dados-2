#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

struct ret
{
    int h; //altura
    int w; //largura
};
typedef struct ret Retangulo;

struct elemento
{
    //insercao
    Retangulo *pt_r;
    //corre a lista
    struct elemento *prox;
};
typedef struct elemento Elemento;

//funcao responsavel pela criacao da lista
Elemento* lst_cria(void);
//funcao responsavel pela insercao da lista
Elemento* lst_insere (Elemento* lst,int h, int w);
//funcao responsavel pela impressao da lista
void lst_imprime (Elemento* lst);

#endif // LISTA_H_INCLUDED

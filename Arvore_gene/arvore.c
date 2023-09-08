#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#define espaco 5


struct arv {
  char info[50];
  struct arv* esq;
  struct arv* dir;
};

typedef struct arv Arv;


Arv* arv_criavazia (void){
	return NULL;
}

Arv* arv_cria (char* c, Arv* sae, Arv* sad){
	Arv* p=(Arv*)malloc(sizeof(Arv));
	
	strcpy(p->info,c);
	p->esq = sae;
	p->dir = sad;
	return p;
}


int arv_vazia (Arv* a){
	return a==NULL;
}


void arv_libera (Arv* a){
	
	if (!arv_vazia(a)){
		arv_libera(a->esq); /* libera sae */
		arv_libera(a->dir); /* libera sad */
		free(a); /* libera raiz */
	}
	
	
}


void desenha_arvore_horiz(Arv* A, int depth, char *path, int direita)
{
    // stopping condition
    if (A== NULL)
        return;

    // increase spacing
    depth++;

    // start with direita no
    desenha_arvore_horiz(A->dir, depth, path, 1);

    // set | draw map
    path[depth-2] = 0;

    if(direita)
        path[depth-2] = 1;

    if(A->esq)
        path[depth-1] = 1;

    // print root after spacing
    printf("\n");

    for(int i=0; i<depth-1; i++)
    {
      if(i == depth-2)
          printf("+");
      else if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<espaco; j++)
      if(i < depth-2)
          printf(" ");
      else
          printf("-");
    }

    printf("%s\n", A->info);

    // vertical espacors below
    for(int i=0; i<depth; i++)
    {
      if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<espaco; j++)
          printf(" ");
    }

    // go to esquerda no
    desenha_arvore_horiz(A->esq, depth, path, 0);
}

//primary fuction
void draw_arvore_hor(Arv* A)
{
    // should check if we don't exceed this somehow..
    char path[255] = {};

    //initial depth is 0
    desenha_arvore_horiz(A, 0, path, 0);
}

void arv_inordem (Arv* a){
	if (!arv_vazia(a)){
		arv_inordem (a->esq);
		arv_inordem (a->dir);
	}
}


void pre_ordemFILE(Arv* A, FILE *p)
{
     if (A != NULL){
                fprintf(p,"%s \n", A->info);
                pre_ordemFILE(A->esq,p);
                pre_ordemFILE(A->dir,p);
     }
}
 
void arquivar(Arv* arquivo){
     FILE *p;
     char str[50];
 
      strcpy(str, "arquivo.txt");
 
      if(!(p = fopen(str, "a")))
      {
             printf("Erro na abertura");
             system("pause");
             exit(1);
      }
 
      pre_ordemFILE(arquivo,p);
      fclose(p);
}



Arv* aux[64];
int count = 0;

int numFolhas(void){
  return count;
}

void buscaFolhas(Arv* a){

    if(a->esq == NULL && a->dir == NULL){
      aux[count] = a;                           // ERRO NESSA LINHA
      count++;
    }else{
      if(a->esq)
        buscaFolhas(a->esq);
      if(a->dir)
        buscaFolhas(a->dir);
    }

  }


Arv** folhas(Arv* a){

  Arv* p = a;

  buscaFolhas(p);

  return aux;

}


void gravarFolha(Arv* a, char* info1, char* info2){

    a->esq = arv_cria(info1, arv_criavazia(), arv_criavazia());
    strcpy(a->esq->info, info1);

    a->dir = arv_cria(info2, arv_criavazia(), arv_criavazia());
    strcpy(a->dir->info, info2);


}


char* retornaInfo(Arv* a){

  return a->info;


}






























 // Faz parte desta função, mas ficou de fora para sofre alterações
               // durante a recursividade

/*
  Arv** buscaFolhas(Arv* a){

    Arv* aux[64];

    if(a->esq == NULL && a->dir == NULL){
      aux[count] = a;
      count++;
    }else{
      if(a->esq)
        buscaFolhas(a->esq);
      if(a->dir)
        buscaFolhas(a->dir);
    }

    return &aux;

  }


*/
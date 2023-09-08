#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "arvore.h"
#define MAXXNAME 50


	void grava(Arv* a);


	int main(){

		setlocale(LC_ALL, "");
		Arv* a = arv_criavazia();
		char name[MAXXNAME];
		int i=0;
		int count=0;
		Arv** aux;
		printf("Se quiser sair Aperte CTRL+C\n");
		printf("Vamos começar!\n");
		printf("O nome do indivíduo da base é: ");
		fgets (name, MAXXNAME, stdin);
		a = arv_cria(name, arv_criavazia(), arv_criavazia());
		grava(a);


		for (int j=0;j<=1;j++){

			aux = folhas(a);
			count = numFolhas();

			while(i < count){
				grava(aux[i]);
				i++;
			}

		}

		draw_arvore_hor(a);
		printf("\n");
		arquivar(a);
		arv_libera(a);

		return 0;
	}


	void grava(Arv* a){

		char name1[MAXXNAME];
		char name2[MAXXNAME];

		printf("Nome da mãe de %s: ", retornaInfo(a));
		fgets (name1, MAXXNAME, stdin);              // MAXXNAME == limite de tamanho

		printf("Nome do Pai de %s: ", retornaInfo(a));
		fgets (name2, MAXXNAME, stdin);

		gravarFolha(a, name1, name2);


		return;

	}

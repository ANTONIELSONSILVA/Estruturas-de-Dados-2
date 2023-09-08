#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAXXVETOR 50

void heapSort(int *vet, int N);
void criaHeap(int *vet, int i, int f);
void stringToInt(char* vet);


void stringToInt(char* vet){


    int count=0,i=0,j=0;
    char vetchar2[5];
    int tam = strlen(vet);
    int* vetorInt = (int*) calloc(tam, sizeof(int));

    do
    {

        while(vet[i] != 32 && i <= tam){
            vetchar2[count] = vet[i];
            i++;
            count++;
        }

        vetorInt[j] = atoi(vetchar2);
        for(int k=0; k<5; k++){vetchar2[k]='-';}
        count=0;
        i++;
        j++;

    }while(i <= tam);

    heapSort(vetorInt, j);

    for (int i = 0; i < j; ++i)
    {
        printf("%i ", vetorInt[i]);
    }

}


void criaHeap(int *vet, int i, int f){
    int aux = vet[i];
    int j = i * 2 + 1;
    while(j <= f){
        if(j < f){
            if(vet[j] < vet[j +  1]){
                j = j + 1;
            }
        }

        if(aux < vet[j]){
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        }else{
            j = f + 1;
        }
    }
    vet[i] = aux;
}


void heapSort(int *vet, int N){
    int i, aux;
    for (i = (N - 1)/2; i >= 0; i--)
    {
        criaHeap(vet, i, N-1);
    }
    for (i = N-1; i >= 1; i--)
    {
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        criaHeap(vet, 0, i - 1);
    }
}


int main(){

    setlocale(LC_ALL,"Portuguese");

    char *vetchar = (char*) malloc(MAXXVETOR * sizeof(char));
    printf("Digite os numeros separados por espaço:\n");
    fgets (vetchar, MAXXVETOR, stdin);

    stringToInt(vetchar);


    return 0;

}

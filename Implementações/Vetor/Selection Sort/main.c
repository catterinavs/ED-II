#include <stdio.h>
#define TAM 10

void imprime(int *vet){
    for (int i=0; i<TAM; i++){
        printf ("%d ", vet[i]);
    }
}

void selection_sort(int *vet, int tam){
    int i = 0, j, menor, pos;
    while(i < tam){
        menor = vet[i];
        pos = i;
        for(j = i; j < tam; j++){
            if(vet[j] < menor){
                menor = vet[j];
                pos = j;
            }
        }
    vet[pos] = vet[i];
    vet[i] = menor;
    i++;
    }
}

void main (){
    int vet[TAM] = {2,5,4,1,6,8,8,7,5,3};

    selection_sort(vet, TAM);
    imprime(vet);
}
#include <stdio.h>
#define TAM 10

void imprime(int *vet){
    for (int i=0; i<TAM; i++){
        printf ("%d ", vet[i]);
    }
}

void bubble_sort(int * vet, int tam){
    int i, j, aux, tam2 = tam-1;
    while ( tam2 > 0 ) {
        for(j = 0; j < tam2; j++){
            if( vet[j+1] < vet[j]) {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;      
            }
        }
        tam2--;
    }
}

void main (){
    int vet[TAM] = {2,5,4,1,6,8,8,7,5,3};

    bubble_sort(vet, TAM);
    imprime(vet);
}
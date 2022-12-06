#include <stdio.h>
#define TAM 10

void imprime(int *vetor) {
    for (int i = 0; i < TAM; i++) 
        printf("%d - ", vetor[i]);
}
void linha(){
    printf("\n---------------------------------------------------------\n");
}

void heap (int *vet, int i, int fim){
    int aux = vet[i], j = i*2+1;
    while(j <= fim){
        if (j < fim){
            if (vet[j] < vet[j+1]){
                j++;
            }
        }
        if(aux < vet[j]){
            vet[i] = vet[j];
            i=j;
            j = i*2+1;
        }
        else{
            j = fim+1;
        }
    }
    vet[i] = aux;
}
void heap_sort(int *vet, int tam){
    int aux;
    for(int i = (tam-1)/2; i>=0; i--){
        heap(vet, i, tam-1);
    }
    for(int i = tam-1; i>0; i--){
        aux = vet[i];
        vet[i] = vet[0];
        vet[0] = aux;
        heap(vet, 0, i-1);
    }
}

void main (){
    int vet[TAM] = {2,5,4,1,6,8,10,7,9,3};

    heap_sort(vet, TAM);
    imprime(vet);
}
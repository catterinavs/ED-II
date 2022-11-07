#include <stdio.h>
#define TAM 10

void imprime(int *vetor) {
    for (int i = 0; i < TAM; i++) 
        printf("%d - ", vetor[i]);
}
void linha(){
    printf("\n---------------------------------------------------------\n");
}

int part (int *vet, int ini, int fim){
    int esq, dir, aux, pivo;
    esq = ini;
    dir = fim;
    pivo = vet[ini];
    while(esq < dir){
        while (vet[esq] <= pivo){
            esq++;
        }
        while(vet[dir] > pivo){
            dir--;
        }
        if (esq < dir){
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;
        }
        imprime(vet);
        linha();
    }
    vet[ini] = vet[dir];
    vet[dir] = pivo;
}

void quick_sort(int *vet, int ini, int fim){
    int pivo;
    if (fim > ini){
        pivo = part(vet, ini, fim);
        quick_sort(vet, ini, pivo-1);
        quick_sort(vet, pivo+1, fim);
    }
}
void main(){
    int vet[TAM] = {2,5,4,1,6,8,10,7,9,3};

    quick_sort(vet, 0, TAM-1);
    imprime(vet);
}
#include <stdio.h>
#define TAM 10

void imprime(int *vetor) {
    for (int i = 0; i < TAM; i++) 
        printf("%d - ", vetor[i]);
}
void linha(){
    printf("\n---------------------------------------------------------\n");
}

void merge (int * vet, int ini, int meio, int fim){
    int aux[fim+1], j, i, k = 0;
    i = ini;
    j = meio+1;
    while(j <= fim && i <= meio){
        if(vet[i] < vet[j]){
            aux[k] = vet[i];
            i++;
            k++;
        }
        else {
            aux[k] = vet[j];
            j++;
            k++;
        }
    }
    if (j <= fim && i > meio){
        while(j <= fim){
            aux[k] = vet[j];
            j++;
            k++;
        }
    }
    if(j > fim && i <= meio){
        while ( i <= meio  ) {
            aux[k] = vet[i];
            i++;
            k++;
        }
    }
    for (int x  = ini; x <= fim; x++){
        vet[x] = aux[x-ini]; 
    }

}
void merge_sort (int *vet, int ini, int fim){
    if (ini < fim){
        int meio = (ini + fim)/2;
        merge_sort(vet, ini, meio);
        merge_sort(vet, meio+1, fim);
        merge(vet, ini, meio, fim);
    }
}

void main(){
    int vet[TAM] = {2,5,4,1,6,8,10,7,9,3};

    merge_sort(vet, 0, TAM-1);
    imprime(vet);
}
#include <stdio.h>
#define TAM 10

void imprime(int *vetor) {
    for (int i = 0; i < TAM; i++) 
        printf("%d - ", vetor[i]);
}
void linha(){
    printf("\n---------------------------------------------------------\n");
}

void shell_sort(int *vet, int tam){
    int i, j, aux, h = 1;
    while(h < tam){
        h = h*3+1;
    }
    h=(h-1)/3;
    while(h>0){
        for (i = h; i < tam; i++){
            aux = vet[i];
            for(j = i; j<=h && aux < vet[j-h]; j=j-h){
                vet[j] = vet[j-h];
                
            }
            vet[j]= aux;
            imprime(vet);
            linha();
        }
        h=(h-1)/3;
    }

}

void main(){
    int vet[TAM]={5, 9, 2, 10, 4, 8, 7, 6, 1, 3};

    //insertion_sort(vet, TAM);
    shell_sort(vet, TAM);
    imprime(vet);
    linha();
}
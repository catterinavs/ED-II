#include <stdio.h>
#define TAM 10

void imprime(int *vetor) {
    for (int i = 0; i < TAM; i++) 
        printf("%d - ", vetor[i]);
}
void linha(){
    printf("\n---------------------------------------------------------\n");
}

void insertion_sort( int *v , int tam) {
    int i, j, aux;
    for ( i = 1; i < tam; i++ ) {
        aux = v[i];
        for ( j = (i-1); j >=0; j-- ) {
            if ( aux < v[j] ) {
                v[j+1] = v[j];
                v[j] = aux;
            }
        }
    }
}

void main(){
    int vet[TAM]={5, 9, 2, 10, 4, 8, 7, 6, 1, 3};

    insertion_sort(vet, TAM);
    imprime(vet);
    linha();

}
#include <stdio.h>
#define MaxV 10

void imprime(int *vetor) {
    for (int i = 0; i < MaxV; i++) 
        printf("%d - ", vetor[i]);
}
void linha(){
    printf("\n---------------------------------------------------------\n");
}
void bs_pedro(int *vetor, int tam) {
    int j, i, auxiliar;
    for ( i = (tam-1); i > 0; i--) {
        for ( j = 0; j < i; j++) {
            if( vetor[j] > vetor[j+1]) {
                auxiliar = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = auxiliar;
            }
        }
    }
}

void bs_cat(int * vet, int tam){
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

int main () {

    int vet[MaxV] = {4,10,5,3,8,7,9,1,2,6};
    bs_pedro(vet, MaxV);
    imprime(vet);
    linha();
    int vet2[MaxV] = {4,10,5,3,8,7,9,1,2,6};
    bs_cat(vet2, MaxV);
    imprime(vet2);

    return 0;
}


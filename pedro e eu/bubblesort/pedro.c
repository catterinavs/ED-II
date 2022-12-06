#include <stdio.h>
#define MaxV 10

void imprime(int *vetor) {
    for (int i = 0; i < MaxV; i++) 
        printf("%d - ", vetor[i]);
}
void linha(){
    printf("\n---------------------------------------------------------\n");
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


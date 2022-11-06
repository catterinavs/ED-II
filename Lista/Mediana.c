#include <stdio.h>

#define TAM 11
void linha(){
    printf("\n---------------------------------------------------\n");
}
void shellsort(int * vet, int tam){
    int h = 0, i, j, aux;
    //calculo do h
    
    while (h < tam){
        h = h*3+1;
    }

    h = (h-1)/3; 
    printf ("%d\n", h);

    while (h > 0){

        for (i=0; i < tam; i++){

            for (j=i; (j+h) < tam; j = j+h){

                if (vet[j] > vet[j+h]){
                    aux = vet[j];
                    vet[j] = vet[j+h];
                    vet[j+h] = aux; 
                }

                for(int k = 0; k < tam; k++){
                    printf("%d-", vet[k]);
                }
                linha();
            }

        }
        h = (h-1)/3;
    }

}


void main (){

    int vet[TAM] = {11,10,9,8,7,6,5,4,3,2,1};

    shellsort(vet, TAM);
    for(int i=0; i<TAM; i++){
        printf("%d ", vet[i]);
    }

}
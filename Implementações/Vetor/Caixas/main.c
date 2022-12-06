#include <stdio.h>

#define TAM 26

void l(){
    printf("\n---------------------------------------------\n");
}

void box (char* vet, int tam){
    int i, j, box[256], k = 0;
    for(i=0; i<256; i++){
        box[i] = 0;
    }
    for(i=0; i<tam; i++){
        box[vet[i]]++;
    }
    l();
    for (i=0; i<256; i++){
        for(j=box[i]; j>0; j--){
            vet[k] = i;
            k++;
        }
    }
}

void main(){
    char vet[26];
    
    scanf("%[^\n]", vet);

    box(vet, TAM);
    for(int i = 0; i<TAM; i++){
        printf("%c ", vet[i]);
    }
}
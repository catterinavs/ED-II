#include <stdio.h>
#define max 15
#define pad 4

void buf(){
    setbuf (stdin, NULL);
}

int forca_bruta(char * cadeia, char * padrao){
    int cont = 0;
    for(int i = 0; i < (max - pad); i++){
        int j = 0;
        while (j<pad && cadeia[i+j] == padrao[j]){
            j++;
            if(j == pad){
                cont++;
            }
        }
    }
    return cont;
}

void main(){
    char cadeia[max], padrao[pad];

    printf ("Cadeia (15): ");
    scanf("%[^\n]", cadeia);
    buf();

    printf("Padrao (4): ");
    scanf("%[^\n]", padrao);
    buf();

    printf("\n%d", forca_bruta(cadeia, padrao));

}
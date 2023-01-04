#include <stdio.h>
#include <stdlib.h>

typedef struct pesquisa {
    char nome[40];
    int idade;
    char sexo;
    int musicas[5];
}Pesquisa;

typedef struct lista{
    Pesquisa info;
    struct lista *prox;
}Lista;

void linha (){
    printf ("\n---------------------------------------------------------\n");
}

void buf(){
    setbuf(stdin, NULL);
}

Lista* criarLista (){
    return NULL;
}

//Cria uma entrada na lista de pesquisa
Lista* CriarEntrada(){
    Lista *n = malloc(sizeof(Lista));
    int i;

    printf("Nome: ");
    buf();
    scanf("%[^\n]", n->info.nome);
    buf();

    printf("Idade: ");
    scanf("%d", &n->info.idade);

    printf("Sexo (F/M): ");
    buf();
    scanf("%c", &n->info.sexo);
    buf();

    printf("Musicas:\n");
    for (i = 0; i < 5; i++){
        printf("%d: ", i+1);
        scanf("%d", &n->info.musicas[i]);
    }

    n->prox = NULL;

    return n;
}

//Adiciona a entrada na lista correta
void AdicionaLista(Lista **l, Lista *n){
    if (*l != NULL){
        *l = n;
    }
    else{
        n->prox = *l;
        *l = n;
    }
}

void main(){
    int opcao, w = 0;
    Lista *novo, *menorFem = criarLista(), *menorMas = criarLista(), *maiorFem = criarLista(), *maiorMas = criarLista();
    
    linha();
    while(w = 0){
        printf("Escolha uma opcao:\n");
        printf("1 - Pesquisa\n");

        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            novo = CriarEntrada();

            if (novo->info.idade <= 20 && novo->info.sexo == 'F'){
                AdicionaLista(&menorFem, novo);
            }
            else if (novo->info.idade <= 20 && novo->info.sexo == 'M'){
                AdicionaLista(&menorMas, novo);
            }
            else if (novo->info.idade > 20 && novo->info.sexo == 'F'){
                AdicionaLista(&maiorFem, novo);
            }
            else{
                AdicionaLista(&maiorMas, novo);
            }
            break;
        
        default:
            break;
        }
    }
}
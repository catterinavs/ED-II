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
    printf ("---------------------------------------------------------\n");
}

void digite(){
    printf(">> ");
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
    if (*l == NULL){
        *l = n;
    }
    else{
        n->prox = *l;
        *l = n;
    }
}

void imprime(Lista **l){
    for (Lista *p = (*l); p!=NULL; p = p->prox){
        printf("%s\t", p->info.nome);
        printf("%d\t", p->info.idade);
        printf("%c\t", p->info.sexo);
        for(int i = 0; i < 5; i++){
            printf("%d ", p->info.musicas[i]);
        }
    linha();
    }
}



void main(){
    int opcao, opcao2, w = 0;
    Lista *novo, *menorFem = criarLista(), *menorMas = criarLista(), *maiorFem = criarLista(), *maiorMas = criarLista();
    
    FILE *arq;
    arq = fopen("save.txt", "r");

    while(w == 0){
        linha();
        printf("Escolha uma opcao:\n");
        printf("1 - Pesquisa\n");
        printf("2 - Imprimir\n");
        linha();

        digite();
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
        
        case 2:
            linha();
            printf("Digite qual lista imprimir:\n");
            printf("1 - Feminino/<=20\n");
            printf("2 - Masculino/<=20\n");
            printf("3 - Feminino/>20\n");            
            printf("4 - Masculino/>20\n");
            
            digite();
            scanf("%d", &opcao2);

            switch (opcao2){
            case 1:
                imprime(&menorFem);
                break;

            case 2:
                imprime(&menorMas);
                break;

            case 3:
                imprime(&maiorFem);
                break;

            case 4:
                imprime(&maiorMas);
                break;
            
            default:
                printf("Entrada invalida!!!!");
                break;
            }
            break;
       
        default:
            w = 1;
            break;
        }
    }
}
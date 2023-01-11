/*
O que já foi feito:
- Lista da pesquisa
- Vetor de 30 espaços para as músicas
- Shellsort nas listas
- Listas das pessoas que ...(olhar no trab)

Próxima coisa
- Módulo para arquivo 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

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

typedef struct listaMusicas{
    int id;
    int numVotos;
}ListaMusicas;

void linha (){
    printf ("-------------------------------------------\n");
}

void limpa(){
    system("cls");
}

void n(){
    printf("\n");
}

void digite(){
    printf(">> ");
}

void buf(){
    setbuf(stdin, NULL);
}

int estaVazia(Lista **l){
    return (*l == NULL);
}

Lista* criarLista (){
    return NULL;
}

//Cria uma entrada na lista de pesquisa
Lista* criarEntrada(){
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
void adicionaLista(Lista **l, Lista *n){
    if (*l == NULL){
        *l = n;
    }
    else{
        n->prox = *l;
        *l = n;
    }
}

void imprime(Lista **l){
    if(!estaVazia(l)){
        for (Lista *p = (*l); p!=NULL; p = p->prox){
            printf("%s\t", p->info.nome);
            printf("%d\t", p->info.idade);
            printf("%c\t", p->info.sexo);
            for(int i = 0; i < 5; i++){
                printf("%d ", p->info.musicas[i]);
        }
        n();
        linha();
        }
    }
    else {
        printf("Lista vazia!!!\n");
    }
}

void iniciaListaMusicas (ListaMusicas *lm){
    for(int i = 0; i < MAX; i++){
        lm[i].id = i+1;
        lm[i].numVotos = 0;
    }
}

void imprimeMusicas (ListaMusicas *lm){
    for(int i = 0; i < MAX; i++){
        printf ("ID: %d\tNumero de votos: %d\n", lm[i].id, lm[i].numVotos);
    }
}

void shellSort(ListaMusicas *vet, int tam){
    int i, j, h = 1;
    ListaMusicas aux;
    
    while(h < tam){
        h = h*3+1;
    }
    while(h > 1){
        h=(h-1)/3;
        for (i = h; i < tam; i++){
            aux = vet[i];
            for(j = i-h; j>=0 && aux.numVotos > vet[j].numVotos; j=j-h){
                vet[j+h] = vet[j];
                
            }
            if (j != i-h){
                vet[j+h] = aux;
            }
        }
    }
}

void gerarListaTop3 (Lista **l, ListaMusicas *lm, Lista **gerar){
    Lista *p, *novo;
    for(p = (*l); p!=NULL; p = p->prox){
        if (p->info.musicas[0] == lm[0].id || p->info.musicas[0] == lm[1].id || p->info.musicas[0] == lm[2].id){
            
            novo = malloc(sizeof(Lista));
            novo->prox = NULL;
            strcpy(novo->info.nome, p->info.nome);
            novo->info.idade = p->info.idade;
            novo->info.sexo = p->info.sexo;
            for(int i = 0; i < 5; i++){
                novo->info.musicas[i] = p->info.musicas[i];
            }
            adicionaLista(gerar, novo);
        }
    }
}

void main(){
    int opcao, opcao2, w = 0;
    
    ListaMusicas musicasMenorFem[MAX], 
    musicasMaiorFem[MAX], 
    musicasMenorMas[MAX], 
    musicasMaiorMas[MAX];

    iniciaListaMusicas(musicasMenorFem);
    iniciaListaMusicas(musicasMaiorFem);
    iniciaListaMusicas(musicasMenorMas);
    iniciaListaMusicas(musicasMaiorMas);

    Lista *novo, 
    *menorFem = criarLista(), 
    *menorMas = criarLista(), 
    *maiorFem = criarLista(), 
    *maiorMas = criarLista(),
    *topMusicasMenorFem = criarLista(),
    *topMusicasMenorMas = criarLista(),
    *topMusicasMaiorFem = criarLista(),
    *topMusicasMaiorMas = criarLista();

    while(w == 0){

        linha();
        printf("Escolha uma opcao:\n");
        printf("1 - Pesquisa\n");
        printf("2 - Imprimir Pesquisa\n");
        printf("3 - Imprimir votos das musicas\n");
        printf("4 - Gerar lista das pessoas que escolheram na 1 opcao uma musica do top 3\n");
        linha();

        digite();
        scanf("%d", &opcao);
        limpa();

        switch (opcao){
        case 1:
            novo = criarEntrada();

            if (novo->info.idade <= 20 && novo->info.sexo == 'F'){
                adicionaLista(&menorFem, novo);
                for(int i = 0; i < 5; i++){
                    for(int j = 0; j < MAX; j++){
                        if(musicasMenorFem[j].id == novo->info.musicas[i]){
                            musicasMenorFem[j].numVotos++;
                        }
                    }

                }
            }
            else if (novo->info.idade <= 20 && novo->info.sexo == 'M'){
                adicionaLista(&menorMas, novo);
                for(int i = 0; i < 5; i++){
                    for(int j = 0; j < MAX; j++){
                        if(musicasMenorMas[j].id == novo->info.musicas[i]){
                            musicasMenorMas[j].numVotos++;
                        }
                    }
                }
            }
            else if (novo->info.idade > 20 && novo->info.sexo == 'F'){
                adicionaLista(&maiorFem, novo);
                for(int i = 0; i < 5; i++){
                    for(int j = 0; j < MAX; j++){
                        if(musicasMaiorFem[j].id == novo->info.musicas[i]){
                            musicasMaiorFem[j].numVotos++;
                        }
                    }
                }
            }
            else{
                adicionaLista(&maiorMas, novo);
                for(int i = 0; i < 5; i++){
                    for(int j = 0; j < MAX; j++){
                        if(musicasMaiorMas[j].id == novo->info.musicas[i]){
                            musicasMaiorMas[j].numVotos++;
                        }
                    }
                }
            }
            limpa();
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
            limpa();

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

        case 3:
            linha();
            printf("Digite qual lista imprimir:\n");
            printf("1 - Feminino/<=20\n");
            printf("2 - Masculino/<=20\n");
            printf("3 - Feminino/>20\n");            
            printf("4 - Masculino/>20\n");
            
            digite();
            scanf("%d", &opcao2);
            limpa();

            switch (opcao2){
                case 1:
                    shellSort(musicasMenorFem, MAX);
                    imprimeMusicas(musicasMenorFem);
                    break;

                case 2:
                    shellSort(musicasMenorMas, MAX);
                    imprimeMusicas(musicasMenorMas);
                    break;

                case 3:
                    shellSort(musicasMaiorFem, MAX);
                    imprimeMusicas(musicasMaiorFem);
                    break;

                case 4:
                    shellSort(musicasMaiorMas, MAX);
                    imprimeMusicas(musicasMaiorMas);
                    break;
                
                default:
                    printf("Entrada invalida!!!!");
                    break;
                }
                break;
            break;

        case 4:    
            linha();
            printf("Digite qual lista gerar:\n");
            printf("1 - Feminino/<=20\n");
            printf("2 - Masculino/<=20\n");
            printf("3 - Feminino/>20\n");            
            printf("4 - Masculino/>20\n");
            
            digite();
            scanf("%d", &opcao2);
            limpa();
            
            switch (opcao2){
                case 1:
                    shellSort(musicasMenorFem, MAX);
                    gerarListaTop3(&menorFem, musicasMenorFem, &topMusicasMenorFem);
                    imprime(&topMusicasMenorFem);
                    break;

                case 2:
                    shellSort(musicasMenorMas, MAX);
                    gerarListaTop3(&menorMas, musicasMenorMas, &topMusicasMenorMas);
                    imprime(&topMusicasMenorMas);
                    break;

                case 3:
                    shellSort(musicasMaiorFem, MAX);
                    gerarListaTop3(&maiorFem, musicasMaiorFem, &topMusicasMaiorFem);
                    imprime(&topMusicasMaiorFem);
                    break;

                case 4:
                    shellSort(musicasMaiorMas, MAX);
                    gerarListaTop3(&maiorMas, musicasMaiorMas, &topMusicasMaiorMas);
                    imprime(&topMusicasMaiorMas);
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
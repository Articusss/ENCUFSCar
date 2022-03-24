#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Cell{
    struct Cell* prox;
    int conteudo;
};

typedef struct Cell Cell;

Cell* criaFila(){
    //Sem header
    return NULL;
}

bool vazia(Cell* F){
    return F == NULL;
}

void insere(Cell **F, int x){
    //Agora inserindo no inicio
    Cell* novo;
    novo = (Cell*) malloc(sizeof(Cell));
    novo->conteudo = x;
    //Apenas inserindo no inicio. Propagacao do null
    novo->prox = *F;
    *F = novo;
}

int retira(Cell **F){
    if(!vazia(*F)){
        int x;
        //Caso de 1 elemento na lista
        if((*F)->prox == NULL){
            x = (*F)->conteudo;
            free(*F);
            *F = criaFila();
        } else {
             //Retirando o ultimo valor
            Cell* morta;
            morta = *F;
            Cell* ant;
            while(morta->prox != NULL){
                ant = morta;
                morta = morta->prox;
            }
            x = morta->conteudo;
            ant->prox = morta->prox;
            free(morta);
            morta = NULL;
        }
        return x;
    }
    return -1;
}

void inverter(Cell **F){
    //Inverte a pilha(linked list)
    Cell* ant = NULL;
    Cell* atual = *F;
    Cell* prox;

    //Agora iniciando o algoritmo de reverter
    while(atual != NULL){
        //Setando
        prox = atual->prox;
        atual->prox = ant;
        //Agora avancando
        ant = atual;
        atual = prox;
    }
    //Ant parou no ultimo elemento
    *F = ant;
}

int main(){
    Cell *fila1;
    fila1 =  criaFila();
    printf(vazia(fila1) ? "True\n" : "False\n");
    insere(&fila1, 1);
    retira(&fila1);
    for(int i=0; i < 10; i++){
        insere(&fila1, i);
    }
    printf(vazia(fila1) ? "True\n" : "False\n");
    //Retirando
    while(!vazia(fila1)){
        printf("%d \n", retira(&fila1));
    }
    printf(vazia(fila1) ? "True" : "False");

    for(int i=0; i<10; i++){
        insere(&fila1,i);
    }

    //Invertendo
    inverter(&fila1);

    while(!vazia(fila1)){
        printf("%d \n", retira(&fila1));
    }
}
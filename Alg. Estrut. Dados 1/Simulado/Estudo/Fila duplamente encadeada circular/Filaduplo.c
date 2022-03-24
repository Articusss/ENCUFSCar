#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Filaduplo.h"

struct Cell{
    struct Cell* dir;
    struct Cell* esq;
    int conteudo;
};

Cell *criaFila(){
    //Sem no header
    return NULL;
}

bool vazia(Cell* F){
    return F ==  NULL;
}

void insere(Cell **F, int x){
    //Insere no inicio
    Cell *nova;
    nova = (Cell*) malloc(sizeof(Cell));
    nova->conteudo = x;

    //Verifica se eh o primeiro elemento
    if(vazia(*F)){
        *F = nova;
        nova->dir = nova;
        nova->esq = nova;
    } else {
        //Nao esta vazia, entao inserir e reposicionar o resto
        //Inserindo os valores na nova
        nova->esq = (*F)->esq;
        nova->dir = *F;
        //Consertando os valores velhos
        (*F)->esq->dir = nova;
        (*F)->esq = nova;
        *F = nova;
    }
    
}

int retira(Cell **F){
    //Agora retirando. 
    if(!vazia(*F)){
        int x;
        //Verificando se ha apenas um elemento
        if((*F)->dir == *F){
            x = (*F)->conteudo;
            free(*F);
            *F = NULL;
        } else {
            //Mais de um elemento, retirar o ultimo
            Cell *morta = (*F)->esq;
            x =morta->conteudo;
            //Consertando os ponteiros
            morta->esq->dir = *F;
            morta->dir->esq = morta->esq;
            free(morta);
        }
        return x;
    }
    return -1;
}

void destroi(Cell **F){
    while(!vazia(*F)){
        //Destruindo
        retira(F);
    }
}
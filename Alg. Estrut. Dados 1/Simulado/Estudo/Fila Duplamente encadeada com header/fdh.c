#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Criando o cell
typedef struct Cell{
    int conteudo;
    struct Cell* esq;
    struct Cell* dir;
} Cell;

//Funcoes
Cell* criaFila(){
    //criando o no header
    Cell * header;
    header = (Cell*) malloc(sizeof(Cell));
    header->esq= header;
    header->dir = header;
    return header;
}

bool vazia(Cell* F){
    return (F->dir == F && F->esq == F);
}

void insere(Cell *F, int x){
    //Inserindo depois do header
    Cell *nova;
    nova = (Cell *) malloc(sizeof(Cell));
    nova->conteudo = x;
    //Ajustando ponteiros da nova
    nova->esq = F;
    nova->dir = (F)->dir;
    //Ajustando ponteiros da antiga
    nova->dir->esq = nova;
    (F)->dir = nova;
}

int retira(Cell *F){
    //Agora retirando, verificar novamente se esta vazia
    if(!vazia(F)){
        Cell *morta = (F)->esq;
        morta->esq->dir =  F;
        (F)->esq = morta->esq;
        int x =morta->conteudo;
        free(morta);
        return x;
    } 
    //else
    return -1;
}

int main(){
    Cell *fila1;
    fila1 =  criaFila();
    printf(vazia(fila1) ? "True\n" : "False\n");
    for(int i=0; i < 10; i++){
        insere(fila1, i);
    }
    printf(vazia(fila1) ? "True\n" : "False\n");
    //Retirando
    while(!vazia(fila1)){
        printf("%d \n", retira(fila1));
    }
    printf(vazia(fila1) ? "True" : "False");
}
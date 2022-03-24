#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node{
    int conteudo;
    struct Node* esq;
    struct Node* dir;
};

typedef struct Node Node;

Node * criaLista(){
    return NULL;
}

bool vazia(Node* L){
    return L == NULL;
}

bool esta(Node* L, int x){
    if(vazia(L)) return false;
    Node *p = L->dir;
    //Percorrendo ate achar
    while(p != L && p->conteudo != x) p = p->dir;
    return p->conteudo == x;     
}

void insere(Node **L, int x){
    if(!esta(*L, x)){
        //Inserindo
        Node *novo;
        novo = (Node*) malloc(sizeof(Node));
        novo->conteudo = x;
        if(vazia(*L)){
            novo->dir = novo;
            novo->esq =  novo;
            *L = novo;
        } else {
            //Inserindo no inicio
            novo->dir = *L;
            novo->esq = (*L)->esq;
            (*L)->esq->dir = novo;
            (*L)->esq = novo;
            *L = novo;
        }
    } 
}

void remover(Node **L, int x){
    if(!vazia(*L)){
        //Verificando se eh o primeiro e o unico da lista
        if((*L)->conteudo == x && (*L)->dir == *L){
            //Resetando
            free(*L);
            *L = criaLista();
        } 
        else if((*L)->conteudo == x){
            //Removendo o primeiro
            (*L)->esq->dir = (*L)->dir;
            (*L)->dir->esq = (*L)->esq;
            free(*L);
            *L = (*L)->dir;

        }
        else{
            Node *morta;
            //Buscando
            morta = (*L)->dir;
            while(morta->conteudo != x && morta != *L) morta =  morta->dir;
            //Removendo, se encontrou
            if(morta != *L){
                morta->esq->dir = morta->dir;
                morta->dir->esq = morta->esq;
                free(morta);
            } else {
                //erro sim
            }
        }
    }
}
//Assume que nao esta vazia
int pegaPrimeiro(Node *L){
    return L->conteudo;
}

int pegaProximo(Node *L, int x){
    Node *p = L;
    //percorrendo
    do{
        if(p->conteudo == x && p->dir != L) return p->dir->conteudo;
        p = p->dir;
    }while(p != L);
    //Nulo
    return -1;

}

int main(){
    Node * lista;
    lista = criaLista();
    
    for(int i=0; i<10; i++){
        insere(&lista, i);
    }
    for(int i=0; i<12; i++){
        printf(esta(lista,i) ? "True\n" : "False\n");
    }

    //imprimindo
    int x;
    x = pegaPrimeiro(lista);
    while(x != -1){
        printf("%d\n", x);
        x = pegaProximo(lista,x);
    }

    printf("%d\n", lista->esq->dir->conteudo);

    while(!vazia(lista)){
        remover(&lista, pegaPrimeiro(lista));
    }

        for(int i=0; i<10; i++){
        insere(&lista, i);
    }
    for(int i=0; i<12; i++){
        printf(esta(lista,i) ? "True\n" : "False\n");
    }

    while(!vazia(lista)){
        remover(&lista, pegaPrimeiro(lista));
    }

    printf(vazia(lista) ? "True\n" : "False\n");

}
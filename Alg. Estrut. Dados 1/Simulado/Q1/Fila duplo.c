#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node{
    int conteudo;
    struct Node *dir;
    struct Node *esq;
};

typedef struct Node Node;

struct Fila{
    struct Node* primeiro;
    struct Node* ultimo;
};

typedef struct Fila Fila;


Fila *criaFila(){
    //Criando a struct de fila
    Fila *temp;
    temp = (Fila *) malloc(sizeof(Fila));
    temp->primeiro = NULL;
    temp->ultimo = NULL;
    return temp;
}

bool vazia(Fila *F){
    //Nao sei pq ta assim
    return (F->primeiro == NULL && F->ultimo == NULL) ? true : false;
}

void empilha(Fila **F, int valor){
    //Empilhando
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->conteudo = valor;

    if (vazia(*F)){
        (*F)->primeiro = p;
        (*F)->ultimo = p;
        p->dir = p;
        p->esq = p;
    }
    else{
        p->dir = (*F)->primeiro;
        p->esq = (*F)->ultimo;
        (*F)->primeiro->esq = p;
        (*F)->ultimo->dir = p;
        (*F)->ultimo = p;
    }
}

void retira(Fila **F, int *X, bool *Erro){
    //Verificando vazia
    if(vazia(*F)){
        *Erro = true;
    }
    //Verificando elemento unico
    else if((*F)->primeiro == (*F)->ultimo){
        *Erro = false;
        //setando elemento
        Node *p = (*F)->primeiro;
        *X = p->conteudo;
        //Liberando a memoria
        free(p);
        //Melhorando a portabilidade, "Reiniciamos" a fila
        (*F) = criaFila();
    }

    //Terceiro caso, mais de um elemento na fila
    //Dado que a operacao insere insere o elemento no valor ulitmo da fila, temos
    else{
        *Erro = false;
        Node *morta;
        morta = (*F)->primeiro;
        (*F)->ultimo->dir = morta->dir;
        morta->dir->esq = (*F)->ultimo;
        (*F)->primeiro = morta->dir;
        *X = morta->conteudo;
        free(morta);
    }

}

void destroi(Fila **F){
    //desalocando dinamicamente todos os elementos da fila. Usando funcoes primitivas
    //Variaveis temporarias apenas para chamada de funcao
    bool erro;
    int x;
    while(!vazia(*F)){
        retira(F,&x,&erro);
    }
}


int main(){
    Fila * F;
    bool erro;
    int x;
    F = criaFila();

    printf(vazia(F) ? "True\n" : "False\n");
    for(int i=0; i<10; i++){
        empilha(&F, i);
    }
    printf(vazia(F) ? "True\n" : "False\n");
    retira(&F, &x, &erro);
    printf("%d\n", x);

    while(!vazia(F)){
        retira(&F, &x, &erro);
        printf("%d\n", x);
    }

    for(int i=0; i<10; i++){
        empilha(&F, i);
    }

    retira(&F, &x, &erro);
    printf("%d\n", x);
    

    destroi(&F);
    printf(vazia(F) ? "True\n" : "False\n");
    



    return 0;
}
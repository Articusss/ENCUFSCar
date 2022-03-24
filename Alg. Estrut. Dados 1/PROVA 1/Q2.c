#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    char info;
    struct Node* dir;
    struct Node* esq;
};

struct Pilha{
    struct Node* header;
};

typedef struct Node Node;
typedef struct Pilha Pilha;

Pilha criaPilha(){
    Pilha temp;
    temp.header = (Node*) malloc(sizeof(Node));
    temp.header->dir = temp.header;
    temp.header->esq = temp.header;
    return temp;
}

bool Vazia(Pilha *P){
    return (P->header->dir ==  P->header && P->header->esq == P->header);
}

//Para usagem em c, elemento == char
//Tratar segundo caso, pilha empilhada na direita, topo esta na direita
void Empilha(Pilha *P, char x){
    Node *nova;
    nova = (Node *) malloc(sizeof(Node));
    nova->info = x;
    //Agora empilhando
    nova->dir = P->header->dir;
    nova->esq = P->header;
    P->header->dir = nova;
}

char Desempilha(Pilha *P){
    if(!Vazia(P)){
        Node * morta;
        morta = P->header->dir;
        morta->dir->esq = P->header;
        P->header->dir = morta->dir;
        char x = morta->info;
        free(morta);
        morta = NULL; 
        return x;
    }
    return '/';
}

int main(){
    Pilha pilha;
    pilha = criaPilha();

    printf(Vazia(&pilha) ? "True\n" : "False\n");
    for(int i=65; i<90; i++){
        Empilha(&pilha, i);
    }
    while(!Vazia(&pilha)){
        printf("%c\n",Desempilha(&pilha));
    }

    printf(Vazia(&pilha) ? "True\n" : "False\n");

    for(int i=65; i<90; i++){
        Empilha(&pilha, i);
    }
    while(!Vazia(&pilha)){
        printf("%c\n",Desempilha(&pilha));
    }

    printf(Vazia(&pilha) ? "True\n" : "False\n");

}
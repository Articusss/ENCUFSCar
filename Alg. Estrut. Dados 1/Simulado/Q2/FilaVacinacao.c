#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int conteudo;
    struct Node *next;
};

typedef struct Node Node;

Node *criaFV(){
    return NULL;
}

bool vazia(FV){
    return FV == NULL;
}

void insere(Node **FV, int idade){
    //Criando e alocando o node
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->conteudo = idade;
    //Primeiro caso: fila vazia
    if(vazia(*FV)){
        //Apenas inserir
        *FV = newnode;
        newnode->next = newnode;
    }
    //Caso 2: novo node deve ser inserido no inicio
    else if(idade > (*FV)->conteudo){
        //Reposicionando
        newnode->next = (*FV);
        //Como nao temos o ponteiro do "ultimo" elemento, percorrer ate o final e setar manualmente
        Node *p = (*FV)->next;
        while(p->next != *FV) p = p->next;
        p->next = newnode;
        (*FV) = newnode;
    }
    //Caso 3: Inserir normalmente. Tambem contem 2 casos dentro dele
    else{
        Node *atual = (*FV)->next;
        Node *ante = *FV;
        //Percorrendo ate encontrar o valor que deve ser encaixado.
        while(atual->conteudo > idade && atual != *FV){
            ante = atual;
            atual = atual->next;
        }
        //Primeiro subcaso, ha pelo menos 1 pessoa mais nova do que o novo node na fila
        if(atual != *FV){
            //Inserindo o newnode entre os 2
            newnode->next = atual;
            ante->next = newnode;
        }
        //Agora, caso for o mais novo da fila, inserir no final
        else{
            ante->next = newnode;
            newnode->next = *FV;
        }
    }
}

void retira(Node **FV, int *X, bool *E){
    if(vazia(*FV)){
        *E = true;
    }
    //Segundo caso - 1 elemento na litsa
    else if(*FV == (*FV)->next){
        *E = false;
        *X = (*FV)->conteudo;
        *FV = NULL;
    }
    else{
        *E = false;
        //Consertar o loop do ultimo
        Node *ultimo = (*FV)->next;
        while(ultimo->next != *FV) ultimo = ultimo->next;
        *X = (*FV)->conteudo;
        Node *p = (*FV);
        (*FV) = (*FV)->next;
        ultimo->next = *FV;

        free(p);
    }
}


int main(){
    Node *FV;
    FV = criaFV();
    insere(&FV, 10);
    insere(&FV, 84);
    insere(&FV, 70);
    insere(&FV, 5);
    insere(&FV, 90);
    insere(&FV, 10);
    insere(&FV, 1);
    insere(&FV, 1200);
    insere(&FV, 43);
    insere(&FV, 87);
    insere(&FV, 55);
    int x;
    bool erro;
    while(!vazia(FV)){
        retira(&FV, &x, &erro);
        printf("%d\n", x);
    }


    return 0;
}
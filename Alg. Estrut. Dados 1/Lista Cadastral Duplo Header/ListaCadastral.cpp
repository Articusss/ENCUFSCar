//ListaCadastral.cpp
#include <iostream>
using namespace std;
#include "ListaCadastral.hpp"

cell::cell(){
    prox = NULL;
    ant =  NULL;
}

//Construtor
ListaCadastral::ListaCadastral(){
    //Criando o no cabeca
    head = new cell;
    head->ant = head;
    head->prox = head;
}

//Insere no inicio
bool ListaCadastral::insere(int x){
    if(!estaNaLista(x)){
        cell *novo;
        novo =  new cell;
        novo->conteudo = x;
        //Ligando os novos enderecos do novo
        novo->prox = head->prox;
        novo->ant = head;
        //Ajustando enderecos da lista
        head->prox = novo;
        novo->prox->ant = novo;
        return true;
    }
    return false;
}

bool ListaCadastral::retira(int x){
    cell *p;
    p = head->prox;
    //Percorrer ate o final ou encontrar o conteudo
    while(p != head){
        if(p->conteudo == x){
            //Caso achou, remover
            //Anterior da proxima
            p->prox->ant = p->ant;
            //Proxima da anterior
            p->ant->prox = p->prox;

            delete[] p;
            p = NULL;
            return true;
        }
        //Avancando
        p = p->prox;
    }
    //Nao achou
    return false;
}

bool ListaCadastral::estaNaLista(int x){
    cell *p;
    p = head->prox;
    while(p != head){
        if(p->conteudo == x) return true;
        p = p->prox;
    }
    return false;
}

bool ListaCadastral::vazia(){
    return head->prox == head;
}

bool ListaCadastral::cheia(){
    //Alocacao dinamica, entao testamos se ha espaco na memoria
    cell *test;
    test = (cell *) malloc(sizeof(cell));
    if(test == NULL){
        return true;
    }
    free(test);
    return false;
}

int ListaCadastral::pegaOPrimeiro(){
    return head->prox->conteudo;
}

int ListaCadastral::pegaOProximo(int x){
    cell *p;
    p = head->prox;
    while(p != head){
        if(p->conteudo == x && p->prox != head) return p->prox->conteudo;
        p = p->prox;
    }

    //"Nulo"
    return -1;
}

//Destrutor
ListaCadastral::~ListaCadastral(){
    cell *morta;
    cell *p;
    morta = NULL;
    p = head->prox;
    //Destruir a lista cadastral toda
    while(p != head){
        morta = p;
        p = p->prox;
        delete[] morta; 
    }
    //Deletando o head
    delete[] p;
}
//ListaCadastral.cpp
#include <iostream>
using namespace std;
#include "ListaCadastral.hpp"

//Construtor
ListaCadastral::ListaCadastral(){
    ini = NULL;
}

//Insere no inicio
bool ListaCadastral::insere(int x){
    if(!estaNaLista(x)){
        cell *nova;
        nova = (cell *) malloc(sizeof(cell));
        nova->conteudo = x;
        nova->prox = ini;
        ini = nova;
        return true;
    }
    return false;
}

bool ListaCadastral::retira(int x){
    //Nao utilizar estaNaLista, para fazer o algoritmo O(n), em vez de O(n^2)
    cell *morta;
    cell *ant;
    morta = ini;
    ant = NULL;
    //Percorrer a lista ate o final ou ate encontrar o conteudo
    while(morta != NULL){
        if(morta->conteudo == x){
            ant->prox = morta->prox;
            free(morta);
            return true;
        } else{
            //Avancar
            ant = morta;
            morta = morta->prox;
        }
    }
    //Percorreu ate o final sem encontrar
    return false;
}

bool ListaCadastral::estaNaLista(int x){
    //Percorrer a lista ate encontrar
    cell *p;
    p = ini;
    while(p != NULL){
        if(p->conteudo == x) return true;
        p = p->prox;
    }
    return false;
}

bool ListaCadastral::vazia(){
    if(ini == NULL) return true;
    return false;
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
    if(vazia()){
        //"nulo"
        return -1;
    }
    return ini->conteudo;
}

int ListaCadastral::pegaOProximo(int x){
    //Novamente, para transformar a funcao em O(n), nao utilizar estaNaLista
    cell *p;
    p = ini;
    while(p->prox!= NULL){
        if(p->conteudo == x){
            p = p->prox;
            return p->conteudo;
        }
        p = p->prox;
    }
    
    //"nulo"
    return -1;
}

//Destrutor
ListaCadastral::~ListaCadastral(){
    //Desalocar toda as celular
    cell *morta;
    //Percorre ate que a lista esteja vazia
    while(ini != NULL){
        morta = ini;
        ini = ini->prox;
        free(morta);
    }
}
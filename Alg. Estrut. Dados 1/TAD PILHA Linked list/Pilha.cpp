//Pilha.cpp

#include <stdio.h>
#include <iostream>
#include "Pilha.hpp"
using namespace std;

//Metodos para a pilha
Pilha::Pilha(){
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
}

//Copy constructor
Pilha::Pilha(const Pilha &p){
    //Alocar inicial
    head = (Node *)malloc(sizeof(Node));
    Node *current = head;
    Node *temp = p.head;
    bool deuCerto;
    //Vai percorrendo até o fim da lista e copiando
    while(temp->next != NULL){
        temp = temp->next;
        current->next = (Node *)malloc(sizeof(Node));
        current = current->next;
        current->content = temp->content;
    }
    current->next = NULL;
}

bool Pilha::vazia(){
    if(head->next == NULL) return true;
    return false;
}

void Pilha::empilha(int x){
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->content = x;
    newnode->next = head->next;
    head->next =  newnode;
}

int Pilha::desempilha(){
   if(!vazia()){
    Node *deletednode;
    deletednode = head->next;
    int x = deletednode->content;
    head->next = deletednode->next;
    free(deletednode);
    deletednode = NULL;
    return x;
   } 
   //else
   return -99999;
}

Pilha::~Pilha(){
    while(!vazia()){
        desempilha();
    }
    free(head);
    head = NULL;
}

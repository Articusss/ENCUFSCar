//Pilha.cpp

#include <stdio.h>
#include <iostream>
#include "Pilha.hpp"
using namespace std;

//Metodos para a pilha
Pilha::Pilha(){
    topo = -1;
}

bool Pilha::cheia(){
    if (topo == 49) return true;
    return false;
}

bool Pilha::vazia(){
    if(topo == -1) return true;
    return false;
}

void Pilha::empilha(int x, bool *deuCerto){
    //Verifica se pilha esta cheia
    if(cheia()){
        *deuCerto = false;
    } else{
        *deuCerto = true;
        topo++;
        stack[topo] = x;
    }
}

void Pilha::desempilha(int *x, bool *deuCerto){
    if(vazia()){
        *deuCerto = false;
    } else {
        *deuCerto = true;
        *x = stack[topo];
        stack[topo] = 0;
        topo--;
    }
}

#include <iostream>
#include "Fila.h"

using namespace std;

int Fila::contador = 0;

int Fila::getContador(){
    return contador;
}

Fila::Fila(int t):tam(t){
    queue = new char[t];
    topo = 0;
    contador++;
}

Fila::~Fila(){
    delete [] queue;
}

//Construtor de cópia
Fila::Fila(Fila &f):tam(f.tam),topo(f.topo){
    //Alocando e copiando os valores
    queue = new char[tam];

    for(int i=0; i < tam; i++){
        queue[i] = f.queue[i];
    }
}

bool Fila::inserir(char x){
    if(!cheia()){
        queue[topo] = x;
        topo++;
        return true;
    }
    return false;
}

//Metodo retira 
char Fila::remover(){
    //Verifica se a fila não está vazia
    if(!vazia()){
        //Retira o primeiro elemento e desloca o topo
        char primeiro = queue[0];
        topo--;
        //Deslocando todos os elementos
        for(int i=0; i < topo; i++){
            queue[i] = queue[i+1];
        }
        return primeiro;
    }
    
    //else retornar "nulo"
    return '/';
}

bool Fila::vazia() const{
    return topo==0;
}

bool Fila::cheia() const{
    return topo == tam;
}
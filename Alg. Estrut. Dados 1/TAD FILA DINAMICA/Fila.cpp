//Fila.cpp
#include <iostream>
#include "Fila.hpp"
using namespace std;

//Agora inserindo metodos para a pilha

Fila::Fila(int tamanho){
    fim = 0;
    v = new int[tamanho];
    tam = tamanho;
}

bool Fila::cheia(){
    return fim == tam;
}

bool Fila::vazia(){
    return fim == 0;
}

void Fila::inserir(int x){
    if(!cheia()){
        v[fim++] = x;
    } else {
        cout << "Fila cheia. Inicialize com um tamanho maior" << endl;
    }
}

int Fila::remover(){
    if(!vazia()){
        int x;
        x = v[0];
        fim--;
        realocar();
        return x;
    }

    return -99999;
};

void Fila::realocar(){
    for(int i=0; i < fim; i++){
        v[i] = v[i + 1];
    }
};

Fila::~Fila(){
    delete[]v;
};
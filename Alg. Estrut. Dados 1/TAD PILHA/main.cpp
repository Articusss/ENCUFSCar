//main.cpp

#include <stdio.h>
#include <iostream>
#include "Pilha.hpp"

using namespace std;

int numeroElementos (Pilha pilha){
    int n;
    //Variaveis apenas para funcao funcionar
    int desempilhado;
    bool deuCerto;
    while(!pilha.vazia()){
        n++;
        pilha.desempilha(&desempilhado, &deuCerto);
    }
    return n;
}
//Retorna o elemento do topo, se nao deu certo, retorna -1
int retornaTopo (Pilha pilha){
    int topo;
    bool deuCerto;
    pilha.desempilha(&topo, &deuCerto);
    if(deuCerto){
        return topo;
    }
    return -1;
}

int main(){
    //Criando a pilha e a varuavel para checagem
    Pilha mypilha;
    bool deuCerto;

    //Agora, testando o TAD pilha.
    //Verifica se eh vazio
    printf("Pilha vazia: ");
    printf(mypilha.vazia() ? "True\n" : "False\n");

    //Adicionando 50 items nela
    for(int i = 0; i<50; i++){
        mypilha.empilha(i, &deuCerto);
    }

    //Verificando se esta cheia
    printf("Pilha cheia apos preenchimento: ");
    printf(mypilha.cheia() ? "True\n" : "False\n");

    //Verificando desempilhamento
    int desempilhado;
    mypilha.desempilha(&desempilhado, &deuCerto);
    printf("O valor desempilhado foi: %d. Resultado esperado eh 49\n", desempilhado);

    //Verificando metodos nao primitivos, que utilizam metodos primitivos
    printf("Numero de elementos eh %d. Esperado = 49\n", numeroElementos(mypilha));

    printf("O elemento do topo eh %d. Esperado = 48\n", retornaTopo(mypilha));

    return 0;
}
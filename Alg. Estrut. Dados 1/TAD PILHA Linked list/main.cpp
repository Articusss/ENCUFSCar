//main.cpp

#include <stdio.h>
#include <iostream>
#include "Pilha.hpp"

using namespace std;

int numeroElementos (Pilha pilha){
    int n=0;
    //Variaveis apenas para funcao funcionar
    while(!pilha.vazia()){
        n++;
        pilha.desempilha();
    }
    return n;
}
//Retorna o elemento do topo, se nao deu certo, retorna -1
int retornaTopo (Pilha pilha){
    return pilha.desempilha();
}

int main(){
    //Criando a pilha e a varuavel para checagem
    Pilha mypilha;

    //Agora, testando o TAD pilha.
    //Verifica se eh vazio
    printf("Pilha vazia: ");
    printf(mypilha.vazia() ? "True\n" : "False\n");

    //Adicionando 50 items nela
    for(int i = 0; i<50; i++){
        mypilha.empilha(i);
    }

    //Removido: teste de pilha cheia.

    //Verificando desempilhamento
    printf("O valor desempilhado foi: %d. Resultado esperado eh 49\n", mypilha.desempilha());

    //Verificando metodos nao primitivos, que utilizam metodos primitivos
    printf("O elemento do topo eh %d. Esperado = 48\n", retornaTopo(mypilha));
    printf("Tentando novamente para testar o construtor de copia, o elemento do topo eh %d. Esperado = 48\n", retornaTopo(mypilha));

    printf("Numero de elementos eh %d. Esperado = 49\n", numeroElementos(mypilha));

    //TESTES ADICIONAIS
    while(!mypilha.vazia()){
        mypilha.desempilha();
    }

    cout << "Desempilhando quando vazio, esperado: (-9999) " << mypilha.desempilha() << endl;

    return 0;
}
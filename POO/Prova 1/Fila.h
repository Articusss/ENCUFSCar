#include <iostream>

using namespace std;

#ifndef FILA_H
#define FILA_H

class Fila{
    private:
        //Atributos
        //contador
        int topo;
        char *queue;
        //tamanho da fila
        int tam;
    static int contador;
    public:
        //Metodos publicos
        //Construtor, construtor de cópia e destrutor
        Fila(int);
        Fila(Fila &f);
        ~Fila();
        bool inserir(char);
        char remover();
        //Metodos "Getter". Principio do menor privilégio
        bool vazia() const;
        bool cheia() const;
    static int getContador();
};

#endif
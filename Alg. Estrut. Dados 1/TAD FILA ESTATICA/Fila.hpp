//Fila.hpp

#include <iostream>

using namespace std;

#ifndef FILA_HPP
#define FILA_HPP

//Definindo classe e metodos primitivos
class Fila{
    private:
        int fim;
        int v[50];
        int tam;
        void realocar();
    public:
        Fila();
        void inserir(int);
        int remover();
        bool cheia();
        bool vazia();
};
#endif
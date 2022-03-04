//Fila.hpp

#include <iostream>

using namespace std;

#ifndef FILA_HPP
#define FILA_HPP

//Definindo classe e metodos primitivos
class Fila{
    private:
        int fim;
        int *v;
        int tam;
        void realocar();
    public:
        Fila(int);
        void inserir(int);
        int remover();
        bool cheia();
        bool vazia();
        ~Fila();
};
#endif
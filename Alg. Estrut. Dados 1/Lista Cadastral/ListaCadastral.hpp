//ListaCadastral.hpp

#include <iostream>

using namespace std;

#ifndef LISTACADASTRAL_HPP
#define LISTACADASTRAL_HPP

//Classe para a lista encadeada s/ no
class cell{
    public:
        cell();
        int conteudo;
        cell *prox;
};

//Definindo classe e metodos primitivos
class ListaCadastral{
    private:
        cell *ini;
    public:
        ListaCadastral();
        bool estaNaLista(int);
        bool insere(int);
        bool retira(int);
        bool vazia();
        bool cheia();
        int pegaOPrimeiro();
        int pegaOProximo(int);
        ~ListaCadastral();
};
#endif
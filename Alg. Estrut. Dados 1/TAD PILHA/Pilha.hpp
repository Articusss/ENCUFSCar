//Pilha.hpp

#ifndef PILHA_HPP
#define PILHA_HPP

//Definindo a pilha
class Pilha{
    private:
        //Variaveis todas privadas. Manipular com metodos.
        int topo;
        int stack[50] = {};
    public:
        //Igual ao Cria();
        Pilha();
        bool cheia();
        bool vazia();
        void empilha(int x, bool *deuCerto);
        void desempilha(int *x, bool *deuCerto);
};

#endif

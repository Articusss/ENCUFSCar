//Pilha.hpp

#ifndef PILHA_HPP
#define PILHA_HPP

//Definindo a lista encadeada
class Node{
    public:
        Node();
        int content;
        Node *next;
};

//Definindo a pilha
class Pilha{
    private:
        //Variaveis todas privadas. Manipular com metodos.
        Node *head;
    public:
        //Igual ao Cria();
        Pilha();
        Pilha(const Pilha&);
        bool vazia();
        void empilha(int x);
        int desempilha();
        ~Pilha();
};

#endif

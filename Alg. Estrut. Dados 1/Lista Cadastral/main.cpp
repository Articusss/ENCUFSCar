//main.cpp

#include <iostream>
#include "ListaCadastral.hpp"

using namespace std;
#define NULO -1

//Passar apenas por referencia, para evitar a necessidade de copy constructors
void imprimeLista(ListaCadastral &x){
    //Imprimindo os elementos da lista
    //Verificando lista vazia
    int i = x.pegaOPrimeiro();
    //Agora imprimindo os proximo
    while(i != NULO){
        cout << i << " ";
        //Avanca
        i = x.pegaOProximo(i);
    }
    cout << endl;
}

//Compara listas: Verifica se o conteudo das listas são exatamente iguais. Nao leva em conta a ordem
bool comparaLista(ListaCadastral &x, ListaCadastral &y){
    int i = x.pegaOPrimeiro();
    //Comparando todos os elementos de x com y
    while(i != NULO){
        if(!y.estaNaLista(i)) return false;
        i = x.pegaOProximo(i);
    }

    i= y.pegaOPrimeiro();
    //Agora comparando todos os elementos de y com x
    while(i!=NULO){
        if(!x.estaNaLista(i)) return false;
        i = y.pegaOProximo(i);
    }

    return true;
}

//Uniao dos elementos terceiro parametro eh o endereco da lista a ser alterada - evitar necessidade de copyconstructor
void uniao(ListaCadastral &x, ListaCadastral &y, ListaCadastral &nova){
    int i;
    //Primeiro copiando todos os elementos de x para a nova lista
    i = x.pegaOPrimeiro();
    while(i != NULO){
        nova.insere(i);
        i = x.pegaOProximo(i);
    }

    //Agora, pegando todos os elementos de x que não estão em y
    i = y.pegaOPrimeiro();
    while (i != NULO){
        //Se nao esta na lista, insere
        if(!x.estaNaLista(i)) nova.insere(i);
        i = y.pegaOProximo(i);
    }
}
//Interseccao dos elementos
void interseccao(ListaCadastral &x, ListaCadastral &y, ListaCadastral &nova){
    int i;
    //Percorrendo x e inserindo elementos que tambem tem y
    i = x.pegaOPrimeiro();
    while(i != NULO){
        if(y.estaNaLista(i)) nova.insere(i);
        i = x.pegaOProximo(i);
    }
}

int main(){
    //Criando a lista
    ListaCadastral lista;
    
    //Verificando vazia
    cout << "Lista vazia? " << (lista.vazia() ? "True" : "False") << endl;

    //Colocando 10 elementos
    for(int i=0; i < 10; i++){
        lista.insere(i);
    }

    //Tentando inserir um elemento ja disposto na lista
    cout << "Tentando colocar elemento ja disposto. Funcionou? " << (lista.insere(1) ? "True" : "False") << endl;

    //Retirando agora um elemento
    cout << "Retirando o elemento 2. Funcionou? " << (lista.retira(2) ? "True" : "False") << endl;
    cout << "Tentando novamente tirar o elemento 2. Funcionou? " << (lista.retira(2) ? "True" : "False") << endl;

    cout << "Elemento 1 esta na lista? " << (lista.estaNaLista(1) ? "True" : "False") << endl; 
    cout << "Elemento 999 esta na lista? " << (lista.estaNaLista(999) ? "True" : "False") << endl; 

    cout << "Pegando o primeiro elemento: " << lista.pegaOPrimeiro() << ". Pegando o proximo a ele: " << lista.pegaOProximo(lista.pegaOPrimeiro()) << endl;
    cout << "Tentando pegar o proximo do ultimo elemento da lista " << lista.pegaOProximo(0) << endl; 

    //Imprimindo
    imprimeLista(lista);

    ListaCadastral lista2, listauniao, listainterseccao;

    for(int i = 8; i <16; i++){
        lista2.insere(i);
    }
    //Testando uniao
    uniao(lista,lista2, listauniao);
    //Testando interseccao
    interseccao(lista, lista2, listainterseccao);

    //Imprimindo os 2
    imprimeLista(listauniao);
    imprimeLista(listainterseccao);

    cout << "Lista 1 e 2 são iguais? " << (comparaLista(lista,lista2) ? "True":"False") << endl;

    ListaCadastral lista3, lista4;
    
    for(int i=0; i<30; i++){
        lista3.insere(i);
        lista4.insere(i);
    }

    cout << "Lista 3 e 4 são iguais? " << (comparaLista(lista3,lista4) ? "True":"False") << endl;

    return 0;
}
//main.cpp
#include <iostream>
#include "Fila.h"

using namespace std;

bool filaIgual(Fila x, Fila y){
    while(!x.vazia() && !y.vazia()){
        if(x.remover() != y.remover()) return false;
    }
    return (x.vazia() && y.vazia());
}

void imprimeFila(Fila x){
    cout << "A fila é : ";
    while(!x.vazia()){
        cout << x.remover() << " ";
    }
    cout << endl;
}

int elementosFila(Fila x){
    int tam = 0;
    while(!x.vazia()){
        x.remover();
        tam++;
    }
    return tam;
}

int main(){
    //Testando agora os mecanismos da pilha
    Fila myFila(50);
    cout << "AAAAA" << myFila.getContador() << endl;

    myFila.inserir('b');
    int x = myFila.remover();

    cout << "Ação simples de empilhe e desempilhe. Resultado (valor esperado = 1) = "<< x << endl;
    cout << myFila.remover() << endl;
    cout << "Empilhando alem do limite. Deve imprimir erros" << endl;

    for(int i=50; i < 101; i++){
        myFila.inserir(i);
    }

    cout << "Imprimindo 2 primeiros valores (esperado 0 e 1): " << myFila.remover() << " e " << myFila.remover() << endl; 
    cout << "Agora esvaziando além do limite." << endl;

    for(int i=0; i< 60; i++){
        myFila.remover();
    }

    cout << "Inserindo valor arbitrário para testar realocação, uma vez que a fila ja foi preenchida até o maximo uma vez" << endl;

    //Tentando empilhar mais uma
    myFila.inserir(84);
    cout << "Esperado 84 -> " << myFila.remover() << endl;

    Fila myFila2(50);
    cout << "AAAAA" << myFila.getContador() << endl;
    for(int i=50; i<101; i++){
        myFila.inserir(i);
        myFila2.inserir(i);
    }

    imprimeFila(myFila);

    cout << "Checando se as duas filas são iguais = " << (filaIgual(myFila, myFila2) ? "True" : "False") << endl; 

    myFila.remover();

    cout << "Agora checando novamente = " << (filaIgual(myFila, myFila2) ? "True" : "False") << endl;

    cout << "A fila 1 tem " << elementosFila(myFila) << " elementos" << endl;
    cout << "A fila 2 tem " << elementosFila(myFila2) << " elementos" << endl;
    //Esvaziando tudo

    return 0;
}

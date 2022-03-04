//main.cpp
#include <iostream>
#include <vector>
#include "Fila.hpp"

using namespace std;

//Vetor dentro da classe é um ponteiro, então é necessário reinserir tudo novamente.
std::vector<int> copiaFila(Fila *x){
    int tam = 0;
    std::vector<int> copia;
    int i = 0;

    while(!x->vazia()){
        //Se tam for divisivel por 0, realocar vetor
        if(i % 10 == 0){
            tam += 10;
            copia.resize(tam);
        }
        copia[i] = x->remover();
        i++;
    }
    //Dando resize ao tamanho correto
    copia.resize(i);

    //Agora reinserido elementos
    for(int j=0; j < copia.size(); j++){
        x->inserir(copia[j]);
    }

    return copia;
}

bool filaIgual(Fila *x, Fila *y){
    std::vector<int> copiax = copiaFila(x);
    std::vector<int> copiay = copiaFila(y);
    //Verifica se as duas pilhas sao exatamente iguais
    if(copiax.size() != copiay.size()) return false;
    
    //Verificar conteudo
    for(int i=0; i < copiax.size(); i++){
        if(copiax[i] != copiay[i]) return false;
    }
    

    return true;
}

void imprimeFila(Fila *x){
    //Vetor dentro da classe é um ponteiro, então é necessário reinserir tudo
    std::vector<int> filaCopia = copiaFila(x);
    cout << "A fila atual é: ";
    for(int i=0; i < filaCopia.size(); i++){
        cout << filaCopia[i] << " ";
    }
    cout << endl;
}

int main(){
    //Testando agora os mecanismos da pilha
    Fila myFila(50);

    myFila.inserir(1);
    int x = myFila.remover();

    cout << "Ação simples de empilhe e desempilhe. Resultado (valor esperado = 1) = "<< x << endl;
    cout << "Empilhando alem do limite. Deve imprimir erros" << endl;

    for(int i=0; i < 51; i++){
        myFila.inserir(i);
    }

    cout << "Imprimindo 2 primeiros valores (esperado 0 e 1): " << myFila.remover() << " e " << myFila.remover() << endl; 
    cout << "Agora esvaziando além do limite." << endl;

    for(int i=0; i< 49; i++){
        myFila.remover();
    }

    cout << "Inserindo valor arbitrário para testar realocação, uma vez que a fila ja foi preenchida até o maximo uma vez" << endl;

    //Tentando empilhar mais uma
    myFila.inserir(84);
    int y = myFila.remover();
    cout << "Esperado 84 -> " << y << endl;

    Fila myFila2(50);
    for(int i=0; i<50; i++){
        myFila.inserir(i);
        myFila2.inserir(i);
    }

    imprimeFila(&myFila);

    cout << "Checando se as duas filas são iguais = " << (filaIgual(&myFila, &myFila2) ? "True" : "False") << endl; 

    myFila.remover();

    cout << "Agora checando novamente = " << (filaIgual(&myFila, &myFila2) ? "True" : "False") << endl;

    return 0;
}
#include <iostream>
#include<string.h>

using namespace std;

class Pessoa{
    public:

};

class Voo{
    public:
        Voo(string origem, string destino, DataHorario horario, int N) :
        origem(origem), destino(destino), horario(horario), nroPoltronas(N) {
        poltronas = new Pessoa*[N];
        memset(poltronas, 0, N * sizeof(Pessoa*));
        }
        bool ocupa(int pos, Pessoa& p); // A ser implementado
        bool desocupa(int pos); // A ser implementado
        int qtdeVagas(); // A ser implementado
        int nroPassageiros(); // A ser implementado
        int nroFuncionarios(); // A ser implementado
        int nroGerentes(); // A ser implementado
        void imprime(); // A ser implementado
    private:
        string origem, destino;
        DataHorario horario;
        int nroPoltronas;
        Pessoa** poltronas;
};

bool Voo::ocupa(int pos, Pessoa &p){
    if(poltronas[pos] != 0){
        cout << "Ocupado" << endl;
        return false;
    }
    poltronas[pos] = &p;
    return true;
}

bool Voo::desocupa(int pos){
    if(poltronas[pos] !=){
        poltronas[pos] = 0;
        return true;
    }
    cout << "Poltrona ja desocupada!" << endl;
    return false;
}

int Voo::qtdeVagas(){
    return nroPoltronas - nroPassageiros();
}

int Voo::


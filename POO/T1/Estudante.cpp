#include "Estudante.h"
using namespace std;

namespace poo{
    //Construtor com copia dos atributos
    Estudante::Estudante(string n, string c, int r,  double p1, double p2, double t1, double t2) : Pessoa(n,c), RA(r), prova1(p1), prova2(p2), trab1(t1), trab2(t2) {};
    //Destrutor
    Estudante::~Estudante(){};
    //Metodos todos const
    int Estudante::getRA() const{
        return RA;
    }
    double Estudante::media() const{
        double mp, mf;
        mp = (prova1 + prova2) / 2;
        mf = (trab1 + trab2) /2;
        return (mp * 8 + mf * 2) / 10;
    }

    bool Estudante::aprovado() const{
        return media() >= 6;
    }

    bool Estudante::sac() const{
        return media() < 6 && media() >= 5;
    }

    double Estudante::notaSAC() const{
        if(aprovado() || !sac()) return 0;
        //else
        return 12 - media();
    }

    ostream& operator<<(ostream& os, const Estudante& e){
        os << e.getNome() << ", " << e.getCPF() << ". Media final: " << e.media();
        return os;
    }

};
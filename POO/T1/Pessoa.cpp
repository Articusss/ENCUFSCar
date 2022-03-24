#include "Pessoa.h"

using namespace std;
namespace poo{
    Pessoa::Pessoa(string n, string c) : nome(n), cpf(c){};

    Pessoa::~Pessoa(){};

    string Pessoa::getCPF() const{
        return cpf;
    }

    string Pessoa::getNome() const{
        return nome;
    }

    std::ostream& operator<<(ostream& os, const poo::Pessoa& p){
        os << p.nome << ", " << p.cpf;
        return os;
    }
}
#include "Professor.h"
using namespace std;
namespace poo{
    //Construtor e destrutor
    Professor::Professor(string n, string c, string u) : Pessoa(n,c), universidade(u){};
    Professor::~Professor(){};

    string Professor::getUniversidade() const{
        return universidade;
    }

    std::ostream& operator<<(ostream& os, const poo::Professor& p){
        os << p.getNome() << ", " << p.getCPF() << ", " << p.getUniversidade();
        return os;
    }

}
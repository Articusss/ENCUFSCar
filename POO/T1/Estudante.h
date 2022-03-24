#include <iostream>
#include <string>
#include "Pessoa.h"

#ifndef ESTUDANTE_H
#define ESTUDANTE_H

namespace poo{
    class Estudante : public Pessoa{
        private:
            int RA;
            double prova1, prova2, trab1, trab2;
        public:
            Estudante(std::string, std::string, int, double, double, double, double);
            ~Estudante();
            int getRA() const;
            double media() const;
            bool aprovado() const;
            bool sac() const;
            double notaSAC() const;
            
            friend std::ostream& operator<<(std::ostream&, const Estudante&); 
    };
};

#endif
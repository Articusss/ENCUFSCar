
#include <iostream>
#include <string>

#ifndef PESSOA_H
#define PESSOA_H

namespace poo{
    class Pessoa{

        private:
            std::string nome;
            std::string cpf;
        public:
            Pessoa(std::string, std::string);
            ~Pessoa();
            std::string getNome() const;
            std::string getCPF() const;
        //operador
        friend std::ostream& operator<<(std::ostream&, const Pessoa&);

    };
};

#endif
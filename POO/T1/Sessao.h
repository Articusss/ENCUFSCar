#include <iostream>
#include <string>
#include "Pessoa.h"
#include "DataHorario.h"

#ifndef SESSAO_H
#define SESSAO_H

namespace poo{    
    class Sessao{
        private:
            std::string nome;
            DataHorario data;
            Pessoa* palco[15][14]{NULL};
        public:
            Sessao(std::string, DataHorario&);
            ~Sessao();
            std::string proximoLivre() const;
            bool verifica(std::string) const;
            bool ocupa(std::string, Pessoa&);
            bool desocupa(std::string);
            int vagas() const;
            //Operador
            friend std::ostream& operator<<(std::ostream& os, const Sessao& s);
    };
};

#endif
#include "Pessoa.h"
#include <string>
#include <iostream>
using namespace std;

#ifndef PROFESSOR_H
#define PROFESSOR_H

namespace poo{
    class Professor : public Pessoa{
        private:
            string universidade;
        public:
            Professor(string, string, string);
            ~Professor();
            string getUniversidade() const;
            friend std::ostream& operator<<(ostream&, const Professor&);

    };
};
#endif
#include <iostream>
#include <iomanip>

#ifndef DATAHORARIO_H
#define DATAHORARIO_H

namespace poo{
    class DataHorario{
        private:
            int dia, mes, ano, hora, minuto, segundo;
        public:
            DataHorario(int, int, int, int, int, int);
            ~DataHorario();
            int getDia() const{ return dia; };
            int getMes() const { return mes; };
            int getAno() const { return ano; };
            int getHora() const { return hora; };
            int getMinuto() const { return minuto; };
            int getSegundo() const { return segundo; };
            //sobrecarregando opeadores
            bool operator== (const DataHorario&) const;
            bool operator< (const DataHorario&) const;
            bool operator> (const DataHorario&) const;
            bool operator<= (const DataHorario&) const;
            bool operator!= (const DataHorario&) const;
            bool operator>= (const DataHorario&) const;
            
            friend std::ostream& operator<<(std::ostream&, const DataHorario&);

    };

};

#endif
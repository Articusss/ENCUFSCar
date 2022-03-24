#include "DataHorario.h"

using namespace std;

namespace poo{
    DataHorario::DataHorario(int d, int me,int a, int h, int min, int seg){
        //Verificando a integridade dos dados
        //Array com meses no index, conteudo como os dias do mes. Nao leva em conta ano bissexto
        int meses[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        //Agora setando atributos com operador ternario
        dia = (d <= meses[me-1] && d > 0) ? d : 1;
        mes = (me > 0 && me < 13) ? me : 1;
        ano = (a > 0) ? a : 1;
        hora = (h > -1 && h < 24) ? h : 0;
        minuto = (min > -1 && min < 61) ? min : 0;
        segundo = (seg > -1 && seg < 61) ? seg : 0;
    }

    DataHorario::~DataHorario(){};

    //Getters ja definido no header

    //Operadores
    ostream& operator<<(ostream& os, const DataHorario& p){
        string meses[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
        os << setfill('0') << setw(2) << p.dia << " de " << meses[p.mes -1] << " de " << setfill('0') << setw(2) << p.ano << " - " << setfill('0') << setw(2) << p.hora << " horas, " << setfill('0') << setw(2) << p.minuto << " minutos e " << setfill('0') << setw(2) << p.segundo << " segundos";
        return os;
    }

    bool DataHorario::operator== (const DataHorario& y) const{
        //Comparando um a um
        if(ano != y.getAno()) return false;
        if(mes != y.getMes()) return false;
        if(dia != y.getDia()) return false;
        if(hora != y.getHora()) return false;
        if(minuto != y.getMinuto()) return false;
        if(segundo != y.getSegundo()) return false;
        return true;
    };

    bool DataHorario::operator<(const DataHorario &y) const{
        //Comparando em ordem decrescente de "tamanho"
        if(ano != y.getAno()) return ano < y.getAno();
        if(mes != y.getMes()) return mes < y.getMes();
        if(dia != y.getDia()) return dia < y.getDia();
        if(hora != y.getHora()) return hora < y.getHora();
        if(minuto != y.getMinuto()) return minuto < y.getMinuto();
        if(segundo != y.getSegundo()) return segundo < y.getSegundo();
        //Iguais
        return false;
    };

    bool DataHorario::operator<=(const DataHorario &y) const{
        return (*this < y || *this == y);
    }

    bool DataHorario::operator!=(const DataHorario &y) const{
        return !(*this == y);
    }

    bool DataHorario::operator>(const DataHorario &y) const{
        return !(*this <= y);
    }

    bool DataHorario::operator>=(const DataHorario &y) const{
        return (*this > y || *this == y);
    }

}


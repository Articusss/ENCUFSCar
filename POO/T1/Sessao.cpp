#include "Sessao.h"
using namespace std;

namespace poo{
    Sessao::Sessao(string n, DataHorario& d) : nome(n), data(d){};
    Sessao::~Sessao(){};

    string Sessao::proximoLivre() const{
        //Percorrendo a matriz 
        for(int i=0; i <15; i++){
            for(int j=0; i<14; j++){
                if(palco[i][j] == NULL){
                    //cout << i << " " << j << " " << endl;
                    char linha = 'A' + i;
                    return linha + to_string(j);
                }
            }
        }
        return "cheio";
    }

    bool Sessao::verifica(string s) const{
        int coluna = stoi(s.substr(1));
        int linhanumero = s[0] - 'A';
        if(linhanumero < 15 && linhanumero > -1 && coluna < 14 && coluna > -1) return palco[linhanumero][coluna] != NULL;
        //posicao invalida
        return true;
    }

    bool Sessao::ocupa(string s, Pessoa& p){
        //metodo de verificagem ja verifica poltrona invalida
        if(verifica(s)) return false;

        //Vazia e valida, ocupar
        palco[s[0] - 'A'][stoi(s.substr(1))] = &p;
        return true;
    }

    bool Sessao::desocupa(string s){
        int linhanumero = s[0] - 'A';
        int coluna = stoi(s.substr(1));
        //Checando invalida ou nao ocupada - Nao é possível usar a a função verifica aqui devido à posição invalida retornando true
        if(!(linhanumero < 15 && linhanumero > -1 && coluna < 14 && coluna > -1)) return false;
        //Posicao nao ocupada
        if(palco[linhanumero][coluna] == NULL) return false;

        //Agora removendo
        palco[linhanumero][coluna] = NULL;
        return true;
    }

    int Sessao::vagas() const{
        int res = 0;
        //Percorrendo a matriz e contando NULLs
        for(int i=0; i<15; i++){
            for(int j=0; j<14; j++){
                if(palco[i][j] == NULL) res++;
            }
        }
        return res;
    };

    ostream& operator<<(ostream& os, const Sessao& s){
        //Nome da peça
        os << s.nome << ", " << s.data << ". Espectadores: " << endl;
        //Percorrendo a matriz
        for(int i=0; i<15; i++){
            for(int j=0; j<14; j++){
                if(s.palco[i][j] != NULL){
                    char linha = ('A' + i);
                    os << *(s.palco[i][j]) << " : " <<  linha + to_string(j) << endl;
                };
            }
        }
        return os;
    }
};

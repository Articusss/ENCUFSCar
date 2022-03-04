#include <iostream>
#include <string>

using namespace std;

class Aluno{
    private:
        int const ra;
        string nome;
        int *notas;
        int tam;
    static int contador;
    public:
        Aluno(string n = "Sem nome", int nota = 0);
        void setNome(string newnome);
        string getNome() const {return nome; };
        int getRa() const{ return ra; };
        void setNota(int, int);
        int getNota(int) const;
        static int getContador() { return contador; };
        ~Aluno(){ delete notas; };
};

Aluno::Aluno(string n, int no) : ra(contador), nome(n){
    tam = no > 0 ? no : 10;
    notas = new int[tam];
    for(int i = 0; i < tam; i++) notas[i] = -1;
    contador++;
}

void Aluno::setNome(string x){
    nome = x;
}

void Aluno::setNota(int pos, int x){
    if(pos <= tam && pos > 0) notas[pos-1] = x;
}

int Aluno::getNota(int pos) const{
    if(pos > tam || pos < 1) return -1;
    return notas[pos-1];
}

int Aluno::contador = 0;

int main(){
    Aluno t("TTT", -1), t1("TTT", 5);
    cout << t.getRa() << endl;
    t.setNota(6,10);
    t.setNota(5,10);
    t.setNota(4,9);
    t.setNota(3,8);
    t.setNota(2,7);
    t.setNota(1,6);

    cout << t.getNota(1) << endl;
    cout << t.getNota(2) << endl;
    cout << t.getNota(3) << endl;
    cout << t.getNota(4) << endl;
    cout << t.getNota(5) << endl;
    cout << t.getNota(6) << endl;
    return 0;
}



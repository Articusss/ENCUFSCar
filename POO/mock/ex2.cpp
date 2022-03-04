#include <iostream>
#include <string>

using namespace std;

class Pessoa{
    private:
        string nome;
        int cpf;
    public:
        Pessoa(string n, int c) : nome(n), cpf(c){};
        string getNome() const{ return nome; };
        string getClasse() const { return "Pessoa";};
        void imprime() const { cout << "Nome: " << nome << ", CPF: " << cpf << endl; };
};

class Empresa{
    private:
        string nome;
        string cpnj;
    public:
        Empresa(string n, string c) : nome(n), cpnj(c){};
        void imprime() const { cout << "Nome: " << nome << ", CPNJ: " << cpnj << endl;}
};

int main(){
    Pessoa t("testeee", 21312);
    t.imprime();
    cout << t.getNome() << " " << t.getClasse() << endl;
    return 0;
}
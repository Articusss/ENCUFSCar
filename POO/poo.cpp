//Caio Obatake Watari Gonçalves Cadini, RA 800383
//Cauã Benini da Silva, RA 801046
//Lucas Pereira Quadros, RA 800981
//Maurício Gallera de Almeida, RA 800366
//Vinicius Leite Censi Faria, RA 804410

// Bibliotecas
#include <iostream>
#include <string>

using namespace std;

// Classe lixeira - volume maximo 100 L.
class Lixeira {
  // Métodos
  public:
    Lixeira(float, string, string); 
    void abrirFechar();
    void depositar(float);
    void esvaziar();
    float obterVolumeDisponivel();
    float obterCapacidade();
    float obterVolumeAtual();
    bool obterEstado();
    string obterCor();
    string obterMaterial();
    bool cheia();
    bool vazia();
    ~Lixeira();
  // Atributos
  private:
    bool estado; // TRUE = aberto / FALSE = fechado 
    float capacidade; // Capacidade total da lixeira em litros
    float volumeAtual;
    string cor;
    string material;
};

// Construtor
Lixeira::Lixeira(float capacidade, string cor, string material){
    estado = false;
    volumeAtual = 0;
    this->cor = cor;
    this->material = material;
    //Volume mín. e máx. considerados, em L 
    if ((capacidade > 0) && (capacidade <= 100)){ 
      this->capacidade = capacidade;
    }
    else{
      capacidade = 100;
    } 
}      

//Ações
//Abre ou fecha a lixeira
void Lixeira::abrirFechar(){
  estado = !estado;
}

//Deposita um volume para o volumeatual
void Lixeira::depositar(float lixo){
  if(cheia()){
    cout<< "Lixeira está cheia!" << endl;
  }
  else if(!obterEstado()){
    cout<< "Lixeira está fechada!" << endl;
  }
  else if (volumeAtual + lixo <= capacidade){
    volumeAtual += lixo;
  }
  else{
    cout << "Não há espaço para depositar tudo isso de lixo!" << endl;
  }
}

//Esvazia o volumeAtual
void Lixeira::esvaziar(){
  volumeAtual = 0;
}

//ÍNÍCIO - Métodos get 

//Getter do volume disponível
float Lixeira::obterVolumeDisponivel(){
  return capacidade - volumeAtual;  
}

//Get capacidade
float Lixeira::obterCapacidade(){
    return capacidade;
}

//Get volume
float Lixeira::obterVolumeAtual(){
  return volumeAtual;
}

//Get estado
bool Lixeira::obterEstado(){
  return estado;
}

//Get cor
string Lixeira::obterCor(){
  return cor;
}

//Get material
string Lixeira::obterMaterial(){
  return material;
}

//Retorna true/false se a lixeira está cheia
bool Lixeira::cheia(){
  return volumeAtual == capacidade;
}

//Retorna true/false se a lixeira está vazia
bool Lixeira::vazia(){
  return volumeAtual == 0;
}
//FIM - Métodos get 

//Função sem ponteiros, sem destrutor explícito necessário
Lixeira::~Lixeira(){}

//Procedimento para esvaziar a lixeira

int main() {

  // Teste da implementação
  
  Lixeira myLixeira(3000, "vermelho", "plástico");
  cout << "Material: "<< myLixeira.obterMaterial() << endl;
  cout << "Capacidade: "<< myLixeira.obterCapacidade() << endl;
  cout << "Cor: " << myLixeira.obterCor() << endl;
  myLixeira.depositar(50);
  cout << "1º Estado: " << (myLixeira.obterEstado() ? "Aberta": "Fechada") << endl;
  myLixeira.abrirFechar();                  
  cout << "2º Estado: " << (myLixeira.obterEstado() ? "Aberta" : "Fechada") << endl;
  //Depositar abertado
  myLixeira.depositar(50);
  //Tentando depositar cheia
  myLixeira.depositar(1);
  //Verificar volume, capacidade e cheia
  cout << "Volume Atual: " << myLixeira.obterVolumeAtual() << ", Capacidade " << myLixeira.obterCapacidade() << ", cheia: " << (myLixeira.cheia() ? "Sim" : "Não") << endl;
  return 0;
}


// "DOR" - Vinicius Leite Censi Faria, 2021

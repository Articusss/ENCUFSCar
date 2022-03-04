#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(){
    auto start = high_resolution_clock::now();
    float nprovas = 100000000;
    int alternativas = 10;
    int aprov = 0;
    int acertos;
    
    //Comecando os testes
    for(int i = 0; i < nprovas; i++){
        //Comecando uma provas
        //Preenchendo alternativas
        acertos = 0;

        for(int j=0; j < alternativas; j++){
            if(rand() % 2 == 1) acertos++;
        }

        if(acertos > 2) aprov++;
    }
    cout << "A probabilidade eh: " << aprov/nprovas * 100 << "%" << endl; 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << duration.count() << endl;

    return 0;
}
#include <stdio.h>

#define pi 3.14159

//Estrutura requisitada
struct raio {
    double raio;
};

int main() {
    //Declarar estrutura
    struct raio circle;
    //Leitura
    scanf("%lf", &circle.raio);
    //Resultado
    printf("A=%.4lf\n", circle.raio * circle.raio * pi);
 
    return 0;
}
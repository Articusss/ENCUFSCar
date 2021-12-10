#include <stdio.h>
#include <math.h>
 
#define pi 3.14159

//Estrutura para raio
struct circle{
    int raio;
};
//Calcular volume em funcao
double volume(int x){
    double r;
    r = (4.0/3.0) * pi * pow(x,3);
    return r;
}
int main() {
 
    struct circle myCircle;

    scanf("%d", &myCircle.raio);

    printf("VOLUME = %.3lf\n", volume(myCircle.raio));

    return 0;
}
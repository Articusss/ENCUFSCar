#include <stdio.h>
 
#define pi 3.14159

//Estrutura
struct sizes{
    float a;
    float b;
    float c;
};

int main() {
 
    struct sizes mySize;
    //Leitura
    scanf("%f %f %f", &mySize.a, &mySize.b , &mySize.c);
    //Triangulo
    printf("TRIANGULO: %.3f\n", (mySize.a * mySize.c)/2);
    //Circulo
    printf("CIRCULO: %.3f\n", mySize.c * mySize.c * pi);
    //Trapezio
    printf("TRAPEZIO: %.3f\n", (mySize.c * (mySize.a + mySize.b))/2);
    //Quadrado
    printf("QUADRADO: %.3f\n", mySize.b * mySize.b);
    //Retangulo
    printf("RETANGULO: %.3f\n", mySize.a * mySize.b);
 
    return 0;
}
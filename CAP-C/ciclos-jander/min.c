#include <stdio.h>

double min (double x, double y){
    double z;

    if (x < y){
        z=x;
    }
    else{
        z=y;
    }

    return z;
}

int main(void){
    double valor1, valor2;
    scanf("%lf %lf", &valor1, &valor2);

    printf("%g", min(valor1, valor2));
    return 0;
}
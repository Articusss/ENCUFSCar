/*

Autor: Vinicius Faria
Data de Criação: 12/9/2021

Objetivo: Calcular a media de 2 numeros

*/



#include <stdio.h>
#include <math.h>
 
int main() {

    int(N);
    int(hours);
    int(minutes);
    int(seconds);

    scanf("%i", &N);

    hours = N / 3600;
    minutes = (N / 60) % 60;
    seconds = N % 60;

    printf("%i:%i:%i\n", hours, minutes, seconds);

    return 0;

}
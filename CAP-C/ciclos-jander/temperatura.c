/*
  Conversão de Celsius para fahrenheit
  Vinicius Leite Censi Faria 804410
*/
#include <stdio.h>

float temp (float x){

    x = (1.8 * x) + 32;
    return x;
}

// programa principal
int main(void){
    
    float celsius;

    scanf("%f", &celsius);

    printf("%.1f\n", temp(celsius));

    return 0;
}
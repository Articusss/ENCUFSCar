#include <stdio.h>

double peso_ideal(char sexo, double altura){
    double peso;
    //Caso homem
    if (sexo == 'H'){
        peso = (72.7 * altura) - 58;
    }
    //Caso mulher
    else if (sexo == 'M'){
        peso = (62.1*altura) - 44.7;
    }
    //retorna resultado
    return peso;
}

int main(void){
    double altura;
    char sexo;
    scanf("%c", &sexo);
    scanf("%lf", &altura);

    printf("%g", peso_ideal(sexo, altura));

    return 0;

}
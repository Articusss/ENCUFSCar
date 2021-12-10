#include <stdio.h>
#include <math.h>
//Organizar
void maiormenor (double *x, double *y){
    double temp; //Variavel temporaria

    if (*x > *y){
        temp = *y;
        *y = *x;
        *x = temp;
    }

}

struct triangle{
    double a;
    double b;
    double c;
};
 
int main() {

    struct triangle myTriangle;
    int x;

    scanf("%lf %lf %lf", &myTriangle.a, &myTriangle.b, &myTriangle.c);

    maiormenor(&myTriangle.b, &myTriangle.a);
    maiormenor(&myTriangle.c, &myTriangle.a);

    if (myTriangle.a >= (myTriangle.b + myTriangle.c))
        printf("NAO FORMA TRIANGULO\n");
    else{ 
        if (pow(myTriangle.a,2) == pow(myTriangle.b,2) + pow(myTriangle.c,2))
            printf("TRIANGULO RETANGULO\n");
        else if (pow(myTriangle.a,2) > pow(myTriangle.b,2) + pow(myTriangle.c,2))
            printf("TRIANGULO OBTUSANGULO\n");
        else if (pow(myTriangle.a,2) < pow(myTriangle.b,2) + pow(myTriangle.c,2))
            printf("TRIANGULO ACUTANGULO\n");
        
        if (myTriangle.a == myTriangle.b && myTriangle.b == myTriangle.c)
            printf("TRIANGULO EQUILATERO\n");
        else if (myTriangle.a == myTriangle.b || myTriangle.b == myTriangle.c || myTriangle.a == myTriangle.c)
            printf("TRIANGULO ISOSCELES\n");
    }
    return 0;
}
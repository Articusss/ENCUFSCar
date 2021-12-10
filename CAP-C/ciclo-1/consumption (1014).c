#include <stdio.h>
 
int main() {
 
    int X;
    float Y, comsup;

    scanf("%i", &X);
    scanf("%f", &Y);

    comsup = X / Y;

    printf("%.3f km/l\n", comsup);
 
    return 0;
}
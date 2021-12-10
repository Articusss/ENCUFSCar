
#include <stdio.h>
#include <math.h>
 
#define pi 3.14159

int main() {

    double radius, volume;

    scanf("%lf", &radius);

    volume = 4.0/3 * pi * pow(radius, 3);

    printf("VOLUME = %.3lf\n", volume);

    return 0;
}
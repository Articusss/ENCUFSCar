#include <stdio.h>

#define eff 12.0
 
int main() {

    int hours, speed;
    float liters;

    scanf("%i", &hours);
    scanf("%i", &speed);

    liters = (speed * hours)/ eff;

    printf("%.3f\n", liters);
 
    return 0;
}
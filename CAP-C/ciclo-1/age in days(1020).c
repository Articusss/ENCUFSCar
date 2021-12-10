#include <stdio.h>
 
int main() {
 
    int diastotal;
    int anos, meses, dias;

    scanf("%i", &diastotal);

    anos = diastotal / 365;
    meses = (diastotal % 365) / 30;
    dias = (diastotal % 365) % 30;

    printf("%i ano(s)\n", anos);
    printf("%i mes(es)\n", meses);
    printf("%i dia(s)\n", dias);

 
    return 0;
}
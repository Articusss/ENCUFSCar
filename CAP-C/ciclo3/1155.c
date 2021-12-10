#include <stdio.h>
 
int main() {
 
    float sum;
    int i;
    //Declara a soma inicial como 0 e inicia a soma da ordem dada
    sum=0;
    for(i=1; i <= 100; i++){
        sum += 1 / (float)i;
    }

    printf("%.2f\n", sum);
 
    return 0;
}
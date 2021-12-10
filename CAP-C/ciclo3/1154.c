#include <stdio.h>
 
int main() {
 
    int age, counter;
    float avg;

    avg = 0;
    counter = 0;
    //Comeca a ler as idades
    do {
        scanf("%d", &age);
        if(age > 0){
            avg += age;
            counter++;
        }
    } while (age > 0);
    //Calcula a media
    avg = avg / counter;

    printf("%.2f\n", avg);
    
    return 0;
}
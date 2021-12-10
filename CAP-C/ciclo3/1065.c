#include <stdio.h>
 
int main() {
 
    int n, i,even;

    even = 0;
    //Loop para ler os 5 valores
    for(i=0; i < 5; i++){
        scanf("%d", &n);
        //Checa se eh par
        if(n % 2 == 0)
            even += 1;
    }

    printf("%d valores pares\n", even);
    return 0;
}
#include <stdio.h>
 
int main() {
 
    int n,i;

    scanf("%d", &n);
    //Loop de 11 valores acima de n, cobrindo todos os 6 proximos impares
    for(i=n; i <= n+11; i++){
        if(i % 2 != 0) //Checar se eh impar
            printf("%d\n", i);
    }
 
    return 0;
}
#include <stdio.h>
 
int main() {
 
    int x,z,i, counter, sum;
    counter =0;
    z = 0;
    //Scanear X
    scanf("%d", &x);
    //Ler Z ate ser maior que x
    do {
        scanf("%d", &z);
    } while (x >= z);
    //Definir o resultado final
    
    sum = 0;
    
    for(i=x + 1; sum < z; i++){
        sum += i;
        counter +=1;
    }

    printf("%d\n", counter);
 
    return 0;
}
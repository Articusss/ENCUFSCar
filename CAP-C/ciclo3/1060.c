#include <stdio.h>
 
int main() {
 
    int i, positive;
    float number;

    positive = 0;

    for(i=0; i<6; i++){
        scanf("%f", &number);
        if(number >= 0){
            positive = positive + 1;
        }
    }
    
    printf("%d valores positivos\n", positive);
    
    return 0;
}
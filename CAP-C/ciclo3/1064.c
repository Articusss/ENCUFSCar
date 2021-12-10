#include <stdio.h>
#include <math.h>


 
int main() {
 
    int i, positive;
    float number, media, total;

    positive = 0;
    media = 0;
    total = 0;
    
    for(i=0; i<6; i++){
        scanf("%f", &number);
        if(number >= 0){
            positive = positive + 1;
            total = total + number;
        }
    }
    
    media = total / positive;

    printf("%d valores positivos\n", positive);
    printf("%.1f\n", media);
    
    return 0;
}

#include <stdio.h>
 
int main() {
 
    int number,i,highest,position;

    highest = 0;

    for(i=1; i<= 100; i++){
        scanf("%d", &number);
        
        if(highest == 0){
            highest = number;
            position = i;
        }
        else if(number > highest){
            highest = number;
            position = i;
        }

    }
    printf("%d\n", highest);
    printf("%d\n", position);
 
    return 0;
}
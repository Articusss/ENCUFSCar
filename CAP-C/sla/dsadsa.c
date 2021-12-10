#include <stdio.h>

int main(void){

    int score = 1529587;

    while(score)
{
    printf("%d\n", score % 10);
    score /= 10;
}

    return 0;
}
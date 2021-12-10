#include <stdio.h>

int teste (int v[]){
    
    v[0] =1;
    
    return 3;
}

int main (void){
    
    int v[5] = {0};

    printf("%d", teste(v));
    
    return 0;
}
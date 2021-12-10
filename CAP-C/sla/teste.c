#include <stdio.h>

void limite (int *n){
    if (*n>10)
        *n = 10;
    else if (*n<0)
        *n = 0;
}

void leia (int *n){
    scanf("%d", n);
    limite(n);
}

int main(void){
    int n;
    leia(&n);
    printf("%d", n);
}
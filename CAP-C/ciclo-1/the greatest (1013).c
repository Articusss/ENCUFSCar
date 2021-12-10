#include <stdio.h>
 
int main() {
 
    int A, B, C, MAIORAB;

    scanf("%d %d %d", &A,&B,&C);

    MAIORAB = (A + B + abs(A-B))/2;
    MAIORAB = (C + MAIORAB + abs(C-MAIORAB) )/2;

    printf("%i eh o maior\n", MAIORAB);

    return 0;
}
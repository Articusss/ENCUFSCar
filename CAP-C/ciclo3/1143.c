#include <stdio.h>
#include <math.h>
 
int main() {
 
    int n,i,pow2,pow3;

    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        pow2 = pow(i,2);
        pow3 = pow(i,3);
        printf("%d %d %d\n", i, pow2, pow3);
    }
 
    return 0;
}
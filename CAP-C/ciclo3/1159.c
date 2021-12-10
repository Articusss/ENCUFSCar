#include <stdio.h>
 
int main() {
 
    int i, x, sum;

    scanf("%d", &x);

    while(x != 0){
        sum = 0;
        if (x % 2 != 0)
            x += 1;
        for(i=x; i <= x+8; i+=2){
            sum += i;
        }
        printf("%d\n", sum);
        scanf("%d", &x);
    }

    return 0;
}
#include <stdio.h>
 
int main() {
 
    int n,x,div, i, j;

    scanf("%d", &n);

    for(i=0; i < n; i++){
        scanf("%d", &x);
        div = 0;
        for(j=2; j < x; j++){
            if(x % j == 0){
                div += 1;
            }
        }
        if(div >= 1)
            printf("%d nao eh primo\n", x);
        else
            printf("%d eh primo\n", x);
    }
 
    return 0;
}
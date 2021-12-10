#include <stdio.h>
 
int main() {
 
    int n1,n2,x, i;

    scanf("%d", &n1);
    scanf("%d", &n2);
    //Sort the highest
    if(n2 < n1){
        x = n2;
        n2 = n1;
        n1 = x;
    }

    for(i = n1 + 1; i < n2; i++){

        if(i % 5 == 2 || i % 5 == 3)
            printf("%d\n", i);
    }
 
    return 0;
}
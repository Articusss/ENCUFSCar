#include <stdio.h>
 
int main() {
 
    int n, i;
    
    scanf("%d", &n);
    
    while(n != 0){
        for(i=1; i<= n; i++){
            if(i==n)
                printf("%d\n", i);
            else
                printf("%d ", i);
        }
        scanf("%d", &n);
    }
 
    return 0;
}
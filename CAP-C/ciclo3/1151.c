#include <stdio.h>
 
int main() {
 
    int n,f1,f2,fr,i;

    scanf("%d", &n);
    f2 = 0;
    f1 = 0;
    
    for (i=1; i < n; i++){
        if(i == 1){
            printf("0 ");
             f2 = 1;
        }
        else if (i == 2){
            printf("%d ", f2);
        }
        else{
            fr = f2 + f1;
            f1 = f2;
            f2 = fr;

            printf("%d ", fr);
        }
    }

    fr = f2 + f1;
    printf("%d\n", fr);
        
 
    return 0;
}
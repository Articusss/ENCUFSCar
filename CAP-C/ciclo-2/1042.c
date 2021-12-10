#include <stdio.h>
 
int main() {
 
    int x,y,z, temp1, temp2, temp3;
    int maior,menor,medio;

    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    if (x > y){
        temp1 = x;
        temp2 = y;
    }
    else{
        temp1 = y;
        temp2 = x;
    }
    if (z > temp1){
        maior = z;
        temp3 = temp1;
    }

    else{
        maior = temp1;
        temp3 = z;
    }

    if (temp3 > temp2){
        medio = temp3;
        menor = temp2;
    }
    else{
        medio = temp2;
        menor = temp3;
    }

    printf("%d\n", menor);
    printf("%d\n", medio);
    printf("%d\n", maior);
    printf("\n");
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", z);
    

 
    return 0;
}
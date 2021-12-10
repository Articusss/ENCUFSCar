#include <stdio.h>
 
int main() {
 
    float total;
    int x, y;

    scanf("%d", &x);
    scanf("%d", &y);

    switch(x){
        case 1:
            total = 4 * y;
        break;
        case 2:
            total = 4.5 * y;
        break;
        case 3:
            total = 5 * y;
        break;
        case 4:
            total = 2 * y;
        break;
        case 5:
            total = 1.50 * y;
        break;

    }

    printf("Total: R$ %.2f\n", total);
 
    return 0;
}
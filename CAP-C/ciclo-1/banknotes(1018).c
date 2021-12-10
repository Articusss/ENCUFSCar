#include <stdio.h>
 
int main() {

    int N, change;
    int n100, n50, n20, n10, n5, n2, n1;

    scanf("%i", &N);

    change = N;

    n100 = change / 100;
    change= change - (n100 * 100);

    n50 = change / 50;
    change = change - (n50 * 50);

    n20 = change / 20;
    change = change - (n20 * 20);

    n10 = change / 10;
    change = change - (n10 * 10);

    n5 = change / 5;
    change = change - (n5 * 5);

    n2 = change / 2;
    change = change - (n2 * 2);

    n1 = change / 1;

    printf("%i\n", N);
    printf("%i nota(s) de R$ 100,00\n", n100);
    printf("%i nota(s) de R$ 50,00\n", n50);
    printf("%i nota(s) de R$ 20,00\n", n20);
    printf("%i nota(s) de R$ 10,00\n", n10);
    printf("%i nota(s) de R$ 5,00\n", n5);
    printf("%i nota(s) de R$ 2,00\n", n2);
    printf("%i nota(s) de R$ 1,00\n", n1);

 
    return 0;
}
#include <stdio.h>
#include<math.h>

 
int main() {

    double N;
    int change, coins;
    int n100, n50, n20, n10, n5, n2, n1;
    int m50, m25, m10, m5, m1;

    scanf("%lf", &N);

    N += 0.001;

    change = (int)N;

    N -= change;

    coins = N * 100;

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
    change = change - (n1 * 1);

    m50 = coins /50;
    
    m25 = (coins %50)/25;
    
    m10 = (((coins %50)%25)/10);
    
    m5 = ((((coins %50)%25)%10)/5);
    
    m1 = ((((coins %50)%25)%10)%5)/1;

 printf("NOTAS:\n");

    printf("%d nota(s) de R$ 100.00\n",n100);

    printf("%d nota(s) de R$ 50.00\n",n50);

    printf("%d nota(s) de R$ 20.00\n",n20);

    printf("%d nota(s) de R$ 10.00\n",n10);

    printf("%d nota(s) de R$ 5.00\n",n5);

    printf("%d nota(s) de R$ 2.00\n",n2);


    printf("MOEDAS:\n");

    printf("%d moeda(s) de R$ 1.00\n",n1);

    printf("%d moeda(s) de R$ 0.50\n",m50);

    printf("%d moeda(s) de R$ 0.25\n",m25);

    printf("%d moeda(s) de R$ 0.10\n",m10);

    printf("%d moeda(s) de R$ 0.05\n",m5);

    printf("%d moeda(s) de R$ 0.01\n",m1);

 
    return 0;
}
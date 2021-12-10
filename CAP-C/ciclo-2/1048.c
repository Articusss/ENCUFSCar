#include <stdio.h>
 
int main() {
 
    float sal, reaj, rate;

    scanf("%f", & sal);

    if (sal <= 400)
        rate = 0.15;
    else if (sal <= 800)
        rate = 0.12;
    else if (sal <= 1200)
        rate = 0.1;
    else if (sal <= 2000)
        rate = 0.07;
    else
        rate = 0.04;
    
    reaj =  sal * rate;

    printf("Novo salario: %.2f\n", reaj + sal);
    printf("Reajuste ganho: %.2f\n", reaj);
    printf("Em percentual: %.0f %%\n", rate * 100);

    return 0;
}
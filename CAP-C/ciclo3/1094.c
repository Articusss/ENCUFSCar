#include <stdio.h>
#include <string.h>
 
int main() {
 
    int n,i;
    int x,coelho,rato,sapo, total;
    float percoelho,persapo,perrato;
    char animal;

    //Numero de experimentos
    scanf("%d", &n);

    coelho = 0;
    rato = 0;
    sapo = 0;
    total = 0;

    for (i=0; i<n ; i++){
        //Ler numero e animal e depois classifica-lo
        scanf("%d %c", &x, &animal);

        total += x;

        if(animal == 'C')
            coelho += x;
        else if(animal == 'R')
            rato += x;
        else if(animal == 'S')
            sapo += x;
    }
    
    percoelho = (float)coelho / (float)total;
    persapo = (float)sapo / (float)total;
    perrato = (float)rato / (float)total;

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", coelho);
    printf("Total de ratos: %d\n", rato);
    printf("Total de sapos: %d\n", sapo);
    printf("Percentual de coelhos: %.2f %%\n", percoelho * 100);
    printf("Percentual de ratos: %.2f %%\n", perrato * 100);
    printf("Percentual de sapos: %.2f %%\n", persapo * 100);

    return 0;
}
#include <stdio.h>

int main (void){
    
    int tamanho, i, divisor;
    double soma, media;
    
    scanf("%d", &tamanho);

    int vet[tamanho];

    soma = 0;

    for (i=0; i<tamanho; i++){
        scanf("%d", &vet[i]);
        if(vet[i]>=0){
            soma += vet[i];
            divisor++;
        }
    }

    if (soma > 0)
        media = soma/divisor;
    else
        media = -1;

    printf("%d", media);


    
    return 0;
}
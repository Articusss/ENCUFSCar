#include <stdio.h>

void teste(int x){
    //Escreve normalmente
    x+=2;
    printf("%d\n", x);
}

void teste2(int *x){
    *x += 2;
}

int main (void){
    int n;
    scanf("%d", &n);
    teste(n);
    printf("n depois do teste1 = %d\n", n);
    teste2(&n);
    printf("n depois do teste2 = %d\n", n);
}


//SE FOR ALTERAR VALORES = USAR PONTEIRO
//APENAS LEITURA/ MANIPULACAO DE VALORES TEMPORARIA = NAO PRECISA USAR
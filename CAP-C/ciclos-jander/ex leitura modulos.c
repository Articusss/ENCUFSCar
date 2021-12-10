#include <stdio.h>

void leitura(int *x){
    do{
        scanf("%d", x);
        if(*x<= 0)
            printf("Valor incorreto\n");

    }while(*x <= 0);
}

int maximo(int x, int y){
    if (x>y)
        return x;
    else
        return y;
}

int main(void){
    int valor1, valor2;
    printf("VALOR1\n");
    leitura(&valor1);
    printf("VALOR2\n");
    leitura(&valor2);

    printf("%d", maximo(valor1,valor2));

    return 0;

}
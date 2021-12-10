#include <stdio.h>
 
int main() {
 
    int n,x,i;
    int in,out;

    in = 0;
    out = 0;

    //Numero de numeros a serem lidos
    scanf("%d", &n);
    //Loop de n vezes
    for(i=0; i < n; i++){
        scanf("%d", &x);
        //Checagem de intervalos e adicionando o numero de valores dentro/fora
        if(x >= 10 && x <= 20)
            in += 1;
        else
            out += 1;
    }

    //Impressao de resultados
    printf("%d in\n", in);
    printf("%d out\n", out);
 
    return 0;
}
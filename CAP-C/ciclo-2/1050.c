#include <stdio.h>
 
int main() {
 
    int DDD;
    char *destino;

    scanf("%d", &DDD);

    switch(DDD){
        case 61:
            destino = "Brasilia";
        break;
        case 71:
            destino = "Salvador";
        break;
        case 11:
            destino = "Sao Paulo";
        break;
        case 21:
            destino = "Rio de Janeiro";
        break;
        case 32:
            destino = "Juiz de Fora";
        break;
        case 19:
            destino = "Campinas";
        break;
        case 27:
            destino = "Vitoria";
        break;
        case 31: 
            destino = "Belo Horizonte";
        break;
        default:
            destino = "DDD nao cadastrado";
    }

    printf("%s\n", destino);
 
    return 0;
}
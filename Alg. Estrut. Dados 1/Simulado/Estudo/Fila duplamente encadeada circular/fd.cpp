#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Filaduplo.h"

int main(){
    Cell *fila1;
    fila1 =  criaFila();
    printf(vazia(fila1) ? "True\n" : "False\n");
    insere(&fila1, 1);
    printf("%d \n", retira(&fila1));
    insere(&fila1, 1);
    insere(&fila1, 2);
    printf("%d \n", retira(&fila1));

    for(int i=0; i < 10; i++){
        insere(&fila1, i);
    }
    printf(vazia(fila1) ? "True" : "False");
    //Retirando
    while(!vazia(fila1)){
        printf("%d \n", retira(&fila1));
    }
    printf(vazia(fila1) ? "True" : "False");
}

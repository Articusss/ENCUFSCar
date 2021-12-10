#include <stdio.h>

int main(void){

    int tamanho;
    printf("Digite o tamanho da string\n");
    scanf("%d", &tamanho);

    char c[tamanho];

    printf("Escaneie os caracteres 1 a 1\n");
    for(int i=0; i<tamanho; i++){
        fflush(stdin);
        scanf("%c", &c[i]);
    }

    printf("Leitura da sua string:\n");
    for(int j=0; j<tamanho; j++){
        printf("%c", c[j]);
    }

    return 0;
}
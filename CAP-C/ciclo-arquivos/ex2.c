#include <stdio.h>
#include <stdlib.h>

struct venda {
	int codigo;
	int quantidade;
	double valor;
};


int main(void){
    //Declaracao do item
    struct venda item;

    //Abrir o arquivo
    FILE *arquivo = fopen("vendas.dat", "rb");

    //Variaveis
    float divisor = 0;
    double valor = 0;
    int codigo;
    printf("Insira o codigo:\n");
    scanf("%d", &codigo);


    while(fread(&item, sizeof(item), 1, arquivo) > 0){
        if(item.codigo == codigo){
            divisor++;
            valor += item.valor;
        }
    }
    float media;
    media = valor/(divisor);

    printf("%f eh a media\n", media);
    return 0;
}
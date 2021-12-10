#include <stdio.h>
#include <stdlib.h>
//Struct de dados
struct venda {
	int codigo;
	int quantidade;
	double valor;
};
 

int main(void){
    FILE *arquivo;
    struct venda item;
    int codigo, total;
    //abrir arquivo para leitura
    arquivo = fopen("vendas.dat", "rb");

    printf("Insira o codigo:\n");
    scanf("%d", &codigo);

    //Leitura linha a linha
    total=0;
    while(fread(&item, sizeof(item),1, arquivo) > 0){
        if(item.codigo == codigo){
            total += (item.quantidade * item.valor);
        }
    }

    //Le o total
    printf("%d eh o total de vendas\n", total);


    //Fecha o arquivo
    fclose("vendas.dat");
    return 0;
}
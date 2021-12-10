#include <stdio.h>
#include <stdlib.h>

struct venda {
	int codigo;
	int quantidade;
	double valor;
};


int main(void){
    //Abertura do arquivo
    FILE *arquivo =  fopen("vendas.dat", "rb");
    struct venda item;
    double maiorVenda = 0;
    int maiorRegistro = 0;
    int ocorrencias = 0;

    //Passar pelo arquivo
    while(fread(&item, sizeof(item), 1, arquivo) > 0){
        if(item.quantidade * item.valor > maiorVenda){
            maiorVenda = item.quantidade * item.valor;
            maiorRegistro = item.codigo;
         }
        }
        //Rewind
        rewind(arquivo);
        //Passar de novo
        while(fread(&item, sizeof(item), 1, arquivo) > 0){
        if(item.codigo == maiorRegistro){
            ocorrencias++;
         }
        }
 
        printf("A maior venda foi %lf. Com o registro %d. O registro aparece %d vezes\n", maiorVenda, maiorRegistro, ocorrencias);



        return 0;
    }

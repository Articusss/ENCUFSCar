#include <stdio.h>
#include <stdlib.h>

struct venda {
    unsigned int codigo; //Codigo do produto. Sem restricoes
    char comentario[50]; //Termina em '\0'
    double quantidade; //Quantidade do produto 
    double valor; //Valor do produto
};

//Funcao pertenceArray: verifica se um item esta no array. retorna 1 se o item nao pertence ao aray
int pertenceArray(int *v, int tam,int codigo){
    for(int i=0;i<tam;i++){
        if(codigo == v[i]){
            return 0;
        }
    }
    return 1;
}

int main(void){
    //Abrir o arquivo para somente leitura em binario
    FILE *arquivo = fopen("vendas1.dat", "rb");
    struct venda item;

    //Primeiro passo: pegar lista de codigos validos, guardar em um array dinamico
    int *codigos;
    int numCodigo;
    
    //Para nao precisar de um if em toda checagem: trabalhar primeiro codigo fora do while
    fread(&item, sizeof(item), 1, arquivo);
    //Vetor dinamico com tamanho 1 no inicio
    numCodigo = 1;
    codigos = (int *) calloc (numCodigo, sizeof(int));
    codigos[0] = item.codigo;

    while(fread(&item, sizeof(item), 1, arquivo) > 0){
        //Se o codigo ainda nao estiver no array de codigos, inserir ele
        if(pertenceArray(codigos, numCodigo, item.codigo)){
            //Incrementa o numCodigo e o tamanho
            numCodigo++;
            //Libera mais um espaco e aloca no vetor
            codigos = realloc(codigos, numCodigo * sizeof(int));
            codigos[numCodigo-1] = item.codigo;
        }
    }

    //Reiniciar o arquivo
    rewind(arquivo);

    //Passar pelo arquivo novamente de acordo com a quantidade de codigos
    for(int i=0; i<numCodigo; i++){
        double vendas=0;
        //Ler todo o arquivo
        while(fread(&item, sizeof(item), 1, arquivo) > 0){
            if(item.codigo == codigos[i]){
                vendas += item.quantidade * item.valor;
            }
        }
        //Printar vendas
        printf("O item de codigo %d possui R$%.2lf de vendas\n", codigos[i], vendas);

        //Prepara arquivo para leitura novamente
        rewind(arquivo);
    }

    //Fechar o arquivo e liberar memoria
    fclose(arquivo);
    free(codigos);
    return 0;
} 
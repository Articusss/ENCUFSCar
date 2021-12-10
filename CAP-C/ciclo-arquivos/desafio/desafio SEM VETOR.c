#include <stdio.h>
#include <stdlib.h>

struct venda {
    unsigned int codigo; //Codigo do produto. Sem restricoes
    char comentario[50]; //Termina em '\0'
    double quantidade; //Quantidade do produto 
    double valor; //Valor do produto
};

int main(void){
    //Abrir o arquivo para somente leitura em binario
    FILE *arquivo = fopen("vendas2.dat", "rb");
    //Arquivo que sera escrito os codigos encontrados
    FILE *arquivocodigos = fopen("teste.dat", "wb+");
    struct venda item;

    //Passar pelo arquivo, pegando os novos codigos
    while(fread(&item, sizeof(item), 1, arquivo)> 0){
        //Para cada nova linha, verificar se o codigo ja esta no arquivo de codigos
        int codigoPresenteTemp=0;
        int codigoTemp;
        while(fread(&codigoTemp, sizeof(int), 1 , arquivocodigos) > 0){
            if(item.codigo ==  codigoTemp){
                codigoPresenteTemp = 1; //Se o codigo ja for visto
            }
        }
        //Se nao estiver presente, escrever no novo codigo
        if(!codigoPresenteTemp){
            fwrite(&item.codigo, sizeof(int), 1, arquivocodigos);
        }   
        //Reseta o arquivo codigos
        rewind(arquivocodigos);
    }

    //Proximo passo= descobrir o valor de cada codigo, passando pelo arquivo de codigos
    int codigoAtual;
    while(fread(&codigoAtual, sizeof(int), 1, arquivocodigos)){
        //Rewind no arquivo de dados
        rewind(arquivo);
        //Ler o arquivo de dados e se o codigo for igual, adicionar o valor
        double valorTotal=0;
        while(fread(&item, sizeof(item), 1, arquivo)> 0){
            if(item.codigo == codigoAtual){
                valorTotal += item.quantidade * item.valor;
            }
        }
        //printa o resultado
        printf("O valor total do codigo %d foi R$%.2lf\n", codigoAtual, valorTotal);
        
    }

    //Fechar arquivos
    fclose(arquivo);
    fclose(arquivocodigos);
    return 0;
}
#include <stdio.h>
#include <errno.h>
#define NOME_ARQUIVO "vendas2.dat"

int busca_elemento(int, int *, int);

typedef struct{
    unsigned int codigo;
    char comentario[50];
    double quantidade;
    double valor;
} venda;

int main(){
    int num_cod = 0;
    int *ja_vistos;
    double *total_vendas;
    long tamanho;

    ja_vistos = (int *) malloc((num_cod+1) * sizeof(int));
    total_vendas = (double *) malloc((num_cod+1) * sizeof(int));

    venda item, item_aux;
    FILE *arquivo;
    
    arquivo = fopen(NOME_ARQUIVO, "rb");
    if (!arquivo){
        perror("erro na leitura do arquivo\n");
        exit(1);
    }

    while(fread(&item, sizeof(item), 1, arquivo) > 0){
        int posicao = ftell(arquivo);
        
        
        
        
        if (!busca_elemento(item.codigo, ja_vistos, num_cod)){
            num_cod++;
            ja_vistos = realloc(ja_vistos, num_cod * sizeof(int));
            total_vendas = realloc(total_vendas, num_cod * sizeof(double));
            fseek(arquivo, 0, SEEK_SET);
            while(fread(&item_aux, sizeof(item_aux), 1, arquivo) != 0)
                if(item.codigo == item_aux.codigo) total_vendas[num_cod - 1] += item_aux.quantidade * item_aux.valor;
            
            ja_vistos[num_cod - 1] = item.codigo;
            fseek(arquivo, posicao, SEEK_SET);
        }
        
    }

    for (int i = 0; i < num_cod; i++){
        printf("total de vendas do codigo %d: R$ %.2lf\n", ja_vistos[i], total_vendas[i]);
    }

    
    fclose(arquivo);
    
    return 0;
}


int busca_elemento(int elemento, int vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++)
        if (elemento == vetor[i]) return 1;

    return 0;
}
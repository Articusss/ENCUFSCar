#include <stdio.h>
#include <stdlib.h>

//Struct solicitado
struct venda{
    int codigo;
    char nome[50];
    int quantidade;
    double preco;
};
//Verificar alocacao
void verificaAlocacao(struct venda *v){
    if(v==NULL){
        printf("Erro na alocacao");
        exit(1);
    }
}
//Criar nova pessoa
struct venda novoItem(){
    struct venda item;
    printf("Inserir dados na ordem: Codigo/nome/quantidade/preco\n");
    //Pegando os dados
    scanf("%d", &item.codigo);
    fflush(stdin);
    fgets(item.nome, 50, stdin);
    scanf("%d", &item.quantidade);
    scanf("%lf", &item.preco);

    return item;
}
//Funcao para achar estoques
struct venda *acharEstoque(struct venda *v, int estoquemin, int produtos, int *numIndex){
    //Criando vetor novo para ser retornado
    struct venda *resultado;
    //Alocar valor maximo: numero de produtos
    resultado = (struct venda *) calloc(produtos, sizeof(struct venda));
    verificaAlocacao(resultado);
    //Iterar pelo vetor e ver qual produto tem estoque suficiente
    for(int i=0; i<produtos; i++){
        if(v[i].quantidade > estoquemin){
            resultado[*numIndex] = v[i];
            *numIndex= *numIndex + 1;
        }
    }
    //Realocar o vetor e testar alocacao
    resultado = realloc(resultado, *numIndex * sizeof(struct venda));

    return resultado;
}
int main(void){

    int produtos;
    //Vetor com produtos
    struct venda *v;
    //Escanear numero de produtos e criar vetor dinamico
    printf("Insira o numero de produtos:\n");
    scanf("%d", &produtos);

    v = (struct venda *) calloc(produtos, sizeof(struct venda));
    //Verificar alocacao
    verificaAlocacao(v);
    //Escanear vendas
    for(int i=0; i < produtos; i++){
        printf("Item %d\n", i+1);
        v[i] = novoItem();
    }
    
    //Agora verificando os estoques
    int estoquemin;
    printf("Insira o numero minimo de estoque:\n");
    scanf("%d", &estoquemin);
    struct venda *itemsEstoque;
    //Variavel por referencia para entrar na funcao, como controle do tamanho do vetor
    int numIndex = 0;

    //Achando os estoques
    itemsEstoque = acharEstoque(v, estoquemin, produtos, &numIndex);

    //Imprimindo os produtos, se encontrados
    if(itemsEstoque == NULL){
        printf("Sem produtos encontrados");
    }
    else{
        for(int j=0; j <numIndex; j++){
            printf("Produto %d----\n", j+1);
            printf("Codigo: %d\n", itemsEstoque[j].codigo);
            printf("Nome: %s", itemsEstoque[j].nome);
            printf("Quantidade: %d\n", itemsEstoque[j].quantidade);
            printf("Preco: R$%.2lf\n", itemsEstoque[j].preco);
        }
    }

    //Liberando memoria
    free(v);
    free(itemsEstoque);

    return 0;
}
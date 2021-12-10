#include <stdio.h>
#define tam_maximo 100

//Estrutura do quadrado com tamanho
struct quadrado{
    int dimensao;
    int mat[tam_maximo][tam_maximo];
};
//Ler o quadrado
struct quadrado leiaquadrado(void){
    struct quadrado novo_quadrado;
    //Ler a dimensao
    scanf("%d", &novo_quadrado.dimensao);
    //Ler o quadrado
    int i, j;
    for(i=0;i<novo_quadrado.dimensao; i++){
        for(j=0; j<novo_quadrado.dimensao; j++){
            scanf("%d", &novo_quadrado.mat[i][j]);
        }
    }
    return novo_quadrado;
}

//Verificar intervalo = verifica se os numeros estao no intervalo. Retorna 0 se falso, 1 se verdadeiro
int verificar_intervalo(struct quadrado item){
    int i, j, n;
    //Para melhorar a legibilidade
    n = item.dimensao;

    for(i=0; i< n; i++){
        for(j=0; j < n; j++){
            if((item.mat[i][j] > n*n) || (item.mat[i][j] < 1))
            return 0;
        }
    }
    //Se nao retornar 0 ate aqui
    return 1;
}
//Soma a linha e verifica se eh igual a soma fornecida
int soma_linha(struct quadrado item, int soma){
    int i, j;
    int soma_atual;
    for(i=0; i< item.dimensao; i++){
        //Soma reseta toda linha
        soma_atual=0;
        for(j=0; j < item.dimensao; j++){
            soma_atual += item.mat[i][j];
        }
        //Retorna 0 se em algum momento for diferente
        if(soma_atual != soma)
            return 0;
    }
    //Se nunca retornou 0
    return 1;
}

//Soma colunas
int soma_coluna(struct quadrado item, int soma){
    int i, j;
    int soma_atual;
    for(j=0; j< item.dimensao; j++){
        soma_atual=0;
        for(i=0;i<item.dimensao; i++){
            soma_atual += item.mat[i][j];
        }
        //Retorna 0 se em algum momento for diferente
        if(soma_atual != soma)
            return 0;
    }
    //Se nunca retornou 0
    return 1;
}

//Soma diagonais
int soma_diagonais(struct quadrado item, int soma){
    int i;
    int soma_atual=0;

    //Diagonal principal
    for(i=0; i<item.dimensao; i++){
        soma_atual += item.mat[i][i];
    }
    //Primeira checagem
    if(soma_atual != soma)
        return 0;
    //Diagonal secundaria
    soma_atual=0;
    for(i=0; i<item.dimensao; i++){
        soma_atual += item.mat[i][item.dimensao -i -1];
    }
    if(soma_atual != soma)
        return 0;
    
    //Se nao retornou ate agora retornar verdadeiro
    return 1;
}

//Verificar magico: verifica se o quadrado eh magico
int verificar_magico(struct quadrado item){
    int soma;
    soma = (item.dimensao*((item.dimensao * item.dimensao) +1))/2;

    if(verificar_intervalo(item) && soma_linha(item, soma) && soma_coluna(item, soma) && soma_diagonais(item, soma))
        return 1;
    else
        return 0;
}

int main(void){
    struct quadrado quadr_magico;

    quadr_magico = leiaquadrado();

    printf("%s\n", verificar_magico(quadr_magico) ? "valido" : "invalido");

    return 0;
}
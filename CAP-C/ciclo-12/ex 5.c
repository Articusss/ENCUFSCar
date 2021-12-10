#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void verificarAlocacao (int ** mat){
    if(mat == NULL){
        printf("Erro na alocacao\n");
        exit(1);
    }
}

int **gerarMatriz(int lin, int col){
    int **m;
    //Alocacao dinamica
    m = (int **) calloc(lin, sizeof(int *));
    verificarAlocacao(m);
    //colunas
    for(int i=0; i<lin; i++){
        m[i] = (int *) calloc(col,sizeof(int));
        verificarAlocacao(m[i]);
    }

    return m;
}
//preenche matriz quadrada
int **preencherMatriz(int **mat, int dimensao){
    int expoente;
    for(int i=0; i<dimensao; i++){
        for(int j=0; j<dimensao; j++){
            //Primeira linha
            if(i==0){
                mat[i][j] = pow(2, j);
            }
            else{
                if(j<dimensao-1){
                    mat[i][j]= mat[i-1][j+1];
                }
                else{
                    mat[i][j] = mat[i][j-1] +mat[i][j-1];
                }
            }
        }
    }

    return mat;
}
//le a matriz
void lerMatriz(int **m,int  lin,int col){
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void liberaMemoria(int **mat, int lin){
    for(int i=0; i<lin; i++){
        //libera cada ponteiro de ponteiro
        free(mat[i]);
    }
    //Libera os ponteiros
    free(mat);
}

int main(void){

    //Criacao de variaveis
    int **mat;
    int input;

    //Bloco do while
    do{
        //Escaneia o bloco
        scanf("%d", &input);
        if(input != 0){
            mat = gerarMatriz(input, input);
            //preencher matriz
            mat = preencherMatriz(mat, input);
            lerMatriz(mat, input, input);
            //liberar a memoria
            liberaMemoria(mat, input);
        }

    }while(input != 0);


    return 0;
}
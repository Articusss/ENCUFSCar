#include <stdlib.h>
#include <stdio.h>

int **criaMatriz(int lin, int col){
    int ** mat;
    //Alocacao dinamica de linhas
    mat = (int **) calloc(lin, sizeof(int*));
    //Verificar alocacao
    if(mat==NULL){
        printf("Erro na alocacao");
        exit(1);
    }

    for(int i=0; i<lin; i++){
        mat[i] = (int *) calloc(col, sizeof(int));
        if(mat[i]==NULL){
            printf("Erro na alocacao");
            exit(1);
        }
        for(int j=0; j<col; j++){
            mat[i][j] = (rand() % 10); 
        }
    }

    return mat;
}

void lerMatriz(int ** mat,int lin,int col){
    //impressao basica
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            printf("%d\n", mat[i][j]);
        }
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

    //Matriz e dimensoes
    int ** mat;
    int lin, col;
    //Escanear dimensoes
    scanf("%d %d", &lin, &col);
    
    //Gerar a matriz dinamicamente com a funcao
    mat = criaMatriz(lin, col);

    //Ler a matriz
    lerMatriz(mat, lin, col);

    //Liberar o espaco
    liberaMemoria(mat, lin);

    return 0;
}

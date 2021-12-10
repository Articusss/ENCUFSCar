#include <stdio.h>
#include <stdlib.h>

void verificaAlocacao(int **mat){
    if(mat==NULL){
        printf("Erro na alocacao");
        exit(1);
    }
}

int **criaMatriz(int lin, int col){
    int **mat;
    //Alocacao dinamica
    mat = (int **) calloc(lin, sizeof(int *));
    //Verifica a alocacao
    verificaAlocacao(mat);

    //Alocacao para colunas
    for(int i=0; i<lin; i++){
        mat[i] =  (int *) calloc(col,sizeof(int));
    }

    return mat;
}

int **transposta(int ** mat,int **mattrans, int lin,int col){    
    for(int l = 0; l < lin; l++){
        for(int c = 0; c < col; c++){
            mattrans[c][l] = mat[l][c];
            printf("%d", mattrans[c][l]);
        }
    }

    return mattrans;
}

void lerMatriz(int **mat, int lin,int col){
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

}

void scanMatriz(int ** mat, int lin, int col){
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            scanf("%d", &mat[i][j]);
        }
    }
}

int main(void){
    //declarar m, n e matriz
    int n, m;
    int **mat;
    int **mattransposta;

    scanf("%d", &n);
    scanf("%d", &m);
    //Cria matriz
    mat = criaMatriz(n, m);
    mattransposta = criaMatriz(m,n);

    //scan matriz
    scanMatriz(mat, n, m);

    //transposta da matriz
    transposta(mat, mattransposta, n, m);

    //leitura
    printf("Matriz inserida:\n");
    lerMatriz(mat, n, m);
    printf("Matriz transposta:\n");
    lerMatriz(mattransposta, m, n);
;
    return 0;
}
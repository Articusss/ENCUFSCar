#include <stdio.h>


int main(void){

    int mat[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

    int temp;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    //lendo
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d\n", mat[i][j]);
        }
    }

}
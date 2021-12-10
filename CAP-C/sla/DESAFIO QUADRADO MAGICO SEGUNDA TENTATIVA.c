//segunda tentativa no exercicio de quadrados magicos para estudo.
#include <stdio.h>
#include <stdbool.h>
#define tamMaximo 100

struct quadrado{
    int dimensao;
    int mat[tamMaximo][tamMaximo];
};

//leitura do quadrado
struct quadrado ler_quadrado(void){
    struct quadrado novoQuadrado;
    //Ler dimensao do quadrado
    scanf("%d", &novoQuadrado.dimensao);
    //Ler numeros a partir da dimensao do quadrado
    for(int i=0; i<novoQuadrado.dimensao; i++){
        for(int j=0; j<novoQuadrado.dimensao; j++){
            scanf("%d", &novoQuadrado.mat[i][j]);
        }
    }
    //Retorna o novo quadrado
    return novoQuadrado;
}

//Verifica a dimensao e os valores
bool verificar_dimensao(struct quadrado quadradoMagico){
    for(int i=0; i<quadradoMagico.dimensao; i++){
        for(int j=0; j<quadradoMagico.dimensao; j++){
            if(quadradoMagico.mat[i][j] > (quadradoMagico.dimensao * quadradoMagico.dimensao) || quadradoMagico.mat[i][j] < 1){
                return false;
            }
        }
    }
    return true;
}

bool soma_linha(struct quadrado quadradoMagico){
    //mais legivel
    int n = quadradoMagico.dimensao;
    for(int i=0; i<quadradoMagico.dimensao; i++){
        int soma =0;
        for(int j=0; j<quadradoMagico.dimensao; j++){
            soma += quadradoMagico.mat[i][j];
        }
        if(soma != (n*((n*n)+1))/2)
            return false;
    }
    return true;
}

bool soma_colunas(struct quadrado quadradoMagico){
    int n = quadradoMagico.dimensao;
    for(int j=0; j<quadradoMagico.dimensao; j++){
        int soma = 0;
        for(int i=0; i<quadradoMagico.dimensao; i++){
            soma += quadradoMagico.mat[i][j];
        }
        if(soma != (n*((n*n)+1))/2)
            return false;
    }
    return true;
}

bool soma_diagonais(struct quadrado quadradoMagico){
    //Diagonal principal
    int n = quadradoMagico.dimensao;
    int somaPrincipal=0;
    for(int i=0; i<quadradoMagico.dimensao; i++){
        somaPrincipal += quadradoMagico.mat[i][i];
    }

    int somaSecundaria = 0;
    for(int i=0; i<quadradoMagico.dimensao; i++){
        somaSecundaria += quadradoMagico.mat[i][quadradoMagico.dimensao - i -1];
    }

    if((somaPrincipal != (n*((n*n)+1))/2) || somaSecundaria != (n*((n*n)+1))/2)
        return false;
    else
        return true;
}


//verificar_magico: retorna a veracidade do quadrado magico
bool verificar_magico(struct quadrado quadradoMagico){
    //Primeiro passo: verificar se os valores estao no maximo na segunda dimensao
    if(verificar_dimensao(quadradoMagico) == false){
        return false;
    }
    //Verificar a soma das linhas
    else if(soma_linha(quadradoMagico) == false){
        return false;
    }
    //Verificar a soma das colunas
    else if(soma_colunas(quadradoMagico) == false){
        return false;
    }
    //Verificar soma das diagonais
    else if(soma_diagonais(quadradoMagico) == false){
        return false;
    }
    else
        return true;
}


int main(void){
    //Iniciar variavel a ser trabalhada
    struct quadrado quadradoMagico;
    //Leitura do quadrado em subrotina
    quadradoMagico = ler_quadrado();
    //Verificacao do quadrado
    printf("%s\n", verificar_magico(quadradoMagico) ? "valido" : "invalido");

    return 0;
}
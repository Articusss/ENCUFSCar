#include <stdio.h>
#include <stdlib.h>

struct regV{
    int *v;
    int tam;
};

void verificaAlocacao(int *v){
    if(v==NULL){
        printf("Erro na alocacao");
        exit(1);
    }
}

struct regV gerarValores(){
    struct regV newReg;
    printf("Digite o tamanho\n");
    scanf("%d", &newReg.tam);
    //Aloca o vetor
    newReg.v = calloc(newReg.tam, sizeof(int));
    verificaAlocacao(newReg.v);
    //Atribui valores aleatorios
    for(int i=0; i<newReg.tam; i++){
        newReg.v[i] = (rand() % 101);
    }

    return newReg;
}

struct regV formarVetor(struct regV regV1, int vmin, int vmax){
    struct regV regV2;
    //Alocar valor maixmo para o vetor que eh o tamanho de v1
    regV2.v = (int *) calloc(regV1.tam, sizeof(int));
    verificaAlocacao(regV2.v);

    //Preenche valores entre o intervalo percorrendo o vetor de regV1
    regV2.tam = 0;
    for(int i=0; i<regV1.tam; i++){
        if((regV1.v[i] > vmin) && (regV1.v[i] < vmax)){
            //Atribui o valor e incrementa o tamanho
            regV2.v[regV2.tam] = regV1.v[i];
            regV2.tam++;
            printf("A\n");
        }
    }
    //Reduz o vetor
    regV2.v = realloc(regV2.v, regV2.tam * sizeof(int));

    return regV2;
}

void printVetor(struct regV regx){
    for(int i=0; i<regx.tam; i++){
        printf("%d ", regx.v[i]);
    }
    printf("\n");
}

int main(void){

    struct regV regV1, regV2;
    int vmax, vmin;
    regV1 = gerarValores();

    printf("Digite o valor minimo\n");
    scanf("%d", &vmin);
    printf("Digite o valor maximo\n");
    scanf("%d", &vmax);
    //Forma o vetor
    regV2 = formarVetor(regV1, vmin, vmax);

    //Le os dois vetores
    printf("Lendo o vetor original:\n");
    printVetor(regV1);
    printf("Lendo o segundo vetor:\n");
    printVetor(regV2);


    //Liberar memoria
    free(regV1.v);
    free(regV2.v);

    return 0;
} 
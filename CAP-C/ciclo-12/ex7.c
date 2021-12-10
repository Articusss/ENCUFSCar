#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct set{
    int *vet;
    int n;
};

void verificaAlocacao(int *v){
    if(v==NULL){
        printf("Erro na alocacao");
        exit(1);
    }
}

struct set lerSet(){
    struct set novoSet;
    printf("Inserir tamanho\n");
    scanf("%d", &novoSet.n);
    printf("Inserir valores:\n");
    //Alocacao dincamica
    novoSet.vet = (int *) calloc(novoSet.n, sizeof(int));
    verificaAlocacao(novoSet.vet);
    for(int i=0; i<novoSet.n; i++){
        scanf("%d", &novoSet.vet[i]);
    }
    return novoSet;
}

//Retorna false se o numero nao for encontrado no array indicado
bool verificarNumero(struct set set1, int numero){
    for(int i=0; i<set1.n; i++){
        if(set1.vet[i] == numero)
            return true;
    }
    return false;
}

struct set uniaoSet(struct set set1, struct set set2){
    struct set novoSet;
    //Alocar dinamicamente o maior tamanho possivel
    novoSet.vet = (int *) calloc(set1.n + set2.n, sizeof(int));
    verificaAlocacao(novoSet.vet);
    //Copiar o primeiro vet
    novoSet.n = set1.n;
    for(int i=0; i<set1.n; i++){
        novoSet.vet[i] = set1.vet[i];
    }
    //Copiando valores do set2 que nao pertencem ao set 1
    for(int j=0; j<set2.n; j++){
        if(verificarNumero(set1, set2.vet[j]) == false){
            novoSet.vet[novoSet.n] = set2.vet[j];
            novoSet.n++;
        }
    }
    //Realocando memoria necessaria
    novoSet.vet = realloc(novoSet.vet, novoSet.n * sizeof(int));
    verificaAlocacao(novoSet.vet);
    return novoSet;
}

void printSet(struct set setx){
    printf("Lendo os valores:\n");
    for(int i=0; i<setx.n;i++){
        printf("%d", setx.vet[i]);
    }
    printf("\n");
}

int main(void){

    struct set set1, set2;
    //Ler os 2 sets
    printf("Set 1:\n");
    set1 = lerSet();
    printf("Set 2:\n");
    set2 = lerSet();

    //Alocacao dinamica para tamanho maximo do set 3. Sera reduzido depois
    struct set set3;
    set3 = uniaoSet(set1,set2);

    //Printa o set
    printSet(set3);

    free(set1.vet);
    free(set2.vet);
    free(set3.vet);

    return 0;
}
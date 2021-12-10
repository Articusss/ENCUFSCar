#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
    int matricula;
    char sobrenome[50];
    int ano;
};

void verificaAlocacao(struct pessoa *v){
    if(v==NULL){
        printf("Erro na alocacao");
        exit(1);
    }
}

struct pessoa novaPessoa(){
    struct pessoa p;

    printf("Inserir matricula\n");
    scanf("%d", &p.matricula);
    fflush(stdin);
    printf("Inserir sobrenome:\n");
    fgets(p.sobrenome,50,stdin);
    printf("Ano de nascimento:\n");
    scanf("%d", &p.ano);

    return p;
}

void lerPessoas(struct pessoa *v,int alunos){
    for (int i=0; i<alunos; i++){
        printf("Pessoa %d----\n", i);
        printf("%d\n", v[i].matricula);
        printf("%s", v[i].sobrenome);
        printf("%d\n", v[i].ano);
    }
}

int main(void){

    struct pessoa *v;
    int alunos;
    //Escaneia o numero de alunos
    printf("Numero de alunos:\n");
    scanf("%d", &alunos);

    v = (struct pessoa *) calloc(alunos, sizeof(struct pessoa));

    for(int i=0; i<alunos; i++){
        v[i] = novaPessoa();
    }

    lerPessoas(v, alunos);

    free(v);

    return 0;
}
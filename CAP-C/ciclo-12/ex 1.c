#include <stdio.h>
#include <stdlib.h>


int main(void){
    int *v;
    int i=0;

    //Inicializando o vetor com 10 posições
    v = (int *) calloc(10, sizeof(int));

    //Inicializacao do bloco de loop
    int temp; //Variavel de apoio
    do{
        //Se i for diferente de 0 e divisivel por 10, alocar mais 10 memorias
        if(i != 0 && i % 10 == 0){
            v=realloc(v, (10+i)*sizeof(int));
        }
        //Escaneia variavel de apoio e atribui ela se for diferente de 0
        scanf("%d", &temp);
        if(temp != 0){
            v[i] = temp;
            i++;
        }
    }while(temp != 0);

    //Verificar erro na alocação
    if(v==NULL){
        printf("Erro na alocacao\n");
        exit(1);
    }

    //Ler o vetor ate o indice que a funcao acima parou
    printf("Leitura da matriz:\n");
    for(int j=0; j<i; j++){
        printf("%d\n", v[j]);
    }

    //Liberar memoria
    free(v);

    return 0;
}
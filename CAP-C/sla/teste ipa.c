#include <stdio.h>
#include <stdlib.h>

//Percorre separadamente todos os numeros da senha para ver se o numero especificado esta dentro dele
int numeroSenha(int senha, int num){
    //Percorre os numeros
    while(senha){
        if(senha % 10 == num){
            //Retorna verdade
            return 1;
        }
        senha /= 10;
    }
    //Retorna falso
    return 0;
}

int verificarVulneravel(int senha, int vulneravel[], int numvulneravel){
    int determinarvulneravel = 0;
    //Percorre todos os numeros dentro do vetor vulneravel
    for(int i=0; i<numvulneravel; i++){
        if(numeroSenha(senha, vulneravel[i])){
            determinarvulneravel++;
        }
    }
    //Se houver mais que 2 numeros vulneraveis, retornar a senha como vulneravel
    if(determinarvulneravel > 1)
        return 1;
    else
        return 0;
}

int main(void){

    int tam;
    printf("Digite o numero de senhas:\n");
    scanf("%d", &tam);

    //Declarar numero de senhas e alocacao dinamica para o vetor contendo os caracteres mais frequentes
    int senhas[tam];
    int *maisFrequente;
    maisFrequente = (int *) calloc(10, sizeof(int));
    maisFrequente[0] = 0;
    //Numero de itens frequentes para realocar o vetor no final
    int numFrequente = 0;

    printf("Digite as senhas:\n");
    for(int k=0; k<tam; k++){
        scanf("%d", &senhas[k]);
    }
    //Percorre o algoritmo 1 vez para cada numero de 0 a 9
    int maiorFrequencia=0;
    for(int i=0; i<10; i++){
        //Inicia a frequencia
        int frequencia = 0;
        for(int j=0; j<tam; j++){
            //Pegar cada digito
            if(numeroSenha(senhas[j], i)){
                frequencia= frequencia+1;
            }
        }
        //Bloco de achar o mais frequente
        if(frequencia > maiorFrequencia){
            //Seta um novo mais frequente
            maisFrequente[0] = i;
            numFrequente = 1;
            maiorFrequencia = frequencia;
        }
        else if(frequencia == maiorFrequencia){
            maisFrequente[numFrequente] = i;
            numFrequente++;
        }
    }
    //Realoca o vetor
    maisFrequente =  realloc(maisFrequente, numFrequente * sizeof(int));

    //Formar vetor com apenas senhas vulneraveis
    int *senhasV;
    senhasV = (int *) calloc(tam, sizeof(int));
    //Numero de senhas vulneraveis para realocar o vetor
    int numVulneraveis=0;
    for(int l=0; l<tam; l++){
        //Verificar se eh vulneravel e se for, atribuir ao novo vetor
        if(verificarVulneravel(senhas[l], maisFrequente, numFrequente)){
            senhasV[numVulneraveis] = senhas[l];
            numVulneraveis++;
        }
    }

    //Realocando o vetor contendo apenas o numero de senhas vulneraveis
    senhasV = realloc(senhasV, numVulneraveis * sizeof(int));

    //Imprimir senhas vulneraveis
    printf("Vulneraveis:\n");
    for(int b=0; b<numVulneraveis; b++){
        printf("%d\n", senhasV[b]);
    }

    //Liberando a memoria
    free(senhasV);
    free(maisFrequente);

    return 0;
}

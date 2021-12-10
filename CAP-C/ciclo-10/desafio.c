#include <stdio.h>

void ler_vetor(int vetor[], int tam){
    int i;
    //Le os elementos
    for (i=0; i<tam; i++){
        scanf("%d", &vetor[i]);
    }
}
//Funcao numeroigual: retorna 0 se houver numero igual no array, 1 se nao houver
int numeroigual (int valor, int v[], int tam){
    int igual = 1;
    int i;
    for (i=0; i<tam; i++){
        if (v[i] == valor)
            igual = 0;
    }
    return igual;
}

void uniao(int v1[], int v2[], int vuniao[], int tam1, int tam2, int *tamuniao){
    //Escreve primeiro todos os elementos do primeiro vetor no vetor vuniao
    int i, k;
    *tamuniao = tam1;
    for (i=0; i < tam1; i++){
        vuniao[i] = v1[i];
    }
    //Agora escrevendo apenas os elementos do segundo vetor, que nao estao presentes no primeiro vetor
    for (k=0; k < tam2; k++){
        if (numeroigual(v2[k],v1, tam1) == 1){
            //Escreve o valor no maior index vazio
            vuniao[*tamuniao] = v2[k];
            //Aumenta o tamanho
            *tamuniao = *tamuniao + 1;
        }
    }

}

void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main (void){
    //Variavel tamanho e leitura
    int tam1, tam2, i;
    int tamuniao; //Tamanho dinamico
    scanf("%d", &tam1);
    //Inicializacao do vetor
    int v1[tam1];
    //ler o vetor
    ler_vetor(v1, tam1);

    //Le o tamanho de novo e fazer leitura do segundo vetor
    scanf("%d", &tam2);
    int v2[tam2];
    ler_vetor(v2, tam2);

    int vuniao[500]; //Tamanho max
    
    //Realizacao da funcao
    uniao(v1, v2, vuniao, tam1, tam2, &tamuniao);

    //Bubble sort. Fonte: http://devfuria.com.br/logica-de-programacao/exemplos-na-linguagem-c-do-algoritmo-bubble-sort/
    bubble_sort(vuniao, tamuniao);

    //Leitura do vetor final
    for (i=0; i<tamuniao; i++){
        printf("%d ", vuniao[i]);
    }
    
    return 0;
}
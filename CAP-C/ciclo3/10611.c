/*

Autor: Vinicius Leite Censi Faria
Data de Criação: 28/9/2020
Data de Atualização: 28/9/2020

Objetivo: Calcular o tempo de um evento

*/
#include <stdio.h>
 
int main() {
    
    //Declarações de variáveis
    int diaI,horaI,minI,segI; //Horários iniciais
    int diaF,horaF,minF,segF; // Horarios finais
    int diaT, horaT, minT, segT; // Horarios totais

    //Leitura de dados
    scanf("Dia %d", &diaI);
    scanf("%d : %d : %d\n", &horaI, &minI, &segI);
    scanf("Dia %d", &diaF);
    scanf("%d : %d : %d", &horaF, &minF, &segF);

    //Calculo de dias,horas,minutos,segundos
    diaT = diaF - diaI;
    horaT = horaF - horaI;
    minT = minF - minI;
    segT = segF - segI;

    //Checagem de numeros negativos. Caso houver, adicionar 1 minuto/segundo ou 24 horas para compensar e escrever os dados corretamente
    if (segT < 0){
        segT += 60;
        minT--;
    }
    if (minT < 0){
        minT += 60;
        horaT--;
    }
    if(horaT < 0){
        horaT += 24;
        diaT--;
    }

    // Escrita dos resultados
    printf("%d dia(s)\n", diaT);
    printf("%d hora(s)\n", horaT);
    printf("%d minuto(s)\n", minT);
    printf("%d segundo(s)\n", segT);

    return 0;
}
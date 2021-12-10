#include <stdio.h>
 
int main() {
 
    int t; //Quantidade de casos
    int i; //Inteiro de loop
    int anos; // Numero total de anos
    int pa, pb; //Populacao atual
    double g1,g2; //Taxas de crescimento

    scanf("%d", &t); //Numero de testes

    for (i=0; i<t; i++){
        anos = 0; // resetando variavel para o proximo loop
        scanf("%d %d %lf %lf", &pa, &pb, &g1, &g2);
        //Conversao para %
        g1 = g1/100;
        g2 = g2/100;

        while(pa <= pb && anos < 101){
            pa += (int)(pa * g1); // Crescimento de A
            pb += (int)(pb * g2); // Crescimento de B
            anos += 1;  // Contagem de anos
        }
        //Verifica se chegou no limite de seculo
        if (anos > 100){
            printf("Mais de 1 seculo.\n");
        }
        else{
            printf("%d anos.\n", anos);
        }
    }
 
    return 0;
}
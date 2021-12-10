#include <stdio.h>
 
int main() {
 
    int diaI,horaI,minI,segI;
    int diaF,horaF,minF,segF;
    int diaT, horaT, minT, segT;

    scanf("Dia %d", &diaI);
    scanf("%d : %d : %d\n", &horaI, &minI, &segI);
    scanf("Dia %d", &diaF);
    scanf("%d : %d : %d", &horaF, &minF, &segF);

    diaT = diaF - diaI;
    horaT = horaF - horaI;
    minT = minF - minI;
    segT = segF - segI;

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

    printf("%d dia(s)\n", diaT);
    printf("%d hora(s)\n", horaT);
    printf("%d minuto(s)\n", minT);
    printf("%d segundo(s)\n", segT);

 
    return 0;
}
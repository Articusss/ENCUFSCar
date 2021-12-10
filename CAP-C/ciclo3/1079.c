#include <stdio.h>
 
int main() {
 
    float n1,n2,n3, media;
    int n,i;

    scanf("%d", &n);
    //Numero de test cases
    for(i=0; i<n; i++){
        //Ler os 3 numeros
        scanf("%f %f %f", &n1, &n2, &n3);
        //Calcular media e printar
        media = (n1*2+n2*3+n3*5)/10;
        printf("%.1f\n", media);
    }
 
    return 0;
}
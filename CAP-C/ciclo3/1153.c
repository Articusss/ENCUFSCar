#include <stdio.h>
 
int main() {
 
    int n, i, fac;

    scanf("%d", &n);
    //Escanear o numero a ser fatoriado
    fac = 1;
    //Calcular o fatorial
    for (i=n; i > 0; i--){
        fac = fac * i;
    }
    
    printf("%d\n", fac);

    return 0;
}
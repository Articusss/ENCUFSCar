/*
  Conversão de Celsius para fahrenheit
  Vinicius Leite Censi Faria 804410
*/
#include <stdio.h>

int primo (int x){
    int i;
    int a=1; //Iniciakmente primo
    //Achar casos que ele nao seria primo
    if (x>1){
        for(i=2; i < x; i++){
            if(x % i == 0)
                a=0;
        }
    }
    else
        a = 0;

    return a;

}

// programa principal
int main(void){
    
    int n;

    scanf("%d", &n);

    printf("%s", primo(n) ? "primo" : "nao");

    return 0;
}
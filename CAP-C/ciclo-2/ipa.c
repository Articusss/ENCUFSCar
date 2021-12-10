#include <stdio.h>
 
int main () {

    int i, n, fn1, fn2, fr;
    scanf("%d", &n);

   for(i = 1 ; i <= n ; ++i) {
      //Assumir valores manualmente para os 2 primeiros termos
      if(i == 1){
         printf("0\n");
         fn2 = 1;
      }
      else if(i == 2){
         fn1 = 0;
         printf("%d\n", fn2);
      }
      else{
         fr = fn1 + fn2;
         printf("%d\n", fr);
         fn1 = fn2;
         fn2 = fr;
      }
   }

   return 0;
}
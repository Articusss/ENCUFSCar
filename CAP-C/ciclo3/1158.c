/*

Autor: Vinicius Leite Censi Faria
Data de Criação: 28/9/2020
Data de Atualização: 28/9/2020

Objetivo: Somar numeros impares consecutivos

*/

#include <stdio.h>

int main()
{
   // Declarações Locais
   int testes; //Numero de testes
   int num1, num2; //2 numeros indicados pelo problema
   int i, j; //Variaveis responsaveis pelo loops
   int soma;
   
   //Leitura da quantidade de testes
   scanf("%d", &testes);

   //Inicialização do loop
   for(i=0; i < testes; i++){
       soma = 0; //Reiniciando variavel

       //Leitura de dados
       scanf("%d %d", &num1, &num2);
       
       //Filtrar num1 para que caso ele for par, adicionar 1 para tornar-se o proximo impar
       if(num1 % 2 == 0){
           num1 += 1;
       }

       //Inicializar soma, com num1 incrementando por 2 a cada loop
       for(j = 0; j < num2; j++){
           soma += num1;
           num1 += 2;
       }

       //Escrita do resultado
       printf("%d\n", soma);
   }
      
      
   return 0;
}
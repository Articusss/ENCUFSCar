/*

Autor: Prof. Ricardo Rodrigues Ciferri.
Data de Criação: 07/10/20.
Data de Atualização: 07/10/20.

Objetivo: Calcular o maior valor dentre 7 números inteiros.

*/

#include <stdio.h>

int main()
{
   // Declarações Locais
   
   int n; // cada um dos números inteiros
   int i = 1;
   int j;
   int maior;
   
   // Inicialização do maior número
   
   printf("Digite o %do número: ", i);
   scanf("%d", &n);
   i++;
   
   maior = n;
   
   // Cálculo do maior número para os demais 6 números
   
   for (j=1; j<6 ; j++)
   {
    
   printf("Digite o %do número: ", i);
   scanf("%d", &n);
   i++;
   
   if (n > maior)
      maior = n;
      
   }
      
   // Escrita do resultado
   
   printf("Maior = %d", maior);
   
   return 0;
}

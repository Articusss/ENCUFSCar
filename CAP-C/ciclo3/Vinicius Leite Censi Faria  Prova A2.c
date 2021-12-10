/*

Autor: Vinicius Leite Censi Faria 
RA: 804410
Data de Criação: 28/9/2020
Data de Atualização: 28/9/2020

Objetivo: Calcular e classificar equacoes de segundo grau

*/

#include <stdio.h>
#include <math.h>

int main()
{
    // Declarações Locais
    float a,b,c; // Coeficientes
    float discrim; //Discriminante
    float raiz1, raiz2;
    char finalizar;

    do{
        //Leitura de dados
        printf("Digite os coeficients da equacao no modelo: a b c\n");
        
        scanf("%f %f %f", &a, &b, &c);

        //Checagem inicial de validade da equação (a != 0), caso nao for, nao mostrar mais nada
        if (a == 0){
            printf("Equacao invalida.\n");
        }
        else{
            //Checagem por raízes reais
            discrim = pow(b,2) -4*a*c; //Obs: Nao utiliza-se a raiz quadrada ainda para possibilitar a leitura correta dos ifs

            if (discrim < 0){ //Caso: sem raizes reais
                printf("Sem raizes reais.\n");
            }

            else if (discrim == 0){ //Caso: raizes reais identicas
                raiz1 = (-b + discrim) / (2 * a); //Calculo da raiz

                printf("O sistema possui duas raizes identicas, iguais a x = %.2f\n", raiz1);
            }

            else if (discrim > 0){ //Caso: 2 raizes distintas
                discrim = sqrt(discrim);
                raiz1 = (-b + discrim) / (2 * a); 
                raiz2 = (-b - discrim) / (2 * a); 
                //Calcular 2 raizes, imprimir resultado
                printf("O sistema possui duas raizes distintas, iguais a x1 = %.2f e x2 = %.2f\n", raiz1, raiz2);
            }
        }
        //Perguntar se o usuário deseja continuar com as operações.
        printf("Caso queira finalizar com as equacoes, digite F. Caso contrario, digite qualquer outra letra.\n");
        fflush(stdin); //Limpar buffer
        scanf("%c", &finalizar);
    } while (finalizar != 'F' && finalizar != 'f');

   return 0;
}
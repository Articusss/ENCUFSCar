#include <stdio.h>
 
int main() {
 
    float n1,n2,n3,n4,n5;
    float media;
    
    scanf("%f", &n1);
    scanf("%f", &n2);
    scanf("%f", &n3);
    scanf("%f", &n4);

    media = ((n1 *2) + (n2 * 3) + (n3 * 4) + n4) / 10;

    if (media < 5)
        printf("Media: %.1f\nAluno reprovado.\n", media);
    else if (media >= 5 && media < 7){
        printf("Media: %.1f\nAluno em exame.\n", media);
        scanf("%f", &n5);
        media = (media + n5) /2;
        printf("Nota do exame: %.1f\n", n5);
        if (media >= 5)
            printf("Aluno aprovado.\n");
        else
            printf("Aluno reprovado\n");
        printf("Media final: %.1f\n", media);
    }
    else if (media >= 7)
        printf("Media: %.1f\nAluno aprovado.\n", media);

 
    return 0;
}
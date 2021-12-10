#include <stdio.h>
#include <string.h>
 
int main() {
 
    char word1[30], word2[30], word3[30];
    int a;

    scanf("%d %s", &a, &word1);
    printf("%s", word1);
    scanf("%s", &word2);
    scanf("%s", &word3);
    
    if (strcmp(word1,"vertebrado") == 0){
        if (strcmp(word2,"ave") == 0){
            if (strcmp(word3,"carnivoro") == 0)
                printf("aguia\n");
            else if (strcmp(word3,"onivoro") == 0)
                printf("pomba\n");
        }
        else if (strcmp(word2,"mamifero") == 0){
            if (strcmp(word3,"onivoro") == 0)
                printf("homem\n");
            else if (strcmp(word3,"herbivoro") == 0)
                printf("vaca\n");
        }
    }
    else if (strcmp(word1,"invertebrado") == 0){
        if (strcmp(word2,"inseto") == 0){
            if(strcmp(word3,"hematofago") == 0)
                printf("pulga\n");
            if(strcmp(word3,"herbivoro") == 0)
                printf("lagarta\n");
        }
        else if (strcmp(word2,"anelideo") == 0){
            if (strcmp(word3,"hematofago") == 0)
                printf("sanguessuga\n");
            else if (strcmp(word3,"onivoro") == 0)
                printf("minhoca\n");
        }
    }
 
    return 0;
}
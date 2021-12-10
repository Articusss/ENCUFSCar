#include <stdio.h>
 //Estrutura
struct coords{
    int x;
    int y;
};
int main() {
    //Leitura
    struct coords point;
    //Loop e classificacao
    do{
        scanf("%d %d", &point.x, &point.y);

        if (point.x > 0 && point.y > 0)
            printf("primeiro\n");
        else if (point.x < 0 && point.y  > 0)
            printf("segundo\n");
        else if (point.x <0 && point.y < 0)
            printf("terceiro\n");
        else if (point.x > 0 && point.y < 0)
            printf("quarto\n");
    } while(point.x != 0 && point.y != 0);

        return 0;
};
#include <stdio.h>
 
//Struct para ler pontos
struct plane {
    float x;
    float y;
};
int main() {
 
    struct plane points;

    scanf("%f %f", &points.x, &points.y);

    if (points.y == 0 && points.x == 0)
        printf("Origem\n");
    else
        if (points.y == 0)
            printf("Eixo X\n");
        else
            if (points.x == 0)
                printf("Eixo Y\n");
            else
                    if (points.x > 0 && points.y > 0)
                        printf("Q1\n");
                    else
                        if (points.x < 0 && points.y > 0)
                             printf("Q2\n");
                         else
                             if (points.x < 0 && points.y < 0)
                                 printf("Q3\n");
                            else
                                 printf("Q4\n");
    
 
    return 0;
}
#include <stdio.h>
#include <math.h>
 
struct coords{
    double x;
    double y;
};

int main() {
 
    struct coords p1;
    struct coords p2;
    double distance;

    scanf("%lf %lf", &p1.x, &p1.y);
    scanf("%lf %lf", &p2.x, &p2.y);

    distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

    printf("%.4lf\n", distance);

    return 0;
}
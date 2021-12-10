#include <stdio.h>
 
float max(float x, float y){
    float z;
    if (x > y)
        z = x;
    else 
        z = y;
    
    return z;

}

int main() {
 
    printf("%g", max(-2.4, 0));

    return 0;
}

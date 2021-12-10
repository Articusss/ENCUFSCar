int resto (int x, int y){
    int z;
    z =  x % y;
    return z;
}

int par(int x){
    int y;
    if(x%2 == 0){
        y=1;
    }
    else
        y=0;
    return y;
}

char compare (double x, double y){
    char z;
    if (x < y)
        z = '<';
    else if (x>y)
        z = '>';
    else
        z = '=';
    return z;
}

int numero_raizes (float x, float y, float z){
    int a, delta;
    delta = (y*y) - 4*x*z;
    if (x == 0)
        a = -1;
    else if (delta > 0)
        a = 2;
    else if (delta == 0)
        a = 1;
    else if (delta < 0)
        a = 0;
    return a;
}
int duas_raizes_reais (float x, float y, float z){
    int a;
    float delta;

    delta = (y*y) - 4*x*z;

    if (delta > 0)
        a = 1;
    else 
        a = 0;
    return a;

}

long long int fatorial (int x){
    long long int fat=1;
    int i;
    if (x >= 0){
        for (i=1; i<=x; i++){
            fat = fat * i;
        }
    }
    else
        fat = -1;
    return fat;
}


#include <stdio.h>

void test (char c) {
    printf("%c\n", c);
}

char inserir(){
    return 'b';
}

int main() {
    printf("Comecando o teste\n");
    test(inserir());
    return 0;
}
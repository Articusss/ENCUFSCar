/*
  Operações em retângulos
  Jander 2021
*/
#include <stdio.h>
#include <math.h>

/*******************************************/
// definições geométricas: ponto e retângulo

// Um ponto cartesiano no plano, ou seja, (x,y).
struct ponto{
	double x, y;
};

// Um retângulo no plano, definido por dois vértices opostos;
// os lados do retângulo são sempre paralelos aos eixos cartesianos
struct retangulo{
	struct ponto vertice1, vertice2;
};

/*******************************************/
// leituras

// leia_ponto: faz a leitura de um ponto, lendo cada coordenada; a leitura é
//	feita do teclado
//   entrada: não há
//   saída: um registro com o ponto lido no valor da função
struct ponto leia_ponto(void){
	struct ponto novo_ponto;
	scanf("%lf %lf", &novo_ponto.x, &novo_ponto.y);

	return novo_ponto;
}

// leia_retangulo: faz a leitura de um retângulo por meio da leitura
//	dos dois pontos que formam os vértices opostos; a leitura é
//	feita do teclado
//  entrada: não há
//  saída: um registro com o retângulo lido
struct retangulo leia_retangulo(void){
	struct retangulo novo_retangulo;

	printf("Coordenadas do vértice 1: ");
	novo_retangulo.vertice1 = leia_ponto();
    printf("%g %g", novo_retangulo.vertice1);
	printf("Coordenadas do vértice 2:");
	novo_retangulo.vertice2 = leia_ponto();

	return novo_retangulo;
}

/*******************************************/
// escritas

// escreva_ponto: escreve as coordenadas do ponto na tela
//  entrada: um registro com o ponto
//  saída: as coordenadas escritas na tela
void escreva_ponto(struct ponto ponto){
	printf("(%g, %g)", ponto.x, ponto.y);
}

// escreva_retangulo: escreve as coordenadas do retangulo na tela
//  entrada: um registro com o retangulo
//  saída: as coordenadas escritas na tela
void escreva_retangulo(struct retangulo retangulo){
	printf("Retângulo: ");
	escreva_ponto(retangulo.vertice1);
	escreva_ponto(retangulo.vertice2);
	printf("\n");
}

double 

double area (struct retangulo retangulo){
    double lado1, lado2, area;
    lado1 = retangulo.vertice1.x - retangulo.vertice2.x;
    printf(" lado 1 = %lf \n", lado1);
    lado2 = retangulo.vertice1.x - retangulo.vertice2.x;
    printf("lado2 = %lf\n", lado2);
    area = fabs(lado1*lado2);
    return area;
}


/*******************************************/
// Programa principal

// Este código exemplifica rapidamente o uso dos registros declarados

int main(void){
	struct retangulo retangulo;

	for(int i = 0; i < 1; i++){
		printf("Entre com o retângulo %d:\n", i + 1);
		retangulo = leia_retangulo();
		printf("\n");
		escreva_retangulo(retangulo);
		printf("\n");
        printf("AREA %lf", area(retangulo));
	}

	return 0;
}
/*
  Operações em retângulos
  Jander 2021
*/
#include <stdio.h>

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

	printf("Coordenadas x e y do vértice 1: ");
	novo_retangulo.vertice1 = leia_ponto();
	printf("Coordenadas x e y do vértice 2: ");
	novo_retangulo.vertice2 = leia_ponto();

	return novo_retangulo;
}

/*******************************************/
/*******************************************/

// ESCREVA SEU CÓDIGO AQUI.
// SUBMETA SOMENTE O SEU PROCEDIMENTO E NÃO PROGRAMA INTEIRO.

/*******************************************/
/*******************************************/

//maiormenor: procedimento que realiza a troca de valores do maior numero com o menor numero
void maiormenor (double *x, double *y){
	//Variavel temporaria
	double temp;
	temp = *x;
	*x = *y;
	//*y recebe o valor antigo de *x
	*y = temp;
}

void torne_canonico(struct retangulo *retangulo){
	//Verificar se o ponto do vertice 1 é maior do que o y, e se sim, trocá-los através do procedimento maiormenor

	//Ponto x entre os 2 vértices
	if((*retangulo).vertice1.x > (*retangulo).vertice2.x){
		maiormenor(&(*retangulo).vertice1.x, &(*retangulo).vertice2.x);
	}
	//Ponto y entre os 2 vértices
	if((*retangulo).vertice1.y > (*retangulo).vertice2.y){
		maiormenor(&(*retangulo).vertice1.y, &(*retangulo).vertice2.y);
	}
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


/*******************************************/
// Programa principal

// Este código apenas lê um retângulo, coloca-o na forma
// canônica e apresenta-o na tela.

int main(void){
	struct retangulo retangulo;

	printf("Entre com os dados do retângulo:\n");
	retangulo = leia_retangulo();
	torne_canonico(&retangulo);	
	escreva_retangulo(retangulo);

	return 0;
}
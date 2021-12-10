/*
  Este programa cria um arquivo de registros de venda de uma dada loja.
  Input: a opcao do modo de operacao do programa (teclado, sendo
	1: digitacao ou 2: geracao aleatoria); para opcao 1 seguem os
	dados dos registros (teclado); para a opcao 2 segue a quantidade
	de registros que sera gerada com valores aleatorios
  Output: cada registro digitado ou gerado aleatoriamente gravado no
	arquivo vendas.dat.

  Jander, 2020

  Cada registro guarda:
	- o codigo do produto (inteiro)
	- a quantidade vendida (inteiro)
	- o valor de venda (double)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <errno.h>
#include <assert.h>

// definicao do registro
struct venda {
	int codigo;
	int quantidade;
	double valor;
};

#define NOME_ARQUIVO "vendas.dat"

// prototipos
struct venda leia_item(void);
struct venda item_aleatorio(void);
void leitura(void);
void aleatorio(void);

//
// programa principal
//
int main(void){
	srand((unsigned int)time(NULL)); // aleatorizacao

	printf("Escolha:\n"
		"1) para digitar os valores\n"
		"2) para gerar dados aleatoriamente\n"
		"\topcao: ");
	int opcao;
	scanf("%d", &opcao);
	switch(opcao){
		case 1:
		  leitura();
		  break;
		case 2:
		  aleatorio();
		  break;
		default:
		  printf("Opcao ignorada\n");
	}

	return 0;
}

// leia_item: leitura dos dados de uma venda do teclado
// Input: os valores para codigo, quantidade e valor (via
//	teclado)
// Output: um registro (struct venda) com os valores digitados
//	no retorno da função
struct venda leia_item(void){
	struct venda item;

	printf("\nCodigo: ");
	scanf("%d", &item.codigo);
	printf("Quantidade: ");
	scanf("%d", &item.quantidade);
	printf("valor (R$): ");
	scanf("%lf", &item.valor);

	return item;
}

// item_aleatorio: gera um item com dados aleatorios, sem
//	qualquer compromisso com a realidade
// Input: nao existe
// Output: um registro (struct venda) com valores dos
//	campos gerados aleatoriamente
struct venda item_aleatorio(void){
	struct venda item;

	item = (struct venda){
		.codigo = rand() % 51 + 10, // 10 a 70
		.quantidade = rand() % 100 + 1, // 1 a 100
		.valor = (double)(rand() % 8000 + 1)/100 // 0.00 a 80.00
	};

	return item;
}

// confirma_continuacao: apresenta mensagem se continua ou nao a digitacao
// Input: ENTER para continuar ou EOF para parar
// Output: a mensagem de orientacao (tela) e true/false se for continuar
//	ou nao (valor de retorno da funcao
bool confirma_continuacao(){
	#ifndef __linux__
		#define TERMINO " Ctrl-Z + ENTER "
	#else
		#define TERMINO " Ctrl-D "
	#endif
	printf("Tecle ENTER para inserir um registro\n"
		"ou" TERMINO "para encerrar a digitacao: ");

	// consome o ENTER da ultima leitura
	while(getchar() != '\n')
		/* nada */;
	return (getchar() == '\n');
}


// leitura: realizacao da leitura de uma sequencia de
//	dados de vendas
// Input: os valores para codigo, quantidade e venda de
//	uma sequencia de vendas
// Output: cada registro (struct venda) gravado no arquivo
//	vendas.dat
void leitura(void){
	// abertura do arquivo e verificacao
	FILE *arquivo_vendas = fopen(NOME_ARQUIVO, "wb");
	if(arquivo_vendas == NULL){
		perror(NOME_ARQUIVO);
		exit(1);
	}
	while(confirma_continuacao()){
		struct venda item = leia_item();
		fwrite(&item, sizeof item, 1, arquivo_vendas);
	}

	// encerramento
	fclose(arquivo_vendas);
}

// aleatorio: gera uma quantidade de registros aleatorios
//	no arquivo de vendas
// Input: a quantidade de registros que serao escritos
// Output: a quantidade especificada de registros com dados
//	aleatorios no arquivo vendas.dat
void aleatorio(void){
	// abertura do arquivo e verificacao
	FILE *arquivo_vendas = fopen(NOME_ARQUIVO, "wb");
	if(arquivo_vendas == NULL){
		perror(NOME_ARQUIVO);
		exit(1);
	}

	printf("Quantidade de registros (0 ou mais): ");
	int quantidade;
	scanf("%d", &quantidade);
	for(int i = 0; i < quantidade; i++){ 
		struct venda item = item_aleatorio();
		fwrite(&item, sizeof item, 1, arquivo_vendas);
	}

	// encerramento
	fclose(arquivo_vendas);
}

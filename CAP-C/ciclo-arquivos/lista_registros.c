/*
  Este programa apresenta todos os registros contidos no arquivo
  de registro de vendas
  Input: os registros contidos no arquivo vendas.dat
  Output: os campos de cada registro (tela), juntamente com
	mensagens "didaticas" sobre o arquivo e as funcoes
	de manipulacao de arquivos em C

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

// definicao do registro
struct venda {
	int codigo;
	int quantidade;
	double valor;
};

#define NOME_ARQUIVO "vendas.dat"

// info_posicao: apresenta mensagem contextual sobre a posicao atual
//	do arquivo
// Input: texto com o contexto e o arquivo (FILE*) como parametros
// Output: a mensagem e a posicao corrente do arquivo
void info_posicao(char *mensagem, FILE *stream){
	printf(">>> %s: byte atual = %lu\n", mensagem, ftell(stream));
}

//
// programa principal
//
int main(void){
	// acesso ao arquivo e verificacao de sucesso
	FILE *arquivo_vendas = fopen(NOME_ARQUIVO, "rb");
	if(arquivo_vendas == NULL)
		perror(NOME_ARQUIVO);
	else{
		info_posicao("Arquivo aberto", arquivo_vendas);

		// varredura do arquivo completo
		struct venda item;
		int numero_registro = 0;
		while(fread(&item, sizeof item, 1, arquivo_vendas) > 0){
			printf("Registro %4d: (%d, %d, %.2lf)\n",
				numero_registro++,
				item.codigo, item.quantidade, item.valor);
			info_posicao("Depois da leitura", arquivo_vendas);
		}

		// encerramento
		info_posicao("Antes do fechamento", arquivo_vendas);
		fclose(arquivo_vendas);
	}

	return 0;
}

/*
  Este programa apresenta o registro de maior venda dentro
  do arquivo de vendas (maior venda corresponde ao registro
  com o maior valor no campo quantidade; no caso de duplicidade
  o primeiro registro sera apresentado)
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

//
// programa principal
//
int main(void){
	// acesso ao arquivo e verificacao de sucesso
	FILE *arquivo_vendas = fopen(NOME_ARQUIVO, "rb");
	if(arquivo_vendas == NULL)
		perror(NOME_ARQUIVO);
	else{
		struct venda item;
		if(fread(&item, sizeof item, 1, arquivo_vendas) == 0)
			printf("Arquivo vazio\n");
		else{
			// pega o primeiro registro
			struct venda item_selecao = item;

			// varredura do restante do arquivo
			while(fread(&item, sizeof item, 1, arquivo_vendas) > 0)
				if(item.quantidade > item_selecao.quantidade)
					item_selecao = item;

			printf("Registro com maior quantidade: "
				"cod: %d; quant: %d; valor: %.2lf\n",
				item_selecao.codigo,
				item_selecao.quantidade,
				item_selecao.valor);
		}

		// encerramento
		fclose(arquivo_vendas);
	}

	return 0;
}

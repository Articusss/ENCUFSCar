#include <stdio.h>
#include <stdlib.h>

#define QUANTIDADE 3
struct aluno{
	unsigned int ra;
	double notas[QUANTIDADE];
};

int main (void){

    //Nome do arquivo
    char nome_arquivo[20];
    int regInvalido = 0;

    //Ler o nome
    fflush(stdin);
    scanf("%s", nome_arquivo);

    //Abrir arquivo para leitura
    FILE *arquivo = fopen(nome_arquivo, "rb");
    struct aluno aluno;

    //Ler o arquivo
    while(fread(&aluno, sizeof(struct aluno), 1, arquivo) > 0){
        //Se estiver fora do intervalo, registrar invalido
        if(aluno.ra < 1 || aluno.ra > 100000){
            regInvalido++;
        }
    }

    //printar numero de invalidos
    printf("%d\n", regInvalido);





    fclose(arquivo);
    return 0;

}
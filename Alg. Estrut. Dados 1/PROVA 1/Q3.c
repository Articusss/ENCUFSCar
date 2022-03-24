#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListaCadastral{
    int conteudo;
    struct ListaCadastral * next;
};

typedef struct ListaCadastral ListaCadastral;
void Cria(ListaCadastral **L){
    *L = NULL;
}

bool EstaNaLista(ListaCadastral *L, int x){
    ListaCadastral *p;
    p = L;
    while(p != NULL && p->conteudo != x) p = p->next;
    return !(p == NULL);
}

bool Vazia (ListaCadastral *L){
    return  L == NULL;
}

void Insere(ListaCadastral **L, int X, bool *Ok){
    if(EstaNaLista(*L, X)){
        *Ok = false;
    } else {
        *Ok = true;
        ListaCadastral *newnode;
        newnode = (ListaCadastral *) malloc(sizeof(ListaCadastral));
        newnode->conteudo = X;
        newnode->next = *L;
        *L = newnode;
    }
}

void Retira(ListaCadastral **L, int X, bool *Ok){
    if(!EstaNaLista(*L, X)){
        *Ok = false;
    } else{
        *Ok = true;
        //Verifica se nao eh o primeiro
        if((*L)->conteudo == X){
            ListaCadastral *p = *L;
            (*L) = (*L)->next;
            free(p);
        } else{
            ListaCadastral *p;
            p = (*L)->next;
            //ate aqui ja eh garantindo que esta na lista, porem algoritmo eh O(n^2)
            while(p->next->conteudo != X) p = p->next;
            ListaCadastral *morta = p->next;
            p->next = morta->next;
            free(morta);
        }
    }
}

void PegaOPrimeiro(ListaCadastral *L, int *X, bool *temElemento){
    if(Vazia(L)) *temElemento = false;
    else{
        *temElemento = true;
        *X = (L)->conteudo;
    }
}

void PegaOProximo(ListaCadastral *L, int *X, bool *temElemento){
    if(!EstaNaLista(L, *X)) *temElemento = false;
    else{
        ListaCadastral *p;
        p = L;
        while(p->conteudo != *X) p = p->next;
        if(p->next == NULL) *temElemento = false;
        else{
            *temElemento = true;
            *X = p->next->conteudo;
        }
    }
}
//Para usagem em c considerar o "elemento" como int.
int ItensCompradosErroneamente(ListaCadastral *carrinho, ListaCadastral *original){
    //Declarando variavies de apoio
    int items = 0;
    int x;
    bool ok;

    //Percorrendo o carrinho de compras
    PegaOPrimeiro(carrinho, &x, &ok);
    while(ok){
        //Marcando os itens que nao estao no carrinho original
        if(!EstaNaLista(original, x)) items++;
        //Selecionando o proximo
        PegaOProximo(carrinho, &x, &ok);
    }

    return items;
}

int NroPessoasVacinadasOuInfectadas(ListaCadastral *L1, ListaCadastral *L2){
    //Numero de elementos da uniao -> Contar numero da primeira lista sem filtros, e contar a segunda filtrando as ja contadas
    int pessoas = 0;
    int x;
    bool ok;
    //Contar todos os elementos da primeira lista
    PegaOPrimeiro(L1, &x, &ok);
    while(ok){
        //Incrementar pessoa
        pessoas++;
        //Pegar o proximo
        PegaOProximo(L1,&x, &ok);
    }

    //Agora percorrendo a lista 2
    PegaOPrimeiro(L2, &x, &ok);
    while(ok){
        //Apenas incrementar se x nao estiver presente na lista 1
        if(!EstaNaLista(L1,x)) pessoas++;
        PegaOProximo(L2, &x, &ok);
    }

    return pessoas;
}

int main(){

    ListaCadastral *original;
    ListaCadastral *carrinho;
    Cria(&original);
    Cria(&carrinho);
    bool ok;

    for(int i=-2; i<10; i++){
        Insere(&original, i, &ok);
    }

    for(int i=10; i<18; i++){
        Insere(&carrinho, i, &ok);
    }

    printf("%d\n", ItensCompradosErroneamente(original,carrinho));
    printf("%d\n", NroPessoasVacinadasOuInfectadas(original,carrinho));
    return 0;
}
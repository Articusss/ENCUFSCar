#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int info;
    struct Node* next;
};

typedef struct Node Node;

Node *criaLista(){
    return NULL;
}

bool vazia(Node*L){
    return L == NULL;
}

void insere(Node **L, int x){
    //Apenas inserir no inicio
    Node *novo;
    novo = (Node*) malloc(sizeof(Node));
    novo->info = x;
    novo->next = *L;
    *L = novo;
}

int pegaPrimeiro(Node *L){
    return L->info;
}

//Remove uma ocorrencia da lista
//Node **L -> ponteiro (ref) do ponteiro para o node (NodePtr)
//Como operacoes primitivas nao forem especificadas, operar apenas com baixo nivel
void Remove1(Node **L, int x, bool *ok){
    //Procurando o elemento na lista
    //Primeiro caso, lista vazia.
    if(*L == NULL){
        *ok = false;
    }
    //Segundo caso, elemento eh o primeiro da lista
    else if((*L)->info == x){
        *ok = true;
        Node* morta = *L;
        *L = morta->next;
        //Liberando
        free(morta);
        morta = NULL;
    }
    //Terceiro caso: procurar manualmente
    else{
        Node *atual = (*L)->next;
        Node *ant = *L;
        while(atual != NULL && atual->info != x){
            ant = atual;
            atual = atual->next;
        }
        //Nao encontrou
        if(atual == NULL) *ok = false;
        //Encontrou
        else{
            *ok = true;
            //Mexendo nos ponteiros
            ant->next = atual->next;
            free(atual);
            atual = NULL;
        }
    }
}

//Removendo todos os elementos x
void RemoveTodos(Node **L, int x, bool *ok){
    //Para portabilidade, usar a remove1 
    //Chamar uma vez fora do loop para setar ok original
    Remove1(L,x,ok);
    bool oktemp =true;
    //Rodar apenas se 1 numero for encontrado previamente
    while(*ok && oktemp){
        Remove1(L,x,&oktemp);
    }
}


void RemoveTodos2 (Node** L, int x, bool *ok){
    //Agora removendo todos
    //Caso vazia
    if(*L == NULL){
        *ok = false;
    }
    else{
        Node *morta;
        //Verificando o(s) primeiro(s) elemento(s)
        //Enquanto fila nao estiver vazia e o primeiro da fila for igual x, ir retirando
        while((*L) != NULL && (*L)->info == x){
            *ok = true;
            //Removendo
            morta = *L;
            *L = (*L)->next;
            free(morta);
            morta = NULL;
        }
        //Verifica novamente se a lista nao esta vazia, evitar segfault
        if(*L != NULL){
            //Agora que o primeiro elemento nao eh x, remover normalmente
            Node *atual = (*L)->next;
            Node *ant = (*L);
            //Percorrer ate o final da lista
            while(atual != NULL){
                if(atual->info == x){
                    *ok = true;
                    ant->next = atual->next;
                    morta = atual;
                    //avancar apenas o atual
                    atual = atual->next;
                    free(morta);
                    morta = NULL;
                } else{
                    //apenas avancar
                    ant = atual;
                    atual = atual->next;
                }
            }
        }
    }
}


int main(){
    Node* lista;
    bool ok;
    lista = criaLista();
    printf(vazia(lista) ? "True\n" : "False\n");
    for(int i = 0; i<5; i++){
        insere(&lista, 1);
        insere(&lista, 2);
        insere(&lista, 3);
    }
    printf(vazia(lista) ? "True\n" : "False\n");

    
    RemoveTodos(&lista,1, &ok);
    RemoveTodos(&lista,2, &ok);
    RemoveTodos(&lista,3, &ok);
    printf(vazia(lista) ? "FINAL True\n" : " FINAL False\n");

    for(int i = 0; i<5; i++){
        insere(&lista, 1);
        insere(&lista, 2);
        insere(&lista, 3);
    }

    printf(vazia(lista) ? "True\n" : "False\n");

    Remove1(&lista, 5, &ok);
    printf(ok ? "Trueok\n" : "Falseok\n");

    Remove1(&lista, 1, &ok);
    printf(ok ? "Trueok\n" : "Falseok\n");
    Remove1(&lista, 3, &ok);
    Remove1(&lista, 2, &ok);

    while(!vazia(lista)){
        printf("%d", pegaPrimeiro(lista));
        Remove1(&lista,pegaPrimeiro(lista), &ok);
    }
    printf(vazia(lista) ? "True\n" : "False\n");

    return 0;
}
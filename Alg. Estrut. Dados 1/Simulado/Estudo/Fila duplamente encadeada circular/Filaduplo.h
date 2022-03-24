#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef FILADUPLO_H
#define FILADUPLO_H

//Encadeamento duplo sem header

typedef struct Cell Cell;

Cell *criaFila();
void insere(Cell**, int);
int retira(Cell**);
bool vazia(Cell*);
void destroi(Cell**);

#endif
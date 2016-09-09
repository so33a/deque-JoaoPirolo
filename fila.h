#ifndef FILA_H
#define FILA_H

typedef struct node * link;
struct node {
  int item;
  link next;
};

typedef struct {
  link maisDireita;
  link maisEsquerda;
} * FILA;

link novoNo(int item, link next);
FILA novaFila();
void inseririnicio(FILA f, int e);
int removerinicio(FILA f);
void inserirfim(FILA f, int e);
int removerfim(FILA f);
void imprimirFila(FILA f);
void destroiFila(FILA f);
int filaVazia(FILA f); 

#endif 

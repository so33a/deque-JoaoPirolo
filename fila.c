#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


link novoNo(int item, link next) {
  link t = malloc(sizeof *t);
  if (t == NULL) {
    printf ("Erro no malloc \n");
    exit(-1);
  }
  t->item = item;
  t->next = next;
  return t;
}

FILA novaFila() {
  FILA f = malloc(sizeof *f);
  f->maisEsquerda = f->maisDireita = NULL;
  return f;
}

void inseririnicio(FILA f, int e) {
  if(f->maisDireita == NULL) {
    f->maisDireita = f->maisEsquerda = novoNo(e, NULL);
  } else {
    f->maisEsquerda->next = novoNo(e, NULL);
    f->maisEsquerda = f->maisEsquerda->next;
  }
}
void inserirfim(FILA f, int e) {
  if(f->maisDireita == NULL) {
    f->maisDireita = f->maisEsquerda = novoNo(e, NULL);
  } else {
    f->maisEsquerda->next = novoNo(e, NULL);
    f->maisEsquerda = f->maisEsquerda->next;
  }
}

int remover(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  
  x = f->maisDireita->item;
  t = f->maisDireita;
  f->maisDireita = f->maisDireita->next;
 
  if(f->maisDireita == NULL)
    f->maisEsquerda = NULL;

  free(t);
  return x;
}
int removerinicio(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  
  x = f->maisDireita->item;
  t = f->maisDireita;
  f->maisDireita = f->maisDireita->next;
 
  if(f->maisDireita == NULL)
    f->maisEsquerda = NULL;

  free(t);
  return x;
}
int filaVazia(FILA f) {
  return ((f->maisEsquerda == NULL) || (f->maisDireita == NULL));
}
void imprimirFila(FILA f) {
  link t;
  for(t = f->maisDireita; t != NULL; t = t->next) 
    printf ("%d ", t->item);
  printf ("\n");
}
void destroiFila(FILA f) {
  while (!filaVazia(f))
    remover(f);
  free(f);
}


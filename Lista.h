#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct nodo {
      int num;
      char* nome;
      struct nodo *prox;
} bloco, *pbloco; // bloco/nodo/elemento da lista

typedef struct lista {
      bloco *inicio;
      bloco *final;
      int dimensao;  
} *plista, **pplista; // descritor da lista

int listaVazia (plista l);
void criarLista (pplista l);
void inserirInicio (pplista l, int n, char* s);
void inserirFinal (pplista l, int n, char* s);
void inserirPosK (pplista l, int p, int n, char* s);
int removerInicio (pplista l);
int removerFinal (pplista l);
int removerPosK (pplista l, int p);
void imprimirLista (plista l);

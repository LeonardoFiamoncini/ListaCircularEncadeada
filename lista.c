#include "Lista.h"

int listaVazia (plista l) {

    return (l->dimensao == 0);
}

void criarLista (pplista l) {
    *l = (struct lista*)malloc(sizeof(struct lista)); 
    (*l)->inicio = NULL;
    (*l)->final = NULL;
    (*l)->dimensao = 0;
}

void inserirInicio (pplista l, int n, char* s) {

    pbloco b = (bloco *) malloc (sizeof(bloco));
    b->num = n;
    b->nome = s;

    if ((*l)->dimensao != 0) {
        b->prox = (*l)->inicio;
        (*l)->inicio = b;
        (*l)->final->prox = b;   
    }
    else {
        b->prox = b;
        (*l)->inicio = b;
        (*l)->final = b;
    }
    
    (*l)->dimensao+= 1;
}

void inserirFinal (pplista l, int n, char* s) {

    bloco *b = (bloco *)malloc(sizeof(bloco));
    b->num = n;
    b->nome = s;

    if ((*l)->dimensao != 0) {
        b->prox = (*l)->inicio;
        (*l)->final->prox = b;
        (*l)->final = b;
    }
    else {
        b->prox = b;
        (*l)->inicio = (*l)->final = b;
    }

    (*l)->dimensao++;
}

void inserirPosK (pplista l, int p, int n, char* s) {

    if ((*l)->dimensao > 0) {
        if (p == 1)
           inserirInicio(l, n, s);
        else {
            if (p > (*l)->dimensao)
               inserirFinal(l, n, s);
            else {
               int pos = 1;
               bloco *tmp = (*l)->inicio;
               bloco *ant = NULL;
               bloco *b = (bloco *)malloc(sizeof(bloco));

               b->num = n;
               b->nome = s;
               b->prox = NULL;

               while (pos < p) {
                 ant = tmp;
                 tmp = tmp->prox;
                 pos++;
               }
    
               ant->prox = b;
               b->prox = tmp;
               (*l)->dimensao++;
            }
        }
    }
    else
       inserirInicio(l, n, s);
}

int removerInicio (pplista l) {
    if ((*l)->dimensao > 0) {
        char* nome = (*l)->inicio->nome;
        int num = (*l)->inicio->num;
        bloco *tmp = (*l)->inicio;

        if ((*l)->inicio != (*l)->final) {
           (*l)->inicio = (*l)->inicio->prox;
           (*l)->final->prox = (*l)->inicio;
        }
        else
            (*l)->inicio = (*l)->final = NULL;

        free(tmp);
        (*l)->dimensao--;

        printf("\nSoldado %s foi removido.", nome);
        return num;
    }
}

int removerFinal (pplista l) {
    if ((*l)->dimensao > 0) {
        char* nome;
        int num;
    
        if ((*l)->dimensao == 1)
           num = removerInicio(l);
        else {
            bloco *tmp = (*l)->inicio;
            bloco *ant = NULL;

            while (tmp->prox != (*l)->inicio) {
                ant = tmp;
                tmp = tmp->prox;
            }

            ant->prox = (*l)->inicio;
            nome = tmp->nome;
            num = tmp->num;
            free(tmp);
            (*l)->dimensao--;
            printf("\nSoldado %s foi removido.", nome);
        }
        return num;
    }
}

int removerPosK (pplista l, int p) {

    if ((*l)->dimensao > 0) {
        char* nome;
        int num;
        if (p == 1)
           num = removerInicio(l);
        else {
            if (p > (*l)->dimensao)
               num = removerFinal(l);
            else {
                int pos = 1;
                bloco *tmp = (*l)->inicio;
                bloco *ant = NULL;

                while (pos < p) {
                    ant = tmp;
                    tmp = tmp->prox;
                    pos++;
                }
                nome = tmp->nome;
                num = tmp->num;
                ant->prox = tmp->prox;
                (*l)->dimensao--;
                free(tmp);
                printf("\nSoldado %s foi removido.", nome);
            }
        }
        return num;
    }
}

void imprimirLista (plista l) {
    if (l->dimensao > 0) {
        int i = 1;
        bloco *tmp = l->inicio;

        while (i <= l->dimensao) {
            printf ("\nNúmero: %d", tmp->num);
            printf ("\nNome: %s", tmp->nome);
            printf("\n");
            tmp = tmp->prox;
            i++;
        }
    }
}
#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0
typedef int bool;
typedef struct
{
    int chave;
} REGISTRO;

typedef struct aux
{
    REGISTRO reg;
    struct aux *ant, *prox;
} ELEMENTO;

typedef struct
{
    ELEMENTO *inicio;
} LISTA;
void inicializarLista(LISTA *l)
{
    l->inicio = NULL;
}
int nroElementos(LISTA l)
{
    int tam = 0;
    ELEMENTO *elem = l.inicio;
    while (elem != NULL)
    {
        tam++;
        elem = elem->prox;
    }
    return tam;
}
void exibeLista(LISTA l)
{
    ELEMENTO *elem = l.inicio;
    printf("LISTA:");
    while (elem != NULL)
    {
        printf("%d ", elem->reg.chave);
        elem = elem->prox;
    }
    printf("\n");
}
ELEMENTO *buscaSeqOrd(LISTA *l, int ch)
{
    ELEMENTO *pos = l->inicio;
    while (pos != NULL && pos->reg.chave < ch)
        pos = pos->prox;
    if (pos->reg.chave > ch || pos == NULL)
        return NULL;
    return pos;
}
ELEMENTO *buscaSeqExc(LISTA *l, int ch, ELEMENTO **ant)
{
    *ant = NULL;
    ELEMENTO *atual = l->inicio;
    while (atual != NULL && atual->reg.chave < ch)
    {
        *ant = atual;
        atual = atual->prox;
    }
    if (atual != NULL && atual->reg.chave == ch)
        return atual;
    return NULL;
}
bool inserirElemListaOrd(LISTA *l, int ch)
{
    ELEMENTO *ant, *i;
    i = buscaSeqExc(l, ch, &ant);
    if (i != NULL)
        return false;
    i = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    i->reg.chave = ch;
    if (ant == NULL)
    {
        i->ant = NULL;
        i->prox = l->inicio;
        l->inicio = i;
    }
    else
    {
        i->ant = ant;
        i->prox = ant->prox;
        ant->prox = i;
    }
    if (i->prox != NULL)
    {
        i->prox->ant = i;
    }
}
bool excluirElemListaOrd(LISTA *l, int ch)
{
    ELEMENTO *ant, *i;
    i = buscaSeqExc(l, ch, &ant);
    if (i == NULL)
        return false;
    if (ant == NULL)
        l->inicio = i->prox;
    else
    {
        if (i->prox != NULL)
            i->prox->ant = ant;
        ant->prox = i->prox;
    }
    free(i);
    return true;
}
int main()
{
    LISTA l;
    inicializarLista(&l);
    inserirElemListaOrd(&l, 90);
    inserirElemListaOrd(&l, 80);
    inserirElemListaOrd(&l, 70);
    inserirElemListaOrd(&l, 60);
    inserirElemListaOrd(&l, 100);
    exibeLista(l);
    excluirElemListaOrd(&l, 100);
    exibeLista(l);
    inserirElemListaOrd(&l, 110);
    exibeLista(l);
    printf("Nro Elementos: %d", nroElementos(l));
}
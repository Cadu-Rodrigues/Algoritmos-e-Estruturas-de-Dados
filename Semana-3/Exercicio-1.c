#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;
typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;
typedef struct
{
    REGISTRO registros[MAX + 1];
    int nroElem;
} LISTA;
void inicializarLISTA(LISTA *l)
{
    l->nroElem = 0;
}
void exibirLISTA(LISTA *l)
{
    int i;
    printf("LISTA:");
    for (i = 0; i < l->nroElem; i++)
        printf("%d ", l->registros[i]);
    printf("\n");
}
int buscaSequencial(LISTA l, int ch)
{
    int i = 0;
    for (i = 0; i < l.nroElem; i++)
    {
        if (l.registros[i].chave == ch)
            return i;
    }
    return -1;
}
void ordenar(LISTA *l)
{
    int i, j;
    REGISTRO temp;
    for (i = 0; i < l->nroElem - 1; i++)
    {
        for (j = i; j < l->nroElem; j++)
        {
            if (l->registros[i].chave > l->registros[j].chave)
            {
                temp = l->registros[i];
                l->registros[i] = l->registros[j];
                l->registros[j] = temp;
            }
        }
    }
}
bool inserir(LISTA *l, int i, TIPOCHAVE registro)
{
    int j;
    if (l->nroElem == MAX || i < 0 || i > l->nroElem)
        return false;
    for (j = l->nroElem; j > i; j++)
    {
        l->registros[j] = l->registros[j - 1];
    }
    l->registros[i].chave = registro;
    l->nroElem++;
    return true;
}
int main()
{
    LISTA l;
    LISTA *pont;
    pont = &l;
    inicializarLISTA(pont);
    exibirLISTA(pont);
    inserir(pont, 0, 90);
    inserir(pont, 1, 80);
    inserir(pont, 2, 70);
    inserir(pont, 3, 60);
    inserir(pont, 4, 900);
    ordenar(pont);
    exibirLISTA(pont);
}
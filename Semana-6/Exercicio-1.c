#include <stdio.h>
#include <malloc.h>
#define false 0
#define true 1
typedef int bool;
typedef struct aux
{
    int chave;
    struct aux *ant, *prox;

} ELEMENTO;

typedef struct
{
    ELEMENTO *cabeca;
} DEQUE;
void inicializarDeque(DEQUE *d)
{
    d->cabeca = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    d->cabeca->ant = d->cabeca;
    d->cabeca->prox = d->cabeca;
}
int nroElementos(DEQUE d)
{
    int tam = 0;
    ELEMENTO *elem = d.cabeca->prox;
    while (elem != d.cabeca)
    {
        tam++;
        elem = elem->prox;
    }
    return tam;
}
void exibirDequeInicio(DEQUE d)
{
    printf("DEQUE pelo inicio: ");
    ELEMENTO *elem = d.cabeca->prox;
    while (elem != d.cabeca)
    {
        printf("%d ", elem->chave);
        elem = elem->prox;
    }
    printf("\n");
}
void exibirDequeFim(DEQUE d)
{
    printf("DEQUE pelo fim: ");
    ELEMENTO *elem = d.cabeca->ant;
    while (elem != d.cabeca)
    {
        printf("%d ", elem->chave);
        elem = elem->ant;
    }
    printf("\n");
}
bool inserirInicio(DEQUE *d, int ch)
{
    ELEMENTO *elem = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    elem->chave = ch;
    elem->ant = d->cabeca;
    elem->prox = d->cabeca->prox;
    d->cabeca->prox = elem;
    elem->prox->ant = elem;
    return true;
}
bool inserirFim(DEQUE *d, int ch)
{
    ELEMENTO *elem = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    elem->chave = ch;
    elem->prox = d->cabeca;
    elem->ant = d->cabeca->ant;
    d->cabeca->ant = elem;
    elem->ant->prox = elem;
    return true;
}
bool encontrarMinMax(DEQUE *d, int *min, int *max)
{
    bool resposta = false;
    if (d->cabeca->ant != d->cabeca && d->cabeca->prox != d->cabeca)
    {
        *min = d->cabeca->prox->chave;
        *max = d->cabeca->prox->chave;
        ELEMENTO *elem = d->cabeca->prox;
        while (elem != d->cabeca)
        {
            if (elem->chave > *max)
                *max = elem->chave;
            if (elem->chave < *min)
                *min = elem->chave;
            elem = elem->prox;
        }
        resposta = true;
    }
    return resposta;
}
int main()
{
    DEQUE d;
    int max, min;
    bool resposta;
    inicializarDeque(&d);
    inserirFim(&d, 20);
    inserirInicio(&d, 4);
    inserirFim(&d, 30);
    inserirInicio(&d, 50);
    exibirDequeInicio(d);
    exibirDequeFim(d);
    resposta = encontrarMinMax(&d, &min, &max);
    printf("Min: %d,Max: %d\n", min, max);
    printf("Resposta: %d\n", resposta);
    printf("Quantidade de elementos: %d", nroElementos(d));
}
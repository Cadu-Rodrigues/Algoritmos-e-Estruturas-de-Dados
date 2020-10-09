#include <stdio.h>
#include <malloc.h>
#define false 0
#define true 1
typedef int bool;

typedef struct
{
    int chave;
} REGISTRO;

typedef struct aux
{
    REGISTRO reg;
    struct aux *prox;
} ELEMENTO;

typedef struct
{
    ELEMENTO *cabeca;
    ELEMENTO *fim;
} FILA;

void inicializarFila(FILA *f)
{
    f->cabeca = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    f->cabeca->prox = NULL;
    f->fim = NULL;
}
int tamanho(FILA f)
{
    int tam = 0;
    ELEMENTO *iterador = f.cabeca->prox;
    while (iterador != NULL)
    {
        tam++;
        iterador = iterador->prox;
    }
    return tam;
}
void exibirFila(FILA f)
{
    ELEMENTO *iterador = f.cabeca->prox;
    printf("Fila: ");
    while (iterador != NULL)
    {
        printf("%d ", iterador->reg.chave);
        iterador = iterador->prox;
    }
    printf("\n");
}
bool inserirNaFila(FILA *f, REGISTRO reg)
{
    ELEMENTO *elem = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    elem->prox = NULL;
    elem->reg = reg;
    if (f->cabeca->prox == NULL)
        f->cabeca->prox = elem;
    else
        f->fim->prox = elem;
    f->fim = elem;
    return true;
}
bool excluirDaFila(FILA *f, REGISTRO *reg)
{
    if (f->cabeca->prox == NULL)
        return false;
    ELEMENTO *exclui = f->cabeca->prox;
    *reg = exclui->reg;
    f->cabeca->prox = exclui->prox;
    free(exclui);
    if (f->cabeca->prox == NULL)
        f->fim = NULL;
    return true;
}
int main()
{
    FILA f;
    REGISTRO r[5] = {10, 20, 30, 40, 50};
    REGISTRO excluido;
    inicializarFila(&f);
    printf("Tamanho Fila: %d\n\n", tamanho(f));
    inserirFila(&f, r[0]);
    inserirFila(&f, r[1]);
    inserirFila(&f, r[2]);
    inserirFila(&f, r[3]);
    inserirFila(&f, r[4]);
    printf("Tamanho Fila: %d\n", tamanho(f));
    exibirFila(f);

    excluirFila(&f, &excluido);
    printf("Elemento excluido: %d\n", excluido.chave);
    printf("Tamanho Fila: %d\n", tamanho(f));
    exibirFila(f);
    printf("\n");

    excluirFila(&f, &excluido);
    printf("Elemento excluido: %d\n", excluido.chave);
    printf("Tamanho Fila: %d\n", tamanho(f));
    exibirFila(f);
    printf("\n");

    excluirFila(&f, &excluido);
    printf("Elemento excluido: %d\n", excluido.chave);
    printf("Tamanho Fila: %d\n", tamanho(f));
    exibirFila(f);
    printf("\n");

    excluirFila(&f, &excluido);
    printf("Elemento excluido: %d\n", excluido.chave);
    printf("Tamanho Fila: %d\n", tamanho(f));
    exibirFila(f);
    printf("\n");

    excluirFila(&f, &excluido);
    printf("Elemento excluido: %d\n", excluido.chave);
    printf("Tamanho Fila: %d\n", tamanho(f));
    exibirFila(f);
    printf("\n");
}

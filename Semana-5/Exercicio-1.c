#include <stdio.h>
#define MAX 50
#define false 0
#define true 1
typedef int bool;
typedef struct
{
    int chave;
} ELEMENTO;
typedef struct
{
    ELEMENTO A[MAX];
    int topo;
} PILHA;
void inicializarPilha(PILHA *p)
{
    p->topo = -1;
}
bool push(PILHA *p, int ch)
{
    if (p->topo > MAX - 1)
        return false;
    p->A[p->topo + 1].chave = ch;
    p->topo += 1;
    return true;
}
bool pop(PILHA *p)
{
    if (p->topo == -1)
        return false;
    p->topo = p->topo - 1;
}
void exibirPilha(PILHA p)
{
    printf("Pilha: \n");
    for (int i = p.topo; i >= 0; i--)
    {
        printf("%d ", p.A[i].chave);
    }
    printf("\n\n");
}
void exibirPilhaInvertida(PILHA p)
{
    printf("Pilha Invertida: \n");
    for (int i = 0; i < p.topo + 1; i++)
    {
        printf("%d ", p.A[i].chave);
    }
    printf("\n\n");
}
int main()
{
    PILHA p;
    inicializarPilha(&p);
    push(&p, 10);
    push(&p, 20);
    push(&p, 30);
    push(&p, 40);
    push(&p, 50);
    push(&p, 60);
    exibirPilha(p);
    exibirPilhaInvertida(p);
    pop(&p);
    exibirPilha(p);
    exibirPilhaInvertida(p);
}
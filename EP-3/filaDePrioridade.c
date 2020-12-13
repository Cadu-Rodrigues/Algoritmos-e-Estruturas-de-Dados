/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2020                           **/
/**   <turma> - Prof. Luciano Antonio Digiampietri                  **/
/**                                                                 **/
/**   EP3 - Fila de Prioridade (utilizando heap)                    **/
/**                                                                 **/
/**   <nome do(a) aluno(a)>                   <numero USP>          **/
/**                                                                 **/
/*********************************************************************/

#include "filaDePrioridade.h"

PFILA criarFila(int max)
{
  PFILA res = (PFILA)malloc(sizeof(FILADEPRIORIDADE));
  res->maxElementos = max;
  res->arranjo = (PONT *)malloc(sizeof(PONT) * max);
  res->heap = (PONT *)malloc(sizeof(PONT) * max);
  int i;
  for (i = 0; i < max; i++)
  {
    res->arranjo[i] = NULL;
    res->heap[i] = NULL;
  }
  res->elementosNoHeap = 0;
  return res;
}

void exibirLog(PFILA f)
{
  printf("Log [elementos: %i]\n", f->elementosNoHeap);
  PONT atual;
  int i;
  for (i = 0; i < f->elementosNoHeap; i++)
  {
    atual = f->heap[i];
    printf("[%i;%f;%i] ", atual->id, atual->prioridade, atual->posicao);
  }
  printf("\n\n");
}
bool elementoInseridoEm(FILADEPRIORIDADE fila, int id)
{
  int i;
  for (i = 0; i < fila.elementosNoHeap; i++)
  {
    if (id == fila.heap[i]->id)
      return true;
  }
  return false;
}
PONT elementoPorId(PFILA fila, int id)
{
  int i;
  for (i = 0; i < fila->elementosNoHeap; i++)
  {
    if (id == fila->heap[i]->id)
      return fila->heap[i];
  }
  return NULL;
}
void ajeitaHeap(PFILA A, int m, int i)
{
  int esq = 2 * i + 1;
  int dir = 2 * 1 + 2;
  int maior = i;
  if (A->heap[esq] && esq < m && A->heap[esq]->prioridade > A->heap[maior]->prioridade)
    maior = esq;
  if (A->heap[dir] && dir < m && A->heap[dir]->prioridade > A->heap[maior]->prioridade)
    maior = dir;
  if (maior != i)
  {
    PONT temp = (PONT)malloc(sizeof(ELEMENTO));
    int posI = A->heap[i]->posicao;
    int posM = A->heap[maior]->posicao;
    temp = A->heap[i];
    A->heap[i] = A->heap[maior];
    A->heap[maior] = temp;
    A->heap[i]->posicao = posI;
    A->heap[maior]->posicao = posM;
    ajeitaHeap(A, m, maior);
  }
}
int tamanho(PFILA f)
{
  int tam = 0;

  /* COMPLETAR */

  return tam;
}

bool inserirElemento(PFILA f, int id, float prioridade)
{
  int i;
  if (id < 0 || id >= f->maxElementos)
    return false;
  if (elementoInseridoEm(*f, id))
    return false;
  f->elementosNoHeap++;
  PONT novo = (PONT)malloc(sizeof(ELEMENTO));
  novo->id = id;
  novo->prioridade = prioridade;
  novo->posicao = f->elementosNoHeap - 1;
  f->arranjo[id] = &*novo;
  f->heap[f->elementosNoHeap - 1] = &*novo;
  for (i = f->elementosNoHeap / 2 - 1; i >= 0; i--)
  {
    ajeitaHeap(f, f->elementosNoHeap, i);
  }
  return true;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade)
{
  int i;
  if (id < 0 || id >= f->maxElementos)
    return false;
  if (!elementoInseridoEm(*f, id))
    return false;
  PONT elemento = elementoPorId(f, id);
  if (elemento->prioridade >= novaPrioridade)
    return false;
  elemento->prioridade = novaPrioridade;
  for (i = f->elementosNoHeap / 2 - 1; i >= 0; i--)
  {
    ajeitaHeap(f, f->elementosNoHeap, i);
  }
  return true;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade)
{
  bool res = false;

  /* COMPLETAR */

  return res;
}

PONT removerElemento(PFILA f)
{
  PONT res = NULL;

  /* COMPLETAR */

  return res;
}

bool consultarPrioridade(PFILA f, int id, float *resposta)
{
  bool res = false;

  /* COMPLETAR */

  return res;
}

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
void swap(PFILA A, int pos1, int pos2)
{
  PONT temp = (PONT)malloc(sizeof(ELEMENTO));
  int posI = A->heap[pos1]->posicao;
  int posM = A->heap[pos2]->posicao;
  temp = A->heap[pos1];
  A->heap[pos1] = A->heap[pos2];
  A->heap[pos2] = temp;
  A->heap[pos1]->posicao = posI;
  A->heap[pos2]->posicao = posM;
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
    swap(A, i, maior);
    ajeitaHeap(A, m, maior);
  }
}
int tamanho(PFILA f)
{
  int tam = 0;
  int i;
  for (i = 0; i < f->elementosNoHeap; i++)
  {
    tam++;
  }
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
  int i;
  if (id < 0 || id >= f->maxElementos)
    return false;
  if (!elementoInseridoEm(*f, id))
    return false;
  PONT elemento = elementoPorId(f, id);
  if (elemento->prioridade <= novaPrioridade)
    return false;
  elemento->prioridade = novaPrioridade;
  for (i = f->elementosNoHeap / 2 - 1; i >= 0; i--)
  {
    ajeitaHeap(f, f->elementosNoHeap, i);
  }
  return true;
}

PONT removerElemento(PFILA f)
{
  PONT res = NULL;
  int i;
  if (f->heap[0] == NULL)
    return NULL;
  int id = f->heap[0]->id;
  int idUltimo = f->heap[f->elementosNoHeap - 1]->id;
  PONT retirado = elementoPorId(f, id);
  PONT ultimoElemento = elementoPorId(f, idUltimo);
  f->arranjo[retirado->id] = ultimoElemento;
  f->heap[0] = ultimoElemento;
  f->arranjo[id] = NULL;
  f->heap[f->elementosNoHeap - 1] = NULL;
  f->elementosNoHeap--;
  res = retirado;
  for (i = f->elementosNoHeap / 2 - 1; i >= 0; i--)
  {
    ajeitaHeap(f, f->elementosNoHeap, i);
  }
  return res;
}

bool consultarPrioridade(PFILA f, int id, float *resposta)
{
  if (id < 0 || id >= f->maxElementos)
    return false;
  if (!elementoInseridoEm(*f, id))
    return false;
  PONT elemento = elementoPorId(f, id);
  *resposta = elemento->prioridade;
  return true;
}

/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2020                           **/
/**   <turma> - Prof. Luciano Antonio Digiampietri                  **/
/**                                                                 **/
/**   EP1 - Fila de Prioridade                                      **/
/**                                                                 **/
/**   Carlos Eduardo Rodrigues de Sousa                   11295758  **/
/**                                                                 **/
/*********************************************************************/

#include "filaDePrioridade.h"

PFILA criarFila(int max)
{
  PFILA res = (PFILA)malloc(sizeof(FILADEPRIORIDADE));
  res->maxElementos = max;
  res->arranjo = (PONT *)malloc(sizeof(PONT) * max);
  int i;
  for (i = 0; i < max; i++)
    res->arranjo[i] = NULL;
  PONT cabeca = (PONT)malloc(sizeof(ELEMENTO));
  res->fila = cabeca;
  cabeca->ant = cabeca;
  cabeca->prox = cabeca;
  cabeca->id = -1;
  cabeca->prioridade = 1000000;
  return res;
}

bool exibirLog(PFILA f)
{
  printf("Log [elementos: %i (alem do no cabeca)]\n", tamanho(f));
  PONT atual = f->fila;
  printf("%p[%i;%f;%p]%p ", atual->ant, atual->id, atual->prioridade, atual, atual->prox);
  atual = atual->prox;
  while (atual != f->fila)
  {
    printf("%p[%i;%f;%p]%p ", atual->ant, atual->id, atual->prioridade, atual, atual->prox);
    atual = atual->prox;
  }
  printf("\nElementos validos: ");
  atual = atual->prox;
  while (atual != f->fila)
  {
    printf("[%i;%f;%p] ", atual->id, atual->prioridade, atual);
    atual = atual->prox;
  }

  printf("\nValores do arranjo:\n\[ ");
  int x;
  for (x = 0; x < f->maxElementos; x++)
    printf("%p ", f->arranjo[x]);
  printf("]\n\n");
}
bool idEhValido(PFILA f, int id)
{
  return !((id < 0) || (id > f->maxElementos));
}
bool idExisteNaFila(PFILA f, int id)
{
  PONT iterador = f->fila->prox;
  while (iterador != f->fila)
  {
    if (iterador->id == id)
      return true;
    iterador = iterador->prox;
  }
  return false;
}
PONT elementoAnterior(PFILA f, int id, float prioridade)
{
  PONT iterador = f->fila->prox;
  PONT ant = f->fila;
  while (iterador != f->fila)
  {
    if (iterador->prioridade > prioridade)
      ant = iterador;
    iterador = iterador->prox;
  }
  return ant;
}
PONT retornaElemento(PFILA f, int id)
{
  if (idEhValido(f, id) && idExisteNaFila(f, id))
    return f->arranjo[id];
  else
    return NULL;
}
void reposicionaElemento(PONT ant, PONT elem)
{
  elem->prox->ant = elem->ant;
  elem->ant->prox = elem->prox;
  elem->prox = ant->prox;
  elem->ant = ant;
  ant->prox = elem;
  elem->prox->ant = elem;
}
int tamanho(PFILA f)
{

  PONT iterador = f->fila->prox;
  int tam = 0;
  while (iterador != f->fila)
  {
    tam++;
    iterador = iterador->prox;
  }
  return tam;
}

bool inserirElemento(PFILA f, int id, float prioridade)
{

  if (!idEhValido(f, id) || idExisteNaFila(f, id))
    return false;
  PONT ant = elementoAnterior(f, id, prioridade);
  PONT elem = (ELEMENTO *)malloc(sizeof(ELEMENTO));
  elem->id = id;
  elem->prioridade = prioridade;
  elem->prox = ant->prox;
  elem->ant = ant;
  ant->prox = elem;
  elem->prox->ant = elem;
  f->arranjo[id] = elem;
  return true;
}
bool aumentarPrioridade(PFILA f, int id, float novaPrioridade)
{
  if (!idEhValido(f, id) || !idExisteNaFila(f, id))
    return false;
  PONT elem = retornaElemento(f, id);
  if (elem->prioridade >= novaPrioridade)
    return false;
  elem->prioridade = novaPrioridade;
  PONT ant = elementoAnterior(f, id, novaPrioridade);
  if (ant != elem->ant)
    reposicionaElemento(ant, elem);
  return true;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade)
{
  if (!idEhValido(f, id) || !idExisteNaFila(f, id))
    return false;
  PONT elem = retornaElemento(f, id);
  if (elem->prioridade <= novaPrioridade)
    return false;
  elem->prioridade = novaPrioridade;
  PONT ant = elementoAnterior(f, id, novaPrioridade);
  if (ant != elem->ant)
    reposicionaElemento(ant, elem);
  return true;
}

PONT removerElemento(PFILA f)
{
  PONT resposta = NULL;

  /* COMPLETAR */

  return resposta;
}

bool consultarPrioridade(PFILA f, int id, float *resposta)
{
  bool resp = false;

  /* COMPLETAR */

  return resp;
}

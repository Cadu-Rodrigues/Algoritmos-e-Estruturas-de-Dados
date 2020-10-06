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
  bool resposta = false;

  /* COMPLETAR */

  return resposta;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade)
{
  bool resposta = false;

  /* COMPLETAR */

  return resposta;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade)
{
  bool resposta = false;

  /* COMPLETAR */

  return resposta;
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

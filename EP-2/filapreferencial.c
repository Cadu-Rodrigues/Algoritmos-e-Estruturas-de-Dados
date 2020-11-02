/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Seugndo Semestre de 2020                           **/
/**   <turma> - Prof. Luciano Antonio Digiampietri                  **/
/**                                                                 **/
/**   EP2 - Fila Preferencial                                       **/
/**                                                                 **/
/**   Carlos Eduardo Rodrigues de Sousa                  11295758   **/
/**                                                                 **/
/*********************************************************************/

#include "filapreferencial.h"

PFILA criarFila()
{
  PFILA res = (PFILA)malloc(sizeof(FILAPREFERENCIAL));
  res->inicioPref = NULL;
  res->fimPref = NULL;
  res->inicioGeral = NULL;
  res->fimGeral = NULL;
  return res;
}

int tamanho(PFILA f)
{
  PONT atual = f->inicioGeral;
  int tam = 0;
  while (atual)
  {
    atual = atual->prox;
    tam++;
  }
  return tam;
}

int tamanhoFilaPreferencial(PFILA f)
{
  PONT atual = f->inicioPref;
  int tam = 0;
  while (atual)
  {
    atual = atual->prox;
    tam++;
  }
  return tam;
}

PONT buscarID(PFILA f, int id)
{
  PONT atual = f->inicioGeral;
  while (atual)
  {
    if (atual->id == id)
      return atual;
    atual = atual->prox;
  }
  return NULL;
}

void exibirLog(PFILA f)
{
  int numElementos = tamanho(f);
  printf("\nLog fila geral [elementos: %i] - Inicio:", numElementos);
  PONT atual = f->inicioGeral;
  while (atual)
  {
    printf(" [%i;%i]", atual->id, atual->ehPreferencial);
    atual = atual->prox;
  }
  printf("\n");
  numElementos = tamanhoFilaPreferencial(f);
  printf("\nLog fila preferencial [elementos: %i] - Inicio:", numElementos);
  atual = f->inicioPref;
  while (atual)
  {
    printf(" [%i;%i]", atual->id, atual->ehPreferencial);
    atual = atual->prox;
  }
  printf("\n\n");
}
PONT alocaPonteiro(int id, int ehPreferencial)
{
  PONT novo = (PONT)malloc(sizeof(ELEMENTO));
  novo->ehPreferencial = ehPreferencial;
  novo->id = id;
  novo->prox = NULL;
  return novo;
}
bool inserirPessoaNaFila(PFILA f, int id, int ehPreferencial)
{
  bool resposta = false;
  /* COMPLETAR */
  if (id < 0 || (buscarID(f, id) != NULL))
    return false;

  PONT novo = alocaPonteiro(id, ehPreferencial);
  if (tamanho(f) == 0)
  {
    f->inicioGeral = novo;
    f->fimGeral = novo;
  }
  else
  {
    f->fimGeral->prox = novo;
    f->fimGeral = novo;
  }
  if (ehPreferencial)
  {
    PONT novoPreferencial = alocaPonteiro(id, ehPreferencial);
    if (f->inicioPref == NULL)
    {
      f->inicioPref = novoPreferencial;
      f->fimPref = novoPreferencial;
    }
    else
    {
      f->fimPref->prox = novoPreferencial;
      f->fimPref = novoPreferencial;
    }
  }
  return true;
}
void removerElemento(PFILA f, bool ehPreferencial)
{
  if (ehPreferencial)
  {
    f->inicioPref = f->inicioPref->prox;
    if (f->inicioPref == f->fimPref)
    {
      f->inicioPref = NULL;
      f->fimPref = NULL;
    }
  }
  else
  {
    f->inicioGeral = f->inicioGeral->prox;
    if (f->inicioGeral == f->fimGeral)
    {
      f->inicioGeral = NULL;
      f->fimGeral = NULL;
    }
  }
}
bool atenderPrimeiraDaFilaPreferencial(PFILA f, int *id)
{
  if (tamanho(f) == 0 || tamanhoFilaPreferencial(f) == 0)
    return false;
  *id = f->inicioPref->id;
  removerElemento(f, true);
  return true;
}

bool atenderPrimeiraDaFilaGeral(PFILA f, int *id)
{
  bool resposta = false;

  /* COMPLETAR */

  return resposta;
}

bool desistirDaFila(PFILA f, int id)
{
  bool resposta = false;

  /* COMPLETAR */

  return resposta;
}

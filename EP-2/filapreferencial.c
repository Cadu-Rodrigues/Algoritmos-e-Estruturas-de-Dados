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
bool filaPreferencialVazia(PFILA f)
{
  if (!f->inicioPref && !f->fimPref)
    return true;
  return false;
}
bool filaGeralVazia(PFILA f)
{
  if (!f->inicioGeral && !f->fimGeral)
    return true;
  return false;
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
void removerElementoPorIDFilaPreferencial(PFILA f, int id)
{
  PONT temp = f->inicioPref;
  PONT geral = buscarID(f, id);
  if (temp->id == geral->id)
  {
    if (temp == f->fimPref)
    {
      f->inicioPref = NULL;
      f->fimPref = NULL;
    }
    else
    {
      f->inicioPref = f->inicioPref->prox;
    }
    free(temp);
    return;
  }
  while (temp->id != geral->id)
  {
    temp = temp->prox;
  }
  temp->prox = geral->prox;
  free(temp);
}
void removerElementoPorIDFilaGeral(PFILA f, int id)
{
  PONT temp = f->inicioGeral;
  PONT excluido = buscarID(f, id);
  if (temp == excluido)
  {
    if (temp == f->fimGeral)
    {
      f->inicioGeral = NULL;
      f->fimGeral = NULL;
    }
    else
    {
      f->inicioGeral = f->inicioGeral->prox;
    }
    free(excluido);
    return;
  }
  while (temp->prox != excluido)
  {
    temp = temp->prox;
  }
  temp->prox = excluido->prox;
  free(excluido);
}
void removerPrimeiroElementoFilaGeral(PFILA f)
{
  if (f->inicioGeral)
  {
    PONT excluido = f->inicioGeral;
    f->inicioGeral = f->inicioGeral->prox;
    if (f->inicioGeral == NULL)
      f->fimGeral = NULL;
    free(excluido);
  }
}
void removerPrimeiroElementoFilaPreferencial(PFILA f)
{
  if (f->inicioPref)
  {
    PONT excluido = f->inicioPref;
    f->inicioPref = f->inicioPref->prox;
    if (f->inicioPref == NULL)
      f->fimPref = NULL;
    free(excluido);
  }
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
  if (filaGeralVazia(f))
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
bool atenderPrimeiraDaFilaPreferencial(PFILA f, int *id)
{
  if (filaGeralVazia(f) || filaPreferencialVazia(f))
    return false;
  if (filaPreferencialVazia(f) && !filaGeralVazia(f))
    *id = f->inicioGeral->id;
  else
    *id = f->inicioPref->id;
  removerPrimeiroElementoFilaPreferencial(f);
  removerElementoPorIDFilaGeral(f, *id);
  return true;
}

bool atenderPrimeiraDaFilaGeral(PFILA f, int *id)
{
  if (filaGeralVazia(f))
    return false;
  *id = f->inicioGeral->id;
  if (f->inicioGeral->ehPreferencial)
  {
    removerElementoPorIDFilaPreferencial(f, *id);
  }
  removerPrimeiroElementoFilaGeral(f);
  return true;
}

bool desistirDaFila(PFILA f, int id)
{
  PONT pessoa = buscarID(f, id);
  if (!pessoa)
    return false;
  if (pessoa->ehPreferencial)
    removerElementoPorIDFilaPreferencial(f, id);
  removerElementoPorIDFilaGeral(f, id);
  return true;
}

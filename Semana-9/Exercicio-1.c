#include <stdio.h>
#include <malloc.h>
typedef struct
{
    int linhas;
    int colunas;
    int **m;
} MATRIZ;

MATRIZ *inicializarMatriz(int linhas, int colunas)
{
    if (linhas <= 0 || colunas <= 0)
        return NULL;
    int i;
    MATRIZ *mat = (MATRIZ *)malloc(sizeof(MATRIZ));
    mat->linhas = linhas;
    mat->colunas = colunas;
    mat->m = (int **)malloc(sizeof(int *) * linhas);
    for (i = 0; i < linhas; i++)
    {
        mat->m[i] = (int *)malloc(sizeof(int) * colunas);
    }
    return mat;
}
void imprimirMatriz(MATRIZ *mat)
{
    int i, j;
    for (i = 0; i < mat->linhas; i++)
    {
        for (j = 0; j < mat->colunas; j++)
            printf("%d ", mat->m[i][j]);
        printf("\n");
    }
    printf("\n");
}
MATRIZ *multiplicarMatrizes(MATRIZ *m1, MATRIZ *m2)
{
    if (m1->colunas != m2->linhas)
        return NULL;
    MATRIZ *res = inicializarMatriz(m1->linhas, m2->colunas);
    int i, j, k;
    int valor; /* COMPLETAR */
    for (i = 0; i < m1->linhas; i++)
    {
        for (j = 0; j < m2->colunas; j++)
        {
            valor = 0;
            for (k = 0; k < m1->linhas; k++)
                valor += m1->m[i][k] * m2->m[k][j];
            res->m[i][j] = valor;
        }
    }
    return res;
}
int main()
{
    MATRIZ *m1 = inicializarMatriz(3, 3);
    int i, j;
    int cont = 1;
    for (i = 0; i < m1->linhas; i++)
        for (j = 0; j < m1->colunas; j++)
        {
            m1->m[i][j] = cont;
            cont++;
        }

    imprimirMatriz(m1);

    MATRIZ *m2 = inicializarMatriz(3, 3);
    for (i = 0; i < m2->linhas; i++)
        for (j = 0; j < m2->colunas; j++)
        {
            m2->m[i][j] = cont;
            cont++;
        }

    imprimirMatriz(m2);

    MATRIZ *m3 = multiplicarMatrizes(m1, m2);

    imprimirMatriz(m3);
    printf("\n");
    return 0;
}
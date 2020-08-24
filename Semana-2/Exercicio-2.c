#include <stdlib.h>
#include <stdio.h>
typedef struct aux{
    int id;
    struct aux* mae;
    struct aux* pai;
}PESSOA;
PESSOA* inicializar(int id){
    PESSOA* p = (PESSOA*) malloc(sizeof(PESSOA));
    p->id = id;
    p->mae = NULL;
    p->pai = NULL;
    return p;
}
int main(){
    PESSOA* outra = inicializar(60);
    printf("%i",outra->id);
}
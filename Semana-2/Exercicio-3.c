#include <stdlib.h>
#include <stdio.h>
typedef struct aux{
    int id;
    struct aux* mae;
    struct aux* pai;
}PESSOA;
void registrar(PESSOA* filho,PESSOA* mae,PESSOA* pai){
    filho->mae = mae;
    filho->pai = pai;
}
void imprimir(PESSOA p){
    if(p.mae != NULL && p.pai != NULL)
    printf("id:%i mae.id:%i pai.id:%i",p.id,p.mae->id,p.pai->id);
}
int main(){
    PESSOA pai;
    PESSOA mae;
    PESSOA filho;
    mae.id = 10;
    pai.id = 20;
    filho.id = 30;
    registrar(&filho,&mae,&pai);
    imprimir(filho);
}
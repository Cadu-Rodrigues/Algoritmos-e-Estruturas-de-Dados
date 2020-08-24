#include <stdio.h>
typedef struct aux{
    int id;
    struct aux* mae;
    struct aux* pai;
}PESSOA;
void imprimir(PESSOA p){
    if(p.mae != NULL && p.pai != NULL)
    printf("id:%i mae.id:%i pai.id:%i",p.id,p.mae->id,p.pai->id);
}
int main(){
    PESSOA eu;
    PESSOA mae;
    PESSOA pai;
    PESSOA outra;
    mae.id = 60;
    pai.id = 70;
    eu.id = 50;
    eu.mae = &mae;
    eu.pai = &pai;
    imprimir(eu);
}
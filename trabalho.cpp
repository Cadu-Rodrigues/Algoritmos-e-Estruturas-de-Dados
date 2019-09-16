    //ler a frase completa como vetor de caracteres
    //percorrer o vetor de caracteres
    //se for um caractere insere na lista
    //se for um numero
        //se estiver no fim da lista adiciona o numero na lista
        //senao adiciona o proximo caractere o numero correspondente de vezes na lista
    //decodificar a frase
#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct estrutura{
    char chave;
    struct estrutura *prox;
} NO;
typedef struct{
    NO* inicio;
} LISTA;
bool isNumber(char caractere){
    switch((int)caractere){
        case 49:
        return true;
        case 50:
        return true;
        case 51:
        return true;
        case 52:
        return true;
        case 53:
        return true;
        case 54:
        return true;
        case 55:
        return true;
        case 56:
        return true;
        case 57:
        return true;
        case 48:
        return true;
        default:
        return false;
    }
}
int tamanho(LISTA* l){
    int tam = 0;
    NO* end = l->inicio;
    while(end != NULL){
        tam++;
        end = end->prox;
    }
    return tam;
}
void exibeLista(LISTA l){
    NO* end = l.inicio;
    printf("Lista: \" ");
    while(end){
        printf("%c", end->chave);
        end = end ->prox;
    }
    printf("\"\n");
}
NO* ultimoElementoLista(LISTA* l) {
    NO* elemento = l->inicio;
    if(elemento){
        while(elemento->prox){
            elemento = elemento->prox;
        }
    }
    return(elemento);
}
void insereElemento(LISTA* l, char ch){
    NO* novo;
    NO* ant;
    ant = ultimoElementoLista(l);
    novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;
    if(!ant){
        l->inicio = novo;
    }else{
        ant->prox = novo;
    }
}
NO* decodificar (char* frase, LISTA* l){
    for(int i=0;i<strlen(frase);i++){
        if(isNumber(frase[i])){
            if(i==strlen(frase)-1){
                insereElemento(l,frase[i]);
            }
            int j = frase[i] - '0';
            for(int k=0;k<j;k++){
                insereElemento(l,frase[i+1]);
            }
            i++;
        }else{
            insereElemento(l,frase[i]);
        }
    }
    return l->inicio;
}
void inicializarLista(LISTA* l){
    l->inicio = NULL;
}
int main(){
    LISTA l;
    LISTA* pont;
    pont = &l;
    inicializarLista(pont);
    char frase[100] = "Li 12 vezes mas não entendi n4ada5! Vou tirar 0010.";
    decodificar(frase,pont);
}

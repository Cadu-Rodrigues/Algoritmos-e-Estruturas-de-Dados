    //ler a frase completa como vetor de caracteres
    //percorrer o vetor de caracteres
    //se for um caractere insere na lista
    //se for um numero
        //se estiver no fim da lista adiciona o numero na lista
        //senao adiciona o proximo caractere o numero correspondente de vezes na lista
    //decodificar a frase
#include <stdio.h>
#include <string.h>
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
void decodificar (char frase[]){
    char fraseDecod[100];
    for(int i=0;i<strlen(frase);i++){
        if(isNumber(frase[i])){
            if(i==strlen(frase)-1){
                printf("%c",frase[i]);
            }
            int j = frase[i] - '0';
            for(int k=0;k<j;k++){
                printf("%c",frase[i+1]);
            }
            i++;
        }else{
            printf("%c",frase[i]);
        }
    }
}
int main(){
    char frase[100] = "Li 12 vezes mas não entendi n4ada5! Vou tirar 0010.";
    decodificar(frase);
}

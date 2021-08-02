#include <stdio.h>

int main(){
    char teclado[49];
    int tamanho;

    for(int i = 0; i < 49; i++){
        scanf(" %c", &teclado[i]);
    }

    scanf(" %d", &tamanho);
    int mensagem[tamanho];

    for(int i = 0; i < tamanho; i++){
        scanf(" %d", &mensagem[i]);
    }

    for(int j = 0; j < tamanho; j++){
        if(teclado[mensagem[j]] == '_'){
            printf(" ");
        }
        else if(teclado[mensagem[j]] == 'E'){
            printf("\n");
        }
        else{
            printf("%c", teclado[mensagem[j]]);
        }
        
    }

    return 0;
}
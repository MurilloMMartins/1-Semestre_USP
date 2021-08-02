#include <stdio.h>
#include <string.h>

int main(){
    int linhas = 0, palavras = 0, caracteres = 0;
    char texto, anterior = ' ';
    while(scanf("%c", &texto) != EOF){
        int novaLinha = 0;
        if(texto != ' ' && texto != '\n' && texto != '\t' && texto != '\r'){
            novaLinha = 1;
        }
        if(texto == '\n'){
            linhas++;
        }
        else if(texto != '\n' && texto != '\r' && texto != '\t' && texto != ' ' && anterior == ' '){
            palavras++;
        }
        else if((anterior == '\n' && novaLinha == 1) || (anterior == '\t' && novaLinha == 1) || (anterior == '\r' && novaLinha == 1)){
            palavras++;
        }
        caracteres++;
        anterior = texto;
        novaLinha = 0;
    }

    printf("Linhas\tPalav.\tCarac.\n");
    printf("%d\t%d\t%d", linhas, palavras, caracteres);

    

    return 0;
}
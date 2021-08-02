#include <stdio.h>
#include <string.h>

int main(){
    char texto[100];
    char caracteres;
    char palavrasProibidas[12][10] = {"gratuito", "atencao", "urgente", "imediato", "zoombie", "oferta", "dinheiro", "renda", "fundo", "limitado", "ajuda" , "SOS"};
    int contChar = 0;
    int contSpam = 0;
    int posStr = 0;

    while(scanf("%c", &caracteres) != EOF){

        switch(caracteres){
            case ' ':
                contChar += posStr + 1;
                posStr = 0;
                strcpy(texto, "");
                break;
            case '\n':
                contChar += posStr;
                if(contChar >= 77){
                    printf("Spam");
                    return 0;
                }
                contChar = 0;
                posStr = 0;
                strcpy(texto, "");
                break;
            default:
                texto[posStr] = caracteres;
                texto[posStr+1] = '\0';
                posStr++;
                break;
        }
        

        for(int i = 0; i < 12; i++){
            if(!(strcmp(palavrasProibidas[i], texto))){
                contSpam++;
            }
        }
        if(contSpam > 1){
            printf("Spam");
            return 0;
        }

        
        
    }

    printf("Inbox");
    
    return 0;
}
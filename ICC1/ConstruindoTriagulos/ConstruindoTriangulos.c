#include <stdio.h>

int main(){
    //declarando variáveis
    int altura = 0;
    char simbolo;

    // definindo um char como espaço para ser repetido
    char espaco = ' ';

    //pegando o input do usuário
    scanf(" %i",&altura);
    scanf(" %c", &simbolo);

    //vendo se 0 < altura <=25, caso seja ele executa a função do programa caso contrário ele imprime "Altura inválida"
    if(altura < 0){
        printf("Altura invalida\n");
    }
    else if(altura <= 25 && altura != 0){
        //estabelecendo um for para controlar as repetições nas linhas
        for(int i = 0; i < altura; i++){
            //esse for serve para imprimir os espaços necessário para a formação do triângulo
            for(int j = 1; j < altura-i; j++){
                printf("%c", espaco);
            }
            //esse for serve para imprimir os caracteres necessários, a variavel k precisa ser <= 2*i pois assim construirá uma piramide completa e o pico dela terá somente um carácter
            for(int k = 0; k <= 2*i; k++){
                printf("%c", simbolo);
            }
            //print para pular linha
            printf("\n");
        }
    }
    else{
        printf("Altura invalida\n");
    }
    

    //famoso return 0 (⌐■_■)
    return 0;
}
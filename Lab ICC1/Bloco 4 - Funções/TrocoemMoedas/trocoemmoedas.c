#include <stdio.h>

void trocoMoedas(int troco, int *real1, int *cent50, int *cent25, int *cent10, int *cent5, int *cent1){
    *real1 = troco/100;
    troco = troco - (*real1*100);
    *cent50 = troco/50;
    troco = troco - (*cent50*50);
    *cent25 = troco/25;
    troco = troco - (*cent25*25);
    *cent10 = troco/10;
    troco = troco - (*cent10*10);
    *cent5 = troco/5;
    troco = troco - (*cent5*5);
    *cent1 = troco;
}

int main(){
    int real1, cent50, cent25, cent10, cent5, cent1;
    int entrada;

    scanf(" %d", &entrada);
    trocoMoedas(entrada, &real1, &cent50, &cent25, &cent10, &cent5, &cent1);

    printf("O valor consiste em %d moedas de 1 real\n", real1);
    printf("O valor consiste em %d moedas de 50 centavos\n", cent50);
    printf("O valor consiste em %d moedas de 25 centavos\n", cent25);
    printf("O valor consiste em %d moedas de 10 centavos\n", cent10);
    printf("O valor consiste em %d moedas de 5 centavos\n", cent5);
    printf("O valor consiste em %d moedas de 1 centavo\n", cent1);

    return 0;
}
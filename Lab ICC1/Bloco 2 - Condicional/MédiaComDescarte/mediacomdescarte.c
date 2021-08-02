#include <stdio.h>

int main(){
    double valores[4], menor = 100000;
    for(int i = 0; i < 4; i++){
        scanf("%lf", &valores[i]);
        if(valores[i] < menor){
            menor = valores[i];
        }
    }

    printf("%.4lf\n", ((valores[0]+valores[1]+valores[2]+valores[3])-menor)/3);
}
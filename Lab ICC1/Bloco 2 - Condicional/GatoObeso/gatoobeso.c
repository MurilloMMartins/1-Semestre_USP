#include <stdio.h>

int main(){
    int peso = 0, brincou, mordidas;
    scanf("%d %d", &brincou, &mordidas);
    peso = (brincou*5) - (mordidas*3);
    if(peso >= 30){
        printf("P");
    }
    else if(peso < 0){
        printf("R");
    }
    else{
        printf("B");
    }
}
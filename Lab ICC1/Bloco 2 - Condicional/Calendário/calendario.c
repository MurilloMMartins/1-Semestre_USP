#include <stdio.h>

int main(){
    int dia;
    scanf("%d", &dia);

    printf("         Abril 2021         \n");
    printf(" Do  Se  Te  Qu  Qu  Se  Sa \n");
    printf("                ");
    for(int i = 1; i < 31; i++){
        if(i == dia){
            printf("(%2d)", i);
            if(i % 7 == 3){
                printf("\n");
            }
        }
        else{
            printf(" %2d ", i);
            if(i % 7 == 3){
                printf("\n");
            }
        }
        
    }

    return 0;
}
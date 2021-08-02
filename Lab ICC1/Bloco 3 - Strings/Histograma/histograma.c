#include <stdio.h>

int main(){
    int imagem;
    int cont0 = 0, cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0;
    int vet0[25], vet1[25], vet2[25], vet3[25], vet4[25];
    for(int i = 0; i < 25; i++){
        scanf(" %d", &imagem);
        switch(imagem){
            case 0:
                vet0[cont0] = i;
                cont0++;
                break;
            case 1:
                vet1[cont1] = i;
                cont1++;
                break;
            case 2:
                vet2[cont2] = i;
                cont2++;
                break;
            case 3:
                vet3[cont3] = i;
                cont3++;
                break;
            case 4:
                vet4[cont4] = i;
                cont4++;
                break;
        }
            
    }

    printf("0: |");
    for(int i = 0; i < cont0; i++){
        printf("#");
    }
    printf("\n");

    printf("1: |");
    for(int i = 0; i < cont1; i++){
        printf("#");
    }
    printf("\n");
    
    printf("2: |");
    for(int i = 0; i < cont2; i++){
        printf("#");
    }
    printf("\n");
    
    printf("3: |");
    for(int i = 0; i < cont3; i++){
        printf("#");
    }
    printf("\n");

    printf("4: |");
    for(int i = 0; i < cont4; i++){
        printf("#");
    }
    printf("\n");

    if(cont0 > cont1 && cont0 > cont2 && cont0 > cont3 && cont0 > cont4){
        for(int i = 0; i < cont0; i++){
            printf("%d\n", vet0[i]);
        }
    }
    else if(cont1 > cont0 && cont1 > cont2 && cont1 > cont3 && cont1 > cont4){
        for(int i = 0; i < cont1; i++){
            printf("%d\n", vet1[i]);
        }
    }
    else if(cont2 > cont0 && cont2 > cont1 && cont2 > cont3 && cont2 > cont4){
        for(int i = 0; i < cont2; i++){
            printf("%d\n", vet2[i]);
        }
    }
    else if(cont3 > cont0 && cont3 > cont2 && cont3 > cont1 && cont3 > cont4){
        for(int i = 0; i < cont3; i++){
            printf("%d\n", vet3[i]);
        }
    }
    else{
        for(int i = 0; i < cont4; i++){
            printf("%d\n", vet4[i]);
        }
    }

    return 0;
}
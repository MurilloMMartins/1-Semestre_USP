#include <stdio.h>
#include <stdlib.h>

int main(){
    //declaração de variáveis
    int La, Ca, Lb, Cb, S, elemento = 0;

    //input do usuário
    scanf("%d %d", &La, &Ca);
    scanf("%d %d", &Lb, &Cb);
    

    

    
    

    //estrutura condicional para o funcionamento do algoritmo
    if(Ca == Lb && La > 0 && Ca > 0 && Lb > 0 && Cb > 0){
        //formação das matrizes, sendo R a matriz do resultado final
        int A[La][Ca];
        int B[Lb][Cb];
        int R[La][Cb];
        //pegando o input para criar a semente da função rand
        scanf("%d", &S);
        srand(S);

        //preenchendo as matrizes
        for(int i = 0; i < La; i++){
            for(int j = 0; j < Ca; j++){
                A[i][j] = rand()%50 - 25;
            }
        }
        for(int i = 0; i < Lb; i++){
            for(int j = 0; j < Cb; j++){
                B[i][j] = rand()%50 - 25;
            }
        }

        //calculo da multiplicação entre A e B
        for(int i = 0; i < La; i++){
            for(int k = 0; k < Cb; k++){

                for(int j = 0; j < Ca; j++){
                    elemento += A[i][j] * B[j][k];
                }

                R[i][k] = elemento;
                elemento = 0;
            }
            
        }

        //imprimindo os valores da matriz R
        for(int i = 0; i < La; i++){
            printf("Linha %d:", i);
            for(int j = 0; j < Cb; j++){
                printf(" %d", R[i][j]);
            }
            printf("\n");
        }
    }
    else{
        //caso o usuário dê valores inválidos, ele receberá essa mensagem
        printf("Valores invalidos para a multiplicacao.\n");
    }

    //famoso return 0 (⌐■_■)
    return 0;
}
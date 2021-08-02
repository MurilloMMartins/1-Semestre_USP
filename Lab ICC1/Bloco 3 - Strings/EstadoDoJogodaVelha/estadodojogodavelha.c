#include <stdio.h>

int main(){
    char jogo[3][3];
    int empate = 1, terminou = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf(" %c", &jogo[i][j]);
            if(jogo[i][j] == '-')
                empate = 0;
        }
    }

    if((jogo[0][0] == 'x' && jogo[1][1] == 'x' && jogo[2][2] == 'x') || (jogo[0][2] == 'x' && jogo[1][1] == 'x' && jogo[2][0] == 'x')){
        printf("x ganhou\n");
        terminou = 1;
    }

    if((jogo[0][0] == 'o' && jogo[1][1] == 'o' && jogo[2][2] == 'o') || (jogo[0][2] == 'o' && jogo[1][1] == 'o' && jogo[2][0] == 'o')){
        printf("o ganhou\n");
        terminou = 1;
    }

    for(int i = 0; i < 3; i++){
        if(jogo[i][0] == 'x' && jogo[i][1] == 'x' &&jogo[i][2] == 'x'){
            printf("x ganhou\n");
            terminou = 1;
        }
        else if(jogo[i][0] == 'o' && jogo[i][1] == 'o' &&jogo[i][2] == 'o'){
            printf("o ganhou\n");
            terminou = 1;
        }
    }

    for(int j = 0; j < 3; j++){
        if(jogo[0][j] == 'x' && jogo[1][j] == 'x' && jogo[2][j] == 'x'){
            printf("x ganhou\n");
            terminou = 1;
        }
        else if(jogo[0][j] == 'o' && jogo[1][j] == 'o' && jogo[2][j] == 'o'){
            printf("o ganhou\n");
            terminou = 1;
        }
    }

    if(terminou == 0 && empate == 1){
        printf("empate\n");
    }
    else if(terminou == 0 && empate == 0){
        printf("em jogo\n");
    }
    
    return 0;
}
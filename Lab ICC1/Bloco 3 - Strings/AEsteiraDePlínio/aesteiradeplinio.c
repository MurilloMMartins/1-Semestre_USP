#include <stdio.h>

int main(){
    char fabrica[32][65];
    int comecox, comecoy;

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 65; j++){
            scanf("%c", &fabrica[i][j]);
        }
    }

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 65; j++){
            if(fabrica[i][j] == '['){
                comecoy = i;
                comecox = j;
            }
        }
    }

    int x = (comecox+2), y = comecoy;
    char anterior;
    char leitura = '[';

    int parar = 1;

    while(parar != 0){
        leitura = fabrica[y][x];
        switch(leitura){
            case '>':
                fabrica[y][x] = '.';
                x = x+2;
                anterior = leitura;
                break;
            case '<':
                fabrica[y][x] = '.';
                x = x-2;
                anterior = leitura;
                break;
            case '^':
                fabrica[y][x] = '.';
                y = y-1;
                anterior = leitura;
                break;
            case 'v':
                fabrica[y][x] = '.';
                y = y+1;
                anterior = leitura;
                break;
            case '#':
                switch(anterior){
                    case '>':
                    x = x+2;
                    break;
                case '<':
                    x = x-2;
                    break;
                case '^':
                    y = y-1;
                    break;
                case 'v':
                    y = y+1;
                    break;
                    }
                break;
            case ']':
                parar = 0;
                printf("Ok.\n");
                break;
            case '.':
                parar = 0;
                printf("Loop infinito.\n");
                break;
            case ' ':
                parar = 0;
                printf("Falha na esteira.\n");
                break;
        }
    }
    
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 65; j++){
            printf("%c", fabrica[i][j]);
        }
    }

    return 0;
}
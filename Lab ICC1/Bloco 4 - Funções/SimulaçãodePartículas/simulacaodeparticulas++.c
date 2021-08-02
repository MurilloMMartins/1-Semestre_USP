#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//defines para facilitar na leitura do código
#define AREIA '#'
#define AGUA '~'
#define CIMENTO '@'
#define AR ' '

/* msleep(): Sleep for the requested number of milliseconds. */
void msleep(long msec){
    struct timespec ts;

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    nanosleep(&ts, &ts);
}

void imprimirMatriz(char matriz[32][64]){
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 64; j++){
            switch(matriz[i][j]){
                case AREIA:
                    printf("\x1b[93m%c", matriz[i][j]);
                    break;
                case AGUA:
                    printf("\x1b[36m%c", matriz[i][j]);
                    break;
                case CIMENTO:
                    printf("\x1b[90m%c", matriz[i][j]);
                    break;
                default:
                    printf("\x1b[0m%c", matriz[i][j]);
                    break;

            }
        }
        printf("\n");
    }
}

//função para copiar os conteudos de uma matriz para outra
void copiarMatriz(char matrizOriginal[32][64], char matrizCopia[32][64]){
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 64; j++){
            matrizCopia[i][j] = matrizOriginal[i][j];
        }
    }
}

void calcularFisica(char matriz[32][64]){
    char matrizCopia[32][64];
    //é criado uma matriz de cópia para fazer as alterações da simulação sem influenciar a matriz principal
    //isso é necessário se não ele simularia uma particula mais de uma vez em um frame
    copiarMatriz(matriz, matrizCopia);

    //for para percorrer a matriz
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 64; j++){
            //essa variavel salva o char do matrizCopia, evitando que certas partículas sumam magicamente
            char tmp = matrizCopia[i][j];

            //identificar qual particula é, só é necessário fazer isso para a AREIA e a AGUA pois o resto não se move
            switch(matriz[i][j]){
                case AREIA:
                    //os parametros i e j estão presentes nos ifs para evitar que haja a manipulação de valores fora da matriz
                    if(i != 31 && (matriz[i+1][j] == AR || matriz[i+1][j] == AGUA)){
                        matrizCopia[i][j] = matrizCopia[i+1][j];
                        matrizCopia[i+1][j] = tmp;
                    }
                    else if(i != 31 && j != 0 && (matriz[i+1][j-1] == AR || matriz[i+1][j-1] == AGUA)){
                        matrizCopia[i][j] = matrizCopia[i+1][j-1];
                        matrizCopia[i+1][j-1] = tmp;
                        }
                    else if(i != 31 && j != 63 && (matriz[i+1][j+1] == AR || matriz[i+1][j+1] == AGUA)){
                        matrizCopia[i][j] = matrizCopia[i+1][j+1];
                        matrizCopia[i+1][j+1] = tmp;
                    }
                    break;
                
                case AGUA:
                    if(i != 31 && matriz[i+1][j] == AR){
                        matrizCopia[i][j] = matrizCopia[i+1][j];
                        matrizCopia[i+1][j] = tmp;
                    }
                    else if(i != 31 && j != 0 && matriz[i+1][j-1] == AR){
                        matrizCopia[i][j] = matrizCopia[i+1][j-1];
                        matrizCopia[i+1][j-1] = tmp;
                    }
                    else if(i != 31 && j != 63 && matriz[i+1][j+1] == AR){
                        matrizCopia[i][j] = matrizCopia[i+1][j+1];
                        matrizCopia[i+1][j+1] = tmp;
                    }
                    else if(j != 0 && matriz[i][j-1] == AR){
                        matrizCopia[i][j] = matrizCopia[i][j-1];
                        matrizCopia[i][j-1] = tmp;
                    }
                    else if(j != 63 && matriz[i][j+1] == AR){
                        matrizCopia[i][j] = matrizCopia[i][j+1];
                        matrizCopia[i][j+1] = tmp;
                    }
                    break;

                default:
                    break;
            }
        }
    }

    //copiar a matriz simulada para a matriz principal
    copiarMatriz(matrizCopia, matriz);

}

int main(){
    char matriz[32][64];

    //preenchimento da matriz principal com ar, assim inicializando todos os valores e evitando que haja lixo de memória
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 64; j++){
            matriz[i][j] = AR;
        }
    }

    int framesTotal, frame, x, y;
    char particulaNova;

    scanf("%d", &framesTotal);
    
    int contador = 0;
    while(contador < framesTotal){

        //o "leitura" é feito para saber quando aparece o EOF(ou seja, quando as instruções param)
        int leitura = scanf(" %d: %d %d %c", &frame, &x, &y, &particulaNova);

        //se achar o EOF, ele só vai simular as particulas que já estão disponiveis até o ultimo frame
        if(leitura == EOF){
            frame = framesTotal;
        }

        //onde ocorre a impressão e simulação dos frames, o frame nesse caso simboliza duas coisas:
        //ou o frame onde acaba a simulação
        //ou o frame em que uma nova particula sera adicionada
        while(contador < frame){
            printf("frame: %d\n", contador+1);
            imprimirMatriz(matriz);
            calcularFisica(matriz);
            contador++;
            msleep(125);
            system("clear");
        }

        //se não achar EOF, ele pega adiciona uma nova particula
        if(leitura != EOF){
            matriz[y][x] = particulaNova;
        }

    }

    printf("\x1b[0m");
    
    return 0;
}
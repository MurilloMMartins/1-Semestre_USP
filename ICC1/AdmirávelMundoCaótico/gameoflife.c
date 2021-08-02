#include <stdio.h>
#include <stdlib.h>

#define VIVA 'x'
#define MORTA '.'

typedef struct{
    int linhas;
    int colunas;
    char modo;
    char **matriz;
}GameofLife;

//função para preencher a matriz com as condições iniciais do jogo, é usado o *tabuleiro para alterar não só os valores da matriz, mas também para alocar espaço dinamicamente para ela
void preencherMatrizInicial(GameofLife *tabuleiro){

    tabuleiro->matriz = (char **)malloc(tabuleiro->linhas * sizeof(char *));
    for(int i = 0; i < tabuleiro->linhas; i++){
        tabuleiro->matriz[i] = (char *)malloc(tabuleiro->colunas * sizeof(char));
    }

    for(int i = 0; i < tabuleiro->linhas; i++){
        for(int j = 0; j < tabuleiro->colunas; j++){
            scanf(" %c", &tabuleiro->matriz[i][j]);
        }
    }

}

//função para calcular a quantidade de células vivas com base no modelo de Moore
void vizinhancaMoore(GameofLife tabuleiro, int *contarVivas, int linha, int coluna){
    //cada if representa uma célula que deverá ser checada de acordo com o modelo
    //dentro das linhas e colunas da matriz, há diversos ifs ternários com o objetivo de evitar o acesso de valores inválidos(nesse caso, quando colunas e/ou linhas == 0)
    if(tabuleiro.matriz[(linha == 0 ? (tabuleiro.linhas-1) : ((linha-1) % tabuleiro.linhas))][(coluna == 0 ? (tabuleiro.colunas-1) : ((coluna-1) % tabuleiro.colunas))] == VIVA) (*contarVivas)++;
    if(tabuleiro.matriz[(linha == 0 ? (tabuleiro.linhas-1) : ((linha-1) % tabuleiro.linhas))][coluna % tabuleiro.colunas] == VIVA) (*contarVivas)++;
    if(tabuleiro.matriz[(linha == 0 ? (tabuleiro.linhas-1) : ((linha-1) % tabuleiro.linhas))][(coluna+1) % tabuleiro.colunas] == VIVA) (*contarVivas)++;
    if(tabuleiro.matriz[linha % tabuleiro.linhas][(coluna == 0 ? (tabuleiro.colunas-1) : ((coluna-1) % tabuleiro.colunas))] == VIVA) (*contarVivas)++;
    if(tabuleiro.matriz[linha % tabuleiro.linhas][(coluna+1) % tabuleiro.colunas] == VIVA) (*contarVivas)++;
    if(tabuleiro.matriz[(linha+1) % tabuleiro.linhas][(coluna == 0 ? (tabuleiro.colunas-1) : ((coluna-1) % tabuleiro.colunas))] == VIVA) (*contarVivas)++;
    if(tabuleiro.matriz[(linha+1) % tabuleiro.linhas][coluna % tabuleiro.colunas] == VIVA) (*contarVivas)++;
    if(tabuleiro.matriz[(linha+1) % tabuleiro.linhas][(coluna+1) % tabuleiro.colunas] == VIVA) (*contarVivas)++;

}

//função para calcular a quantidade de células vivas com base no modelo de Neuman
void vizinhancaNeumann(GameofLife tabuleiro, int *contarVivas, int linha, int coluna){
    //cada if representa uma célula que deverá ser checada de acordo com o modelo
    //dentro das linhas e colunas da matriz, há diversos ifs ternários com o objetivo de evitar o acesso de valores inválidos(nesse caso, quando colunas e/ou linhas == 0 ou ==1)
    if(tabuleiro.matriz[(linha == 0 ? (tabuleiro.linhas-2) : (linha == 1 ? (tabuleiro.linhas-1) : ((linha-2) % tabuleiro.linhas)))][coluna % tabuleiro.colunas] == VIVA) (*contarVivas)++;
    if(tabuleiro.matriz[(linha == 0 ? (tabuleiro.linhas-1) : ((linha-1) % tabuleiro.linhas))][coluna % tabuleiro.colunas] == VIVA) (*contarVivas)++;
    if(tabuleiro.matriz[(linha+2) % tabuleiro.linhas][coluna % tabuleiro.colunas] == VIVA) (*contarVivas)++;
    if(tabuleiro.matriz[(linha+1) % tabuleiro.linhas][coluna % tabuleiro.colunas] == VIVA) (*contarVivas)++;
    if(tabuleiro.matriz[linha % tabuleiro.linhas][(coluna == 0 ? (tabuleiro.colunas-2) : (coluna == 1 ? (tabuleiro.colunas-1) : (coluna-2) % tabuleiro.colunas))] == VIVA) (*contarVivas)++;
    if(tabuleiro.matriz[linha % tabuleiro.linhas][(coluna == 0 ? (tabuleiro.colunas-1) : ((coluna-1) % tabuleiro.colunas))] == VIVA) (*contarVivas)++;
    if(tabuleiro.matriz[linha % tabuleiro.linhas][(coluna+1) % tabuleiro.colunas] == VIVA) (*contarVivas)++;
    if(tabuleiro.matriz[linha % tabuleiro.linhas][(coluna+2) % tabuleiro.colunas] == VIVA) (*contarVivas)++;
    
}

void simularJogo(GameofLife *tabuleiro){
    //é criado uma matriz de cópia e os valores da matriz original são atribuidos a copia
    //é feito isso para que o estado antes da simulação não seja alterado, o que faz com que a simulação funcione
    char matrizCopia[tabuleiro->linhas][tabuleiro->colunas];
    for(int i = 0; i < tabuleiro->linhas; i++){
        for(int j = 0; j < tabuleiro->colunas; j++){
            matrizCopia[i][j] = tabuleiro->matriz[i][j];
        }
    }
    
    //variavel para contar as celulas vivas, ela será usada para determinar o estado de uma célula com base nas vizinhas
    int contarVivas = 0;
    //fors para acessar todas as células do jogo
    for(int i = 0; i < tabuleiro->linhas; i++){
        for(int j = 0; j < tabuleiro->colunas; j++){
            switch(tabuleiro->modo){
                case 'M':
                    //os parametros i e j representam as linhas e colunas respectivamente
                    vizinhancaMoore(*tabuleiro, &contarVivas, i, j);
                    //condição para determinar se a célula deve estar viva, morta ou manter seu estado atual
                    if(contarVivas < 2 || contarVivas > 3){
                        matrizCopia[i][j] = MORTA;
                    }
                    else if(contarVivas == 3){
                        matrizCopia[i][j] = VIVA;
                    }
                    break;
                case 'N':
                    vizinhancaNeumann(*tabuleiro, &contarVivas, i, j);
                    if(contarVivas < 2 || contarVivas > 3){
                        matrizCopia[i][j] = MORTA;
                    }
                    else if(contarVivas == 3){
                        matrizCopia[i][j] = VIVA;
                    }
                    break;
            }
            //resetando a variavel para contar os vizinhos vivos da próxima célula
            contarVivas = 0;
        }
    }

    //é o mesmo processo de cópia do início, porém dessa vez a matriz original fica com os valores da matriz cópia(pois essa contém o próximo estado da simulação)
    //não criei uma função para isso pq eu teria que criar a matriz cópia na heap, o que não valeria muito a pena já que eu sei as dimensões
    //e se eu fosse tentar criar uma função, eu teria que criar uma para a cópia direta e outra para a cópia indireta(o que daria em duas funções e não valeria a pena)
    for(int i = 0; i < tabuleiro->linhas; i++){
        for(int j = 0; j < tabuleiro->colunas; j++){
            tabuleiro->matriz[i][j] = matrizCopia[i][j];
        }
    }
}



int main(){
    //criação e inicialização das variáveis principais, sendo a struct e as gerações que serão simuladas
    GameofLife jogo;
    int geracoes;
    scanf("%d %d %d", &jogo.linhas, &jogo.colunas, &geracoes);
    scanf(" %c", &jogo.modo);

    //usado para evitar que dados de entrada apresentem erros, é importante ressaltar que no fim há um OR pois o modelo ou pode ser o de Moore ou de Neumann
    if(jogo.linhas > 0 && jogo.colunas > 0 && geracoes > 0 && (jogo.modo == 'M' || jogo.modo == 'N')){
        preencherMatrizInicial(&jogo);

        //simula o Game of Life tantas vezes que o úsuário quiser no início
        for(int contador = 0; contador < geracoes; contador++){
            simularJogo(&jogo);
        }

        //usado para imprimir a matriz final
        for(int i = 0; i < jogo.linhas; i++){
            for(int j = 0; j < jogo.colunas; j++){
                printf("%c", jogo.matriz[i][j]);
            }
            printf("\n");
        }

        //dando free nos valores alocados dinamicamente
        for(int i = 0; i < jogo.linhas; i++){
            free(jogo.matriz[i]);
        }
        free(jogo.matriz);
    }
    else{
        printf("Dados de entrada apresentam erro.\n");
    }

    //RETURN 0 YEAAAAAHHH!!!!!
    return 0;
}
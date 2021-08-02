/*
 * Disciplina: Laboratório de Introdução à Ciência de Computação I 
 *
 * Título: Ataques e Tipos
 * 
 * Funcionalidade: O programa abaixo simula a IA de um jogador escolhendo qual
 * ataque é o mais efetivo em relação à um tipo de oponente. No começo é dado uma
 * matriz que representa o multiplicador entre os tipos de ataques e tipos de
 * oponentes. Logo após são dados dois parâmetros dos ataques, o dano e o tipo,
 * após o fim dos ataques é colocado um -1 pelo usuário, e, logo depois, vem o
 * tipo do oponente. O programa, baseado nisso, irá determinar o melhor ataque
 * a ser escolhido.
 * 
 * Nome: Murillo Moraes Martins
 * 
 * Número Usp: 12701599
 *
 * Data de Modificação: 14/07/2021
*/


#include <stdio.h>
#include <stdlib.h>

void preencherMatriz(double **matriz, int linhasColunas);
double calcularDano(double **matriz, int *ataque, int tipoInimigo);

int main(){
    //declaração da matriz e da quantidade de linhas/colunas
    double **matrizTipos;
    int quantidadeTipos;

    scanf(" %d", &quantidadeTipos);

    //alocando espaço para matriz
    matrizTipos = (double **)malloc(quantidadeTipos * sizeof(double *));
    for(int i = 0; i < quantidadeTipos; i++){
        matrizTipos[i] = (double *)malloc(quantidadeTipos * sizeof(double));
    }

    //função para preencher a matriz com os valores de input
    preencherMatriz(matrizTipos, quantidadeTipos);

    //declaração das variáveis para armazenar os ataques
    //é necessário que **ataques = NULL pois ele não passará por malloc
    int **ataques = NULL;
    int quantidadeAtaques = 0;

    /*
    variável de leitura, é preciso do scanf antes do while para que
    possa ter um scanf no final do while
    */
    int leitura;
    scanf(" %d", &leitura);

    while(leitura != -1){
        quantidadeAtaques++;
        //alocar espaço dinamicamente para os ataques
        ataques = (int **)realloc(ataques, quantidadeAtaques * sizeof(int*));
        for(int i = 0; i < quantidadeAtaques; i++){
            ataques[i] = (int *)realloc(ataques[i], 2 * sizeof(int));
        }
        
        /*
        j < 2 pois o ataque só tem dois parametros:
            -dano do ataque
            -tipo do ataque
        */
        for(int j = 0; j < 2; j++){
            ataques[quantidadeAtaques-1][j] = leitura;
            scanf(" %d", &leitura);
        }
    }

    //tipo do inimigo
    int tipoInimigo;

    scanf(" %d", &tipoInimigo);

    //variaveis para calcular o dano e pegar o indice do maior dano
    //danoMaior = 0 para evitar lixo de memória
    double danoAtual, danoMaior = 0;
    int indice;

    for(int i = 0; i < quantidadeAtaques; i++){
        danoAtual = calcularDano(matrizTipos, ataques[i], tipoInimigo);
        if(danoAtual > danoMaior){
            danoMaior = danoAtual;
            indice = i;
        }
    }

    //fors para desalocar as matrizes, tanto os tipos quanto os ataques
    for(int i = 0; i < quantidadeTipos; i++){
        free(matrizTipos[i]);
    }
    free(matrizTipos);

    for(int i = 0; i < quantidadeAtaques; i++){
        free(ataques[i]);
    }
    free(ataques);

    printf("O melhor ataque possui indice %d e dano %.2lf", indice, danoMaior);
    
    return 0;
}

void preencherMatriz(double **matriz, int linhasColunas){
    for(int i = 0; i < linhasColunas; i++){
        for(int j = 0; j < linhasColunas; j++){
            scanf(" %lf", &matriz[i][j]);
        }
    }
}

double calcularDano(double **matriz, int *ataque, int tipoInimigo){
    //ataque[1] é está no indice da matriz pois esse indica qual o tipo do ataque
    int multiplicador = matriz[ataque[1]][tipoInimigo];
    //ataque[0] é o dano sem o multiplicador
    return ataque[0] * multiplicador;
}
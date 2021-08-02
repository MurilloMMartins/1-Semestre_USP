/*
 * Disciplina: Laboratório de Introdução à Ciência de Computação I 
 *
 * Título: Padding de Imagens
 * 
 * Funcionalidade: O programa tem a funcionalidade de adicionar o bordas a 
 * uma imagem. Ele recebe a "imagem" original(que é uma matriz de numeros entre)
 * 0 a 255 e adiciona uma borda de "0" do tamanho desejado
 * 
 * Nome: Murillo Moraes Martins
 * 
 * Número Usp: 12701599
 *
 * Data de Modificação: 15/07/2021
*/

#include <stdio.h>
#include <stdlib.h>

void preencherMatriz(int **matriz, int linhas, int colunas);
void imprimirMatriz(int **matriz, int linhas, int colunas);

int main(){
    //declarando variaveis
    int largura, altura;
    int **imagem;
    int tamanhoBorda;

    scanf(" %d %d", &largura, &altura);

    //alocando memória para a matriz da imagem
    imagem = (int **)malloc(altura * sizeof(int *));
    for(int i = 0; i < altura; i++){
        imagem[i] = (int *)malloc(largura * sizeof(int));
    }

    preencherMatriz(imagem, altura, largura);

    scanf(" %d", &tamanhoBorda);

    //essas variaveis são a nova largura e altura da imagem com padding
    int larguraPadding = 2*tamanhoBorda + largura;
    int alturaPadding = 2*tamanhoBorda + altura;
    
    //for para imprimir a imagem com padding
    for(int i = 0; i < alturaPadding; i++){
        for(int j = 0; j < larguraPadding; j++){
            //aqui é feito um if para saber se será imprimido um 0 ou o conteúdo da imagem
            if(i < tamanhoBorda || j < tamanhoBorda || i >= (altura+tamanhoBorda) || j >= (largura+tamanhoBorda)){
                printf("0 ");
            }
            else{
                printf("%d ", imagem[i-tamanhoBorda][j-tamanhoBorda]);
            }
        }
        printf("\n");
    }
    printf("\n");

    imprimirMatriz(imagem, altura, largura);

    //desalocando a matriz
    for(int i = 0; i < altura; i++){
        free(imagem[i]);
    }
    free(imagem);

    return 0;
}

//preenche a matriz com os valores de input
void preencherMatriz(int **matriz, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf(" %d", &matriz[i][j]);
        }
    }
}

//imprime a matriz
void imprimirMatriz(int **matriz, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
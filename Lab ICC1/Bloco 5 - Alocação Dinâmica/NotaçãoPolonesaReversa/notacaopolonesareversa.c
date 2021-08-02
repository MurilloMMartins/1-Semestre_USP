/*
 * Disciplina: Laboratório de Introdução à Ciência de Computação I 
 *
 * Título: Notação Polonesa Reversa
 * 
 * Funcionalidade: O programa tem a funcionalidade de realizar operações de acordo com
 * as regras da Notação Polonesa Reversa(NPR). A NPR é uma forma de representar operações
 * numéricas onde o operador(que pode ser +, -, * ou /) está após os operandos(ou seja, 2 + 2
 * em NPR é 2 2 +). O programa recebe lê essas operações até encontrar um EOF, aí ele executa
 * as operações e imprime o resultado. Além disso, esse programa utiliza a estrutura de dado
 * Stack, onde os dados são "empurrados" e "puxados" de acordo com o seu uso no programa.
 * 
 * Nome: Murillo Moraes Martins
 * 
 * Número Usp: 12701599
 *
 * Data de Modificação: 16/07/2021
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

double realizarOperacao(double *pilha, int topoPilha, char operacao);

int main(){
    //declaração da Stack com a variável topoPilha indicando o indice do valor do topo da Stack
    double *pilha = NULL;
    int topoPilha = 0;

    //variáveis que serão utilizadas durante o programa
    char caractere;
    double resultadoOperacao;
    while(scanf("%c", &caractere) != EOF){
        //a função isdigit filtra se o caracter encontrado é um número ou uma operação
        if(isdigit(caractere) == 0){
            if(caractere != ' '){
                resultadoOperacao = realizarOperacao(pilha, topoPilha, caractere);
                /*
                operações para desempilhar um dos números da pilha(e substituir 
                o outro pelo resultado da operação)]
                */
                topoPilha--;
                pilha = (double *)realloc(pilha, topoPilha * sizeof(double));
                pilha[topoPilha-1] = resultadoOperacao;
            }
        }
        else{
            //adicionando números a pilha
            topoPilha++;
            pilha = (double *)realloc(pilha, topoPilha * sizeof(double));
            ungetc(caractere, stdin);
            scanf(" %lf", &pilha[topoPilha-1]);
        }
    }

    printf("Resultado: %.6lf\n", pilha[0]);

    //desaloca a Stack
    free(pilha);

    return 0;
}

//função que vai realizar dada operação de acordo com o input
double realizarOperacao(double *pilha, int topoPilha, char operacao){
    double resultadoOperacao;
    //switch filtando qual operação a ser feita
    switch(operacao){
        //os números que faram parte da operação são o número do topo e o logo abaixo dele
        //por isso os indices da pilha são topoPilha-1 e topoPilha-2
        case '+':
            resultadoOperacao = pilha[topoPilha-2] + pilha[topoPilha-1];
            break;
        case '-':
            resultadoOperacao = pilha[topoPilha-2] - pilha[topoPilha-1];
            break;
        case '*':
            resultadoOperacao = pilha[topoPilha-2] * pilha[topoPilha-1];
            break;
        case '/':
            resultadoOperacao = pilha[topoPilha-2] / pilha[topoPilha-1];
            break;
    }

    return resultadoOperacao;
}
/*
 * Disciplina: Introdução à Ciência de Computação I 
 *
 * Título: REDRUM
 * 
 * Funcionalidade: O programa tem a funcionalidade de receber uma frase e decidir
 * se ela é um palíndromo direto, indireto ou não é um palíndromo. Serão utilizados
 * alocação dinâmica e recursão para a confecção desse código.
 * 
 * Nome: Murillo Moraes Martins
 * 
 * Número Usp: 12701599
 *
 * Data de Modificação: 15/07/2021
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SUCESSO 1
#define FALHA 0

int verificarPalindromo(char *frase, int inicioFrase, int finalFrase);

int main(){
    /*
    serão salvos duas frases para a verificação, uma dessas frases irá conter somente 
    os caracteres alfanuméricos e a outra possuirá todos os caracteres permitidos.
    */
    char *fraseInteira = NULL;
    char *fraseAlfaNum = NULL;
    
    //variaveis para salvar o tamanho das frases
    int tamanhoFraseInteira = 0;
    int tamanhoFraseAlfaNum = 0;

    //caractere de leitura
    char caractere;
    do{
        caractere = getchar();
        //é feito isso para todos os caracteres estarem em letra minuscula
        caractere = tolower(caractere);

        //if para ver se o caractere deve ser salvo
        if(isalnum(caractere) || caractere == ' ' || caractere == '/'){
            //if para ver se o caractere é alfanumerico(assim fazendo parte da string alfanum)
            if(isalnum(caractere)){
                tamanhoFraseAlfaNum++;
                fraseAlfaNum = (char *)realloc(fraseAlfaNum, sizeof(char) * tamanhoFraseAlfaNum);
                fraseAlfaNum[tamanhoFraseAlfaNum-1] = caractere;
            }

            //nessa etapa e a anterior são feitas a alocação dinamica das frases
            tamanhoFraseInteira++;
            fraseInteira = (char *)realloc(fraseInteira, sizeof(char) * tamanhoFraseInteira);
            fraseInteira[tamanhoFraseInteira-1] = caractere;
        }
    }while(caractere != '\n');

    //if para verificar se uma palavra é um palíndromo
    if(verificarPalindromo(fraseAlfaNum, 0, tamanhoFraseAlfaNum) == SUCESSO){
        //if para verificar se é um palíndromo direto ou indireto
        if(verificarPalindromo(fraseInteira, 0, tamanhoFraseInteira) == SUCESSO){
            printf("Palindromo direto\n");
        }
        else{
            printf("Palindromo indireto\n");
        }
    }
    else{
        printf("Nao eh um palindromo\n");
    }

    //desalocar as variaveis dinamicas
    free(fraseInteira);
    free(fraseAlfaNum);

    return 0;
}

/*
função recursiva para verificar se a frase é um palindromo
na primeira situação, ela retornará 1 se for um palíndromo e 0 se não for
na segunda situação, ela retornará 1 se for um palíndromo direto e 0 se for um palíndromo indireto
*/
int verificarPalindromo(char *frase, int inicioFrase, int finalFrase){

    //condição de parada
    if(inicioFrase > finalFrase){
        return SUCESSO;
    }
    
    //passo recursivo
    if(frase[inicioFrase] == frase[finalFrase-1]){
        //são usados inicioFrase+1 e finalFrase-1 para avançar o passo recursivo
        return verificarPalindromo(frase, inicioFrase+1, finalFrase-1);
    }

    //outra condição de parada
    return FALHA;
}
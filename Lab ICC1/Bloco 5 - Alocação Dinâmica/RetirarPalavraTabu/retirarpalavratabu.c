/*
 * Disciplina: Laboratório de Introdução à Ciência de Computação I 
 *
 * Título: Retirar Palavra Tabu
 * 
 * Funcionalidade: O programa tem a funcionalidade de retirar uma palavra tabu(
 * que é determinada pelo usuário) do texto inserido. Primeiro é inserido a palavra
 * à ser retirada e logo após o texto em si. Após isso o programa imprimirá quantas
 * palavras tabus foram encontradas e a frase sem as palavras tabus.
 * 
 * Nome: Murillo Moraes Martins
 * 
 * Número Usp: 12701599
 *
 * Data de Modificação: 15/07/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerTexto(char **texto);
int contarTabu(char *texto, char palavraTabu[20], int **indicePalavrasTabu);
void excluirPalavraTabu(char *texto, int tamanhoPalavraTabu, int *indicePalavrasTabu, int tabuEncontradas);

int main(){
    //inicialização das variáveis
    //palavra tabu tem 21 chars pq ela pode ter 20 caracteres + \0
    char palavraTabu[21];
    char *texto = NULL;
    int tabuEncontradas;

    //lê a palavra tabu
    scanf("%s\n", palavraTabu);

    lerTexto(&texto);

    //variavel que irá armazenar os indices do começo das palavras tabu
    int *indicePalavrasTabu = NULL;
    tabuEncontradas = contarTabu(texto, palavraTabu, &indicePalavrasTabu);
    printf("A palavra tabu foi encontrada %d vezes\n", tabuEncontradas);

    //excluirá as palavras tabus do texto(e o imprimirá), strlen(palavraTabu) é o tamanho da palavra tabu
    excluirPalavraTabu(texto, strlen(palavraTabu), indicePalavrasTabu, tabuEncontradas);

    //desalocando as variáveis dinâmicas
    free(texto);
    free(indicePalavrasTabu);
    
    return 0;
}

/*
função que lê o texto que contém as palavras tabus
é usado ponteiro de ponteiro nos parâmetros pois será feita uma modificação no vetor texto
*/
void lerTexto(char **texto){
    char leitura = '\0';
    int tamanhoTexto = 0;
    
    //o fim do texto é demarcado por um $
    while(leitura != '$'){
        leitura = getchar();
        tamanhoTexto++;
        //aqui é feito a alocação dinâmica do texto inserido
        (*texto) = (char *)realloc((*texto), tamanhoTexto * sizeof(char));
        (*texto)[tamanhoTexto-1] = leitura;
    }
    
    (*texto)[tamanhoTexto-1] = '\0';
}

//função que conta a quantidade de palavras tabus e salva os indices dessas palavras no vetor texto
//ela retorna o numero de palavras tabu encontradas
int contarTabu(char *texto, char palavraTabu[], int **indicePalavrasTabu){
    int tamanhoTexto = strlen(texto);
    int tabuEncontradas = 0;
    //for que percorre a string
    for(int i = 0; i < tamanhoTexto; i++){
        /*
        if para ver se há uma palavra tabu, caso ele ache uma palavra tabu, a variavel que percorre 
        a string terá o tamanho da palavra tabu somado à ela, assim ele não percorrerá os caracteres
        da palavra tabu
        */
        if(strncmp(texto+i, palavraTabu, strlen(palavraTabu)) == 0){
            tabuEncontradas++;
            (*indicePalavrasTabu) = (int *)realloc((*indicePalavrasTabu), tabuEncontradas * sizeof(int));
            (*indicePalavrasTabu)[tabuEncontradas-1] = i;

            i += strlen(palavraTabu)-1;
        }
    }

    //retorna o numero de palavras tabu encontradas
    return tabuEncontradas;
}

//função que irá excluir a palavra tabu do texto e irá imprimi-lo
void excluirPalavraTabu(char *texto, int tamanhoPalavraTabu, int *indicePalavrasTabu, int tabuEncontradas){
    /*
    essa variável indica o tamanho do texto final, o cálculo é feito da seguinte forma:
    tamanho do texto - (tamanho da palavra tabu * palavras tabus encontradas) + 1
    é somado o 1 pois a função strlen não conta o \0
    */
    int tamanhoTextoFinal = (strlen(texto)+1) - (tamanhoPalavraTabu * tabuEncontradas);
    //alocação dinamica do texto final
    char *textoFinal = (char *)malloc(tamanhoTextoFinal * sizeof(char));

    //variavel para contar, tem a mesma função do j no for, porém ela não é afetada pois indica os indices do textoFinal
    int contador = 0;
    for(int j = 0; j < strlen(texto); j++){
        /*
        esse for e if são feitos para checar se o j é igual a algum dos indices das palavras tabus presentes
        caso ele seja, ele irá pular a palavra tabu de ser atribuida ao textoFinal
        */
        for(int i = 0; i < tabuEncontradas; i++){
            if(j == indicePalavrasTabu[i]){
                j += tamanhoPalavraTabu;
            }
        }
        //atribuição dos caracteres do texto ao textoFinal(o que não inclui as palavras tabus)
        textoFinal[contador] = texto[j];
        contador++;
    }
    //adicionando o \0 ao final de textoFinal
    textoFinal[tamanhoTextoFinal-1] = '\0';
    
    printf("Frase: %s\n", textoFinal);

    //desalocando o textoFinal
    free(textoFinal);
}
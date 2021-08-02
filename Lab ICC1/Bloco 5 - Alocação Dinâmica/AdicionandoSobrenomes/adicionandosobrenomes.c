#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lerNomeCompleto(char *texto, int *estado);
char *copiarUltimoSobrenome(char *nomeCompleto, char *ultimoSobrenome);

int main(){
    //declarando as variáveis
    char *nomeCompletoAtual = NULL;
    char *sobrenomeAnterior = NULL;
    int quantidadeNomes = 0;

    /*
    essa variável armazena o estado da operação:
        -estado = 0: indica que ainda não chegou no final dos nomes
        -estado = 1: indica que não serão adicionados mais nomes(ou seja,
        quando o caractér "$" aparece)
    */
    int estado = 0;

    while(estado != 1){
        //é necessário declarar os ponteiros como NULL pois eles passaram por realloc e free
        nomeCompletoAtual = NULL;
        nomeCompletoAtual = lerNomeCompleto(nomeCompletoAtual, &estado);

        //if para ver se o nome tem indice ou indice impar
        if(quantidadeNomes % 2 == 0){
            sobrenomeAnterior = NULL;
            sobrenomeAnterior = copiarUltimoSobrenome(nomeCompletoAtual, sobrenomeAnterior);
            printf("%s\n", nomeCompletoAtual);
            quantidadeNomes++;
        }
        else{
            //printa o nome atual e o sobrenome do anterior
            printf("%s %s\n", nomeCompletoAtual, sobrenomeAnterior);
            quantidadeNomes++;
            //esse free é dado para dar espaço ao próximo sobrenome
            free(sobrenomeAnterior);
        }
        
        //esse free é dado para dar espaço ao próximo nome
        free(nomeCompletoAtual);
    }

    /*
    esse if é realizado caso o numero total de nomes seja impar
    se ele for é necessário dar um free a mais, pois o if do while não
    dará free no sobrenomeAnterior
    */
    if(quantidadeNomes % 2 == 1){
        free(sobrenomeAnterior);
    }
    
    return 0;
}

//função para ler o nome completo
//ela retorna char* para evitar o uso de ponteiro de ponteiro(aka: **ponteiro)
char *lerNomeCompleto(char *texto, int *estado){
    char leitura;
    //o tamanhoString é igual a um para compensar pelo \0
    int tamanhoTexto = 1;
    texto = (char *)malloc(tamanhoTexto * sizeof(char));
    
    //é feito um primeiro scanf para que o scanf do while possa ser no final(assim verificando que um \n estara presente e evitando que esse seja parte do return)
    scanf("%c", &leitura);

    while(leitura != '\n' && leitura != '$'){
        texto = (char *)realloc(texto, tamanhoTexto * sizeof(char));
        //o "tamanhoString-1" é usado para compensar o fato do C começar a ler do 0
        texto[tamanhoTexto-1] = leitura;
        tamanhoTexto++;
        scanf("%c", &leitura);
    }
    
    //check para ver se não há mais nomes sendo lidos
    if(leitura == '$'){
        *estado = 1;
    }

    //usado para anexar o \0 no final
    texto = (char *)realloc(texto, (tamanhoTexto) * sizeof(char));
    texto[tamanhoTexto-1] = '\0';

    return texto;
}

//variavel para copiar o ultimo sobrenome
char *copiarUltimoSobrenome(char *nomeCompleto, char *ultimoSobrenome){
    //declaração de variáveis
    char leitura;
    int tamanhoNomeCompleto = strlen(nomeCompleto);
    int tamanhoSobrenome = 1;

    //aqui é feito um malloc para evitar problemas com o realloc
    ultimoSobrenome = (char *)malloc(1 * sizeof(char));

    //loop para passar por todos os caracteres do nome
    for(int i = 0; i < tamanhoNomeCompleto; i++){
        leitura = nomeCompleto[i];
        //se a leitura detectar um espaço, o sobrenome será descartado para dar espaço ao próximo sobrenome
        if(leitura != ' '){
            ultimoSobrenome = (char *)realloc(ultimoSobrenome ,tamanhoSobrenome * sizeof(char));
            ultimoSobrenome[tamanhoSobrenome-1] = leitura;
            tamanhoSobrenome++;
        }
        else{
            tamanhoSobrenome = 1;
        }
    }

    //realocando para o \0 no final
    ultimoSobrenome = (char *)realloc(ultimoSobrenome ,tamanhoSobrenome * sizeof(char));
    ultimoSobrenome[tamanhoSobrenome-1] = '\0';

    return ultimoSobrenome;
}
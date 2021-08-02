#include <stdio.h>
#include <stdlib.h>

char *readLine(char *string){
    char leitura;
    //o tamanhoString é igual a um para não haver problema com o malloc
    int tamanhoString = 1;
    //primeira alocação só para alocar o \0
    string = (char *)malloc(tamanhoString * sizeof(char));
    
    //é feito um primeiro scanf para que o scanf do while possa ser no final(assim verificando que um \n estara presente e evitando que esse seja parte do return)
    scanf("%c", &leitura);

    while(leitura != '\n'){
        string = (char *)realloc(string, tamanhoString * sizeof(char));
        //o "tamanhoString-1" é usado para compensar o fato do C começar a ler do 0
        string[tamanhoString-1] = leitura;
        tamanhoString++;
        scanf("%c", &leitura);
    }

    //usado para anexar o \0 no final
    string = (char *)realloc(string, (tamanhoString+1) * sizeof(char));
    string[tamanhoString-1] = '\0';

    return string;
}

int main(){
    
    int nlinhas;
    scanf(" %d", &nlinhas);
    //esse scanf é usado para pular o \n que é inserido apos o nlinhas
    scanf("%*[\r\n]s");

    //criando um vetor de strings(ou seja, uma matriz de char) com linhas = nlinhas
    char **livro = (char **)malloc(nlinhas * sizeof(char *));
    //for usado para ler as linhas do livro corrompido e colocar as linhas no vetor livro
    for(int linha = 0; linha < nlinhas; linha++){
        livro[linha] = readLine(livro[linha]);
    }

    //criação e leitura do número de linhas válidas no livro
    int linhasValidas;
    scanf(" %d", &linhasValidas);

    //for usado para ler qual linha é válida, dentro do for é usado o "int i" pq ele não vai afetar o código, ele só serve como um contador
    for(int i = 0; i < linhasValidas; i++){
        int linha;
        scanf(" %d", &linha);
        printf("%s\n", livro[linha]);
    }

    //for para desalocar memória de todas as linhas
    for(int linha = 0; linha < nlinhas; linha++){
        free(livro[linha]);
    }

    //desalocar memória do vetor de strings em si
    free(livro);

    //return 0 S2
    return 0;
}
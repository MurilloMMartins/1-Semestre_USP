/*
 * Disciplina: Laboratório de Introdução à Ciência de Computação I 
 *
 * Título: Compilador JIT de Brainf*ck
 * 
 * Funcionalidade: O programa funciona como um compilador JIT(Just in time) da
 * linguagem Brainfuck(BF). O programa lê as operações em BF e as traduz para C,
 * criando um arquivo contendo tal programação, após isso ele roda o arquivo em c
 * assim executando o código em BF.
 * 
 * Nome: Murillo Moraes Martins
 * 
 * Número Usp: 12701599
 *
 * Data de Modificação: 21/07/2021
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    //criando o arquivo
    FILE *arquivoBF = fopen("brainfuck.c", "w");

    //escrevendo as operações iniciais do arquivo em c
    fprintf(arquivoBF, "#include <stdio.h>\n\n"
                        "int main(){\n"
                            "\tchar mem[30000];\n"
                            "\tint i = 0;\n"
                            "\tfor (int j = 0; j < 30000; j++){\n"
                                "\t\tmem[j] = 0;\n"
                            "\t}\n\n");
    
    char operacao;
    //while usado para ler a entrada e traduzir de brainfuck para C até encontrar um EOF
    while(scanf("%c", &operacao) != EOF){
        switch(operacao){
            case '+':
                fprintf(arquivoBF, "\tmem[i]++;\n");
                break;
            case '-':
                fprintf(arquivoBF, "\tmem[i]--;\n");
                break;
            case '>':
                fprintf(arquivoBF, "\ti++;\n");
                break;
            case '<':
                fprintf(arquivoBF, "\ti--;\n");
                break;
            case '.':
                fprintf(arquivoBF, "\tputchar(mem[i]);\n");
                break;
            case '[':
                fprintf(arquivoBF, "\twhile (mem[i]) {\n");
                break;
            case ']':
                fprintf(arquivoBF, "\t}\n");
                break;
            default:
                break;
        }
    };

    fprintf(arquivoBF, "\n\tprintf(\"\\n\");\n"
                        "\tfor(int j = 0; j < 30000; j++){\n"
                        "\t\tif(mem[j] != 0){\n"
                        "\t\t\tprintf(\"%%d \", mem[j]);\n"
                        "\t\t}\n"
                        "\t}\n"
                        "\tprintf(\"\\n\");\n\n"
                        "return 0;\n"
                        "}");
    
    //fechando o arquivo, assim salvando se conteúdo
    fclose(arquivoBF);

    //fazendo com que o sistema compile e rode o código gerado em C
    system("gcc brainfuck.c -o brainfuck");
    system("./brainfuck");

    return 0;
}
/*
 * Disciplina: Laboratório de Introdução à Ciência de Computação I 
 *
 * Título: Gerenciamento de estudantes
 * 
 * Funcionalidade: O programa funciona como um gerenciador de estudantes, em que
 * são inseridos o nome, o curso, o identificador do aluno e a sua idade e esses
 * valores são cadastrados em um vetor de structs. São utilizados structs, funções
 * e alocação dinâmica nesse programa
 * 
 * Nome: Murillo Moraes Martins
 * 
 * Número Usp: 12701599
 *
 * Data de Modificação: 21/07/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno{
    char *nome;
    char *curso;
    int identificador;
    int idade;
}aluno_t;

char *lerLinha(char *texto);
void registrarNovoAluno(aluno_t **registroDeAlunos, int totalDeAlunos, int identificador);
void imprimirRegistro(aluno_t registro);
void consultarIdentificador(aluno_t *registroDeAlunos, int totalDeAlunos, int identificador);
void consultarCurso(aluno_t *registroDeAlunos, int totalDeAlunos, char *curso);

int main(){
    //a variavel registroDeAlunos funcionará como um vetor de struct
    aluno_t *registroDeAlunos = NULL;
    int totalDeAlunos = 0;

    //variável para armazenar a operação
    int operacao;
    scanf(" %d", &operacao);
    while(operacao != -1){
        totalDeAlunos++;
        //usado para evitar que o \n entre na função
        scanf("%*[\r\n]s");
        //operação é passado como um parâmetro pois a operação ou lerá o -1 ou o identificador do aluno
        registrarNovoAluno(&registroDeAlunos, totalDeAlunos, operacao);
        scanf(" %d", &operacao);
    }

    //reinicia a variável
    operacao = 0;
    while(operacao != -1){
        //variaveis que armazenaram o identificador e a string do curso que será procurado
        int identificadorDesejado = 0;
        char *cursoDesejado = NULL;

        scanf(" %d", &operacao);
        switch(operacao){
            case 1:
                scanf(" %d", &identificadorDesejado);
                consultarIdentificador(registroDeAlunos, totalDeAlunos, identificadorDesejado);
                break;
            case 2:
                //evita que o \n é lido
                scanf("%*[\r\n]s");
                cursoDesejado = lerLinha(cursoDesejado);
                consultarCurso(registroDeAlunos, totalDeAlunos, cursoDesejado);
                break;
            case 3:
                for(int i = 0; i < totalDeAlunos; i++){
                    imprimirRegistro(registroDeAlunos[i]);
                }
                break;
            default:
                break;
        }
    }

    //desalocando as variáveis alocadas dinamicamente
    for(int i = 0; i < totalDeAlunos; i++){
        free(registroDeAlunos[i].nome);
        free(registroDeAlunos[i].curso);
    }
    free(registroDeAlunos);

    return 0;
}

//função de ler a string de uma linha até o \n
char *lerLinha(char *texto){
    char leitura;
    //o tamanho começa em 1 para compensar pelo \0
    int tamanhoTexto = 1;
    texto = NULL;

    do{
        leitura = getchar();
        texto = (char *)realloc(texto, tamanhoTexto*sizeof(char));
        texto[tamanhoTexto-1] = leitura;
        tamanhoTexto++;
    }while(leitura != '\n');

    //é usado [tamanhoTexto-2] pois o \n está inserido na string, portanto isso substitui ele pelo \0
    texto[tamanhoTexto-2] = '\0';

    return texto;
}

//função para registrar um novo aluno no registro
void registrarNovoAluno(aluno_t **registroDeAlunos, int totalDeAlunos, int identificador){
    //alocando dinamicamente a struct
    (*registroDeAlunos) = (aluno_t *)realloc((*registroDeAlunos), totalDeAlunos * sizeof(aluno_t));

    //leitura dos inputs
    (*registroDeAlunos)[totalDeAlunos-1].identificador = identificador;
    (*registroDeAlunos)[totalDeAlunos-1].nome = lerLinha((*registroDeAlunos)->nome);
    (*registroDeAlunos)[totalDeAlunos-1].curso = lerLinha((*registroDeAlunos)->curso);
    scanf(" %d", &(*registroDeAlunos)[totalDeAlunos-1].idade);
}

//função que imprime os dados do registro de um aluno
void imprimirRegistro(aluno_t registro){
    printf("Nome: %s\n", registro.nome);
    printf("Curso: %s\n", registro.curso);
    printf("N USP: %d\n", registro.identificador);
    printf("IDADE: %d\n\n", registro.idade);
}

/*
função que consulta a presença de um aluno com o identificador específicado, se há ela imprime os dados
de tal aluno, se não ela imprime que esse aluno não está cadastrado
*/
void consultarIdentificador(aluno_t *registroDeAlunos, int totalDeAlunos, int identificador){
    
    for(int i = 0; i < totalDeAlunos; i++){
        if(registroDeAlunos[i].identificador == identificador){
            imprimirRegistro(registroDeAlunos[i]);
            //esse return está aqui para parar a execução dessa função caso ache o aluno, assim evitando o printf abaixo
            return;
        }
    }

    printf("Aluno nao cadastrado\n");
}

//função que consulta os alunos presentes em um curso especifícado e imprime os dados dos alunos
void consultarCurso(aluno_t *registroDeAlunos, int totalDeAlunos, char *curso){
    
    for(int i = 0; i < totalDeAlunos; i++){
        if(strcmp(registroDeAlunos[i].curso, curso) == 0){
            imprimirRegistro(registroDeAlunos[i]);
        }
    }

}
#include <stdio.h>

int main(){
    //declaração dos 512 valores da fita
    int fita[512];
    for(int i = 0; i < 512; i++){
        scanf(" %d", &fita[i]);
    }

    //declaração de variáveis que serão utilizadas na leitura da lista
    int ponteiro = 0;
    int endereco = 0;

    //variaveis utilizadas para armazenar os argumentos das operações
    int arg1 = 0;
    int arg2 = 0;
    int arg3 = 0;

    //esse print é feito antes da execução pra eu não precisar criar uma varíavel que segura os char q vão ser imprimidos depois
    printf("Saida do programa:\n");    

    while(endereco < 512){
        //declarar o ponteiro com o valor da fita a partir do endereço atual
        ponteiro = fita[endereco];

        //switch feito para as operações de execução da linguagem
        switch(ponteiro){
            //HALT
            case 0:
                endereco = 512;
                break;
            //ADD
            case 1:
                //declaração dos argumentos da operação
                arg1 = fita[endereco+1];
                arg2 = fita[endereco+2];
                arg3 = fita[endereco+3];
                //operação de ADD
                fita[arg3] = fita[arg1] + fita[arg2];
                //reposicionando o endereço
                endereco = endereco+4;
                break;
            //MUL
            case 2:
                //declaração dos argumentos da operação
                arg1 = fita[endereco+1];
                arg2 = fita[endereco+2];
                arg3 = fita[endereco+3];
                //operação de MUL
                fita[arg3] = fita[arg1] * fita[arg2];
                //reposicionando o endereço
                endereco = endereco+4;
                break;
            //CLT
            case 3:
                //declaração dos argumentos da operação
                arg1 = fita[endereco+1];
                arg2 = fita[endereco+2];
                arg3 = fita[endereco+3];
                //operação de CLT
                if(fita[arg1] < fita[arg2]){
                    fita[arg3] = 1;
                }
                else{
                    fita[arg3] = 0;
                }
                //reposicionando o endereço
                endereco = endereco+4;
                break;
            //CEQ
            case 4:
                //declaração dos argumentos da operação
                arg1 = fita[endereco+1];
                arg2 = fita[endereco+2];
                arg3 = fita[endereco+3];
                //operação CEQ
                if(fita[arg1] == fita[arg2]){
                    fita[arg3] = 1;
                }
                else{
                    fita[arg3] = 0;
                }
                //reposicionando o endereço
                endereco = endereco+4;
                break;
            //JMP
            case 5:
                //declaração dos argumentos da operação
                arg1 = fita[endereco+1];
                //operação JMP com reposicionamento do endereço
                endereco = fita[arg1];
                break;
            //JEQ
            case 6:
                //declaração dos argumentos da operação
                arg1 = fita[endereco+1];
                arg2 = fita[endereco+2];
                //operação JEQ com 2 reposicionamentos
                if(fita[arg1] != 0){
                    //se for verdade o endereço faz o "JUMP"
                    endereco = fita[arg2];
                }
                else{
                    //senão o endereço se reposiciona
                    endereco = endereco+3;
                }
                break;
            //CPY
            case 7:
                //declaração dos argumentos da operação
                arg1 = fita[endereco+1];
                arg2 = fita[endereco+2];
                //operação CPY
                fita[arg2] = fita[arg1];
                //reposicionando o endereço
                endereco = endereco+3;
                break;
            //PUT
            case 8:
                //declaração dos argumentos da operação
                arg1 = fita[endereco+1];
                //imprime o caracter correspondente ao inteiro na tabela ASCII
                printf("%c", fita[arg1]);
                //reposicionamento do endereço
                endereco = endereco+2;
                break;
            //PTN
            case 9:
                //declaração dos argumentos da operação
                arg1 = fita[endereco+1];
                //imprime o caracter correspondente ao inteiro na tabela ASCII
                printf("%d", fita[arg1]);
                //reposicionamento do endereço
                endereco = endereco+2;
                break;

        }

    }

    //pula uma linha para ter o formato da resposta
    printf("\n");
    //imprime o texto abaixo
    printf("Estado final da fita:\n");
    //for para imprimir a fita inteira
    for(int i = 0; i < 512; i++){
        printf("%d\n", fita[i]);
    }

    return 0;
}
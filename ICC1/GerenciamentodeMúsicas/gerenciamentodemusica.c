#include <stdio.h>
#include <stdlib.h>

typedef struct musica{
    char* nome;
    char* artista;
    int duracao;
} Musica;

typedef struct playlist{
    char* nome;
    int numeroMusicas;
    int musicaEscolhida;
    Musica* musicas;
} Playlist;

//função para ler as linhas e fazer a alocação dinâmica da memória necessária para cada string
char *lerLinha(char *texto){
    char leitura;
    //o tamanhoString é igual a um para compensar pelo \0
    int tamanhoTexto = 1;
    texto = (char *)malloc(tamanhoTexto * sizeof(char));
    
    //é feito um primeiro scanf para que o scanf do while possa ser no final(assim verificando que um \n estara presente e evitando que esse seja parte do return)
    scanf("%c", &leitura);

    while(leitura != '\n'){
        texto = (char *)realloc(texto, tamanhoTexto * sizeof(char));
        //o "tamanhoString-1" é usado para compensar o fato do C começar a ler do 0
        texto[tamanhoTexto-1] = leitura;
        tamanhoTexto++;
        scanf("%c", &leitura);
    }

    //usado para anexar o \0 no final
    texto = (char *)realloc(texto, (tamanhoTexto) * sizeof(char));
    texto[tamanhoTexto-1] = '\0';

    return texto;
}

void adicionarMusica(Playlist *playlistAtual){
    playlistAtual->numeroMusicas++;
    //criei essa variavel para facilitar na leitura
    int quantidadeMusica = playlistAtual->numeroMusicas;
    playlistAtual->musicas = (Musica*)realloc(playlistAtual->musicas, quantidadeMusica * sizeof(Musica));

    //realocação dinamica do nome e do artista da música, a duração é só um int ent nn precisa de realloc
    playlistAtual->musicas[quantidadeMusica-1].nome = lerLinha(playlistAtual->musicas[quantidadeMusica-1].nome);
    playlistAtual->musicas[quantidadeMusica-1].artista = lerLinha(playlistAtual->musicas[quantidadeMusica-1].artista);
    scanf(" %d", &playlistAtual->musicas[quantidadeMusica-1].duracao);

    printf("Musica %s de %s adicionada com sucesso.\n", playlistAtual->musicas[quantidadeMusica-1].nome, playlistAtual->musicas[quantidadeMusica-1].artista);
}

void exibirMusicas(Playlist playlistAtual){
    printf("---- Playlist: %s ----\n", playlistAtual.nome);
    printf("Total de musicas: %d\n\n", playlistAtual.numeroMusicas);

    for(int i = 0; i < playlistAtual.numeroMusicas; i++){
        if(i == playlistAtual.musicaEscolhida){
            printf("=== NOW PLAYING ===\n");
        }

        printf("(%d). '%s'\n", (i+1), playlistAtual.musicas[i].nome);
        printf("Artista: %s\n", playlistAtual.musicas[i].artista);
        printf("Duracao: %d segundos\n\n", playlistAtual.musicas[i].duracao);
    }
}

void avancarMusica(Playlist *playlistAtual){
    playlistAtual->musicaEscolhida++;
}

void retrocederMusica(Playlist *playlistAtual){
    playlistAtual->musicaEscolhida--;
}



int main(){
    Playlist playlistJuliana;
    //inicializando as variaveis da playlist para as funções terem uma base a ser usada e para evitar seg.fault
    playlistJuliana.musicaEscolhida = 0;
    playlistJuliana.numeroMusicas = 0;
    playlistJuliana.nome = NULL;
    playlistJuliana.musicas = (Musica*)malloc(1 + sizeof(Musica));
    
    int comando;

    playlistJuliana.nome = lerLinha(playlistJuliana.nome);

    //scanf é feito antes do while para garantir que o programa fechará caso o primeiro comando seja 5
    scanf(" %d", &comando);

    while(comando != 5){
        //como os comandos são numéricos é melhor fazer um switch
        switch(comando){
            case 1:
                if(playlistJuliana.numeroMusicas < 15){
                    //usado para se livrar de possiveis /r ou /n deixados na leitura do comando
                    scanf("%*[\r\n]s");
                    adicionarMusica(&playlistJuliana);
                    break;
                }
                else{
                    printf("Playlist cheia!\n");
                    break;
                }
            case 2:
                exibirMusicas(playlistJuliana);
                break;
            case 3:
                avancarMusica(&playlistJuliana);
                break;
            case 4:
                retrocederMusica(&playlistJuliana);
                break;
            default:
                break;
        }

        scanf(" %d", &comando);
        
    }

    for(int i = 0; i < playlistJuliana.numeroMusicas; i++){
        free(playlistJuliana.musicas[i].nome);
        free(playlistJuliana.musicas[i].artista);
    }

    free(playlistJuliana.nome);
    free(playlistJuliana.musicas);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct musica{
    char* nome;
    char* artista;
    unsigned int duracao;
} Musica;

typedef struct playlist{
    char* nome;
    int numeroMusicas;
    int musicaEscolhida;
    Musica* musicas;
} Playlist;

// Soma polinomial que interpreta o valor binário como um valor numérico.
// Quanto mais próximo o valor de retorno, mais próximo seu binário está do ideal.
// Não há necessidade de entender o funcionamento dessa função.
//
// Parâmetros: Nome do arquivo (binFilename: char *)
// Retorno: Nada (void)
void binaryToNum(char *binFilename) {
    FILE *fp = fopen(binFilename, "rb");

    double binValue = 0;
    double accumulator = 0.01;
    char ch;
    while (fread(&ch, sizeof(char), 1, fp)) {
        binValue += (double) ch * accumulator;
        accumulator += 0.01;
    }

    fclose(fp);
    printf("%lf\n", binValue);
}

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
    scanf(" %i", &playlistAtual->musicas[quantidadeMusica-1].duracao);

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

void salvarPlaylist(Playlist playlistAtual){
    //criação do arquivo
    char *nomeArquivo = NULL;
    nomeArquivo = lerLinha(nomeArquivo);
    FILE *arquivoPlaylist = fopen(nomeArquivo, "wb");
    
    //pegar o tamanho de uma string com o strlen(ele não inclui o \0)
    int tamanhoNomePlaylist = strlen(playlistAtual.nome);
    //escrever o tamanho, o nome e o numero de musicas no arquivo
    fwrite(&tamanhoNomePlaylist, sizeof(int), 1, arquivoPlaylist);
    fwrite(playlistAtual.nome, sizeof(char), tamanhoNomePlaylist, arquivoPlaylist);
    fwrite(&playlistAtual.numeroMusicas, sizeof(int), 1, arquivoPlaylist);

    //usado para escrever uma musica de cada vez
    for(int i = 0; i < playlistAtual.numeroMusicas; i++){

        //escrever nome da música
        int tamanhoNomeMusica = strlen(playlistAtual.musicas[i].nome);
        fwrite(&tamanhoNomeMusica, sizeof(int), 1, arquivoPlaylist);
        fwrite(playlistAtual.musicas[i].nome, sizeof(char), tamanhoNomeMusica, arquivoPlaylist);

        //escrever artista
        int tamanhoNomeArtista = strlen(playlistAtual.musicas[i].artista);
        fwrite(&tamanhoNomeArtista, sizeof(int), 1, arquivoPlaylist);
        fwrite(playlistAtual.musicas[i].artista, sizeof(char), tamanhoNomeArtista, arquivoPlaylist);

        //escrever duracao
        fwrite(&playlistAtual.musicas[i].duracao, sizeof(int), 1, arquivoPlaylist);
    }

    fclose(arquivoPlaylist);
    printf("Playlist %s salva com sucesso.\n", nomeArquivo);

    binaryToNum(nomeArquivo);

    //necessário por conta da função lerLinha que aloca dinamicamente
    free(nomeArquivo);
}

void lerStringArquivo(char **texto, int tamanhoString, FILE *arquivo){
    /*
    o char **texto é passado como ponteiro de ponteiro para passar essa variável por referência nessa função
    assim modificando o conteúdo da variável
    */
    *texto = (char *)malloc((tamanhoString+1) * sizeof(char));
    fread(*texto, sizeof(char), tamanhoString, arquivo);
    (*texto)[tamanhoString] = '\0';
}

void carregarPlaylist(Playlist *playlistAtual){
    //abrindo arquivo
    char *nomeArquivo = NULL;
    nomeArquivo = lerLinha(nomeArquivo);
    FILE *arquivoPlaylist = fopen(nomeArquivo, "rb");

    //if para registrar a existencia do arquivo
    if(!arquivoPlaylist){
        printf("Arquivo %s nao existe.\n", nomeArquivo);
        exit(1);
    }

    //são feitas essas operações para desalocar memória que pode ter sobrado de operações anteriores
    for(int i = 0; i < playlistAtual->numeroMusicas; i++){
        free(playlistAtual->musicas[i].nome);
        free(playlistAtual->musicas[i].artista);
    }
    free(playlistAtual->nome);
    free(playlistAtual->musicas);

    //Ler o nome da playlist, é necessário ler o tamanho antes para evitar problemas com a leitura
    int tamanhoNomePlaylist;
    fread(&tamanhoNomePlaylist, sizeof(int), 1, arquivoPlaylist);
    lerStringArquivo(&playlistAtual->nome, tamanhoNomePlaylist, arquivoPlaylist);
    playlistAtual->musicaEscolhida = 0;

    //alocar memória para as novas músicas
    fread(&playlistAtual->numeroMusicas, sizeof(int), 1, arquivoPlaylist);
    playlistAtual->musicas = (Musica*)malloc(playlistAtual->numeroMusicas * sizeof(Musica));

    //ler cada música do arquivo
    for(int i = 0; i < playlistAtual->numeroMusicas; i++){

        int tamanhoNomeMusica;
        fread(&tamanhoNomeMusica, sizeof(int), 1, arquivoPlaylist);
        lerStringArquivo(&playlistAtual->musicas[i].nome, tamanhoNomeMusica, arquivoPlaylist);

        int tamanhoNomeArtista;
        fread(&tamanhoNomeArtista, sizeof(int), 1, arquivoPlaylist);
        lerStringArquivo(&playlistAtual->musicas[i].artista, tamanhoNomeArtista, arquivoPlaylist);

        fread(&playlistAtual->musicas[i].duracao, sizeof(int), 1, arquivoPlaylist);
    }

    fclose(arquivoPlaylist);
    printf("Playlist %s carregada com sucesso.\n", nomeArquivo);

    binaryToNum(nomeArquivo);

    //necessário por conta da função lerLinha que aloca dinamicamente
    free(nomeArquivo);
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

    while(comando != 7){
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
            case 5:
                scanf("%*[\r\n]s");
                salvarPlaylist(playlistJuliana);
                break;
            case 6:
                scanf("%*[\r\n]s");
                carregarPlaylist(&playlistJuliana);
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
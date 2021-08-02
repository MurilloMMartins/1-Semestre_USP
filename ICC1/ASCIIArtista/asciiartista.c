/*
 * Disciplina: Introdução à Ciência de Computação I 
 *
 * Título: ASCII Artista
 * 
 * Funcionalidade: O programa tem a mesma funcionalidade do "Bucket" do Paint, porém
 * funciona para ASCII art. É necessário um arquivo com a line art em ascii para o programa
 * funcionar. A partir disso, são dados o nome do arquivo, o número de "preenchimento" a
 * serem feitos, o caracter que irá preencher tal área e as coordenadas X e Y do lugar à
 * preencher. Nesse projeto são usados structs, alocação dinâmica e recursão para ele funcionar.
 * 
 * Nome: Murillo Moraes Martins
 * 
 * Número Usp: 12701599
 *
 * Data de Modificação: 26/07/2021
*/

#include <stdio.h>
#include <stdlib.h>

//struct que contém os dados da arte inserida
typedef struct Arte{
    char *nome;
    char **matriz;
    int linhas;
    int colunas;
}arte_t;

//struct que contém as informações do pixel à ser substituido na "pintura"
typedef struct caracterPixel{
    char antes;
    char depois;
}caracter_pixel_t;

char *lerLinha(char *texto);
void preencherMatriz(FILE *arquivoArte, arte_t *arte);
void imprimirMatriz(arte_t arte);
void pintarMatriz(arte_t *arte, caracter_pixel_t pixel, int coordX, int coordY);
void salvarArteFinal(arte_t arte);
void enquadra_arte(char *nome_do_arquivo_da_arte, int  altura_do_quadro, int  largura_do_quadro);

int main(){
    //inicialização das variáveis da struct
    arte_t arteAtual;
    arteAtual.nome = NULL;
    arteAtual.matriz = NULL;
    arteAtual.linhas = 0;
    arteAtual.colunas = 0;

    //lendo o nome e abrindo o arquivo .ascii
    arteAtual.nome = lerLinha(arteAtual.nome);
    FILE *arquivoArte = fopen(arteAtual.nome, "r");
    if(!arquivoArte){
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    //a matriz é preenchida com os dados do arquivo
    preencherMatriz(arquivoArte, &arteAtual);
    //fecha o arquivo
    fclose(arquivoArte);

    //impressão do estado inicial da arte
    printf("Arte inicial:\n");
    imprimirMatriz(arteAtual);

    //variavel que dirá quantas vezes será feito a operação de "preenchimento"
    int etapas;
    scanf(" %d", &etapas);
    for(int i = 0; i < etapas; i++){
        //variaveis necessárias para as operações posteriores
        caracter_pixel_t pixelAtual;
        int coordX, coordY;

        //leitura do caracter que será pintado além das coordenadas que ele será "aplicado"
        scanf(" %c %d %d", &pixelAtual.depois, &coordX, &coordY);
        //declaração dos pixels que serão substituidos na "pintura"
        pixelAtual.antes = arteAtual.matriz[coordX][coordY];

        pintarMatriz(&arteAtual, pixelAtual, coordX, coordY);

        //impressão do estado da arte após as etapas de pintura
        printf("\nArte apos a etapa %d:\n", i);
        imprimirMatriz(arteAtual);
    }

    //salva a arte final no arquivo inicial
    salvarArteFinal(arteAtual);
    
    //enquadra a arte
    printf("\nArte enquadrada:\n");
    enquadra_arte(arteAtual.nome, arteAtual.linhas, arteAtual.colunas);

    //desaloca as variaveis alocadas dinamicamente
    for(int i = 0; i < arteAtual.linhas; i++){
        free(arteAtual.matriz[i]);
    }
    free(arteAtual.matriz);
    free(arteAtual.nome);

    return 0;
}

/**
 * @brief Lê uma string até o \\n
 * 
 * @param texto String que conterá o texto
 * @return char* Retorna o ponteiro que contém o texto armazenado
 */
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

/**
 * @brief Função que preenche a matriz de acordo com o que está armazenado no arquivo .ascii(menos o \\n), 
 * além disso a função também dá update nas linhas e nas colunas da matriz
 * 
 * @param arquivoArte Arquivo que contém a ascii art
 * @param arte Struct que contém os dados da arte
 */
void preencherMatriz(FILE *arquivoArte, arte_t *arte){
    //variaveis para controlar os whiles
    char leitura;
    int controle;

    do{
        //aloca as linhas da matriz dinamicamente
        arte->linhas++;
        arte->matriz = (char **)realloc(arte->matriz, arte->linhas * sizeof(char *));
        //reseta os ponteiros das linhas, assim evitando o uso de um malloc
        arte->matriz[arte->linhas-1] = NULL;
        
        //reseta a variavel de colunas a cada nova linha
        arte->colunas = 0;
        do{ 
            //lê o caracter do arquivo e adiciona ele caso ele seja diferente de \n e não seja encontrado um EOF
            controle = fscanf(arquivoArte, "%c", &leitura);
            if(leitura != '\n' && controle != EOF){
                //aloca as colunas dinamicamente
                arte->colunas++;
                arte->matriz[arte->linhas-1] = (char *)realloc(arte->matriz[arte->linhas-1], arte->colunas * sizeof(char));
                arte->matriz[arte->linhas-1][arte->colunas-1] = leitura;
            }
        }while(leitura != '\n' && controle != EOF);

    }while(controle != EOF);

}

/**
 * @brief Imprime a matriz que contém a arte ascii
 * 
 * @param arte Struct que contém os dados da arte
 */
void imprimirMatriz(arte_t arte){
    for(int i = 0; i < arte.linhas; i++){
        for(int j = 0; j < arte.colunas; j++){
            printf("%c", arte.matriz[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Função recursiva que pinta a uma área com um caracter desejado
 * 
 * @param arte Struct que contém os dados da arte
 * @param pixel Struct que contém os caracteres que serão substituidos e os que irão substituir
 * @param coordX Linha que contem o caractere
 * @param coordY Coluna que contem o caractere
 */
void pintarMatriz(arte_t *arte, caracter_pixel_t pixel, int coordX, int coordY){
    //condição de parada da recursão
    //nesse if é determinado se o pixel escolhido é igual ao caractere que deve ser trocado
    if(arte->matriz[coordX][coordY] == pixel.antes){
        //altera o caracter na matriz
        arte->matriz[coordX][coordY] = pixel.depois;

        //ifs para evitar que sejam acessados valores fora da matriz
        if(coordX+1 < arte->linhas){
            //passo recursivo
            pintarMatriz(arte, pixel,coordX+1, coordY);
        }
        if(coordX-1 >= 0){
            //passo recursivo
            pintarMatriz(arte, pixel, coordX-1, coordY);
        }
        if(coordY+1 < arte->colunas){
            //passo recursivo
            pintarMatriz(arte, pixel, coordX, coordY+1);
        }
        if(coordY-1 >= 0){
            //passo recursivo
            pintarMatriz(arte, pixel, coordX, coordY-1);
        }
    }
}

/**
 * @brief Função que salva a arte final no arquivo inicial, assim sobreescrevendo-o
 * 
 * @param arte Struct que contem os dados da arte final
 */
void salvarArteFinal(arte_t arte){
    //abertura do arquivo no modo write(assim sobreescrevendo o anterior)
    FILE *arquivoArte = fopen(arte.nome, "w");

    //escrevendo os dados da matriz no arquivo
    for(int i = 0; i < arte.linhas; i++){
        for(int j = 0; j < arte.colunas; j++){
            fprintf(arquivoArte, "%c", arte.matriz[i][j]);
        }
        //if que evita que seja adicionado um \n na ultima linha
        if(i != arte.linhas-1){
            fprintf(arquivoArte, "\n");
        }
    }

    //fechando o arquivo
    fclose(arquivoArte);
}

/**
 * @brief Função que enquadra a arte
 * 
 * @param nome_do_arquivo_da_arte Nome do arquivo que contém a arte
 * @param altura_do_quadro Altura da arte
 * @param largura_do_quadro Largura da arte
 */
void enquadra_arte(
	char *nome_do_arquivo_da_arte,
	int  altura_do_quadro,
	int  largura_do_quadro
) {
	FILE *f_arte_ptr = fopen(nome_do_arquivo_da_arte, "r");
	if (f_arte_ptr == NULL) {
		printf(
			"Erro na abertura do arquivo, "
			"Você esqueceu de fechar o arquivo antes? "
			"Ou deu free na string com o nome sem querer?\n"
		);

		exit(EXIT_FAILURE);
	}

	int qtd_espc_comeco;
	const char *apoio;
	if (largura_do_quadro % 2 == 0) {
		qtd_espc_comeco = largura_do_quadro / 2;
		apoio           = "/\\";
	} else {
		qtd_espc_comeco = largura_do_quadro / 2 + 1;
		apoio           = "Ʌ";
	}

	for (int i = 0; i < qtd_espc_comeco; i++) printf(" ");
	printf("%s\n", apoio);

	printf("╭");
	for (int i = 0; i < largura_do_quadro; i++) printf("—");
	printf("╮\n");

	for (int i = 0; i < altura_do_quadro; i++) {
		printf("|");
		for (int j = 0; j < largura_do_quadro; j++) {
			char pixel_atual = fgetc(f_arte_ptr);
			printf("%c", pixel_atual);
		}
		printf("|");

		char quebra = fgetc(f_arte_ptr);
		if (quebra != EOF) printf("%c", quebra);
	};
	fclose(f_arte_ptr);

	printf("\n╰");
	for (int i = 0; i < largura_do_quadro; i++) printf("—");
	printf("╯\n");
}
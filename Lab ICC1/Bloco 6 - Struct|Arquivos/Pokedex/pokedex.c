/*
 * Disciplina: Laboratório de Introdução à Ciência de Computação I 
 *
 * Título: Pokedex
 * 
 * Funcionalidade: O programa funciona como uma pokedex em que o usuário consegue
 * armazenar os dados de vários pokemons. O programa possui 4 comandos, o de
 * adicionar um novo pokemon, o de adicionar/substituir um ataque dele, o de imprimir
 * os dados do pokemon e o de imprimir um ataque de determinado pokemon. Esse programa
 * utiliza alocação dinâmica e structs para operar.
 * 
 * Nome: Murillo Moraes Martins
 * 
 * Número Usp: 12701599
 *
 * Data de Modificação: 22/07/2021
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct atributos{
    int HP;
    int ataque;
    int defesa;
    int ataqueEspecial;
    int defesaEspecial;
    int velocidade;
}atributos_t;

typedef struct ataque{
    char nome[20];
    int poderBase;
    float acuracia;
    char classe;
}ataque_t;

typedef struct pokemon{
    char nome[50];
    char tipoPrimario[20];
    char tipoSecundario[20];
    atributos_t atributos;
    ataque_t ataques[4];
}pokemon_t;

void cadastrarPokemon(pokemon_t **pokedex, int totalPokemons);
void adicionarAtaque(ataque_t *ataque);
void imprimirPokemon(pokemon_t pokemon);
void imprimirAtaque(ataque_t ataque);

int main(){
    //criação da pokedex(que é um vetor da struct pokemon)
    pokemon_t *pokedex = NULL;
    //variavel para guardar o total de pokemons
    int totalDePokemons = 0;

    //variaveis utilizadas durante a execução do programa
    int comando;
    int pokemonSelecionado;
    int ataqueSelecionado;
    do{
        scanf(" %d", &comando);
        switch(comando){
            case 1:
                totalDePokemons++;
                cadastrarPokemon(&pokedex, totalDePokemons);
                break;
            case 2:
                //são feitos scanfs para definir o pokemon selecionado e o ataque selecionado para tal função
                scanf(" %d", &pokemonSelecionado);
                scanf(" %d", &ataqueSelecionado);
                adicionarAtaque(&pokedex[pokemonSelecionado].ataques[ataqueSelecionado]);
                break;
            case 3:
                scanf(" %d", &pokemonSelecionado);
                imprimirPokemon(pokedex[pokemonSelecionado]);
                break;
            case 4:
                scanf(" %d", &pokemonSelecionado);
                scanf(" %d", &ataqueSelecionado);
                imprimirAtaque(pokedex[pokemonSelecionado].ataques[ataqueSelecionado]);
                break;
                break;
            default:
                break;
        }

    }while(comando != 0);

    //desaloca a variável dinâmica
    free(pokedex);

    return 0;
}

//função para cadastrar um novo pokemon
void cadastrarPokemon(pokemon_t **pokedex, int totalPokemons){
    (*pokedex) = (pokemon_t *)realloc((*pokedex), totalPokemons *sizeof(pokemon_t));

    //scanf feito para evitar que um \n entre no fgets abaixo
    scanf("%*[\r\n]s");

    fgets((*pokedex)[totalPokemons-1].nome, 50, stdin);
    fgets((*pokedex)[totalPokemons-1].tipoPrimario, 20, stdin);
    fgets((*pokedex)[totalPokemons-1].tipoSecundario, 20, stdin);
    scanf(" %d", &(*pokedex)[totalPokemons-1].atributos.HP);
    scanf(" %d", &(*pokedex)[totalPokemons-1].atributos.ataque);
    scanf(" %d", &(*pokedex)[totalPokemons-1].atributos.defesa);
    scanf(" %d", &(*pokedex)[totalPokemons-1].atributos.ataqueEspecial);
    scanf(" %d", &(*pokedex)[totalPokemons-1].atributos.defesaEspecial);
    scanf(" %d", &(*pokedex)[totalPokemons-1].atributos.velocidade);

}

//função para adicionar um ataque em um determinado pokemon
void adicionarAtaque(ataque_t *ataque){
    //scanf para evitar que o \n entre no fgets abaixo
    scanf("%*[\r\n]s");

    fgets((*ataque).nome, 20, stdin);
    scanf(" %d", &(*ataque).poderBase);
    scanf(" %f", &(*ataque).acuracia);
    scanf(" %c", &(*ataque).classe);
}

//função para imprimir os dados de um pokemon
void imprimirPokemon(pokemon_t pokemon){
    printf("Nome do Pokemon: %s", pokemon.nome);
    printf("Tipo primario: %s", pokemon.tipoPrimario);
    printf("Tipo secundario: %s", pokemon.tipoSecundario);
    printf("Status:\n");
    printf("\tHP: %d\n", pokemon.atributos.HP);
    printf("\tAtaque: %d\n", pokemon.atributos.ataque);
    printf("\tDefesa: %d\n", pokemon.atributos.defesa);
    printf("\tAtaque Especial: %d\n", pokemon.atributos.ataqueEspecial);
    printf("\tDefesa Especial: %d\n", pokemon.atributos.defesaEspecial);
    printf("\tVelocidade: %d\n\n", pokemon.atributos.velocidade);
}

//função para imprimir os dados de um ataque de um pokemon
void imprimirAtaque(ataque_t ataque){
    printf("Nome do Ataque: %s", ataque.nome);
    printf("Poder base: %d\n", ataque.poderBase);
    printf("Acuracia: %f\n", ataque.acuracia);
    printf("Classe: %c\n\n", ataque.classe);
}
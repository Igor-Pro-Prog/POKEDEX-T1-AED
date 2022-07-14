#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUANTIDADE_POKEMONS 18

typedef struct Pokemon {
    char nome[100];
    int sla,hp,score_total,id ,ataque, defesa, vel_ataque, vel_defesa, velocidade,tipo;
    struct Pokemon *proximo;
} Pk;

typedef struct lista {
    Pk *inicio;
    Pk *fim;
    int tamanho, seed;
} Pokedex;

void inicializa (Pokedex *lista);
int removerPokemon(Pokedex *lista, int id);
int inserirInicio(Pokedex *lista,char nome[],int ataque,int score_total,
    int hp, int defesa,int  vel_ataque,int vel_defesa,int velocidade,int tipo);
void imprime(Pokedex *lista);
void qtd_por_Tipor ( Pokedex *lista , char *tipos[], int tipo);
void tamanho (Pokedex *lista);
int atualiza_Pokemon ( Pokedex *lista , int id );
void libera_Pokedex ( Pokedex *lista );
void procurarPokemonPorId(Pokedex *lista, int id);

#include <stdlib.h>
#include "pokedex.h"

const char *tipos[QUANTIDADE_POKEMONS] = {
    "Fire", "Watter", "Grass", "Electric", "Ice", "Fighting",
    "Poison", "Ground", "Flying", "Psychic", "Bug", "Rock", "Ghost",
    "Dragon", "Dark", "Steel", "Normal", "Fairy"};

Pk *criarPokemon()
{
    Pk *pokemon = (Pk *)malloc(sizeof(Pk));

    pokemon->nome = (char *)malloc(sizeof(char) * 50);
    pokemon->sla = 0;

    printf("Digite o nome do pokemon: ");
    scanf("%s", pokemon->nome);
    printf("\n");
    fflush(stdin);
    printf("Digite quantos pontos de ataque o pokemon tem: ");
    scanf("%d", &pokemon->ataque);
    printf("\n");
    fflush(stdin);
    printf("Digite quantos pontos de defesa o pokemon tem: ");
    scanf("%d", &pokemon->defesa);
    printf("\n");
    fflush(stdin);
    printf("Digite quantos pontos de HP o pokemon tem: ");
    scanf("%d", &pokemon->hp);
    printf("\n");
    fflush(stdin);
    printf("Digite quantos pontos de velocidade de ataque o pokemon tem: ");
    scanf("%d", &pokemon->vel_ataque);
    printf("\n");
    fflush(stdin);
    printf("Digite quantos pontos de velocidade de defesa o pokemon tem: ");
    scanf("%d", &pokemon->vel_defesa);
    printf("\n");
    fflush(stdin);
    printf("Digite quantos pontos de velocidade o pokemon tem: ");
    scanf("%d", &pokemon->velocidade);
    printf("\n");
    fflush(stdin);
    pokemon->tipo = pedirTipo();
    printf("\n");
    fflush(stdin);

    pokemon->id = rand();
    pokemon->score_total = pokemon->ataque + pokemon->defesa + pokemon->hp + pokemon->vel_ataque + pokemon->vel_defesa + pokemon->velocidade;

    pokemon->prox = NULL;

    return pokemon;
}

ListaPokemon *criarLista()
{
    ListaPokemon *lista = (ListaPokemon *)malloc(sizeof(ListaPokemon));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return lista;
}

Pokedex *criarPokedex()
{
    Pokedex *pokedex = (Pokedex *)malloc(sizeof(Pokedex));
    int i;
    for (i = 0; i < QUANTIDADE_POKEMONS; i++)
    {
        pokedex->listas[i] = criarLista();
    }
    return pokedex;
}

int inserir(Pokedex *pokedex, Pk *pokemon)
{
    if (pokedex == NULL || pokemon == NULL)
        return 0;

    int tipo = pokemon->tipo;
    ListaPokemon *lista = pokedex->listas[tipo];
    if (lista->tamanho == 0)
    {
        lista->inicio = pokemon;
        lista->fim = pokemon;
        lista->tamanho++;
        return 1;
    }
    else
    {
        lista->fim->prox = pokemon;
        lista->fim = pokemon;
        lista->tamanho++;
        return 1;
    }

    return 0;
}

int removerPokemon(Pokedex *pokedex, int id, int tipo)
{
    if (pokedex == NULL)
        return 0;

    ListaPokemon *lista = pokedex->listas[tipo];
    if (lista->tamanho == 0)
    {
        return 0;
    }
    else
    {
        Pk *pokemon = lista->inicio;
        Pk *anterior = NULL;
        while (pokemon != NULL)
        {
            if (pokemon->id == id)
            {
                if (anterior == NULL)
                {
                    lista->inicio = pokemon->prox;
                    lista->tamanho--;
                    free(pokemon);
                    return 1;
                }
                else
                {
                    anterior->prox = pokemon->prox;
                    lista->tamanho--;
                    free(pokemon);
                    return 1;
                }
            }
            anterior = pokemon;
            pokemon = pokemon->prox;
        }
    }
}

void imprimePokemon(Pk *pokemon)
{
    if (pokemon == NULL)
        return;

    printf("Nome: %s\n", pokemon->nome);
    printf("Id: %d\n", pokemon->id);
    printf("Ataque: %d\n", pokemon->ataque);
    printf("Defesa: %d\n", pokemon->defesa);
    printf("HP: %d\n", pokemon->hp);
    printf("Velocidade de ataque: %d\n", pokemon->vel_ataque);
    printf("Velocidade de defesa: %d\n", pokemon->vel_defesa);
    printf("Velocidade: %d\n", pokemon->velocidade);
    printf("Tipo: %s\n", tipos[pokemon->tipo]);
    printf("Score total: %d\n", pokemon->score_total);
    printf("\n");
}

void imprimeTipo(Pokedex *pokedex)
{
    if (pokedex == NULL)
        return;

    int tipo = pedirTipo();

    ListaPokemon *lista = pokedex->listas[tipo];

    if (lista->tamanho == 0)
    {
        printf("Nenhum pokemon do tipo %s foi encontrado.\n", tipos[tipo]);
    }
    else
    {
        Pk *pokemon = lista->inicio;
        while (pokemon != NULL)
        {
            imprimePokemon(pokemon);
            pokemon = pokemon->prox;
        }
    }
}

void qtdPokemonsPokedex(Pokedex *pokedex)
{
    if (pokedex == NULL)
        return;

    int i;
    int qtd = 0;
    for (i = 0; i < QUANTIDADE_POKEMONS; i++)
    {
        ListaPokemon *lista = pokedex->listas[i];
        qtd += lista->tamanho;
    }
    printf("Quantidade de pokemons na pokedex: %d\n", qtd);
}

void qtdPorTipo(Pokedex *pokedex, int tipo)
{
    if (pokedex == NULL)
        return;

    ListaPokemon *lista = pokedex->listas[tipo];
    if (lista->tamanho == 0)
    {
        printf("Lista vazia\n");
    }
    else
    {
        printf("%d\n", lista->tamanho);
    }
}

unsigned int tamanho(Pokedex *pd)
{
    if (pd == NULL)
        return 0;

    unsigned int total = 0;
    for (int i = 0; i < QUANTIDADE_POKEMONS; i++)
    {
        ListaPokemon *lista = pd->listas[i];
        total += lista->tamanho;
    }
    return total;
}

int atualiza_Pokemon(ListaPokemon *lista_pokemon, int id)
{
    if (lista_pokemon == NULL)
        return 0;

    Pk *pokemon = lista_pokemon->inicio;

    // achar o pokemon com o id passado como parametro
    while (pokemon != NULL)
    {
        if (pokemon->id == id)
        {
            break;
        }
        pokemon = pokemon->prox;
    }

    // se nao encontrar o pokemon, retorna 0
    if (pokemon == NULL)
        return 0;

    // atualiza o pokemon
    printf("Digite o nome do pokemon: ");
    scanf("%s", pokemon->nome);
    printf("\n");
    fflush(stdin);
    printf("Digite quantos pontos de ataque o pokemon tem: ");
    scanf("%d", &pokemon->ataque);
    printf("\n");
    fflush(stdin);
    printf("Digite quantos pontos de defesa o pokemon tem: ");
    scanf("%d", &pokemon->defesa);
    printf("\n");
    fflush(stdin);
    printf("Digite quantos pontos de HP o pokemon tem: ");
    scanf("%d", &pokemon->hp);
    printf("\n");
    fflush(stdin);
    printf("Digite quantos pontos de velocidade de ataque o pokemon tem: ");
    scanf("%d", &pokemon->vel_ataque);
    printf("\n");
    fflush(stdin);
    printf("Digite quantos pontos de velocidade de defesa o pokemon tem: ");
    scanf("%d", &pokemon->vel_defesa);
    printf("\n");
    fflush(stdin);
    printf("Digite quantos pontos de velocidade o pokemon tem: ");
    scanf("%d", &pokemon->velocidade);
    printf("\n");
    fflush(stdin);

    pokemon->score_total = pokemon->ataque + pokemon->defesa + pokemon->hp + pokemon->vel_ataque + pokemon->vel_defesa + pokemon->velocidade;

    return 1;
}

void libera_Pokedex(Pokedex *pokedex)
{
    if (pokedex == NULL)
        return;

    for (int i = 0; i < QUANTIDADE_POKEMONS; i++)
    {
        ListaPokemon *lista = pokedex->listas[i];
        if (lista->tamanho == 0)
        {
            continue;
        }
        else
        {
            Pk *pokemon = lista->inicio;
            while (pokemon != NULL)
            {
                Pk *aux = pokemon;
                pokemon = pokemon->prox;
                free(aux);
            }
        }
    }
    free(pokedex);
}

void procurarPokemonPorId(Pokedex *pokedex, int id, Pk *saida)
{
    if (pokedex == NULL)
        return;

    int tipo = pedirTipo();
    Pk *pokemon = pokedex->listas[tipo]->inicio;
    while (pokemon != NULL)
    {
        if (pokemon->id == id)
        {
            *saida = *pokemon;
            break;
        }
        pokemon = pokemon->prox;
    }

    if (pokemon == NULL)
    {
        printf("Pokemon nao encontrado\n");
    }
    else
    {
        imprimePokemon(saida);
    }
}

int pedirTipo()
{
    int tipo;
    do
    {
        printf("Digite o tipo do pokemon:\n");
        for (int i = 0; i < QUANTIDADE_POKEMONS; i++)
        {
            if (i < 10)
                printf(" ");
            printf("%i - TIPO: %s\n", i, tipos[i]);
            fflush(stdin);
        }
        scanf("%d", &tipo);
        printf("\n");
        fflush(stdin);
    } while (tipo < 0 || tipo >= QUANTIDADE_POKEMONS);

    return tipo;
}

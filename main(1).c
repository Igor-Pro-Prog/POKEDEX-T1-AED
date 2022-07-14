#include "pokedex.h"

int main()
{
    printf("                                  ,'\\\n    _.----.        ____         ,'  _\\   ___    ___     ____\n_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |\n   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |\n     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n                                `'                            '-._|\n");

    Pokedex *lista = criarPokedex();
    int n = 1;
    int id;

    while (n != 0)
    {
        printf("Escolha uma Opcao\n");
        printf("0.SAIR \n");
        printf("1.Inserir Pokedex\n");
        printf("2.Remover Pokemon da Pokedex\n");
        printf("3.Imprimir Pokemon Por Tipo\n");
        printf("4.Quantidade De Pokemons Por Tipo\n");
        printf("5.Buscar Pokemon\n");
        printf("6.Quantidade De Pokemons na Pokedex\n");
        printf("7.Liberar Pokedex\n");
        printf("8.Atualizar Pokemon\n");
        printf("Opcao: ");
        scanf("%d", &n);
        printf("\n");
        fflush(stdin);

        if (n != 0 && n > 9 || n < 0)
            printf("OPCAO INVALIDA!\n\n");

        else if (n == 0)
        {
            printf("              .''-,.__\n                 `.     `.  ,\n              .--'  .._,'''-' `.\n             .    .'         `'\n             `.   /          ,'\n               `  '--.   ,-'''\n                `''`   |  \\\n                   -.  \\, |\n                    `---.'      ___.\n                         \\     L._, \\\n               _.,        `.   <  <\\ \\               _\n             ,' '           `, `.   | \\            ( `\n          ../, `.            `  |    . \\`.           \\ \\_\n         ,' ,..  .           _.,'    |  \\            )  ''.\n        , ,'   \\           ,'.-.`-._,'  |           .  _._`.\n      ,' /      \\ \\        `' ' `--/   | \\          / /   ..\\\n    .'  /        \\ .         |\\__ - _ ,'` `        / /     `.`.\n    |  '          ..         `-...-'  |  `-'      / /        . `.\n    | /           |L__           |    |          / /          `. `.\n   , /            .   .          |    |         / /             ` `\n  / /          ,. ,`._ `-_       |    |  _   ,-' /               ` \\\n / .           \\'`_/. `-_ \\_,.  ,'    +-' `-'  _,        ..,-.    \\`.\n.  '         .-|    ,'   `    '.       \\__.---'     _   .'   '     \\ \\\n' /          `.'    |     .' /          \\..      ,_|/   `.  ,'`     L`\n|'      _.-''` `.    \\ _,'  `            \\ `.___`.''`-.  , |   |    | \\\n||    ,'      `. `.   '       _,...._        `  |    `/ '  |   '     .|\n||  ,'          `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   ||\n|| '              V      / /           `   | `   ,'   ,' '.    !  `. ||\n||/            _,-------7 '              . |  `-'    |         /    `||\n. |          ,' .-   ,' ||               | .-.        `.      .'     ||\n `'        ,'    `'.'    |               |    `.        '. -.'       `'\n          /      ,'      |               |,'    \\-.._,.'/'\n          .     /        .               .       \\    .''\n        .`.    |         `.             /         :_,'.'\n          \\ `...\\   _     ,'-.        .'         /_.-'\n           `-.__ `,  `'   .  _.>----''.  _  __  /\n                .'        /''          |  ''   '_\n               /_|.-'\\ ,'.             '.'`__'-( \\\n                 / ,'''\\,'               `/  `-.|'\n");
            printf("DESLIGANDO POKEDEX...\n Treinadores pokemon Igor ketchum e Gabriel Kutrapale da cidade de pallet ate breve\n");
        }
        else if (n == 1)
        {
            if (inserir(lista, criarPokemon()))
                printf("Pokemon inserido com sucesso!\n\n");
            else
                printf("Erro ao inserir Pokemon!\n\n");
        }
        else if (n == 2)
        {

            printf("Digite o ID a ser removido\n");
            scanf("%d", &id);
            int tipo = pedirTipo();

            if (removerPokemon(lista, id, tipo))
                printf("Pokemon removido com sucesso!\n\n");
            else
                printf("Erro ao remover Pokemon!\n\n");
        }
        else if (n == 3)
        {
            imprimeTipo(lista);
        }
        else if (n == 4)
        {
            qtdPorTipo(lista, pedirTipo());
        }
        else if (n == 5)
        {
            printf("Digite o id: ");
            scanf("%d", &id);
            Pk *saida = (Pk *)malloc(sizeof(Pk));
            procurarPokemonPorId(lista, id, saida);
        }
        else if (n == 6)
        {
            qtdPokemonsPokedex(lista);
        }

        else if (n == 7)
        {
            libera_Pokedex(lista);
            printf("Deseja encerrar o programa ou criar outra Pokedex?\n");
            printf("1.Encerrar\n");
            printf("2.Criar outra Pokedex\n");

            do
            {
                scanf("%d", &n);
            } while (n != 1 && n != 2);

            if (n == 1)
                n = 0;
            else if (n == 2)
                lista = criarPokedex();
        }
        else if (n == 8)
        {
            printf("digite id ");
            scanf("%d", &id);
            int score_atualizar;
            printf("digite score a ser atualizado ");
            scanf("%d", &score_atualizar);
            atualiza_Pokemon(lista->listas[pedirTipo()], id);
        }
    }

    return 0;
}

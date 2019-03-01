/*
** EPITECH PROJECT, 2019
** map_creator
** File description:
** creates map for navy
*/

#include "include/my.h"
#include "include/navy.h"

void create_maps(map_t *maps, int player)
{
    malloc_maps(maps, player);
    if (player == 1) {
        maps->playerone_map = fill_maps(maps->playerone_map);
        maps->playertwo_hidden_map = fill_maps(maps->playertwo_hidden_map);
    } else {
        maps->playertwo_map = fill_maps(maps->playertwo_map);
        maps->playerone_hidden_map = fill_maps(maps->playerone_hidden_map);
    }
}

char **fill_maps(char **map)
{
    int ascii_letters = 65;

    map[0][0] = ' ';
    for (int j = 2; j < 17; j++) {
        if (j % 2 != 0)
            map[0][j] = ' ';
        else {
            map[0][j] = ascii_letters;
            ascii_letters++;
        }
    }
    for (int j = 0; j < 17; j++)
        map[1][j] = '-';
    for (int i = 0; i < 10; i++)
        map[i][1] = '|';
    map[1][1] = '+';
    for (int i = 2; i < 10; i++)
        map[i][0] = i - 1 + 48;
    map = add_dots(map);
    return (map);
}

char **add_dots(char **map)
{
    for (int i = 2; i < 10; i++) {
        for (int j = 2; j < 17; j++) {
            if (j % 2 != 0)
                map[i][j] = ' ';
            else
                map[i][j] = '.';
        }
    }
    map[10] = NULL;
    return (map);
}

void display_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    my_putchar('\n');
}

void malloc_maps(map_t *maps, int player)
{
    if (player == 1) {
        maps->playerone_map = malloc(sizeof(char *) * 11);
        maps->playertwo_hidden_map = malloc(sizeof(char *) * 11);
        for (int i = 0; i < 11; i++) {
            maps->playerone_map[i] = malloc(sizeof(char) * 22);
            maps->playertwo_hidden_map[i] = malloc(sizeof(char) * 22);  
        }
    } else {
        maps->playertwo_map = malloc(sizeof(char *) * 11);
        maps->playerone_hidden_map = malloc(sizeof(char *) * 11);
        for (int i = 0; i < 11; i++) {
            maps->playertwo_map[i] = malloc(sizeof(char) * 22);
            maps->playerone_hidden_map[i] = malloc(sizeof(char) * 22);
        }
    }
}
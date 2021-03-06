/*
** EPITECH PROJECT, 2019
** map_creator
** File description:
** creates map for navy
*/

#include "include/my.h"
#include "include/navy.h"

void create_maps(map_t *maps)
{
    malloc_maps(maps);
    maps->playerone_map = fill_maps(maps->playerone_map);
    maps->playertwo_hidden_map = fill_maps(maps->playertwo_hidden_map);
    maps->playertwo_map = fill_maps(maps->playertwo_map);
    maps->playerone_hidden_map = fill_maps(maps->playerone_hidden_map);
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

char **add_dots_j(char **map, int i)
{
    for (int j = 2; j < 17; j++) {
        if (j % 2 != 0)
            map[i][j] = ' ';
        else
            map[i][j] = '.';
    }
    return (map);
}

char **add_dots(char **map)
{
    for (int i = 2; i < 10; i++)
        map = add_dots_j(map, i);
    map[10] = NULL;
    return (map);
}
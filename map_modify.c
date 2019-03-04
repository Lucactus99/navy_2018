/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** map_modify
*/

#include "include/get_next_line.h"
#include "include/my.h"
#include "include/navy.h"

char **modify_map(char **map, int x, int y)
{
    if (counter == 3)
        map[y + 1][x + x] = 'x';
    else
        map[y + 1][x + x] = 'o';
    return (map);
}

int check_length_ship_condition(char **map, int i)
{
    if (map[i][2] == map[i][5]) {
        if (map[i][3] != map[i][6] - i - 1)
            return (1);
    } else if (map[i][2] - 64 != map[i][5] - i - 65)
        return (1);
    return (0);
}

int check_length_ship(char **map)
{
    for (int i = 0; i < 4; i++) {
        if (check_length_ship_condition(map, i) == 1)
            return (1);
    }
    return (0);
}

void display_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    my_putchar('\n');
}

void malloc_maps(map_t *maps)
{
    maps->playerone_map = malloc(sizeof(char *) * 11);
    maps->playertwo_hidden_map = malloc(sizeof(char *) * 11);
    maps->playertwo_map = malloc(sizeof(char *) * 11);
    maps->playerone_hidden_map = malloc(sizeof(char *) * 11);
    for (int i = 0; i < 11; i++) {
        maps->playerone_map[i] = malloc(sizeof(char) * 22);
        maps->playertwo_hidden_map[i] = malloc(sizeof(char) * 22);
        maps->playertwo_map[i] = malloc(sizeof(char) * 22);
        maps->playerone_hidden_map[i] = malloc(sizeof(char) * 22);
    }
}
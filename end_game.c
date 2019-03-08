/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** end_game
*/

#include "my.h"
#include "navy.h"

void display_end_player(map_t *maps)
{
    if (maps->player == 1) {
        display_map(maps->playerone_map);
        display_map(maps->playertwo_hidden_map);
    } else {
        display_map(maps->playertwo_map);
        display_map(maps->playerone_hidden_map);
    }
}

int display_end(int value, map_t *maps)
{
    if (value == 84)
        return (84);
    else if (value == 2) {
        display_end_player(maps);
        my_putstr("I won\n");
        return (0);
    } else {
        display_end_player(maps);
        my_putstr("Enemy won\n");
        return (1);
    }
}

int is_finished_loop(char **map, int i, int counter)
{
    for (int j = 2; map[i][j] != 0; j++) {
        if (map[i][j] == 'x')
            counter++;
    }
    return (counter);
}

int is_finished(char **map)
{
    int counter = 0;

    for (int i = 2; map[i] != NULL; i++)
        counter = is_finished_loop(map, i, counter);
    if (counter >= 14)
        return (0);
    return (1);
}
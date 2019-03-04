/*
** EPITECH PROJECT, 2019
** input_handler.c
** File description:
** handles input for navy
*/

#include "include/get_next_line.h"
#include "include/my.h"
#include "include/navy.h"

int stock_first_pos(int tmp, map_t *maps, int i, char *buffer)
{
    maps->x_init[0] = buffer[i] - 64;
    maps->y_init[0] = buffer[i + 1] - 48;
    tmp++;
    return (tmp);
}

int stock_second_pos(int tmp, map_t *maps, int i, char *buffer)
{
    maps->x_init[1] = buffer[i] - 64;
    maps->y_init[1] = buffer[i + 1] - 48;
    tmp++;
    return (tmp);
}

void modify_map_with_ships(map_t *maps)
{
    if (maps->y_init[0] == maps->y_init[1])
        horizontal_fill(maps);
    if (maps->x_init[0] == maps->x_init[1])
        vertical_fill(maps);
}

void horizontal_fill(map_t *maps)
{
    int i = maps->x_init[0] * 2;

    for (int j = 0; j < maps->boat_length; j++) {
        if (maps->player == 1)
            maps->playerone_map[maps->y_init[0] + 1][i] = maps->boat_length + 48;
        else
            maps->playertwo_map[maps->y_init[0] + 1][i] = maps->boat_length + 48;
        i += 2;
    }
}

void vertical_fill(map_t *maps)
{
    for (int i = maps->y_init[0] + 1; i <= maps->y_init[1] + 1; i++) {
        if (maps->player == 1)
            maps->playerone_map[i][maps->x_init[0] + maps->x_init[1]] = maps->boat_length + 48;
        else
            maps->playertwo_map[i][maps->x_init[0] + maps->x_init[1]] = maps->boat_length + 48;
    }
}


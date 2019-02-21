/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for navy
*/

#include "include/my.h"
#include "include/navy.h"
#include "include/get_next_line.h"

int main(int ac, char **av)
{
    map_t *maps = malloc(sizeof(map_t));
    input_t *input = malloc(sizeof(input_t));

    create_maps(maps);
    if (ac == 2) {
        store_ship_coordinate(maps, av);
    }
    display_map(maps->playerone_map);
    get_playerone_input(input);
    return (0);
}
/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** player_one
*/

#include "my.h"
#include "navy.h"

void player_one_main(map_t *maps, input_t *input, char **av)
{
    int pid = 0;

    printf("my_pid: %d\n", getpid());
    printf("waiting for enemy connection...\n\n");
    while (counter >= 0)
        usleep(10);
    create_maps(maps, 1);
    store_ship_coordinate(maps, av);
    display_map(maps->playerone_map);
    get_playerone_input(input, pid);
}
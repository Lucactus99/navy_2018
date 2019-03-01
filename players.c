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
    maps->player = 1;

    printf("my_pid: %d\n", getpid());
    printf("waiting for enemy connection...\n\n");
    while (counter >= 0)
        usleep(10);
    create_maps(maps);
    store_ship_coordinate(maps, av);
    display_map(maps->playerone_map);
    printf("enemy's positions:\n");
    display_map(maps->playertwo_hidden_map);
    // get_playerone_input(input, pid);
}

void player_two_main(map_t *maps, input_t *input, char **av)
{
    int pid = 0;
    maps->player = 2;

    printf("my_pid: %d\n", getpid());
    pid = my_getnbr(av[2]);
    kill(pid, SIGUSR2);
    while (counter >= 0)
        usleep(10);
    create_maps(maps);
    store_ship_coordinate(maps, av);
    display_map(maps->playertwo_map);
    printf("enemy's positions:\n");
    display_map(maps->playerone_hidden_map);
    // get_playerone_input(input, pid);
}
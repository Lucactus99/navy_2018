/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** player_one
*/

#include "my.h"
#include "navy.h"

int player_one_main(map_t *maps, input_t *input, char **av)
{
    int pid = 0;
    maps->player = 1;

    create_maps(maps);
    if (store_ship_coordinate(maps, av) == 1)
        return (84);
    printf("my_pid: %d\n", getpid());
    printf("waiting for enemy connection...\n\n");
    while (counter >= 0)
        usleep(10);
    display_map(maps->playerone_map);
    printf("enemy's positions:\n");
    display_map(maps->playertwo_hidden_map);
    get_playerone_input(input, counter);
    return (0);
}

int player_two_main(map_t *maps, input_t *input, char **av)
{
    int pid = 0;
    int pos1 = 0;
    int pos2 = 0;
    maps->player = 2;

    create_maps(maps);
    if (store_ship_coordinate(maps, av) == 1)
        return (84);
    printf("my_pid: %d\n", getpid());
    pid = my_getnbr(av[1]);
    kill(pid, SIGUSR2);
    while (counter >= 0)
        usleep(10);
    display_map(maps->playertwo_map);
    printf("enemy's positions:\n");
    display_map(maps->playerone_hidden_map);
    counter = 1;
    printf("waiting for enemy's attack...\n");
    for (int i = 0; i < 800; i++) {
        usleep(1000);
        if (counter == 1)
            i = 0;
    }
    pos1 = counter - 1;
    printf("%c", pos1 + 64);
    counter = 1;
    for (int i = 0; i < 800; i++) {
        usleep(1000);
        if (counter == 1)
            i = 0;
    }
    pos2 = counter - 1;
    printf("%d\n", pos2);
    if (check_receive_input(pos1, pos2, maps))
        printf("hit\n");
    else
        printf("missed\n");
    
    // get_playerone_input(input, pid);
    return (0);
}

int check_receive_input(int x, int y, map_t *maps)
{
    x = x + x;
    y = y + 1;
    if (maps->player == 1) {
        if (maps->playerone_map[y][x] != '.')
            return (1);
    } else {
        if (maps->playertwo_map[y][x] != '.')
            return (1);
    }
    return (0);
}
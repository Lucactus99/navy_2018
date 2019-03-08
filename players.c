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
    int value = 0;

    maps->player = 1;
    create_maps(maps);
    if (store_ship_coordinate(maps, av) == 1)
        return (84);
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putchar('\n');
    my_putstr("waiting for enemy connection...\n\n");
    while (counter >= 0);
    input->playertwo_pid = counter * (-1);
    while (1) {
        display_map(maps->playerone_map);
        my_putstr("enemy's positions:\n");
        display_map(maps->playertwo_hidden_map);
        counter = 1;
        value = player_attack(maps, input);
        if (value > 0)
            return (value);
        value = player_wait(maps, input);
        if (value > 0)
            return (value);
    }
    return (0);
}

int player_two_main(map_t *maps, input_t *input, char **av)
{
    int value = 0;

    maps->player = 2;
    create_maps(maps);
    if (store_ship_coordinate(maps, av) == 1)
        return (84);
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putchar('\n');
    input->playerone_pid = my_getnbr(av[1]);
    kill(input->playerone_pid, SIGUSR2);
    while (counter >= 0)
        usleep(100);
    while (1) {
        display_map(maps->playertwo_map);
        my_putstr("enemy's positions:\n");
        display_map(maps->playerone_hidden_map);
        counter = 1;
        value = player_wait(maps, input);
        if (value > 0)
            return (value);
        value = player_attack(maps, input);
        if (value > 0)
            return (value);
    }
    return (0);
}

void send_hit_signal(int pid, int player)
{
    if (player == 1) {
        kill(pid, SIGUSR1);
        usleep(1000);
        kill(pid, SIGUSR1);
    } else {
        kill(pid, SIGUSR2);
        usleep(1000);
        kill(pid, SIGUSR2);
    }
}

void send_miss_signal(int pid, int player)
{
    if (player == 1)
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
    usleep(1000);
}

int check_receive_input(int x, int y, map_t *maps)
{
    x = x + x;
    y = y + 1;
    if (maps->player == 1) {
        if (maps->playerone_map[y][x] >= 50 && maps->playerone_map[y][x] <= 53)
            return (1);
    } else {
        if (maps->playertwo_map[y][x] >= 50 && maps->playertwo_map[y][x] <= 53)
            return (1);
    }
    return (0);
}
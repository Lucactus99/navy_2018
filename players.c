/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** player_one
*/

#include "my.h"
#include "navy.h"

void check_wait(int pos1, int pos2, map_t *maps, input_t *input)
{
    if (check_receive_input(pos1, pos2, maps)) {
        if (maps->player == 1)
            send_hit_signal(input->playertwo_pid, maps->player);
        else
            send_hit_signal(input->playerone_pid, maps->player);
        my_putchar(pos1 + 64);
        my_putchar(pos2 + 48);
        my_putstr(": hit\n\n");
        counter = 3;
    } else {
        if (maps->player == 1)
            send_miss_signal(input->playertwo_pid, maps->player);
        else
            send_miss_signal(input->playerone_pid, maps->player);
        my_putchar(pos1 + 64);
        my_putchar(pos2 + 48);
        my_putstr(": missed\n\n");
        counter = 2;
    }
}

void my_sleep(void)
{
    counter = 1;
    for (int i = 0; i < 100; i++) {
        usleep(1000);
        if (counter == 1)
            i = 0;
    }
}

void player_wait(map_t *maps, input_t *input)
{
    int pos1 = 0;
    int pos2 = 0;

    my_putstr("waiting for enemy's attack...\n");
    my_sleep();
    pos1 = counter - 1;
    my_sleep();
    pos2 = counter - 1;
    check_wait(pos1, pos2, maps, input);
    if (maps->player == 1)
        maps->playerone_map = modify_map(maps->playerone_map, pos1, pos2);
    else
        maps->playertwo_map = modify_map(maps->playertwo_map, pos1, pos2);
}

void player_attack(map_t *maps, input_t *input)
{
    if (maps->player == 1)
        get_player_input(input, input->playertwo_pid, maps);
    else
        get_player_input(input, input->playerone_pid, maps);
    counter = 1;
    for (int i = 0; i < 100; i++) {
        usleep(1000);
        if (counter == 1)
            i = 0;
    }
    if (counter == 3) {
        if (maps->player == 1) {
            my_putchar(input->playerone_x + 64);
            my_putchar(input->playerone_y + 48);
        } else {
            my_putchar(input->playertwo_x + 64);
            my_putchar(input->playertwo_y + 48);
        }
        my_putstr(": hit\n\n");
    } else {
        if (maps->player == 1) {
            my_putchar(input->playerone_x + 64);
            my_putchar(input->playerone_y + 48);
        } else {
            my_putchar(input->playertwo_x + 64);
            my_putchar(input->playertwo_y + 48);
        }
        my_putstr(": missed\n\n");
    }
    if (maps->player == 1)
        maps->playertwo_hidden_map = modify_map(
            maps->playertwo_hidden_map, input->playerone_x, input->playerone_y);
    else
        maps->playerone_hidden_map = modify_map(
            maps->playerone_hidden_map, input->playertwo_x, input->playertwo_y);
}

int player_one_main(map_t *maps, input_t *input, char **av)
{
    maps->player = 1;
    create_maps(maps);
    if (store_ship_coordinate(maps, av) == 1)
        return (84);
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putchar('\n');
    my_putstr("waiting for enemy connection...\n\n");
    while (counter >= 0)
        usleep(100);
    input->playertwo_pid = counter * (-1);
    while (1) {
        display_map(maps->playerone_map);
        my_putstr("enemy's positions:\n");
        display_map(maps->playertwo_hidden_map);
        counter = 1;
        player_attack(maps, input);
        player_wait(maps, input);
    }
    return (0);
}

char **modify_map(char **map, int x, int y)
{
    if (counter == 3)
        map[y + 1][x + x] = 'x';
    else
        map[y + 1][x + x] = 'o';
    return (map);
}

int player_two_main(map_t *maps, input_t *input, char **av)
{
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
        player_wait(maps, input);
        player_attack(maps, input);
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
        if (maps->playerone_map[y][x] != '.')
            return (1);
    } else {
        if (maps->playertwo_map[y][x] != '.')
            return (1);
    }
    return (0);
}
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
    int pos1 = 0;
    int pos2 = 0;
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
        get_player_input(input, input->playertwo_pid, maps);
        counter = 1;
        for (int i = 0; i < 100; i++) {
            usleep(1000);
            if (counter == 1)
                i = 0;
        }
        if (counter == 3) {
            my_putchar(input->playerone_x + 64);
            my_putchar(input->playerone_y + 48);
            my_putstr(": hit\n\n");
        } else {
            my_putchar(input->playerone_x + 64);
            my_putchar(input->playerone_y + 48);
            my_putstr(": missed\n\n");
        }
        maps->playertwo_hidden_map =
            modify_hidden_map(maps->playertwo_hidden_map, input->playerone_x, input->playerone_y);
        counter = 1;
        my_putstr("waiting for enemy's attack...\n");
        for (int i = 0; i < 100; i++) {
            usleep(1000);
            if (counter == 1)
                i = 0;
        }
        pos1 = counter - 1;
        counter = 1;
        for (int i = 0; i < 100; i++) {
            usleep(1000);
            if (counter == 1)
                i = 0;
        }
        pos2 = counter - 1;
        if (check_receive_input(pos1, pos2, maps)) {
            send_hit_signal(input->playertwo_pid, maps->player);
            my_putchar(pos1 + 64);
            my_putchar(pos2 + 48);
            my_putstr(": hit\n\n");
            counter = 3;
        } else {
            send_miss_signal(input->playertwo_pid, maps->player);
            my_putchar(pos1 + 64);
            my_putchar(pos2 + 48);
            my_putstr(": missed\n\n");
            counter = 2;
        }
        maps->playerone_map = modify_hidden_map(maps->playerone_map, pos1, pos2);
    }
    return (0);
}

char **modify_hidden_map(char **map, int x, int y)
{
    printf("%d\n", x + x);
    if (counter == 3)
        map[y + 1][x + x] = 'x';
    else
        map[y + 1][x + x] = 'o';
    printf("ok\n");
    return (map);
}

int player_two_main(map_t *maps, input_t *input, char **av)
{
    int pos1 = 0;
    int pos2 = 0;
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
        my_putstr("waiting for enemy's attack...\n");
        for (int i = 0; i < 100; i++) {
            usleep(1000);
            if (counter == 1)
                i = 0;
        }
        pos1 = counter - 1;
        counter = 1;
        for (int i = 0; i < 100; i++) {
            usleep(1000);
            if (counter == 1)
                i = 0;
        }
        pos2 = counter - 1;
        if (check_receive_input(pos1, pos2, maps)) {
            send_hit_signal(input->playerone_pid, maps->player);
            my_putchar(pos1 + 64);
            my_putchar(pos2 + 48);
            my_putstr(": hit\n\n");
            counter = 3;
        } else {
            send_miss_signal(input->playerone_pid, maps->player);
            my_putchar(pos1 + 64);
            my_putchar(pos2 + 48);
            my_putstr(": missed\n\n");
            counter = 2;
        }
        maps->playertwo_map = modify_hidden_map(maps->playertwo_map, pos1, pos2);
        get_player_input(input, input->playerone_pid, maps);
        counter = 1;
        for (int i = 0; i < 100; i++) {
            usleep(1000);
            if (counter == 1)
                i = 0;
        }
        if (counter == 3) {
            my_putchar(input->playertwo_x + 64);
            my_putchar(input->playertwo_y + 48);
            my_putstr(": hit\n\n");
        } else {
            my_putchar(input->playertwo_x + 64);
            my_putchar(input->playertwo_y + 48);
            my_putstr(": missed\n\n");
        }
        maps->playerone_hidden_map =
            modify_hidden_map(maps->playerone_hidden_map, input->playertwo_x, input->playertwo_y);
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
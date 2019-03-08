/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** players_useful
*/

#include "include/get_next_line.h"
#include "include/my.h"
#include "include/navy.h"

void my_sleep(void)
{
    counter = 1;
    for (int i = 0; i < 100; i++) {
        usleep(100);
        if (counter == 1)
            i = 0;
    }
}

void display_wait(int pos1, int pos2, map_t *maps, input_t *input)
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

void player_wait(map_t *maps, input_t *input)
{
    int pos1 = 0;
    int pos2 = 0;

    my_putstr("waiting for enemy's attack...\n");
    my_sleep();
    pos1 = counter - 1;
    my_sleep();
    pos2 = counter - 1;
    display_wait(pos1, pos2, maps, input);
    if (maps->player == 1)
        maps->playerone_map = modify_map(maps->playerone_map, pos1, pos2);
    else
        maps->playertwo_map = modify_map(maps->playertwo_map, pos1, pos2);
}

void display_attack(map_t *maps, input_t *input)
{
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
}

void player_attack(map_t *maps, input_t *input)
{
    if (maps->player == 1)
        get_player_input(input, input->playertwo_pid, maps);
    else
        get_player_input(input, input->playerone_pid, maps);
    my_sleep();
    display_attack(maps, input);
    if (maps->player == 1) {
        maps->playertwo_hidden_map = modify_map(maps->playertwo_hidden_map,
        input->playerone_x, input->playerone_y);
    } else {
        maps->playerone_hidden_map = modify_map(maps->playerone_hidden_map,
        input->playertwo_x, input->playertwo_y);
    }
}
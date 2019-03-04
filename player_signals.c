/*
** EPITECH PROJECT, 2019
** player_signal.c
** File description:
** get player input and sends signals
*/

#include "include/get_next_line.h"
#include "include/my.h"
#include "include/navy.h"

void get_player_input(input_t *input, int pid, map_t *maps)
{
    char *tmp_pos;

    my_putstr("attack: ");
    tmp_pos = get_next_line(0);
    if (check_errors(tmp_pos) == 1) {
        my_putstr("wrong position\n");
        get_player_input(input, pid, maps);
    } else if (check_errors(tmp_pos) == 0)
        translate_input(tmp_pos, input, pid, maps);
}

void send_signal_one(int x, int y, int pid, map_t *maps)
{
    for (int i = 0; i < x; i++) {
        kill(pid, SIGUSR1);
        usleep(1000);
    }
    usleep(1250000);
    for (int i = 0; i < y; i++) {
        kill(pid, SIGUSR1);
        usleep(1000);
    }
}

void send_signal_two(int x, int y, int pid, map_t *maps)
{
    for (int i = 0; i < x; i++) {
        kill(pid, SIGUSR2);
        usleep(1000);
    }
    usleep(1250000);
    for (int i = 0; i < y; i++) {
        kill(pid, SIGUSR2);
        usleep(1000);
    }
}

void translate_input(char *tmp_pos, input_t *input, int pid, map_t *maps)
{
    for (int i = 0; tmp_pos[i] != 0; i++) {
        if (tmp_pos[0] > 64 && tmp_pos[0] < 73) {
            if (maps->player == 1)
                input->playerone_x = tmp_pos[0] - 64;
            else
                input->playertwo_x = tmp_pos[0] - 64;
        }
        if (tmp_pos[1] > 48 && tmp_pos[1] < 57) {
            if (maps->player == 1)
                input->playerone_y = tmp_pos[1] - 48;
            else
                input->playertwo_y = tmp_pos[1] - 48;
        }
    }
    if (maps->player == 1)
        send_signal_one(input->playerone_x, input->playerone_y, input->playertwo_pid, maps);
    else
        send_signal_two(input->playertwo_x, input->playertwo_y, input->playerone_pid, maps);
}
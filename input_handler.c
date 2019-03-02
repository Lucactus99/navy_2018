/*
** EPITECH PROJECT, 2019
** input_handler.c
** File description:
** handles input for navy
*/

#include "include/get_next_line.h"
#include "include/my.h"
#include "include/navy.h"

int store_ship_coordinate(map_t *maps, char **av)
{
    int fd;
    char *buffer = malloc(sizeof(char) * 34);
    char **coord_file;
    int x[2] = {0, 0};
    int y[2] = {0, 0};
    int i = 0;
    int a = 0;
    int tmp = 0;
    int length = 0;

    if (maps->player == 2)
        fd = open(av[2], O_RDONLY);
    else
        fd = open(av[1], O_RDONLY);
    read(fd, buffer, 33);
    coord_file = malloc_2d_file(buffer);
    if (check_error_in_file(coord_file, buffer) == 1)
        return (1);
    for (; buffer[i] != '\0'; i++) {
        if (a == 0 && buffer[i] != ':')
            length = buffer[i] - 48;
        if (a == 1 && buffer[i + 1] != ':' && tmp == 0) {
            x[0] = buffer[i] - 64;
            y[0] = buffer[i + 1] - 48;
            tmp++;
        }
        if (a == 2 && buffer[i + 1] != ':' && tmp == 1) {
            x[1] = buffer[i] - 64;
            y[1] = buffer[i + 1] - 48;
            tmp++;
        }
        if (buffer[i] == ':')
            a++;
        if (buffer[i] == '\n' || buffer[i + 1] == 0) {
            a = 0;
            tmp = 0;
            modify_map_with_ships(x, y, length, maps);
        }
    }
    return (0);
}

char **malloc_2d_file(char *buffer)
{
    int lines = count_lines_buffer(buffer);
    int tmp_lines = 0;
    int tmp_cols = 0;
    char **tmp = malloc(sizeof(char *) * lines + 1);

    for (int i = 0; i < lines; i++)
        tmp[i] = malloc(sizeof(char) * 8);
    for (int i = 0; buffer[i] != 0; i++) {
        if (buffer[i] == '\n') {
            tmp_lines++;
            tmp_cols = 0;
        } else {
            tmp[tmp_lines][tmp_cols] = buffer[i];
            tmp_cols++;
        }
    }
    return (tmp);
}

int count_lines_buffer(char *buffer)
{
    int tmp = 0;

    for (int i = 0; buffer[i] != 0; i++) {
        if (buffer[i] == '\n' || buffer[i + 1] == 0)
            tmp++;
    }
    return (tmp);
}

void modify_map_with_ships(int x[], int y[], int length, map_t *maps)
{
    if (y[0] == y[1])
        horizontal_fill(x, y, length, maps);
    if (x[0] == x[1])
        vertical_fill(x, y, length, maps);
}

void horizontal_fill(int x[], int y[], int length, map_t *maps)
{
    int i;

    if (x[0] % 2 == 0)
        i = x[0] + 4;
    else
        i = x[0] + 1;
    for (int j = 0; j < length; j++) {
        if (maps->player == 1)
            maps->playerone_map[y[0] + 1][i] = length + 48;
        else
            maps->playertwo_map[y[0] + 1][i] = length + 48;
        i += 2;
    }
}

void vertical_fill(int x[], int y[], int length, map_t *maps)
{
    for (int i = y[0] + 1; i <= y[1] + 1; i++) {
        if (maps->player == 1)
            maps->playerone_map[i][x[0] + x[1]] = length + 48;
        else
            maps->playertwo_map[i][x[0] + x[1]] = length + 48;
    }
}

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
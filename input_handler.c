/*
** EPITECH PROJECT, 2019
** input_handler.c
** File description:
** handles input for navy
*/

#include "include/my.h"
#include "include/navy.h"
#include "include/get_next_line.h"

void store_ship_coordinate(input_t *input, map_t *maps, char **av)
{
    int fd = open(av[1], O_RDONLY);
    char *buffer = malloc(sizeof(char) * 34);
    int x[2] = {0, 0};
    int y[2] = {0, 0};
    int i = 0;
    int a = 0;
    int tmp = 0;
    int length = 0;

    read(fd, buffer, 33);
    for (i; buffer[i] != '\0'; i++) {
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
    int tmp = x[0];

    for (tmp; tmp <= x[1] + 2; tmp++) {
        maps->playerone_map[y[0]][tmp] = length + 48;
        tmp++;
    }
}

void vertical_fill(int x[], int y[], int length, map_t *maps)
{
    int tmp = y[0];

    for (tmp; tmp <= y[1]; tmp++)
        maps->playerone_map[tmp][x[0]] = length + 48;
}

void get_playerone_input(input_t *input)
{
    char *tmp_pos;

    tmp_pos = get_next_line(0);

    if (check_errors(tmp_pos) == 1) {
        my_putstr("wrong position\n");
        //faire fonction qui redemande la pos
    }
    else if(check_errors(tmp_pos) == 0)
        translate_input(tmp_pos, input);
}

void translate_input(char *tmp_pos, input_t *input)
{
    for (int i = 0; tmp_pos[i] != 0; i++) {
        if (tmp_pos[0] > 64 && tmp_pos[0] < 73)
            input->playerone_x = tmp_pos[0] - 64;
        if (tmp_pos[1] > 48 && tmp_pos[1] < 57)
            input->playerone_y = tmp_pos[1] - 48;
    }
}


int check_errors(char *tmp_pos)
{
    if (strlen(tmp_pos) != 2)
        return (1);
    if ((tmp_pos[0] > 0 && tmp_pos[0] < 65) || (tmp_pos[0] > 72))
        return (1);
    if ((tmp_pos[1] > 0 && tmp_pos[1] < 48) || (tmp_pos[1] > 57))
        return (1);
    return (0);
}
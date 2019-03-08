/*
** EPITECH PROJECT, 2019
** stock_txt.c
** File description:
** stock txt from input
*/

#include "include/get_next_line.h"
#include "include/my.h"
#include "include/navy.h"

int store_ship_coordinate(map_t *maps, char **av)
{
    int fd;
    char *buffer = malloc(sizeof(char) * 34);
    char **coord_file;

    if (maps->player == 2)
        fd = open(av[2], O_RDONLY);
    else
        fd = open(av[1], O_RDONLY);
    read(fd, buffer, 33);
    coord_file = malloc_2d_file(buffer);
    if (check_error_in_file(coord_file, buffer) == 1)
        return (1);
    put_ship_coord_struct(buffer, maps);
    return (0);
}

int put_ship_coord_struct(char *buffer, map_t *maps)
{
    int a = 0;
    int tmp = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (a == 0 && buffer[i] != ':')
            maps->boat_length = buffer[i] - 48;
        if (a == 1 && buffer[i + 1] != ':' && tmp == 0)
            tmp = stock_first_pos(tmp, maps, i, buffer);
        if (a == 2 && buffer[i + 1] != ':' && tmp == 1)
            tmp = stock_second_pos(tmp, maps, i, buffer);
        if (buffer[i] == ':')
            a++;
        if (buffer[i] == '\n' || buffer[i + 1] == 0) {
            a = 0;
            tmp = 0;
            modify_map_with_ships(maps);
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

void my_sleep(void)
{
    counter = 1;
    for (int i = 0; i < 100; i++) {
        usleep(100);
        if (counter == 1)
            i = 0;
    }
}
/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** handles file error for navy
*/

#include "include/my.h"
#include "include/navy.h"

int check_error_in_file(char **coord_file, char *buffer)
{
    if (check_number_of_line(coord_file, buffer) == 1)
        return (1);
    if (check_length_ship(coord_file))
        return (1);
    for (int i = 0; coord_file[i] != NULL; i++)
        if (check_coords_on_line(coord_file[i]) == 1) {
            my_putstr("error in file\n");
            return (1);
        }
    return (0);
}

int check_coords_on_line(char *coord_file)
{
    if (my_strlen(coord_file) != 7)
        return (1);
    if (coord_file[1] != ':' || coord_file[4] != ':')
        return (1);
    if ((coord_file[2] > 0 && coord_file[2] < 65) || (coord_file[2] > 72))
        return (1);
    if ((coord_file[3] > 0 && coord_file[3] < 49) || (coord_file[3] > 56))
        return (1);
    if ((coord_file[5] > 0 && coord_file[5] < 65) || (coord_file[5] > 72))
        return (1);
    if ((coord_file[6] > 0 && coord_file[6] < 49) || (coord_file[6] > 56))
        return (1);
    return (0);
}

int check_number_of_line(char **coord_file, char *buffer)
{
    char tmp = '2';

    if (count_lines_buffer(buffer) != 4) {
        my_putstr("error number of line\n");
        return (1);
    }
    for (int i = 0; i < count_lines_buffer(buffer); i++) {
        if (coord_file[i][0] != tmp) {
            my_putstr("error in first char\n");
            return (1);
        }
        tmp++;
    }
    return (0);
}

int check_errors(char *tmp_pos)
{
    if (my_strlen(tmp_pos) != 2)
        return (1);
    if ((tmp_pos[0] > 0 && tmp_pos[0] < 65) || (tmp_pos[0] > 72))
        return (1);
    if ((tmp_pos[1] > 0 && tmp_pos[1] < 49) || (tmp_pos[1] > 56))
        return (1);
    return (0);
}
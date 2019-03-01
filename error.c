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
	return (0);
}

int check_number_of_line(char **coord_file, char *buffer)
{
	char tmp = '2';

	if (count_lines_buffer(buffer) != 4) {
		printf("error number of line\n");
		return (1);
	}
	for (int i = 0; i < count_lines_buffer(buffer); i++) {
		if (coord_file[i][0] != tmp) {
			printf("error in first char\n");
			return (1);
		}
		tmp++;
	}
	return (0);
}
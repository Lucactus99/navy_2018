/*
** EPITECH PROJECT, 2019
** input_handler.c
** File description:
** handles input for navy
*/

#include "include/my.h"
#include "include/navy.h"
#include "include/get_next_line.h"

void store_ship_coordinate(input_t *input, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *buffer = malloc(sizeof(char) * 34);
	read(fd, buffer, 33);
	int x[2] = {0, 0};
	int y[2] = {0, 0};
	int i = 0;
	int a = 0;
	int tmp = 0;
	int length = 0;

	for (i; buffer[i] != '\n'; i++) {
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
	}
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
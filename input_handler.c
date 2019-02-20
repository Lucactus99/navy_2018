/*
** EPITECH PROJECT, 2019
** input_handler.c
** File description:
** handles input for navy
*/

#include "include/my.h"
#include "include/navy.h"

void store_ship_coordinate(input_t *input, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *buffer = malloc(sizeof(char) * 34);
	read(fd, buffer, 33);
	int x[2] = {0, 0};
	int y[2] = {0, 0};
	int i = 0;
	int a = 0;
	int length = 0;

	for (i; i < 10; i++) {
		if (a == 0)
			length = buffer[i] + 48;
		if (a == 1) {
			x[0] = buffer[i] - 55;
			y[0] = buffer[i] - 48;
		}
		if (buffer[i] == ':')
			a++;
	}
	printf("%d\n", x[0]);
	printf("%d\n", y[0]);
}
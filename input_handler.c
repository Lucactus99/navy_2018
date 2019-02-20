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
	//printf("%d\n", length);
	printf("%d\n", x[0]);
	printf("%d\n", y[0]);
	printf("%d\n", x[1]);
	printf("%d\n", y[1]);
}
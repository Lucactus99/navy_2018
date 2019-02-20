/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for navy
*/

#include "include/my.h"
#include "include/navy.h"

int main(int ac, char **av)
{
	map_t *maps = malloc(sizeof(map_t));

	create_maps(maps);
	return (0);
}
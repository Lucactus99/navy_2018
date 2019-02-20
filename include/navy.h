/*
** EPITECH PROJECT, 2019
** navy.h
** File description:
** navy .h file
*/

#ifndef NAVY_H_
#define NAVY_H_

typedef struct map {
	char **playerone_map;
	char **playertwo_map;
	char **playerone_hidden_map;
	char **playertwo_hidden_map;
} map_t;

typedef struct input {
	char *playerone_ship_pos;
	char *playertwo_ship_pos;
}input_t;


void malloc_maps(map_t *);
char **fill_maps(char **);
void create_maps(map_t *);
void display_map(char **);
char **add_dots(char **);

#endif
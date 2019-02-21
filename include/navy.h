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
	int playerone_x;
	int playerone_y;
}input_t;


void malloc_maps(map_t *);
char **fill_maps(char **);
void create_maps(map_t *);
void display_map(char **);
char **add_dots(char **);
void get_playerone_input(input_t *);
char *get_next_line(int);
int check_errors(char *);
void translate_input(char *, input_t *);
void modify_map_with_ships(int x[], int y[], int, map_t *);
void horizontal_fill(int x[], int y[], int, map_t *);
void vertical_fill(int x[], int y[], int, map_t *);
void store_ship_coordinate(map_t *, char **);

#endif
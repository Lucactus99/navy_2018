/*
** EPITECH PROJECT, 2019
** navy.h
** File description:
** navy .h file
*/

#ifndef NAVY_H_
#define NAVY_H_

extern int counter;

typedef struct map {
    char **playerone_map;
    char **playertwo_map;
    char **playerone_hidden_map;
    char **playertwo_hidden_map;
    int player;
    int x_init[2];
    int y_init[2];
    int boat_length;
} map_t;

typedef struct input {
    char *playerone_ship_pos;
    char *playertwo_ship_pos;
    int playerone_x;
    int playerone_y;
    int playertwo_x;
    int playertwo_y;
    int playerone_pid;
    int playertwo_pid;
} input_t;

void malloc_maps(map_t *);
char **fill_maps(char **);
void create_maps(map_t *);
void display_map(char **);
char **add_dots(char **);
void get_player_input(input_t *, int, map_t *);
char *get_next_line(int);
int check_errors(char *);
void translate_input(char *, input_t *, int , map_t *);
void modify_map_with_ships(map_t *);
void horizontal_fill(map_t *);
void vertical_fill(map_t *);
int store_ship_coordinate(map_t *, char **);
int player_one_main(map_t *, input_t *, char **);
int player_two_main(map_t *, input_t *, char **);
char **malloc_2d_file(char *);
int count_lines_buffer(char *);
int check_number_of_line(char **, char *);
int check_error_in_file(char **, char *);
int check_coords_on_line(char *);
char **modify_map(char **, int, int);
void send_hit_signal(int, int);
void send_miss_signal(int, int);
int check_receive_input(int, int, map_t *);
int check_length_ship(char **);
int put_ship_coord_struct(char *, map_t *);
int stock_first_pos(int, map_t *, int, char *);
int stock_second_pos(int, map_t *, int, char *);

#endif
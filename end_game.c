/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** end_game
*/

#include "my.h"
#include "navy.h"

int is_finished(char **map)
{
    int counter = 0;

    for (int i = 2; map[i] != NULL; i++) {
        for (int j = 2; map[i][j] != 0; j++) {
            if (map[i][j] == 'x')
                counter++;
        }
    }
    if (counter >= 14) {
        return (0);
    }
    return (1);
}
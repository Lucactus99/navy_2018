/*
** EPITECH PROJECT, 2018
** h
** File description:
** h
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#ifndef MY_H_
#define MY_H_
#define GNU_SOURCE

void my_putchar(char);
int my_put_nbr(int);
int my_putstr(char const *);
int my_strlen(char *);
int my_getnbr(char *);

#endif //MY_H_

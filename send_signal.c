/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** send_signal
*/

#include "my.h"
#include "navy.h"

void send_hit_signal(int pid, int player)
{
    if (player == 1) {
        kill(pid, SIGUSR1);
        usleep(1000);
        kill(pid, SIGUSR1);
    } else {
        kill(pid, SIGUSR2);
        usleep(1000);
        kill(pid, SIGUSR2);
    }
}

void send_miss_signal(int pid, int player)
{
    if (player == 1)
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
    usleep(1000);
}
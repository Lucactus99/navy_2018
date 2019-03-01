/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for navy
*/

#include "include/get_next_line.h"
#include "include/my.h"
#include "include/navy.h"

int counter = 0;

void receive_signal(int sig, siginfo_t *siginfo, void *context)
{
    if (sig == SIGUSR2) {
        printf("enemy connected\n\n");
        counter = -1;
        kill(siginfo->si_pid, SIGUSR1);
    } else if (sig == SIGUSR1) {
        printf("successfully connected\n\n");
        counter = -1;
    }
}

void init_sig()
{
    struct sigaction act;

    act.sa_sigaction = &receive_signal;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
}

int main(int ac, char **av)
{
    map_t *maps = malloc(sizeof(map_t));
    input_t *input = malloc(sizeof(input_t));
    int pid = 0;

    init_sig();
    if (ac < 2)
        return (84);
    if (ac >= 2 && ac <= 3) {
        if (ac == 2) {
            player_one_main(maps, input, av);
        } else if (ac == 3) {
            player_two_main(maps, input, av);
        }
    }
    return (0);
}
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
        if (counter == 0) {
            my_putstr("enemy connected\n\n");
            counter = -1 * (siginfo->si_pid);
            kill(siginfo->si_pid, SIGUSR1);
        } else {
            counter++;
        }
    } else if (sig == SIGUSR1) {
        if (counter == 0) {
            my_putstr("successfully connected\n\n");
            counter = -1;
        } else {
            counter++;
        }
    }
}

void init_sig(void)
{
    struct sigaction act;

    act.sa_sigaction = &receive_signal;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
}

void display_help(void)
{
    my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n\tfirst_player_pid: only for the 2nd");
    my_putstr(" player. pid of the first player.\n\tnavy_positions:");
    my_putstr(" file representing the positions of the ships.\n");
}

int main(int ac, char **av)
{
    map_t *maps = malloc(sizeof(map_t));
    input_t *input = malloc(sizeof(input_t));
    int value = 0;

    init_sig();
    if (ac < 2 || ac > 3)
        return (84);
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            display_help();
            return (0);
        }
        value = player_one_main(maps, input, av);
    } else if (ac == 3)
        value = player_two_main(maps, input, av);
    return (display_end(value, maps));
}
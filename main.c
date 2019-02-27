/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for navy
*/

#include "include/my.h"
#include "include/navy.h"
#include "include/get_next_line.h"

int counter = 0;

void receive_signal(int sig, siginfo_t *siginfo, void *context)
{
    if (sig == 12) {
        printf("enemy connected\n\n");
        counter = -1;
        kill(siginfo->si_pid, SIGUSR1);
    } else if (sig == 10) {
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

    init_sig();
    if (ac < 2)
    	return (84);
    if (ac >= 2 && ac <= 4) {
        if (ac == 2) {
            printf("my_pid: %d\n", getpid());
            printf("waiting for enemy connection...\n\n");
            while (counter >= 0)
                usleep(10);
        } else if (ac == 3) {
            printf("my_pid: %d\n", getpid());
            long pid = strtol(av[1], NULL, 10);
            kill(pid, SIGUSR2);
            while (counter >= 0)
                usleep(10);
        }
    	create_maps(maps);
        store_ship_coordinate(maps, av);
    	display_map(maps->playerone_map);
    	get_playerone_input(input);
    }
    return (0);
}
##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

.RECIPEPREFIX +=

CC      =       gcc

SRC     =   main.c \
			map_creator.c \
            input_handler.c \
            players.c \
            players_useful.c \
            src/my_putstr.c \
            src/my_putchar.c \
            src/get_next_line.c \
            src/my_getnbr.c \
            src/my_put_nbr.c \
            error.c \
            players_signal.c \
            map_modify.c \
            stock_txt.c \
            end_game.c \
            send_signal.c


OBJ     =       $(SRC:.c=.o)

NAME    =       navy

CFLAGS  =       -W -Wextra -Wall -pedantic -g -I ./include

all:    $(NAME)

$(NAME):	$(OBJ)
    $(CC) $(OBJ) -o $(NAME) $(CFLAGS)
    rm -f $(OBJ)

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re:		fclean all
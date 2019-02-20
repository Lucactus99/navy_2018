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
            my_putstr.c \
            my_putchar.c \
            input_handler.c \


OBJ     =       $(SRC:.c=.o)

NAME    =       navy

CFLAGS  =       -W -Wextra -Wall -ansi -pedantic -g -std=c99 -I ./include

all:    $(NAME)

$(NAME):	$(OBJ)
    $(CC) $(OBJ) -o $(NAME) $(CFLAGS)
    rm -f $(OBJ)

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re:		fclean all
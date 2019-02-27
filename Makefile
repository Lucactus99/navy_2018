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
            src/my_putstr.c \
            src/my_putchar.c \
            src/get_next_line.c \
            src/my_getnbr.c


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
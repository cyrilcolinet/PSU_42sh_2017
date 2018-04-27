##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Made by developers
##

SRC	=	$(wildcard src/*.c)

CFLAGS	+=	-Wextra -Wall -g3 #-Werror

CFLAGS	+=	-I./include/

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc $(OBJ) -o $(NAME) -Llib/my -lmy

clean:
	make -C lib/my clean
	rm -f $(OBJ)

fclean:	clean
	make -C lib/my fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

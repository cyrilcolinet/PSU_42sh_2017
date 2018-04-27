##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Made by developers
##

SRC	=	$(wildcard src/*.c)

CFLAGS	+=	-Wextra -Wall -g3 #-Werror

CFLAGS	+=	-I../../include/

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

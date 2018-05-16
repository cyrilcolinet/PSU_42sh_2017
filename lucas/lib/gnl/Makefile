##
## EPITECH PROJECT, 2017
## libmy
## File description:
## library my
##

SRC	=	get_next_line.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wextra -Wall -Werror

CFLAGS	=	-I./

LIB_GNL	=	libgnl.a

all:	$(LIB_GNL)

$(LIB_GNL):
	gcc -c $(SRC) -I./
	ar rc $(LIB_GNL) *.o
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB_GNL)

re:	fclean all

.PHONY: all clean fclean re

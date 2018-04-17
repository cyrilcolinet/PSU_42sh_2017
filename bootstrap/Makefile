##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	= my_exec2

NAME_UT	=	units

SRC	=	src/main.c

SRC_UT	=	""

OBJ_UT	=	$(SRC_UT:.c=.o)

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra

CFLAGS	+=	-I./include -g3

LDFLAG	=	-lcriterion -lgcov --coverage

all	:	lib $(NAME)

lib :
		make -C lib

$(NAME)	:	$(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAG)

tests_run:	lib $(OBJ_UT)
		cc -o $(NAME_UT) $(OBJ_UT) $(LDFLAG)
		./units

clean	:
		make -C lib/ clean
		rm -f $(NAME)
		rm -f $(NAME_UT)

fclean	:	clean
		make -C lib/ fclean
		rm -f $(OBJ)

re	:	fclean all

.PHONY: lib

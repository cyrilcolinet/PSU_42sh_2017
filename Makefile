##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	=

NAME_UT	=	units

SRC	=

SRC_UT	=

OBJ_UT	=	$(SRC_UT:.c=.o)

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra

CFLAGS	+=	-I./include -g3

LDFLAG	=	-L./lib/my -lmy

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		make -C lib/my
		cc -o $(NAME) $(OBJ) $(LDFLAG)

tests_run:	$(OBJ_UT)
		make -C lib/my
		cc -o $(NAME_UT) $(OBJ_UT) $(LDFLAG)
		./units

clean	:
		make -C lib/my clean
		rm -f $(NAME)
		rm -f $(NAME_UT)

fclean	:	clean
		make -C lib/my fclean
		rm -f $(OBJ)

re	:	fclean all

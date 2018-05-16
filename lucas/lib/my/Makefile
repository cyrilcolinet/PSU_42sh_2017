##
## EPITECH PROJECT, 2017
## libmy
## File description:
## library my
##

SRC	=	my_put_nbr.c \
		my_getnbr.c \
		my_putchar.c \
		my_strlen.c \
		my_strcat_malloc.c \
		my_putstr.c \
		my_putstr_err.c \
		my_strncmp.c \
		my_strcpy.c \
		my_str_to_word_array2.c \
		my_str_isalpha.c \
		my_strcmp.c \
		my_array_size.c \
		clear_str.c \
		my_memset.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./

LIB_NAME=	libmy.a

all:	$(LIB_NAME)

$(LIB_NAME):
	gcc -c $(SRC) -I./
	ar rc $(LIB_NAME) *.o
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB_NAME)

re:	fclean all

##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC_DIR		=	./src

SRC		=	$(SRC_DIR)/mnshell.c\
			$(SRC_DIR)/boucle.c\
			$(SRC_DIR)/fonction/clear_space.c\
			$(SRC_DIR)/fonction/clear_str.c\
			$(SRC_DIR)/fonction/my_putchar.c\
			$(SRC_DIR)/fonction/my_putstr.c\
			$(SRC_DIR)/fonction/my_strlen.c\
			$(SRC_DIR)/fonction/my_getnbr.c\
			$(SRC_DIR)/fonction/get_next_line.c\
			$(SRC_DIR)/fonction/my_strconfigure.c\
			$(SRC_DIR)/fonction/my_strdup.c\
			$(SRC_DIR)/fonction/my_put_nbr.c\
			$(SRC_DIR)/fonction/my_freetab.c\
			$(SRC_DIR)/argument/my_get_all_arg.c\
			$(SRC_DIR)/argument/my_get_current_arg.c\
			$(SRC_DIR)/argument/my_get_pipe_arg.c\
			$(SRC_DIR)/argument/my_get_pipe_copy_arg.c\
			$(SRC_DIR)/argument/check_pipe_error.c\
			$(SRC_DIR)/argument/check_redirect_error.c\
			$(SRC_DIR)/argument/redirect_get_args.c\
			$(SRC_DIR)/argument/get_type_redirect.c\
			$(SRC_DIR)/environement/check_env.c\
			$(SRC_DIR)/environement/call_setenv.c\
			$(SRC_DIR)/environement/call_unsetenv.c\
			$(SRC_DIR)/environement/print_env.c\
			$(SRC_DIR)/environement/copy_env.c\
			$(SRC_DIR)/environement/copy_path.c\
			$(SRC_DIR)/environement/setenv.c\
			$(SRC_DIR)/environement/unsetenv.c\
			$(SRC_DIR)/environement/add_env.c\
			$(SRC_DIR)/exit/exit.c\
			$(SRC_DIR)/exit/exit2.c\
			$(SRC_DIR)/command/command.c\
			$(SRC_DIR)/command/echo_ex_val.c\
			$(SRC_DIR)/command/execution_command.c\
			$(SRC_DIR)/command/is_dir_file.c\
			$(SRC_DIR)/command/redirect.c\
			$(SRC_DIR)/command/redirect_function.c\
			$(SRC_DIR)/deplacement_cd/call_cd.c\
			$(SRC_DIR)/deplacement_cd/check_is_a_file.c\
			$(SRC_DIR)/deplacement_cd/check_tiret.c\
			$(SRC_DIR)/signaux/handler.c

NAME		=	mysh

CFlAGS		=	-Wall -Wextra

all:		$(NAME)

$(NAME):
		gcc  -g3 $(CFLAGS) -o $(NAME) $(SRC) $(SRC_DIR)/main.c -I./include

clean:
		rm -f *.o
		rm -f *.gc*
		rm -f vgcore.*

fclean: 	clean
		rm -f $(NAME)
		rm -f units

re:		fclean all

.PHONY		=	all, clean, fclean, re

##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	=	42sh

NAME_UT	=	units

SRC_PARSER	=	src/parser/parser.c \
			src/parser/parser_pipe.c

SRC_ENV	=	src/env/init_env.c \
		src/env/env.c \
		src/env/set_env.c \
		src/env/unsetenv.c \
		src/env/init_listenv.c \
		src/env/init_syspath.c \
		src/env/free_env.c \
		src/env/update_env.c

SRC_BUI	=	src/builtin/my_chdir.c \
		src/builtin/my_chdir_err.c \
		src/builtin/my_exit.c \
		src/builtin/is_builtin.c \
		src/builtin/call_builtin.c \
		src/builtin/my_setenv_cmd.c \
		src/builtin/my_unsetenv_cmd.c \
		src/redirection/right_redirection.c \
		src/redirection/left_redirection.c \
		src/redirection/pipe_exec.c

SRC	=	src/exec/my_exec.c \
		src/prompt/prompt_line.c \
		src/main/minishell.c \
		src/utils/my_list_to_array.c \
		src/utils/my_list_size.c \
		src/utils/is_alone.c \
		src/exec/check_access.c \
		src/sig/wstatus_handler.c \
		src/sig/error_messages.c

SRC_UT	=	src/exec/my_exec.c \
		src/prompt/prompt_line.c \
		src/utils/my_list_to_array.c \
		src/utils/my_list_size.c \
		src/exec/check_access.c \
		src/sig/wstatus_handler.c \
		src/sig/error_messages.c \
		tests/test_builtin.c \
		tests/test_builtin2.c \
		tests/test_setenv.c \
		tests/test_unsetenv.c \
		tests/test_path.c \
		tests/test_call.c \
		tests/test_access.c \
		tests/test_exec.c \
		tests/test_prompt.c \
		tests/test_error.c \
		src/utils/is_alone.c

OBJ	=	$(SRC:.c=.o) $(SRC_ENV:.c=.o) \
		$(SRC_BUI:.c=.o) $(SRC_PARSER:.c=.o)

CFLAGS	+=	-Wall -Wextra

CFLAGS	+=	-I./include

LDFLAG	=	-L./lib/my -lmy -L./lib/gnl/ -lgnl

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		make -C lib/my
		make -C lib/gnl
		cc -o $(NAME) $(OBJ) $(LDFLAG)

tests_run:
		make -C lib/my
		make -C lib/gnl
		gcc -o $(NAME_UT) $(SRC_UT) $(SRC_ENV) $(SRC_BUI) \
		-Wall -Wextra -I./include -L./lib/my -lmy --coverage \
		-lgcov -lcriterion -fprofile-arcs -ftest-coverage
		./units

clean	:
		make -C lib/my clean
		rm -f $(NAME)
		rm -f $(NAME_UT)

fclean	:	clean
		make -C lib/my fclean
		make -C lib/gnl fclean
		rm -f $(OBJ)

re	:	fclean all

##
## EPITECH PROJECT, 2018
## CPE_corewar_2017
## File description:
## Corewar Folder Makefile
##

## VARIABLES

NAME			= 	42sh

UNITS 			= 	units

SRC_DIR 		= 	src/

TEST_DIR		= 	tests/

SRC_FILES		= 	main.c							\
				main/main_42.c 						\
				main/get_next_line.c 					\
				main/exec_btree.c					\
				parser/clear/clear_str.c				\
				parser/clear/clear_begin.c				\
				parser/clear/clear_end.c				\
				parser/clear/clear_space.c				\
				parser/clear/clear_separator.c				\
				parser/clear/clear_semicolon.c				\
				parser/clear/clear_begin_end_semicolon.c		\
				parser/clear/clear_ampersand.c				\
				parser/clear/clear_dampersand.c				\
				parser/clear/clear_pipe.c				\
				parser/clear/clear_dpipe.c				\
				parser/clear/clear_redirect_left.c			\
				parser/clear/clear_redirect_dleft.c			\
				parser/clear/clear_redirect_right.c			\
				parser/clear/clear_redirect_dright.c			\
				parser/split_line_separator.c				\
				parser/str_to_tab_separator.c				\
				parser/check_next_separator.c				\
				parser/parser.c 					\
				parser/parser_pipe.c 					\
				parser/str_to_array_42/my_str_to_array_42.c		\
				parser/str_to_array_42/my_str_to_array_pipe_42.c	\
				error_management/error_management.c			\
				env/init_env.c						\
				env/env.c 						\
				env/set_env.c 						\
				env/unsetenv.c 						\
				env/init_listenv.c 					\
				env/init_syspath.c 					\
				env/free_env.c 						\
				env/update_env.c 					\
				builtin/my_chdir.c 					\
				builtin/my_chdir_err.c 					\
				builtin/my_exit.c 					\
				builtin/is_builtin.c 					\
				builtin/call_builtin.c 					\
				builtin/my_setenv_cmd.c 				\
				builtin/my_unsetenv_cmd.c 				\
				builtin/my_echo.c					\
				redirection/right_redirection.c 			\
				redirection/left_redirection.c 				\
				redirection/pipe_exec.c 				\
				exec/my_exec.c 						\
				exec/check_access.c 					\
				utils/my_list_to_array.c 				\
				utils/my_list_size.c 					\
				utils/is_alone.c 					\
				utils/get_next_line.c 					\
				utils/parsing.c						\
				sig/wstatus_handler.c 					\
				sig/error_messages.c 					\
				prompt/prompt_line.c 					\
				globbings/checker.c 					\
				globbings/globbings.c					\
				inhibitors/inhibitors.c					\
				inhibitors/replace_inhibitors.c				\
				inhibitors/inhibitor_errors.c				\
				alias/alias.c						\
				alias/search_alias.c					\
				alias/alias_cmd.c					\
				variables/add_variable.c				\
				variables/delete_variable.c 				\
				variables/parse_variable.c				\
				variables/find_variable.c				\
				variables/replace_variable.c				\
				history/history.c 					\
				ncurses/load_keys.c 					\
				ncurses/can_apply_keybinding.c 				\
				ncurses/get_next_line_ncurses.c				\
				ncurses/ncurses_loader.c				\
				controls/history_getter.c

SRC			= 	$(addprefix $(SRC_DIR), $(SRC_FILES))

TESTS_FILES		=	$(filter-out main.c, $(SRC_FILES))

TESTS_FILES		+=	test_builtin.c

INCLUDE			= 	include/

LIBRARY_DIR		= 	lib/

CC			=	gcc

CFLAGS			= 	-Wall -Wextra -I $(INCLUDE) -g3 -lncurses

LFLAGS			= 	-L $(LIBRARY_DIR) -lmy

UNITS_LFLAGS		= 	$(LFLAGS) -lgcov -lcriterion

## BUILD VARIABLES

BUILD_DIR		= 	build/

BUILD_TESTS_DIR		= 	tests/build/

BUILD_OBJ		= 	$(addprefix $(BUILD_DIR), $(SRC_FILES:.c=.o))

BUILD_TESTS_OBJ		= 	$(addprefix $(BUILD_TESTS_DIR), $(TESTS_FILES:.c=.o))

BUILD_SD		= 	$(shell find $(SRC_DIR) -mindepth 1 -type d -printf '%p\n' | sed -e 's/^src\///')

## RULES

all:			library $(BUILD_DIR) $(NAME)

library:
			$(info [INFO] Compile library)
			make -C $(LIBRARY_DIR)

$(BUILD_DIR):
			mkdir -p $(BUILD_DIR)
			$(foreach SUB_DIR, $(BUILD_SD), $(shell mkdir -p $(BUILD_DIR)$(SUB_DIR)))

$(BUILD_DIR)%.o:	$(SRC_DIR)%.c
			$(CC) $(CFLAGS)   -c -o $@ $<

$(NAME):		$(BUILD_OBJ)
			@$(CC) $(CFLAGS)   -o $(NAME) $(BUILD_OBJ) $(LFLAGS)

tests_run:		fclean library $(UNITS)
			find $(BUILD_TESTS_DIR) -name '*.gc*' -exec mv -t ./ {} +
			./$(UNITS)

$(UNITS):		$(BUILD_TESTS_DIR) $(BUILD_TESTS_OBJ)
			$(CC) $(CFLAGS) -lgcov --coverage   -o $(UNITS) $(BUILD_TESTS_OBJ) --coverage $(UNITS_LFLAGS)

$(BUILD_TESTS_DIR):
			mkdir -p $(BUILD_TESTS_DIR)$(TEST_DIR)
			$(foreach SUB_DIR, $(BUILD_SD), $(shell mkdir -p $(BUILD_TESTS_DIR)$(SUB_DIR)))

$(BUILD_TESTS_DIR)%.o:	$(SRC_DIR)%.c
			$(CC) $(CFLAGS) -lgcov --coverage   -c -o $@ $<

$(BUILD_TESTS_DIR)%.o:	$(TEST_DIR)%.c
			$(CC) $(CFLAGS) -lgcov --coverage   -c -o $@ $<

clean:
			rm -rf $(BUILD_DIR)
			rm -rf $(BUILD_TESTS_DIR)
			find -name '*.gc*' -delete -or -name 'vgcore.*' -delete -o -name '*.o' -delete
			make clean -C $(LIBRARY_DIR)

fclean:			clean
			rm -rf $(NAME)
			rm -rf $(UNITS)
			make fclean -C $(LIBRARY_DIR)

re:			fclean all
